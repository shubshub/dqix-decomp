#include <globaldefs.h>

#if defined(jpn)
#define RG(usa, jpn) (jpn)
#else
#define RG(usa, jpn) (usa)
#endif

// USA: func_ov002_02155024
extern "C" ARM void func_ov002_02155024(unsigned char* obj) {
    if (obj[0x2000 + RG(0x48f, 0x2bf)] == 0 && obj[0x2000 + RG(0x48e, 0x2be)] == 0) {
        obj[0x2000 + RG(0x48e, 0x2be)] = 1;
        obj = obj + 0x1000;
        *(int*)(obj + RG(0xbb8, 0xa80)) = RG(0x2a, 0x2d);
        *(int*)(obj + RG(0xbc0, 0xa88)) = 0;
    }
}
