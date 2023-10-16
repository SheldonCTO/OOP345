// Student Name: Ngai Man Szeto
// Student No: 180094211
// UserId:nszeto1


#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <string>
#include "SpellChecker.h"

namespace sdds
{
	class Book
	{
		std::string m_author{};
		std::string m_title{};
		std::string m_country{};
		size_t m_year{};
		double m_price{};
		std::string m_desc{};

	public:
		Book(){};
		Book(const std::string &bookStr);
		const std::string &title() const;
		const std::string &country() const;
		const size_t &year() const;
		
		double &price();
		//returns the price by reference
		double operator*=(double priceRef);

		//using template T 
		//on the instance spellChecker
		//passing m_desc
		template<typename T>
		void fixSpelling(T& spellChecker)
		{

			spellChecker(m_desc);
		}

		friend std::ostream &operator<<(std::ostream &os, const Book &obj);
	};
}
#endif