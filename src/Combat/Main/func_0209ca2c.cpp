#include <globaldefs.h>

extern "C" int func_020bc0a4(int);

// USA: func_0209ca2c
extern "C" ARM int func_0209ca2c(void* obj) {
    short handle = *(short*)((char*)obj + 0xce);
    if (handle < 0) return 0;
    if (*(unsigned char*)((char*)obj + 0xc9) != 0) return 1;
    return func_020bc0a4(handle) > 0;
}
