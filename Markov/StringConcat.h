#pragma once
#include "IRunnable.h"
#include <iostream>

///
///@brief Prints sentence after execution
///
///
class StringConcat final : public IRunnable
{
public:
	///
	///@brief Construct a new @c StringConcat object
	///
	///@param sentence sentence to print
	///
	explicit StringConcat(std::string sentence);
	///
	///@brief Prints sentence
	///
	void Run() override;

	///
	///@brief Resets state 
	///
	void Reset() override;
private:
	std::string m_sentence;
};
