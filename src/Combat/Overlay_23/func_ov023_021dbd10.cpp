#include <globaldefs.h>

extern "C" void* func_ov023_021db4e4(void* obj, int key);
extern "C" void func_ov023_021e23d0(void* obj, int val, int f0xc, unsigned char arg3, unsigned char arg4);
struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310*, int);

struct Struct_ov023_021dbd10 {
    char pad[0x16];
    unsigned char flags;
};

struct Struct_ov023_021dbd10_2 {
    char pad[8];
    unsigned int unknown_8_0_ : 4;
};

struct Struct_ov023_021ff9e0_2 {
#if !defined(jpn)
    unsigned char pad[0x14];
#endif
    struct Container020e0310* field14;
};
extern struct Struct_ov023_021ff9e0_2 data_ov023_021ff9e0;

// USA: func_ov023_021dbd10
extern "C" ARM void func_ov023_021dbd10(void* obj, struct Struct_ov023_021dbd10_2* p) {
    struct Struct_ov023_021dbd10* e;
    if (!obj || !p) return;

    int cond = (p->unknown_8_0_ <= 7) ? 1 : 0;
    if (cond) {
        e = (struct Struct_ov023_021dbd10*)func_ov023_021db4e4(obj, 0x9);
        if (e) e->flags &= ~1;
        e = (struct Struct_ov023_021dbd10*)func_ov023_021db4e4(obj, 0x1c);
        if (e) e->flags &= ~1;
        e = (struct Struct_ov023_021dbd10*)func_ov023_021db4e4(obj, 0x1b);
        if (e) e->flags &= ~1;
        e = (struct Struct_ov023_021dbd10*)func_ov023_021db4e4(obj, 0xb);
        if (e) e->flags &= ~1;
        e = (struct Struct_ov023_021dbd10*)func_ov023_021db4e4(obj, 0x2a);
        if (e) e->flags &= ~1;
        e = (struct Struct_ov023_021dbd10*)func_ov023_021db4e4(obj, 0x2c);
        if (e) e->flags &= ~1;
        return;
    }

    e = (struct Struct_ov023_021dbd10*)func_ov023_021db4e4(obj, 0x14);
    if (e) e->flags &= ~1;
    e = (struct Struct_ov023_021dbd10*)func_ov023_021db4e4(obj, 0x13);
    if (e) e->flags &= ~1;
    e = (struct Struct_ov023_021dbd10*)func_ov023_021db4e4(obj, 0x10);
    if (e) e->flags &= ~1;
    e = (struct Struct_ov023_021dbd10*)func_ov023_021db4e4(obj, 0x12);
    if (e) e->flags &= ~1;
    e = (struct Struct_ov023_021dbd10*)func_ov023_021db4e4(obj, 0xf);
    if (e) e->flags &= ~1;
    e = (struct Struct_ov023_021dbd10*)func_ov023_021db4e4(obj, 0xe);
    if (e) e->flags &= ~1;

    func_ov023_021e23d0(obj, 0x19, KeyTable_Get(data_ov023_021ff9e0.field14, 0x24), 0xa, 0xf);
    func_ov023_021e23d0(obj, 0x17, KeyTable_Get(data_ov023_021ff9e0.field14, 0x23), 0x8, 0xf);
    func_ov023_021e23d0(obj, 0x1a, KeyTable_Get(data_ov023_021ff9e0.field14, 0x25), 0xa, 0xf);
    func_ov023_021e23d0(obj, 0x18, KeyTable_Get(data_ov023_021ff9e0.field14, 0x23), 0x8, 0xf);
    func_ov023_021e23d0(obj, 0x15, KeyTable_Get(data_ov023_021ff9e0.field14, 0x26), 0xa, 0xf);
    func_ov023_021e23d0(obj, 0x16, KeyTable_Get(data_ov023_021ff9e0.field14, 0x27), 0xa, 0xf);
}
