#include <globaldefs.h>

// USA: func_ov023_021e1518
extern "C" ARM void func_ov023_021e1518(void* obj) {
    char* arr = *(char**)((char*)obj + 0x4);
    short count = *(short*)((char*)obj + 0x8);
    for (short i = 0; i < count; i++) {
        char* e = arr + (i << 4);
        *(unsigned int*)e = 0;
        *(unsigned char*)(e + 0xe) &= ~1;
    }
    *(int*)obj = 0;
}
