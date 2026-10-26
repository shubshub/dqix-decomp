#include <globaldefs.h>

extern "C" void func_ov023_021f6ed8(void* obj);
extern "C" void* func_ov011_021849c8(void* x);
extern "C" void* func_ov023_021f6880(void** list, int value);
extern "C" void* func_ov023_021fad18(void* obj);
extern "C" int func_ov023_021f6c90(void* list, int arg1, int flag);
extern "C" ARM void func_ov023_021f6bec(void* obj, int arg1, unsigned int arg2, unsigned int count);

// USA: func_ov023_021fb2b0
extern "C" ARM int func_ov023_021fb2b0(void* obj, void* arg1, unsigned short arg2, unsigned short arg3, unsigned int arg4, unsigned int arg5) {
    func_ov023_021f6ed8(obj);
    *(unsigned short*)((char*)obj + 0x4) = 0xb;
    *(unsigned short*)((char*)obj + 0x6) = arg2;
    *(unsigned short*)((char*)obj + 0x8) = arg3;
    *(unsigned short*)((char*)obj + 0xa) = 0;
    *(unsigned int*)((char*)obj + 0x10) = 0;
    *(unsigned int*)((char*)obj + 0x1c) = 2;
    *(unsigned short*)((char*)obj + 0x20) = arg4;
    void* list = func_ov011_021849c8(arg1);
    void* node = func_ov023_021f6880((void**)list, *(unsigned short*)((char*)obj + 0x20));
    if (node == 0) return 0;
    void* p = func_ov023_021fad18(node);
    unsigned char b = *(unsigned char*)((char*)p + 0x50);
    *(unsigned short*)((char*)obj + 0x22) = arg5;
    int r = func_ov023_021f6c90(list, b, 1);
    *(unsigned short*)((char*)obj + 0x24) = r;
    func_ov023_021f6bec(list, b, *(unsigned short*)((char*)obj + 0x24), 1);
    *(unsigned short*)((char*)obj + 0x26) = 0;
    *(unsigned short*)((char*)obj + 0x28) = 0;
    *(unsigned short*)((char*)obj + 0x2a) = 0;
    return 1;
}
