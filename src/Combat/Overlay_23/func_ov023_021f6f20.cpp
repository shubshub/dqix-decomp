#include <globaldefs.h>

extern "C" void func_ov023_021f6ed8(void* obj);
extern "C" void SprSprite_Init(void* ptr);
extern "C" void func_ov023_021f71a8(void* obj, int p1);

// USA: func_ov023_021f6f20
extern "C" ARM int func_ov023_021f6f20(void* obj, int p1, int p3, int p4, int arg4, unsigned int arg5) {
    func_ov023_021f6ed8(obj);
    *(unsigned short*)((char*)obj + 0x4) = 0;
    *(unsigned short*)((char*)obj + 0x6) = p3;
    *(unsigned short*)((char*)obj + 0x8) = p4;
    *(unsigned short*)((char*)obj + 0xa) = arg4;
    *(unsigned int*)((char*)obj + 0x10) = arg5;
    SprSprite_Init((char*)obj + 0x20);
    func_ov023_021f71a8(obj, p1);
    *(unsigned short*)((char*)obj + 0xa8) = 0;
    *(unsigned short*)((char*)obj + 0xaa) = 0;
    return 1;
}
