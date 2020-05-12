#pragma once
#include "Chain.h"
#include "StringConcat.h"
#include "RegexWrapper.h"
#include "Linker.h"
#include <fstream>
#include <unordered_map>

///
///@brief Builds chain from a file
///
class Builder
{
public:
	Builder();
	///
	///@brief Builds chain from a file
	///
	///@param file file
	///@param head Chain starting node
	///
	void Build(std::ifstream &file, const std::shared_ptr<Chain> &head);
private:
	///
	///@brief Calculates arcs amount
	///
	///@param file file
	///@return int arcs amount
	///
	size_t PreBuild(std::ifstream &file) const;

	static std::string ParsePath(const std::string& path);

	RegexWrapper m_variableRegex{"@\\w+@"};
	std::unordered_map<std::string, std::shared_ptr<Chain>> m_chainList{};
	std::shared_ptr<Linker> m_linker;
};
