#include <globaldefs.h>

extern "C" void func_ov000_0216d370(void*, int, int, int);
extern "C" void func_0202ecec(unsigned char* obj);

// USA: func_ov000_0216d530
extern "C" ARM void func_ov000_0216d530(void* obj, int val) {
    if (val < 0) {
        func_ov000_0216d370(obj, 1, 1, 1);
    } else {
        func_0202ecec((unsigned char*)obj);
    }
    *(int*)((char*)obj + 0x224) = val;
}
