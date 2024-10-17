#include "BeautyShell.h"

namespace CnslTime {

	std::chrono::steady_clock::time_point currentTime;

	std::chrono::steady_clock::time_point GetCurrentTime() {
		return std::chrono::steady_clock::now();
	}

	int ConvertTimeDifToMs(std::chrono::steady_clock::duration duration) {
		return static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(duration).count());
	}
}