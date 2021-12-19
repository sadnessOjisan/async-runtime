#include <semaphore>
#include <cstddef>
#include <limits>

class CountingSemaphore {
    public: 
	explicit CountingSemaphore(std::ptrdiff_t desired): semaphore(desired){}
	auto acquire() -> void;
	auto release() -> void;

	private:
	  std::counting_semaphore<std::numeric_limits<std::ptrdiff_t>::max()> semaphore;
};

CountingSemaphore::CountingSemaphore(std::ptrdiff_t desired):semaphore(desired){
}

void CountingSemaphore::acquire(){
	// TODO: call counting semaphore
	this->semaphore.acquire();
};

void CountingSemaphore::release(){
	this->semaphore.release();
}

void acquire(){}