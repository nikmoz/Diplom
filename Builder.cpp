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

bool Builder::CheckIRunnable(const std::string& String, std::shared_ptr<IRunnable> IRunnable)
{
	const auto IPos=List_.find(String);
	if(IPos!=List_.end())
	{
		IRunnable=IPos->second;
		return true;
	}
	return false;
}

void Builder::Build(std::ifstream& File, const std::shared_ptr<Chain>& Head)
{
	const auto Size=Builder::PreBuild(File);

	std::unordered_map<std::string,std::shared_ptr<IRunnable>> List;
	
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

		if(!CheckIRunnable(String,TmpArc->IRunnable))
		{
			if (Type == "Chain")
			{
				auto Chain = std::make_shared<class Chain>();
				TmpArc->IRunnable = Chain;
				List.insert({String, Chain});

				std::ifstream NewFile(String);
				Build(NewFile, Chain);
			}
			else if (Type == "String")
			{
				const auto StringRunner = std::make_shared<StringConcat>(String);
				TmpArc->IRunnable = StringRunner;
				//List.insert({String, StringRunner});
			}
			else throw "Wrong IRunnable type";
		}
		Head->Arcs.push_back(TmpArc);
	}
	File.close();
}
