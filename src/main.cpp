// test semaphore

#include "my_semaphore.h"
// #include <atomic>
#include <iostream>
int main()
{
    auto semaphore = new CountingSemaphore(3);
    semaphore->acquire();
    semaphore->acquire();
    semaphore->release();
}

constexpr int NUM = 100;

void acquire(volatile int *cnt)
{
    for (;;)
    {
        while (*cnt >= NUM)
            ;
        __sync_fetch_and_add(cnt, 1);
        if (*cnt <= NUM)
            break;
        __sync_fetch_and_sub(cnt, 1);
    }
}

void release(int *cnt)
{
    __sync_fetch_and_sub(cnt, 1);
}

bool try_acquire(volatile int *cnt)
{
    for (;;)
    {
        if (*cnt >= NUM)
        {
            return false;
        }
        __sync_fetch_and_add(cnt, 1);
        if (*cnt <= NUM)
        {
            return true;
        }
        else
        {
            __sync_fetch_and_sub(cnt, 1);
            return true;
        }
    }
}

int main()
{
    int cnt = 0;
    for (;;)
    {
        acquire(&cnt);
        std::cout << "aa" << std::endl;
        release(&cnt);
    }
}
