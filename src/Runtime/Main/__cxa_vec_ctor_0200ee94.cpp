#include <globaldefs.h>

typedef void (*ArrayObjectCallback0200ee94)(void*);
extern "C" void func_0200ee38(void*, void*, unsigned int, ArrayObjectCallback0200ee94);

// Main, originally func_0200ee94 (USA/EUR 0x0200ee94, JPN 0x0200ed58)
extern "C" ARM void __cxa_vec_ctor(void* array, unsigned int count, unsigned int stride, ArrayObjectCallback0200ee94 constructor, ArrayObjectCallback0200ee94 destructor) {
    if (constructor) {
        if (destructor) {
            unsigned char* current = static_cast<unsigned char*>(array);
            try {
                if (count) {
                    do {
                        constructor(current);
                        current += stride;
                    } while (--count);
                }
            } catch (...) {
                func_0200ee38(array, current, stride, destructor);
                throw;
            }
        } else {
            unsigned char* current = static_cast<unsigned char*>(array);
            if (count) {
                do {
                    constructor(current);
                    current += stride;
                } while (--count);
            }
        }
    }
}
