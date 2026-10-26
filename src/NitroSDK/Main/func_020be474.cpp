#include <globaldefs.h>

extern "C" void func_020be3f4(int, void*, unsigned int);

extern "C" void func_020d2c00(int);
extern "C" void func_020d20a4(int, int);

// USA: func_020be474
extern "C" ARM void func_020be474(int start, int length, int c, int d) {
    func_020be3f4((int)(start), (void*)(c), (unsigned int)(d));
    func_020d20a4(start, start + length);
    func_020d2c00(start);
}
