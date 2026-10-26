#include <globaldefs.h>

extern "C" void func_ov023_021f6ed8(void* obj);

// USA: func_ov023_021fbb64
extern "C" ARM int func_ov023_021fbb64(void* obj, int unused, unsigned short arg2, unsigned short arg3,
                                         int arg4, int arg5, int arg6,
                                         int arg7, int arg8, int arg9, int arg10) {
    func_ov023_021f6ed8(obj);
    *(unsigned short*)((char*)obj + 0x4) = 0xf;
    *(unsigned int*)((char*)obj + 0x2c) = 0;
    *(unsigned short*)((char*)obj + 0x6) = arg2;
    *(unsigned short*)((char*)obj + 0x8) = arg3;
    *(unsigned short*)((char*)obj + 0xa) = 0;
    *(unsigned int*)((char*)obj + 0x10) = 0;
    *(unsigned int*)((char*)obj + 0x1c) = 2;
    *(unsigned int*)((char*)obj + 0x20) = -0x10000;
    *(unsigned int*)((char*)obj + 0x24) = -0x3000;
    *(unsigned int*)((char*)obj + 0x28) = 0;
    *(unsigned short*)((char*)obj + 0x30) = (unsigned short)arg4;
    *(unsigned short*)((char*)obj + 0x32) = (unsigned short)arg5;
    *(unsigned short*)((char*)obj + 0x34) = (unsigned short)arg6;
    unsigned char* var0 = (unsigned char*)obj + 0x3a;
    unsigned char var1 = (unsigned char)arg7;
    *var0 = (*var0 & ~0xf) | (var1 & 0xf);
    *(unsigned char*)((char*)obj + 0x3b) = (unsigned char)arg8;
    *(unsigned char*)((char*)obj + 0x3c) = (unsigned char)arg9;
    *(unsigned char*)((char*)obj + 0x3d) = 0;
    unsigned char b10 = (unsigned char)arg10;
    *var0 = (*var0 & ~0xf0) | ((b10 & 0xf) << 4);
    return 1;
}
