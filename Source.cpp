#include "Builder.h"
int main()
{
	auto Head=std::make_shared<class Chain>();
	std::ifstream File("TestChain.txt");
	
	Builder::Build(File,Head);
	for (auto I(0);I<5;I++)
	{
		Head->Run();
	}
	return 0;
}
