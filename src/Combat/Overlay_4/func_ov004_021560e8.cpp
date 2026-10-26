#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
extern "C" unsigned int func_ov023_021f6f10(void* self);
#define NODE_KIND_CALL func_ov023_021f6f10
#else
extern "C" int func_ov024_021f6f10(void* self);
#define NODE_KIND_CALL func_ov024_021f6f10
#endif
extern "C" int func_ov023_021f9bc8(void*);
extern "C" void func_ov011_021848a0(void*, int);

struct Struct_020a15bc_2 { unsigned int field : 9; unsigned int pad : 23; unsigned int w1; unsigned int w2; };
struct Struct_020a15bc { struct Struct_020a15bc_2* base; unsigned short pad4; unsigned short count; };
extern "C" struct Struct_020a15bc_2* func_020a15bc(struct Struct_020a15bc* arr, int id);

struct Struct_ov004_021707c8 {
#if defined(jpn)
 char pad[4];
#else
 char pad[8];
#endif
 short* keys; struct Struct_020a15bc* arr; };
extern struct Struct_ov004_021707c8 data_ov004_021707c8;

// USA: func_ov004_021560e8
extern "C" ARM int func_ov004_021560e8(void* a) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(a), 3);
    if (!node) return 0;
    if (NODE_KIND_CALL(node) != 7) return 0;

    short var1 = *(short*)((char*)node + 0x5c);
    #if defined(jpn)
    short offset = (short)(var1 * 16);
#else
    short offset = (short)(var1 * 12);
#endif
    int addr = func_ov023_021f9bc8(node) + offset;

    short key = data_ov004_021707c8.keys[addr];
    struct Struct_020a15bc_2* elem = func_020a15bc(data_ov004_021707c8.arr, key);
    if (!elem) return 0;

    unsigned int var6 = *(unsigned int*)elem >> 30;
    switch (var6) {
        case 0: func_ov011_021848a0(a, 0x6e); break;
        case 1: func_ov011_021848a0(a, 0x6f); break;
        case 2: func_ov011_021848a0(a, 0x70); break;
    }
    return 0;
}
