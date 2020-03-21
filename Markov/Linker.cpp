#include "Linker.h"
#include <fstream>
#include <iostream>

Linker::Linker(const std::string& fileName)
{
	std::ifstream file(fileName);
	while (!file.eof())
	{
		std::string operation, arg1, arg2;
		file >> operation >> arg1 >> arg2;
		if (operation == "define")
		{
			m_map.insert({ "@"+arg1+"@",arg2 });
		}
		else
		{
			throw "Wrong operation type";
		}
	}
	file.close();
}

std::string Linker::Link(const std::string& string)
{
	try
	{
		const auto replacement= m_map.at(m_variableRegex.FindMatch(string));
		return m_variableRegex.ReplaceMatches(string,replacement);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return "";
	}
}
