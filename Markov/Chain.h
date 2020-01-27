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
	///@brief Resets chain current arc 
	///
	void Reset() override;
	
	std::vector<Arc> m_arcs{};

private:
	int m_currentArc;
};
