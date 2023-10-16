
// Student Name: Ngai Man Szeto
// Student No: 180094211
// UserId:nszeto1
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <string>
#include "SpellChecker.h"

namespace sdds
{
	class Movie
	{
		std::string m_title{};
		size_t m_year{};
		std::string m_desc{};

	public:
		const std::string &title() const;
		const size_t &year() const;
		Movie(){};
		~Movie(){};
		Movie(const std::string &strMovie);
		template <typename T>
		void fixSpelling(T &spellChecker)
		{
			spellChecker(m_title);
			spellChecker(m_desc);
		}

		friend std::ostream &operator<<(std::ostream &os, const Movie &obj);
	};
}
#endif