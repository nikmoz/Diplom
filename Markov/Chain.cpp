#include "Chain.h"
#include "RandomGenerator.h"
#include <iostream>

Chain::Chain() : m_currentArc(0) {}

void Chain::Run()
{
	while (true)
	{
		char isFound = 0;
		const auto chance = RandomGenerator::Generate();

		auto sumChance(0.0);
		for (const auto &arc : m_arcs)
		{
			if (arc->m_from == m_currentArc)
			{
				sumChance += arc->m_chance;
				if (sumChance - chance > 0)
				{
					m_currentArc = arc->m_to;
					arc->m_iRunnable->Run();
					isFound = 1;
					break;
				}
			}
		}
		if (!isFound)
		{
			//m_currentArc = 0;
			break;
		}
	}
}

bool Chain::IsPresent(unsigned state)
{
	for (auto s: m_arcs)
	{
		if(s->m_from == state || s->m_to==state)
		{
			return true;
		}
	}
	return false;
}
