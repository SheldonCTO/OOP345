#include <fstream>
#include <iostream>
#include <iomanip>
#include "AirportModels.h"

using namespace std;
namespace sdds
{
	std::ostream &Airport::print(std::ostream &os) const
	{
		// find any empty data
		// check str.length()
		if (m_code.length() == 0)
		{
			os << "Empty Airport";
		}
		else
		{
			printTitle(os, "Airport Code : ");
			printString(os, m_code);
			printTitle(os, "Airport Name : ");
			printString(os, m_name);
			printTitle(os, "City : ");
			printString(os, m_city);
			printTitle(os, "State : ");
			printString(os, m_state);
			printTitle(os, "Country : ");
			printString(os, m_country);
			printTitle(os, "Latitude : ");
			os << setw(30) << left << setfill('.');
			os<< m_latitude<<endl;
			printTitle(os, "Longitude : ");
			os << setw(30) << left << setfill('.');
			os<< m_longitude <<endl;
		}

		return os;
	}
	std::ostream &Airport::printString(std::ostream &os, std::string info) const
	{
		os << setw(30) << left << setfill('.');
		os << info << endl;
		return os;
	}


	AirportLog::AirportLog(){};

	AirportLog::~AirportLog()
	{
		delete[] m_Airport;
		m_Airport = nullptr;
	}

	AirportLog::AirportLog(const AirportLog& obj)
	{
		*this = obj;
	}

	AirportLog& AirportLog::operator=(const AirportLog& obj)
	{
		if(this != &obj)
		{
			m_noOfStored = obj.m_noOfStored;
			delete[]m_Airport;
			m_Airport= new Airport[m_noOfStored];
			for (size_t i = 0; i < m_noOfStored; i++)
			{
				m_Airport[i]=obj.m_Airport[i];
			}
			
		}
		return *this;
	}

	AirportLog::AirportLog(AirportLog&& obj)noexcept
	{
		//use move() for moving construct
		*this = std::move(obj);
	}

	AirportLog& AirportLog::operator=(AirportLog&& obj)noexcept
	{
		if (this != &obj) {
			delete[] m_Airport;
			m_Airport = obj.m_Airport;
			m_noOfStored = obj.m_noOfStored;
			obj.m_Airport = nullptr;
			obj.m_noOfStored = 0;
		}
		return *this;
	}
	AirportLog::AirportLog(string fileName)
	{
		// review the file
		ifstream oFile(fileName);
		if (oFile.is_open())
		{
			// set string for reading file line by line
			std::string fileString;
			getline(oFile, fileString);
			while (oFile)
			{
				getline(oFile, fileString);
				if (fileString.length())
				{
					m_noOfStored++;
				}
			}
			oFile.close();
			ifstream oFile(fileName);
			m_Airport = new Airport[m_noOfStored];
			if (oFile.is_open())
			{
				getline(oFile, fileString);
				for (size_t i = 0; i < m_noOfStored && oFile; i++)
				{
					getline(oFile, m_Airport[i].m_code, ',');
					getline(oFile, m_Airport[i].m_name, ',');
					getline(oFile, m_Airport[i].m_city, ',');
					getline(oFile, m_Airport[i].m_state, ',');
					getline(oFile, m_Airport[i].m_country, ',');
					oFile >> m_Airport[i].m_latitude;
					oFile.ignore();
					oFile >> m_Airport[i].m_longitude;
					oFile.ignore();
				}
			}
		}
	}

	void AirportLog::addAirport(Airport curObj)
	{
		Airport *tempData = new Airport[m_noOfStored + 1];
		for (size_t i = 0; m_noOfStored && i < m_noOfStored; i++)
		{
			tempData[i] = m_Airport[i];
		}
		tempData[m_noOfStored] = curObj;
		m_noOfStored++;
		// make sure no memory leak
		delete[] m_Airport;

		// set m_Airport pointer to tempData
		m_Airport = tempData;
	}

	AirportLog AirportLog::findAirport(string stat, string couty)
	{
		AirportLog find{};
		for (size_t i = 0; i < m_noOfStored; i++)
		{
			// check state and country
			if (m_Airport[i].m_state == stat && m_Airport[i].m_country == couty)
			{

				find.addAirport(m_Airport[i]);
			}
		}
		return find;
	}
	Airport AirportLog::operator[](size_t index)
	{
		// set Airport = {}
		Airport empty{};
		return m_noOfStored ? m_Airport[index] : empty;
	}

	AirportLog::operator size_t()
	{
		return m_noOfStored;
	}

	std::ostream &printTitle(std::ostream &os, const string title)
	{
		os.setf(ios::right);
		os.width(23);
		os.fill('.');
		os << title;
		os.unsetf(ios::right);
		return os;
	}

	std::ostream &operator<<(std::ostream &os, Airport right)
	{
		right.print(os);
		return os;
	}
}