#include <globaldefs.h>
extern "C" void func_020be3f4(int, void*, unsigned int);

extern "C" void func_020d2c98(int);
extern "C" void func_020d20c4(int, int);

// USA: func_020be4a4
extern "C" ARM void func_020be4a4(int start, int length, int c, int d) {
    func_020be3f4((int)(start), (void*)(c), (unsigned int)(d));
    func_020d20c4(start, start + length);
    func_020d2c98(start);
}
