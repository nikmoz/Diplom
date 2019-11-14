#pragma once
#include "Chain.h"
#include <fstream>
#include <unordered_map>



class Builder
{
public:
	static void Build(std::ifstream& File, const std::shared_ptr<Chain>& Head);
private:
	static int PreBuild(std::ifstream& File);
	
	static bool CheckIRunnable(const std::string& String, std::shared_ptr<IRunnable> IRunnable);
	
	inline static std::unordered_map<std::string, std::shared_ptr<class IRunnable>> List_{}; 
};
/*THEME(Nick):
 *1)Do I make List static?
 *-Yes,so I can Link from lower to higher node and save memory
 *-No,so I don't have to deal with name pollution
 *-Change check for created IRunnable so I don't have this problem
*/
