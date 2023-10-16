// Student Name: Ngai Man Szeto
// Student No: 180094211
// UserId:nszeto1

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <string>

namespace sdds
{
	class SpellChecker
	{
		std::string m_badWords[6]{};
		std::string m_goodWords[6]{};
		size_t m_size[6]{};
	public:
		/// @brief If the file exists,loads its contents.
		///If missing, throws an exception  const char*, 
		///with the message Bad file name!
		///set count for each bad and good words
		/// @param filename 
		SpellChecker(const char *filename);

		/// @brief searches text and replaces any misspelled word
		///ount how many times each misspelled word
		///using std::string::find()
		///using std::string::replace()
		/// @param text 
		void operator()(std::string &text);

		/// @brief 
		/// @param out 
		void showStatistics(std::ostream &os) const;
	};
}

#endif