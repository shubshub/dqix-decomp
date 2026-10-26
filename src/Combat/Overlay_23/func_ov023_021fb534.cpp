#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov023_021f6ed8(void* obj);
extern "C" void* func_ov011_021849c8(void* x);
extern "C" int func_ov023_021f6c90(void* list, int arg1, int flag);
extern "C" ARM void func_ov023_021f6bec(void* obj, int arg1, unsigned int arg2, unsigned int count);
struct Struct_02075cdc;
extern "C" void func_02075cdc(struct Struct_02075cdc* s);
extern "C" void* OamManager_GetInstance(void);
extern "C" void* OamManager_GetMainOamBuffer(void);
extern "C" void* OamManager_GetSubOamBuffer(void);
extern "C" int func_ov023_021f6e5c(void* obj, int idx);
extern "C" void func_ov023_021f6e10(void* obj, int idx, unsigned int bit);
struct Struct_ov023_021fb534;
extern "C" void func_ov023_021fb8dc(struct Struct_ov023_021fb534* obj, void* keyObj);

// USA: func_ov023_021fb534
extern "C" ARM int func_ov023_021fb534(void* obj, void* ctx, unsigned short arg2, unsigned short arg3, unsigned int arg4, int arg5) {
    func_ov023_021f6ed8(obj);
    *(unsigned short*)((char*)obj + 0x4) = 0xc;
    *(unsigned short*)((char*)obj + 0x6) = arg2;
    *(unsigned short*)((char*)obj + 0x8) = arg3;
    *(unsigned short*)((char*)obj + 0xa) = 0;
    *(unsigned int*)((char*)obj + 0x10) = arg4;
    void* list = func_ov011_021849c8(ctx);
    int var1 = func_ov023_021f6c90(list, arg5, 1);
    func_ov023_021f6bec(list, arg5, var1, 1);
    func_02075cdc((struct Struct_02075cdc*)((char*)obj + 0x20));
    void* base;
    if (arg5 == 0) {
        OamManager_GetInstance();
        base = OamManager_GetMainOamBuffer();
    } else {
        OamManager_GetInstance();
        base = OamManager_GetSubOamBuffer();
    }
    *(void**)((char*)obj + 0x34) = (char*)base + var1 * 8;
    *(unsigned int*)((char*)obj + 0x58) = 0;
    int bit = func_ov023_021f6e5c(list, arg5);
    func_ov023_021f6e10(list, arg5, bit);
    *(unsigned int*)((char*)obj + 0x5c) = bit & 0xf;
    *(unsigned int*)((char*)obj + 0x60) = 0;
    *(unsigned char*)((char*)obj + 0x7e) = (unsigned char)arg5;
    *(unsigned short*)((char*)obj + 0xa4) = 0;
    memset((char*)obj + 0x94, 0, 0x10);
    *(unsigned int*)((char*)obj + 0xa8) = 0;
    *(unsigned int*)((char*)obj + 0xac) = 0;
#if defined(jpn)
    *(unsigned char*)((char*)obj + 0xb0) = 0;
#else
    *(unsigned char*)((char*)obj + 0xb0) = 0;
    *(unsigned char*)((char*)obj + 0xb1) = 0;
#endif
    func_ov023_021fb8dc((struct Struct_ov023_021fb534*)obj, ctx);
    return 1;
}
