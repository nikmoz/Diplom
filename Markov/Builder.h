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
	///
	///@brief Builds chain from a file
	///
	///@param file file
	///@param head Chain starting node
	///
	static void Build(std::ifstream &file, const std::shared_ptr<Chain> &head);
private:
	///
	///@brief Calculates arcs amount
	///
	///@param file file
	///@return int arcs amount
	///
	static size_t PreBuild(std::ifstream &file);

	static std::string ParsePath(const std::string& path);

	inline static RegexWrapper m_variableRegex{"@\\w+@"};
	inline static std::unordered_map<std::string, std::shared_ptr<Chain>> m_chainList{};
	static std::shared_ptr<Linker> m_linker;
};
