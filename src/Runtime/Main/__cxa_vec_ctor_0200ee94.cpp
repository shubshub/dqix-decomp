#include <globaldefs.h>

typedef void (*Type_0200ee94)(void*);
extern "C" void func_0200ee38(void*, void*, unsigned int, Type_0200ee94);

// Main, originally func_0200ee94 (USA/EUR 0x0200ee94, JPN 0x0200ed58)
extern "C" ARM void __cxa_vec_ctor(void* array, unsigned int count, unsigned int stride, ArrayObjectCallback0200ee94 constructor, ArrayObjectCallback0200ee94 destructor) {
    if (constructor) {
        if (destructor) {
            unsigned char* current = static_cast<unsigned char*>(array);
            try {
                if (arg1) {
                    do {
                        arg3(var0);
                        var0 += arg2;
                    } while (--arg1);
                }
            } catch (...) {
                func_0200ee38(arg0, var0, arg2, arg4);
                throw;
            }
        } else {
            unsigned char* var1 = static_cast<unsigned char*>(arg0);
            if (arg1) {
                do {
                    arg3(var1);
                    var1 += arg2;
                } while (--arg1);
            }
        }
    }
}
