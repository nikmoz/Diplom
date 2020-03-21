#include "RegexWrapper.h"
#include <iostream>

RegexWrapper::RegexWrapper(const std::string& regex)
	: m_regex(regex)
{
}

bool RegexWrapper::IsMatch(const std::string& string)
{
	std::regex_search(string.c_str(),m_match,m_regex);
	return !m_match.empty();
}

std::string RegexWrapper::FindMatch(const std::string& string)
{
	std::regex_search(string.c_str(),m_match,m_regex);
	if(m_match.empty())
	{
		return "";
	}
	return m_match[0];
}

std::shared_ptr<std::cmatch> RegexWrapper::FindMatches(const std::string& string)
{
	std::regex_search(string.c_str(),m_match,m_regex);
	return std::make_shared<std::cmatch>(m_match);
}

std::string RegexWrapper::ReplaceMatches(const std::string& string,const std::string& replacer) const
{
	return std::regex_replace(string,m_regex,replacer);
}
