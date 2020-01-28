#pragma once
#include <regex>

///
///@brief Wrapper around std::regex
///
class RegexWrapper
{
public:
	explicit RegexWrapper(const std::string& regex);
	///
	///@brief Checks if regex found match in string
	///@param string string to check
	///@return true match found
	///@return false match not found
	///
	bool IsMatch(const std::string& string);
	///
	///@brief Finds first match in string 
	///@param string string to check
	///@return std::string first match
	///
	std::string FindMatch(const std::string& string);
	///
	///@brief Finds all matches in string 
	///@param string string to check
	///@return std::shared_ptr<std::cmatch> matches sptr 
	///
	std::shared_ptr<std::cmatch> FindMatches(const std::string& string);
	std::string ReplaceMatches(const std::string& string,const std::string& replacer) const;
private:
	std::regex m_regex;
	std::cmatch m_match;
};

