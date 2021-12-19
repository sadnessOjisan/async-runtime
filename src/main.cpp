// test semaphore

// #include "my_semaphore.h"
// #include <atomic>
#include <iostream>
// int main(){
//   // Q: 明示的に型を指定すると怒られる
//   auto semaphore = new CountingSemaphore::CountingSemaphore(3);
//   semaphore->acquire();
//   semaphore->acquire();
//   semaphore->release();
// }


    int const NUM = 3;

void acquire(volatile int *cnt) {
        for(;;){
            while(*cnt >= NUM);
            __sync_fetch_and_add(cnt,1);
            if(*cnt <= NUM) break;
            __sync_fetch_and_sub(cnt, 1);
        }
    }

    void release(int *cnt){
        __sync_fetch_and_sub(cnt, 1);
    }

int main(){
    int cnt = 0;
    for(;;){
        acquire(&cnt);
        std::cout << "aa" << std::endl;
        release(&cnt);
    }
}
