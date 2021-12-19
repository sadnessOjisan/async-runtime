#include <semaphore>
#include <cstddef>
#include <limits>
#include "my_semaphore.h"

CountingSemaphore::CountingSemaphore(std::ptrdiff_t desired):semaphore(desired){
}

void CountingSemaphore::acquire(){
	// TODO: call counting semaphore
	this->semaphore.acquire();
};

void CountingSemaphore::release(){
	this->semaphore.release();
}

bool CountingSemaphore::try_acquire(){
	return this->semaphore.try_acquire();
}

void acquire(){}