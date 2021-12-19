#include <iostream>
#include <semaphore.h>
#include <cstddef>
#include"test.h"

int hello_world() {
    std::cout << "Hello worldddd." << std::endl;
    return 0;
}

class CountingSemaphore {
    public: 
	CountingSemaphore(std::ptrdiff_t desired);
	void acquire();
	void release();
};
