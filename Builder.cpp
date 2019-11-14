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

std::shared_ptr<Chain> Builder::CheckChain(const std::string& String)
{
	
	return nullptr;
}

void Builder::Build(std::ifstream& File,const std::shared_ptr<Chain>& Head)
{
	const auto Size=Builder::PreBuild(File);

	
	Head->Arcs.reserve(Size);
	
	while (!File.eof())
	{
		auto TmpArc=std::make_shared<Arc>();
		
		std::string Type,String;
		File>>TmpArc->From>>TmpArc->To>>TmpArc->Chance>>Type;
		File.get();
		std::getline(File,String);
		if (Type == "Chain")
		{
			const auto IPos=List_.find(String);
			if(IPos!=List_.end())
			{
				TmpArc->IRunnable = IPos->second;
				std::ifstream NewFile(String);
				Build(NewFile,IPos->second);
			}
			else
			{
				auto ChainT=std::make_shared<Chain>();
				ChainT=std::make_shared<Chain>();
				List_.insert({String, ChainT});
				TmpArc->IRunnable = ChainT;
				std::ifstream NewFile(String);
				Build(NewFile,ChainT);
			}
		}
		else if (Type == "String")
		{
			const auto StringRunner = std::make_shared<StringConcat>(String);
			TmpArc->IRunnable = StringRunner;
			//List.insert({String, StringRunner});
		}
		else throw "Wrong IRunnable type";
		
		Head->Arcs.push_back(TmpArc);
	}
	File.close();
}
