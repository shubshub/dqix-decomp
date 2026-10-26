#include <globaldefs.h>

extern "C" int func_02049468(unsigned char*);
extern "C" int func_0204948c(unsigned char*);

// USA: func_ov025_021e1f08
extern "C" ARM int func_ov025_021e1f08(unsigned char* obj, unsigned char* other) {
    int a = func_02049468(obj);
    if (a != 0xff) {
        return a;
    }
    int b = func_0204948c(obj);
    if (b != 0xff) {
        return b;
    }
    void* p = *(void**)(other+0x14);
    if (p != 0) {
        return *(short*)((unsigned char*)p+0xe);
    }
    return b;
}
