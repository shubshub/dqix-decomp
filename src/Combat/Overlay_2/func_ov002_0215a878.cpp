#include <globaldefs.h>
#include "Resource/GameResources.h"

#if defined(jpn)
#define RG(usa, jpn) (jpn)
#else
#define RG(usa, jpn) (usa)
#endif

// USA: func_ov002_0215a878
extern "C" ARM void func_ov002_0215a878(char* p) {
    short v1 = *(short*)(p + RG(0x1b00 + 0xe0, 0x1a00 + 0xa8));
    *(unsigned int*)(p + 0x2000 + RG(0x540, 0x368)) = v1;
    short v2 = *(short*)(p + RG(0x1b00 + 0xfe, 0x1a00 + 0xc6));
    *(unsigned int*)(p + 0x2000 + RG(0x544, 0x36c)) = v2;
    *(unsigned char*)(p + 0x2000 + RG(0x53c, 0x364)) = 1;
    char* other = (char*)GetGameResources();
    char* obj2 = *(char**)(other + 0x3000 + RG(0x71c, 0x50c));
    *(unsigned char*)(obj2 + 0x24) = *(unsigned char*)(p + 0x2000 + RG(0x53c, 0x364));
    *(unsigned int*)(obj2 + 0x28) = *(unsigned int*)(p + 0x2000 + RG(0x540, 0x368));
    *(unsigned int*)(obj2 + 0x2c) = *(unsigned int*)(p + 0x2000 + RG(0x544, 0x36c));
}
