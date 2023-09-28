/*
Name: Ngai Man Szeto
SID:180094211
Email:nszeto1
Date: 27 Sep 2023
*/

#include <iostream>
#include <iomanip>
#include "Book.h"

namespace sdds
{
	Book::Book() : m_title(""), m_numChapters(), m_numPages() {}

	std::ostream &Book::print(std::ostream &os) const
	{
		if (m_title[0] != '\0')
		{
			std::string info = m_title + "," + std::to_string(m_numChapters) + "," + std::to_string(m_numPages);
			os << std::setw(56)<< std::right << info << " ";
			os << "|";
			double avg = ((double)m_numPages / (double)m_numChapters) * 1.000000;
			std::string avgContent = " (" + std::to_string(avg) + ")";
			os<<std::setw(16)<<std::left <<std::fixed << avgContent;
			os.unsetf(std::ios::fixed);
		}
		else
		{
			os<< "| Invalid book data";
		}
		return os;
	}

	std::ostream &operator<<(std::ostream &os, const Book &bk)
	{
		bk.print(os);
		return os;
	}

}