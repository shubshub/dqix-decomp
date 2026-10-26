#include <globaldefs.h>

// USA: func_020a2770
extern "C" ARM void func_020a2770(void* obj, short value) {
    *(short*)((char*)obj + 0x21c) = value;
}
