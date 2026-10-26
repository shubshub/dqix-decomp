#include <globaldefs.h>

// USA: func_ov001_021641e0
extern "C" ARM int func_ov001_021641e0(void* out, int type, int a, int b) {
    if (b == 0)
        return 0;
    *(int*)((char*)out + 0x0) = type;
    switch (type) {
    case 2:
    case 6:
        *(int*)((char*)out + 0x4) = a;
        *(int*)((char*)out + 0xc) = b;
        return 1;
    default:
        return 0;
    }
}
