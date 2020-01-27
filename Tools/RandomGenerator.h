#pragma once
#include <random>

///
///@brief Generates random float number
///
class RandomGenerator
{
public:
	///
	///@brief Generates random double number via uniform distribution
	///
	///@return double generated number
	///
	static double Generate();

private:
	static std::random_device m_randomDevice;
	static std::default_random_engine m_generator;
	static std::uniform_real_distribution<> m_distribution;
};
