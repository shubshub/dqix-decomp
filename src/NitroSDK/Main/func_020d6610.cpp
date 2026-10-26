#include <globaldefs.h>

#if defined(jpn)
#define func_020ca390 func_020cbe5c
#endif

#if defined(jpn)
#define func_020ca3b8 func_020cbe84
#endif

extern "C" int func_020d6884(void*, int, int, int);
extern "C" int func_020ca3b8(int, int, int);
extern "C" void func_020ca390(int, void*, unsigned int);
unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int mask);

struct Struct_020d6610 {
    unsigned short flagsA;
    unsigned short unknown_2_;
    unsigned char pad[0x1fc];
};

struct Struct_020d6610_2 {
    unsigned char pad0[8];
    unsigned short idx;
    unsigned char pad1[4];
    unsigned short flags;
    unsigned short field10;
    unsigned char pad2[6];
    unsigned short state;
};

struct Struct_020d5fd0 {
    struct Struct_020d6610 blocks[4];
    struct Struct_020d6610_2 sub;
};

// USA: func_020d6610
extern "C" ARM void func_020d6610(struct Struct_020d5fd0* obj, int bit, int extra) {
    unsigned short mask = (unsigned short)(1 << bit);
    unsigned short flags = obj->sub.flags;
    if (!(flags & mask)) return;
    int idx = obj->sub.idx;
    if (!(obj->blocks[idx].flagsA & mask)) {
        if (obj->sub.state != 1) return;
        idx = (idx + 1) & 3;
        if (!(obj->blocks[idx].flagsA & mask)) return;
    }
    int val = func_020d6884(obj, flags, (int)&obj->blocks[idx] + 4, bit);
    if (extra != 0) {
        func_020ca3b8(extra, val, obj->sub.field10);
    } else {
        func_020ca390(0, (void*)val, obj->sub.field10);
    }
    unsigned int state = DisableIRQInterrupts();
    obj->blocks[idx].flagsA &= ~mask;
    obj->blocks[idx].unknown_2_ |= mask;
    SetIRQInterruptState(state);
}
