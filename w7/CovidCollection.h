//Student name:Ngai Man Szeto
// USerID: nszeto1
// student ID:180094211
// submit date: 10 Nov 2023


#ifndef SDDS_COVIDCOLLECTION_H
#define SDDS_COVIDCOLLECTION_H
#include <string>
#include <vector>
namespace sdds
{
	struct Covid
	{
		std::string country{};
		std::string city{};
		std::string variant{};
		int year;
		unsigned int noOfCases;
		unsigned int noOfDeaths;
		std::string status{"General"};
	};
	
	class CovidCollection
	{
		std::vector<Covid> m_covid;

	public:
		CovidCollection(){};
		CovidCollection(const std::string &fileName);
		void display(std::ostream &out, const std::string& country= "ALL") const;
		void sort(const std::string& field ="");
		bool inCollection(const std::string& variant, const std::string& country, unsigned int deaths) const;
		std::list<Covid> getListForDeaths(unsigned int deaths) const;
		void updateStatus();
		
	};
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid);
}

#endif