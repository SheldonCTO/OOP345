#ifndef SDDS_RIDEREQUEST_H
#define SDDS_RIDEREQUEST_H

extern double g_taxrate;
extern double g_discount;

namespace sdds {
	void arguments(int argc, char* argv[]);
	class RideRequest
	{
		
		char m_cName[11]{};
		char m_rideDesc[26]{};
		double m_priceOfRide{};
		bool m_discount{};
	public:
		//constructor
		RideRequest();

		//receive istream
		//if good state ->is =  true
		//read and store info into Cur-obj
		std::istream& read(std::istream& is);

		//display function
		//cout format if, good cName
		//cout no ride , if no cName
		void display();

		
	};
}
#endif 