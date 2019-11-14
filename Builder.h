#pragma once
#include "Chain.h"
#include <fstream>
#include <unordered_map>
#include <optional>


class Builder
{
public:
	static void Build(std::ifstream& File,const std::shared_ptr<Chain>& Head);
private:
	static int PreBuild(std::ifstream& File);
	
	static std::shared_ptr<Chain> CheckChain(const std::string& String);
	
	inline static std::unordered_map<std::string, std::shared_ptr<Chain>> List_{}; 
};
