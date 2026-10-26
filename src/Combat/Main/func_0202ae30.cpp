#include <globaldefs.h>

extern int data_020fefec;

// USA: func_0202ae30
extern "C" ARM void func_0202ae30(void* obj) {
    if (*(unsigned short*)((char*)obj + 0x4) == 0x10) {
        *(int*)((char*)&data_020fefec + 0x8) = 2;
    }
}
