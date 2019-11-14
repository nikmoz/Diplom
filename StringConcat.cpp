#include "StringConcat.h"

StringConcat::StringConcat(std::string Sentence):Sentence_(std::move(Sentence)){}

void StringConcat::Run()
{
	std::cout<<Sentence_<<" ";
}
