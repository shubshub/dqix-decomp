#include <globaldefs.h>

struct Struct_02021410;

// USA: func_02021410
extern "C" ARM void func_02021410(Struct_02021410* state, int active, int mode) {
    unsigned char* storage = (unsigned char*)state;
#if defined(jpn)
    storage[0x918] = active != 0;
    storage[0x91c] = mode;
#else
    storage[0x9c4] = active != 0;
    storage[0x9c8] = mode;
#endif
}
