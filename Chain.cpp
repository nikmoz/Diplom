#include "Chain.h"

Chain::Chain():Generator_(RandomDevice_()),Distribution_(0.0,1.0),CurrentArc_(0){}
void Chain::Run()
{
	while (true)
	{
		char IsFound=0;
		const auto Chance = Distribution_(Generator_);

		auto SumChance(0.0);
		for (const auto& Arc : Arcs)
		{
			if (Arc->From == CurrentArc_)
			{
				SumChance += Arc->Chance;
				if (SumChance - Chance > 0)
				{
					CurrentArc_ = Arc->To;
					Arc->IRunnable->Run();
					IsFound=1;
					break;
				}
			}
		}
		if(!IsFound)
		{
			CurrentArc_=0;
			break;
		}
	}
}


