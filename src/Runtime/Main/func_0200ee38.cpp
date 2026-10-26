#include <globaldefs.h>

typedef void (*Type_0200ee38)(void*);
extern "C" void func_0200efb8();

// USA: func_0200ee38
extern "C" ARM void func_0200ee38(unsigned char* arg0, unsigned char* end,
    unsigned int stride, Type_0200ee38 arg3)
{
    try {
        if (end > arg0) {
            do {
                end -= stride;
                arg3(end);
            } while (end > arg0);
        }
    } catch (...) {
        func_0200efb8();
    }
}
