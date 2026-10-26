#include <globaldefs.h>

extern "C" void func_0200efb8();

// USA: func_0200ef44
extern "C" ARM void func_0200ef44(unsigned char* array, unsigned int count,
    unsigned int stride, void (*arg3)(void*))
{
    if (arg3) {
        unsigned char* end = array + count * stride;
        try {
            if (count) {
                do {
                    end -= stride;
                    arg3(end);
                } while (--count);
            }
        } catch (...) {
            func_0200efb8();
        }
    }
}
