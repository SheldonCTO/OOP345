#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include "Book.h"

namespace sdds
{

	
	Book::Book(const std::string &bookStr)
	{
		std::string subStr = bookStr;
		// lambda function for member
		auto bookMember = [=](std::string &memberStr)
		{
			memberStr.erase(0, memberStr.find_first_not_of(" "));
			memberStr.erase(memberStr.find_last_not_of(" ") + 1);
		};
		// lambda function for whole String
		auto wholeStr = [=](std::string &fullStr)
		{
			fullStr = fullStr.substr(fullStr.find(",") + 1, fullStr.length());
		};

		m_author = subStr.substr(0, subStr.find(","));
		bookMember(m_author);
		wholeStr(subStr);

		m_title = subStr.substr(0, subStr.find(","));
		bookMember(m_title);
		wholeStr(subStr);

		m_country = subStr.substr(0, subStr.find(","));
		bookMember(m_country);
		wholeStr(subStr);

		m_price = std::stod(subStr);
		wholeStr(subStr);

		m_year = std::stoi(subStr);
		wholeStr(subStr);

		m_desc = subStr.substr(0, subStr.length());
		bookMember(m_desc);
	}

	const std::string &Book::title() const
	{
		return m_title;
	}

	const std::string &Book::country() const
	{
		return m_country;
	}

	const size_t &Book::year() const
	{
		return m_year;
	}
	

	double &Book::price()
	{
		return m_price;
	}

	double Book::operator*=(double priceRef)
	{
		return m_price *= priceRef;
	}

	std::ostream &operator<<(std::ostream &os, const Book &obj)
	{

		if (os)
		{
			os << " ";
			os << std::setw(19) << std::right << obj.m_author;
			os << " | ";
			os << std::setw(22) << std::right << obj.m_title;
			os << " | ";
			os << std::setw(5) << std::right << obj.m_country;
			os << " | ";
			os << std::setw(4) << std::right << obj.m_year;
			os << " | ";
			os << std::setw(6) << std::fixed << std::setprecision(2) << std::right << obj.m_price;
			os << " | ";
			os << std::left << obj.m_desc<<std::endl;
		}
		return os;
	}
}