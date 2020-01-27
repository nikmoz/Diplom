#include "RandomGenerator.h"

std::uniform_real_distribution<> RandomGenerator::m_distribution{0.0, 1.0};
std::random_device RandomGenerator::m_randomDevice{};
std::default_random_engine RandomGenerator::m_generator{m_randomDevice()};

double RandomGenerator::Generate()
{
	return m_distribution(m_generator);
}
