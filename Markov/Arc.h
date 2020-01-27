#pragma once
#include "IRunnable.h"
#include <memory>

///
///@brief Connects Nodes in Markov chain
///
struct Arc
{
	int m_from, m_to;
	double m_chance;
	std::shared_ptr<IRunnable> m_iRunnable;
};
