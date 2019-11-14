#include "Builder.h"
#include "StringConcat.h"
#include <string>


int Builder::PreBuild(std::ifstream& File)
{
	//NOTE(Nick): Temporary here so I can leave header in files
	std::string Header;
	std::getline(File,Header);

	const auto Backup=File.tellg();

	//NOTE(Nick):Count arcs to reserve
	const int Size=std::count(std::istreambuf_iterator<char>(File), 
             std::istreambuf_iterator<char>(), '\n');
	
	File.clear();
	File.seekg(Backup);
	return Size;
}

void Builder::Build(std::ifstream& File, const std::shared_ptr<Chain>& Head)
{
	const auto Size=Builder::PreBuild(File);
	
	Head->Arcs.reserve(Size);
	
	while (!File.eof())
	{
		auto TmpArc=std::make_shared<Arc>();
		
		std::string Type,String;
		File>>TmpArc->From;
		File>>TmpArc->To;
		File>>TmpArc->Chance;
		File>>Type;
		File.get();
		std::getline(File,String);

		//TODO(Nick):Instead of creating new IRunnable, I should check if it exists and create new only if I could find one
		if (Type == "Chain")
		{
			auto IPos=ChainList_.find(String);
			if(IPos!=ChainList_.end())
			{
				TmpArc->IRunnable=IPos->second;
			}
			else
			{
				auto Chain = std::make_shared<class Chain>();
				TmpArc->IRunnable = Chain;
				ChainList_.insert({String,Chain});
				
				std::ifstream NewFile(String);
				Build(NewFile, Chain);
			}
		}
		else if (Type == "String")
		{
			#ifdef STRING_OPTIMIZATION
				auto IPos=StringList_.find(String);
				if(IPos!=StringList_.end())
				{
					TmpArc->IRunnable=IPos->second;
				}
				else
				{
					auto StringRunner = std::make_shared<StringConcat>(String);
					TmpArc->IRunnable = StringRunner;
					StringList_.insert({String,StringRunner});
				}
			#else
			TmpArc->IRunnable = std::make_shared<StringConcat>(String);
			#endif
		}
		else throw "Wrong IRunnable type";

		Head->Arcs.push_back(TmpArc);
	}
	File.close();
}