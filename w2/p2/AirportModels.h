#ifndef SDDS_AIRPORTMODELS_H
#define SDDS_AIRPORTMODELS_H

#include <string>
#include <iostream>


namespace sdds
{
	struct Airport
	{
		std::string m_code{};
		std::string m_name{};
		std::string m_city{};
		std::string m_state{};
		std::string m_country{};
		float m_latitude{};
		float m_longitude{};

	public:
		/// @brief overload and print the operator
		/// If a given Airport object is in an empty  "Empty Airport"
		/// @param os insertion operator to airport obj
		/// @return os
		std::ostream &print(std::ostream &os) const;

		/// @brief overload and print the operator "All airport string info"
		/// @param info
		/// @return
		std::ostream &printString(std::ostream &os, std::string info) const;

		
		/* data */
	};

	class AirportLog
	{
		/// @brief manage arrays of airport
		Airport *m_Airport{};
		/// @brief count of how many are being stored
		size_t m_noOfStored{};

		/// @brief default constructor
	public:
		AirportLog();

		///rule of five
		///destructor
		~AirportLog();
		//copy construct
		AirportLog(const AirportLog& obj);
		//copy assignment
		AirportLog& operator=(const AirportLog& obj);
		//move constructor
		//add noexcept,to make sure the functionwill not throw exceptions.
		AirportLog(AirportLog&& obj) noexcept;
		//move assignment
		AirportLog& operator=(AirportLog&&obj)noexcept;


		/// @brief review the file from the current obj
		/// read the file to count the num of airport
		/// allocate memory for arr
		/// reread the file from the beginning to load the data into the array
		/// @param file receive filename parameter
		AirportLog(std::string file);

		/// @brief receive const refer to the airport obj, and no return
		/// @param curObj dynamic array of airport held by curObj
		/// resize the array to accommodate the new obj
		/// avoid memory leaks->set temp and delete
		void addAirport(Airport curObj);

		/// @brief receives two C-style strings the state name and the country name
		/// @param location location.state and country
		/// @return returns an AirportLog object
		AirportLog findAirport(std::string stat, std::string couty);

		/// @brief  If the index is not valid, return an empty Airport instead.
		/// @param index airport array num
		/// @return noOfStore to airport[index] or empty
		Airport operator[](size_t index);

		/// @brief convert the obj to the size_t m_stored
		operator size_t();
	};
	/// @brief print the string title to the os
	/// @param os os obj
	/// @param title curObj
	/// @return os
	std::ostream &printTitle(std::ostream &os, const std::string title);
	/// @brief overload the airport obj to os
	/// @param os cout obj
	/// @param right curObj
	/// @return os
	std::ostream &operator<<(std::ostream &os, Airport right);

}

#endif
