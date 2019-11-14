#pragma once
#include "IRunnable.h"
#include "Arc.h"
#include <vector>
#include <random>


class Chain final :public IRunnable
{
public:
	explicit Chain();
	void Run() override;
	std::vector<std::shared_ptr<Arc>> Arcs{};
private:
	std::random_device RandomDevice_;
	std::default_random_engine Generator_;
	std::uniform_real_distribution<> Distribution_;

	
	int CurrentArc_;
};

