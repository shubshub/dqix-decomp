#include <globaldefs.h>

// USA: func_ov023_021f7188
extern "C" ARM void func_ov023_021f7188(void* obj, unsigned short value) {
    *(unsigned short*)((char*)obj + 0xa8) = value;
}
