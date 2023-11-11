//Student name:Ngai Man Szeto
// USerID: nszeto1
// student ID:180094211
// submit date: 10 Nov 2023


#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
#include <numeric>
#include <iterator>
#include "CovidCollection.h"

namespace sdds
{

	CovidCollection::CovidCollection(const std::string &fileName)
	{

		auto subString = [](std::string &str, std::string &fileStr)
		{
			str = fileStr.substr(0, 25);
			str = str.erase(0, str.find_first_not_of(" "));
			str = str.erase(str.find_last_not_of(" ") + 1);
			fileStr = fileStr.substr(25, fileStr.length() - 25);
		};

		std::ifstream openFile(fileName);
		if (!openFile.is_open())
		{
			throw "Unable to open [" + fileName + "]";
		}
		std::string covidData{};
		while (getline(openFile, covidData))
		{
			Covid covid{};
			subString(covid.country, covidData);
			subString(covid.city, covidData);
			subString(covid.variant, covidData);
			covid.year = std::stoi(covidData);
			covidData = covidData.substr(5, covidData.length() - 5);
			covid.noOfCases = std::stoi(covidData);
			covidData = covidData.substr(5, covidData.length() - 5);
			covid.noOfDeaths = std::stoi(covidData);
			m_covid.push_back(covid);
		}
	}

	void CovidCollection::sort(const std::string &field)
	{
		std::sort(m_covid.begin(), m_covid.end(), [=](const Covid &covid, const Covid &next)
				  { 
				bool sorting{false};
		

		if (field == "country")
		{
			sorting = covid.country < next.country;
			if (covid.country == next.country)
			{
				sorting = covid.noOfDeaths < next.noOfDeaths;
			}
			
		}
		else if (field == "city")
		{
			sorting = covid.city < next.city;
			if (covid.city == next.city)
			{
				sorting = covid.noOfDeaths < next.noOfDeaths;
			}
			
		}
		else if (field == "variant")
		{
			sorting = covid.variant < next.variant;
			if (covid.variant == next.variant)
			{
				sorting = covid.noOfDeaths < next.noOfDeaths;
			}
			
		}
		else if (field == "year")
		{
			sorting = covid.year < next.year;
			if (covid.year == next.year)
			{
				sorting = covid.noOfDeaths < next.noOfDeaths;
			}
			
		}
		else
		{
			sorting = covid.country < next.country;
			// Default case for sorting by "country" field
			if (covid.country == next.country)
			{
				sorting = covid.noOfDeaths < next.noOfDeaths;
			}
		}
				  return sorting; });
	}

	bool CovidCollection::inCollection(const std::string &variant, const std::string &country, unsigned int deaths) const
	{
		auto result = std::find_if(m_covid.begin(), m_covid.end(), [&](const Covid &item)
								   { return item.country == country && item.variant == variant && item.noOfDeaths > deaths; });

		// Return true if a matching object was found, otherwise return false
		return result != m_covid.end();
	}

	std::list<Covid> CovidCollection::getListForDeaths(unsigned int deaths) const
	{
		// using copy_if and back_insert to create the list
		std::list<Covid> deathList{};
		std::copy_if(m_covid.begin(), m_covid.end(), std::back_inserter(deathList),
					 [&](const Covid &death)
					 {
						 return death.noOfDeaths >= deaths;
					 });

		return deathList;
	}

	void CovidCollection::updateStatus()
	{
		std::transform(m_covid.begin(), m_covid.end(), m_covid.begin(), [&](Covid &item)
					   {
			if(item.noOfDeaths > 300)
			{
				item.status = "EPIDEMIC";
			}
			else if (item.noOfDeaths<50)
			{
				item.status = "EARLY";
			}
			else
			{
				item.status = "MILD";
			}
			return item; });
	}
	void CovidCollection::display(std::ostream &out, const std::string &country) const
	{
		int totalCases{};
		int totalDeaths{};
		bool countryStr{false};
		if (country != "ALL")
		{
			countryStr = true;
			out << "Displaying information of country = " << country << std::endl;
		}

		std::copy_if(m_covid.begin(), m_covid.end(), std::ostream_iterator<Covid>(out, "\n"), [&country](const Covid &covid)
					 { return (country == "ALL" || covid.country == country); });
		totalCases = std::accumulate(m_covid.begin(), m_covid.end(), 0, [&country](int total, const Covid &covid)
									 { return (country == "ALL" || covid.country == country) ? total + covid.noOfCases : total; });

		totalDeaths = std::accumulate(m_covid.begin(), m_covid.end(), 0, [&country](int total, const Covid &covid)
									  { return (country == "ALL" || covid.country == country) ? total + covid.noOfDeaths : total; });
		int totalWorldCases = std::accumulate(m_covid.begin(), m_covid.end(), 0,
											  [](int total, const Covid &covid)
											  {
												  return total + covid.noOfCases;
											  });

		int totalWorldDeaths = std::accumulate(m_covid.begin(), m_covid.end(), 0,
											   [](int total, const Covid &covid)
											   {
												   return total + covid.noOfDeaths;
											   });

		// Print information based on the country parameter
		std::string totalCaseOutput{}, totalDeathOutput{}, caseCountry{}, deathCountry{}, casesPercentageStr{}, deathsPercentageStr{}, percentOutput{};
		std::ostringstream stream;
		if (countryStr)
		{
			out << std::setw(88) << std::setfill('-') << "" << std::endl;
			std::cout << std::setw(0) << std::setfill(' ');
			caseCountry = "Total cases in " + country + ": " + std::to_string(totalCases) + " |";
			deathCountry = "Total deaths in " + country + ": " + std::to_string(totalDeaths) + " |";

			out << "| " << std::setw(86) << caseCountry << std::endl;
			out << "| " << std::setw(86) << deathCountry << std::endl;
			if (totalWorldCases > 0)
			{
				double casesPercentage = static_cast<double>(totalCases) / totalWorldCases * 100;
				double deathsPercentage = static_cast<double>(totalDeaths) / totalWorldDeaths * 100;

				stream << std::fixed << std::setprecision(6) << casesPercentage;
				casesPercentageStr = stream.str();

				stream.str(""); // Clear the stream
				stream << std::fixed << std::setprecision(6) << deathsPercentage;
				deathsPercentageStr = stream.str();
				percentOutput = country + " has " + casesPercentageStr + "% of global cases and " + deathsPercentageStr + "% of global deaths |";
				out << "| " << std::setw(86) << percentOutput << std::endl;
			}
		}
		else
		{
			totalCaseOutput = "Total cases around the world: " + std::to_string(totalWorldCases) + " |";
			totalDeathOutput = " Total deaths around the world: " + std::to_string(totalWorldDeaths) + " |";
			out << "| " << std::setw(86) << std::right << totalCaseOutput << std::endl;
			out << "| " << std::setw(86) << std::right << totalDeathOutput << std::endl;
		}
	}

	std::ostream &operator<<(std::ostream &out, const Covid &theCovid)
	{

		out << "| " << std::setw(21) << std::left << theCovid.country << " | "
			<< std::setw(15) << theCovid.city << " | "
			<< std::setw(20) << theCovid.variant << " | ";
		    theCovid.year > 0 ? out << std::right << std::setw(6) << theCovid.year << " | " : 
		                        out << std::right << std::setw(6) << " "<< " | ";

		out << std::setw(4) << theCovid.noOfCases << " | "
			<< std::setw(3) << theCovid.noOfDeaths << " |"
			<< " | " << std::setw(8) << std::right << theCovid.status << " |";

		return out;
	}
}