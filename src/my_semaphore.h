#include <semaphore>
#include <cstddef>
#include <limits>

class CountingSemaphore {
    public: 
	explicit CountingSemaphore(std::ptrdiff_t desired);
	auto acquire() -> void;
	auto release() -> void;

	private:
	  std::counting_semaphore<std::numeric_limits<std::ptrdiff_t>::max()> semahore;
};
