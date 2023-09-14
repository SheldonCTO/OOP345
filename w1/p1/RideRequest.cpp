#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "RideRequest.h"

using namespace std;
double g_taxrate;
double g_discount;

namespace sdds
{
	void arguments(int argc, char *argv[])
	{
		cout << "Command Line:\n";
		cout << "--------------------------\n";
		for (int i = 0; i < argc; i++)
		{
			cout << "  " << i + 1 << ": " << argv[i] << endl;
		}
		cout << "--------------------------\n\n";
	}
	// constructor
	RideRequest::RideRequest(){};

	std::istream &RideRequest::read(std::istream &is)
	{
		if (is)
		{
			// set var discount for converting to bool m_discount
			char discount;
			if (is.getline(m_cName, 11, ','))
			{
				is.getline(m_rideDesc, 26, ',');
				is >> m_priceOfRide;
				is.ignore(1);
				is >> discount;
				is.ignore(1, '\n');
				// condit express
				m_discount = discount == 'Y' ? true : false;
			}
		}

		return is;
	}

	void RideRequest::display()
	{
		static int numRides = 0;
		cout << setw(2) << left << ++numRides << ". ";
		if (m_cName[0] != '\0')
		{
			cout << setw(10) << m_cName << "|";
			cout << setw(25) << m_rideDesc << "|";
			cout << setw(12) << fixed << setprecision(2);
			cout << m_priceOfRide * (1 + g_taxrate) << "|";
			cout << setw(13) << setprecision(2);
			cout << fixed << right;
			if (m_discount)
			{
				cout << (m_priceOfRide * (1 + g_taxrate)) - g_discount << endl;
			}
			else
			{
				cout << endl;
			}
		}
		else
		{
			cout << "No Ride Request" << endl;
		}
		}

}