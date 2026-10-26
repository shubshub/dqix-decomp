#include <globaldefs.h>

#if defined(jpn)
#define func_020ca3b8 func_020cbe84
#endif

extern "C" void func_020ca3b8(void* src, void* dst, unsigned int len);

struct Struct_020c99c8 { unsigned short v : 3; };
struct Struct_020c99c8_2 { unsigned char v : 4; };

// Main, originally func_020c99c8 (USA 0x020c99c8, EUR 0x020c99d8, JPN 0x020cb494)
extern "C" ARM void OS_GetOwnerInfo(void* dst) {
    char* d = (char*)dst;
    unsigned char* s = (unsigned char*)0x27ffc80;
    d[0] = ((struct Struct_020c99c8*)(s + 0x64))->v;
    d[1] = ((struct Struct_020c99c8_2*)(s + 2))->v;
    d[2] = s[3];
    d[3] = s[4];
    *(unsigned short*)(d + 0x1a) = (unsigned char)s[0x1a];
    *(unsigned short*)(d + 0x52) = (unsigned char)s[0x50];
    func_020ca3b8(s + 6, d + 4, 0x14);
    func_020ca3b8(s + 0x1c, d + 0x1c, 0x34);
    *(unsigned short*)(d + 0x18) = 0;
    *(unsigned short*)(d + 0x50) = 0;
}
