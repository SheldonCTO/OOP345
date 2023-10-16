// Student Name: Ngai Man Szeto
// Student No: 180094211
// UserId:nszeto1
#include <iomanip>
#include <string>
#include <fstream>
#include "SpellChecker.h"

namespace sdds
{
	SpellChecker::SpellChecker(const char *filename)
	{
		std::ifstream file(filename);
		// handle error condition
		// throw error msg
		if (!file)
		{
			throw "Bad file name!";
		}
		// count and stored the bad and good words to arrary
		std::string str;
		size_t count{};
		while (std::getline(file, str) && count < 6)
		{
			size_t post = str.find(" ");
			m_badWords[count] = str.substr(0, post);
			m_goodWords[count] = str.substr(post + 1);
			m_goodWords[count].erase(0, m_goodWords[count].find_first_not_of(" "));
			count++;
		}
	}

	void SpellChecker::operator()(std::string &text)
	{
		for (size_t i = 0; i < 6; i++)
		{
			while (text.find(m_badWords[i]) < text.length())
			{
				text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]);
				m_size[i]++;
			}
		}
	}

	void SpellChecker::showStatistics(std::ostream &os) const
	{
		os << "Spellchecker Statistics" << std::endl;
		for (size_t i = 0; i < 6; i++)
		{
			os << std::setw(15) << std::right << m_badWords[i]
			   << ": " << m_size[i] << " replacements" << std::endl;
		}
	}

}