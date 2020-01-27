#include "StringConcat.h"

StringConcat::StringConcat(std::string sentence) : m_sentence(std::move(sentence)) {}

void StringConcat::Run()
{
	std::cout << m_sentence << ' ';
}

void StringConcat::Reset()
{
}
