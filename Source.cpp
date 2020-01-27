#include "Markov/Builder.h"
#include <iostream>

int main()
{
	auto head = std::make_shared<class Chain>();
	std::ifstream file("Chains/TestChain.txt");

	try
	{
		Builder::Build(file, head);
		for (auto i(0); i < 10; i++)
		{
			head->Run();
			head->Reset();
			std::cout << '\n';
		}
	}
	catch (const char *msg)
	{
		std::cerr << msg << '\n';
	}

	getchar(); //TODO delete
	return 0;
}
