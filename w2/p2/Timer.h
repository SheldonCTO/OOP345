
#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H 
#include <chrono>
namespace sdds {
	class Timer
	{
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endTime;
	public:
		void start();
		__int64_t stop();
	};
}
#endif