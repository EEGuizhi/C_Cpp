#include "mbed.h"

// ex1
class MemoryManager {
    public:
        MemoryManager(size_t size) {
            m_ptr = new uint8_t[size];
        }

        ~MemoryManager() {
            if(m_ptr != NULL) {
                delete[] m_ptr;
            }
            printf("Returning Resources!\n");
        }

        uint8_t *get() {
            return m_ptr;
        }
    
    private:
        uint8_t *m_ptr;
};

int main() {
    MemoryManager manager(1024);

    uint8_t *buf = manager.get();
    if(buf != NULL) {
        memset(buf, 0, 1024);
    }

    for(int i=0; i<100; i++) {
        *(buf + i) = i;
        printf("buf[%d] : %d\n", i, *(buf+i));
    }
}


// ex2
#define BUFFER_SIZE 10
MemoryPool<int, BUFFER_SIZE> pool;

int main() {
    int *item;
    item = pool.alloc();
    if(item == NULL) {
        printf("MermoryPool is full");
        return 1;
    }
    *item = 2147483647;
    printf("Size of pointer item : %d, data : %d\n", sizeof(item), *item);

    printf("Release the remaining block back to the MemoryPool\n");
    pool.free(item);
    while(true) {
    }
}
