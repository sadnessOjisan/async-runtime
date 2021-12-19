#include <semaphore>
#include <cstddef>
#include <limits>

class CountingSemaphore {
    public: 
	explicit CountingSemaphore(std::ptrdiff_t desired);
	auto acquire() -> void;
	auto release() -> void;
	auto try_acquire() -> bool;

	private:
	  std::counting_semaphore<std::counting_semaphore<>::max()> semaphore;
};
