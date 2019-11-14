#pragma once
#include "Chain.h"
#include <fstream>
#include <unordered_map>
#include "StringConcat.h"
#define STRING_OPTIMIZATION

class Builder
{
public:
	static void Build(std::ifstream& File, const std::shared_ptr<Chain>& Head);
private:
	static int PreBuild(std::ifstream& File);

	inline static std::unordered_map<std::string,std::shared_ptr<Chain>> ChainList_{};

	#ifdef STRING_OPTIMIZATION
	inline static std::unordered_map<std::string,std::shared_ptr<StringConcat>> StringList_{};
	#endif
};

