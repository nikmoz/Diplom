#pragma once
#include "IRunnable.h"
#include <memory>


struct Arc
{
	int From,To;
	double Chance;
	std::shared_ptr<IRunnable> IRunnable;
};



