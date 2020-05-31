#include "Markov/Builder.h"
#include <iostream>
#include <functional>
#include <limits>

#include <windows.h>

template <class T, typename F = std::function<bool(const T)>>
void Input(T& a,const std::string_view error = "", F&& validation = [](const T){return true;})
{
	using namespace std;
	while (true)
	{
		cin >> a;
		if (cin.eof() || cin.bad())
		{
			break;
		}
		else if (cin.fail())
		{	
			cin.clear();
			cin.ignore((std::numeric_limits<std::streamsize>::max)(),'\n');
		}
		else if (validation(a)&&(cin.get()=='\n'))
		{
			break;
		}
		std::cout << "Invalid Value! " << error << std::endl;
	}
}
std::shared_ptr<Chain> ResetChain(std::shared_ptr<Chain> head, std::string file_name)
{
	head.reset();
	head = std::make_shared<class Chain>();
	std::ifstream file("Chains/TestChain.txt");

	Builder builder;

	builder.Build(file, head);
	file.close();

	return head;
}
int main()
{
	auto head = std::make_shared<class Chain>();
	std::ifstream file("Chains/TestChain.txt");

	unsigned n;
	std::cout << "Enter amount of sentences to generate:";
	Input(n, "Positive integer value is required",[](const int n){return n>=1;} );

	try
	{
		Builder builder;
		
		builder.Build(file, head);
		file.close();

		for (auto i(0U); i < n; i++)
		{
			head->Run();
			head = ResetChain(head,"Chains/TestChain.txt");
			std::cout << '\n';
		}
	}
	catch (const char* msg)
	{
		std::cerr << msg << '\n';
	}

	std::cout << "\nPress escape key" << std::endl;
	while (true)
	{
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			return 0;
		}
	}
}
