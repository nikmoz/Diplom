#pragma once
#include "IRunnable.h"
#include "Arc.h"
#include <vector>
#include <random>

///
///@brief Markov chain
///
class Chain final : public IRunnable
{
public:
	explicit Chain();
	///
	///@brief Finds next node and executes arc action
	///
	void Run() override;
		
	///
	///@brief Chech if state with @State number is present in chain
	///
	bool IsPresent(unsigned state);

	std::vector<std::shared_ptr<struct Arc>> m_arcs{};

private:
	bool visited = false;
	int m_currentArc;
};
