#pragma once
#include <string>
#include <unordered_map>
#include "RegexWrapper.h"

class Linker
{
public:
	explicit Linker(const std::string& fileName);
	~Linker() = default;
	std::string Link(const std::string& string);
private:
	std::unordered_map<std::string,std::string> m_map;
	RegexWrapper m_variableRegex{"(@\\w+@)"};
};

