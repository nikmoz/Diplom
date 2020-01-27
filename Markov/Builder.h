#pragma once
#include "Chain.h"
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
	static int PreBuild(std::ifstream &file);

	static std::string ParsePath(const std::string& path);
	inline static std::unordered_map<std::string, std::shared_ptr<Chain>> m_list{};
};
