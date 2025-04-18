// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Hina Tariq - 2023/03/06
// Cornel - 2023/09/08

#include <iostream>
#include <iomanip>
#include <fstream>
#include "RideRequest.h"


int cout = 0; // won't compile if headers don't follow convention regarding namespaces


int main(int argc, char* argv[])
{
	constexpr int max_record = 10;
	cout = 1;
// TODO: write the prototype for the main function
//         to accept command line arguments
	sdds::arguments(argc, argv);
	// Keep a record of the *Home* rides separately
	sdds::RideRequest recordedRequests[max_record];
	// Keep a count of how many rides recorded
	size_t numRides = 0;

	sdds::RideRequest currentRide;

	for (auto day = 1; day < argc; ++day)
	{
		// Rates change from day 1 to day 2
		if (day == 1) {
			g_taxrate = 0.13;
			g_discount = 1.15;
		}
		else {
			g_taxrate = 0.14;
			g_discount = 1.20;
		}

		// each parameter contains the rides from one day, process each one at a time
		std::cout << "--------------------\n";
		std::cout << "    Day " << day << '\n';
		std::cout << "--------------------\n";
		std::ifstream in(argv[day]);
		if (in.is_open() == false)
		{
			std::cout << "Cannot open file [" << argv[day] << "]. Ignoring it!\n";
			continue; // go to the next iteration of the loop
		}
		std::cout << "Name          |Ride Description         |Price w/ Tax|Price with Discount" << std::endl;
		char ridetag = '\0';

		// loop through each order in the file
		while (!in.eof()) {

			// read in the ridetag
			in >> ridetag;
			// skip the delimiter
			in.ignore();

			// end of the file
			if (in.fail())
				break;

			// read in the rest of the data as a RideRequest
			currentRide.read(in);
			currentRide = currentRide;

			// Handle the office and home rides differently
			if (ridetag == 'O') {
				sdds::RideRequest copy = currentRide;
				copy.display();
			}
			else if (ridetag == 'H') { // adds the home rides to the record
				recordedRequests[numRides++] = currentRide;
				currentRide.display();
			}
		}
	}

	// print the recorded rides
	std::cout << "--------------------\n";
	std::cout << "Recorded Home Ride Orders\n";
	std::cout << "--------------------\n";
	std::cout << "Name          |Ride Description         |Price w/ Tax|Price with Discount" << std::endl;
	for (auto i = 0u; i < numRides; ++i)
		recordedRequests[i].display();
	std::cout << "--------------------\n";

	return cout;
}
