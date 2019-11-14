#pragma once
#include "IRunnable.h"
#include <iostream>

class StringConcat final :
	public IRunnable
{
public:
	explicit StringConcat(std::string Sentence);
	void Run() override;
private:
	std::string Sentence_;
};

