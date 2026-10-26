#include <globaldefs.h>

#if defined(jpn)
#define RG(usa, jpn) (jpn)
#else
#define RG(usa, jpn) (usa)
#endif

// USA: func_ov002_021556ec
extern "C" ARM void func_ov002_021556ec(void* obj, int a, int b) {
    unsigned char* p = (unsigned char*)obj + 0x2000;
    p[RG(0x485, 0x2b5)] = (unsigned char)a;
    p[RG(0x486, 0x2b6)] = (unsigned char)b;
}
