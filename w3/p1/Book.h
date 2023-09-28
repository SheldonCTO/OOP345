/*
Name: Ngai Man Szeto
SID:180094211
Email:nszeto1
Date: 27 Sep 2023
*/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <string>

namespace sdds
{
	class Book
	{
		std::string m_title{};
		unsigned m_numChapters{};
		unsigned m_numPages{};

	public:
		Book();
		Book(const std::string &title, unsigned chapters, unsigned pages) : m_title{title}, m_numChapters{chapters}, m_numPages{pages} {}

		// using string to get the title string and return to member
		const std::string &getTitle() const
		{
			return m_title;
		}

		// get the number of Chapter, and number of page and return to member
		const unsigned &getNumChapter() const
		{
			return m_numChapters;
		}

		const unsigned &getNumPages() const
		{
			return m_numPages;
		}

		// In completing Part 2, add here the missing
		// member prototypes that would be necessary for
		// OrderedCollection module code and tester module
		// w3_p2.cpp to manage Book-type object.
		//
		// Write the implementations of these functions
		// in Book.cpp file

		std::ostream &print(std::ostream &os) const;
	};
	std::ostream &operator<<(std::ostream &os, const Book &bk);
}

#endif
