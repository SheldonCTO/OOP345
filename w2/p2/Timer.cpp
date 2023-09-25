
// student: Ngai Man Szeto
// student No: 180094211

#include "Timer.h"
#include <iostream>
#include <ctime>
#include <iomanip>

namespace sdds {
	void Timer::start() {
		startTime = std::chrono::steady_clock::now();
	}

	__int64_t Timer::stop() {
		endTime = std::chrono::steady_clock::now();
		std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
		return static_cast<__int64_t>(duration.count());

	}

}