#include <globaldefs.h>

// USA: func_020103c8
extern "C" ARM void func_020103c8(void* obj, float value) {
    if (!(value < 0.0f)) {
        *(float*)((char*)obj + 0x3e0) = value;
    }
}
