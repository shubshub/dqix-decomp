#include <globaldefs.h>

extern "C" void func_0200d894(void* p);

// USA: func_0200d91c
extern "C" ARM int func_0200d91c(void* unused, char* base, unsigned int* arg2) {
    unsigned int i = 0;
    unsigned int count = *arg2;
    if (i < count) {
        do {
            func_0200d894(base + i);
            i++;
        } while (i < count);
    }
    return 0;
}
