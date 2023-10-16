// Student Name: Ngai Man Szeto
// Student No: 180094211
// UserId:nszeto1
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include "Movie.h"

namespace sdds
{
	const std::string &Movie::title() const
	{
		return m_title;
	}

const size_t &Movie::year() const
	{
		return m_year;
	}

	Movie::Movie(const std::string &strMovie)
	{
		std::string subStr = strMovie;

		auto movieStr =[=](std::string& movie)
		{
			movie.erase(0, movie.find_first_not_of(" "));
			movie.erase(movie.find_last_not_of(" ") + 1);
		};

		auto wholeMovie=[=](std::string& fullStr)
		{
			fullStr= fullStr.substr(fullStr.find(",") + 1, fullStr.length());
		};
		
		m_title = subStr.substr(0, subStr.find(","));
		movieStr(m_title);
		wholeMovie(subStr);

		m_year = std::stoi(subStr);
		wholeMovie(subStr);

		m_desc = subStr.substr(0, subStr.length());
		movieStr(m_desc);
	}




	std::ostream &operator<<(std::ostream &os, const Movie &obj)
	{
		if (os)
		{
			os << std::setw(40) << std::right <<obj.m_title
				<<" | "
				<<std::setw(4) << std::right<<obj.m_year
				<<" | "
				<<obj.m_desc<<std::endl;
		}
		return os;
	}

}