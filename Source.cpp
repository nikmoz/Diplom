#include "Builder.h"
#include <iostream>

int main()
{
	auto Head=std::make_shared<class Chain>();
	std::ifstream File("TestChain.txt");
	
	Builder::Build(File,Head);
	for (auto I(0);I<10;I++)
	{
		Head->Run();
		std::cout<<'\n';
	}
	return 0;
}
