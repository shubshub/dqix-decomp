#include <globaldefs.h>

#if defined(jpn)
#define func_020ca390 func_020cbe5c
#endif

unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int mask);
extern "C" unsigned short func_020d46fc(void);
extern "C" void func_020ca390(int, void*, unsigned int);
extern "C" int func_020d59bc(void* cb, void* obj, void* arg2, unsigned short f14, unsigned short arg4, unsigned short arg5, int one);
extern "C" int func_020d6318(void*);

struct Struct_020d66dc {
    unsigned short unknown_0_[4];
    unsigned short cur;
    unsigned short counter;
    unsigned char pad0[2];
    unsigned short flags;
    unsigned char pad1[4];
    unsigned short field14;
    unsigned short unknown_16_;
    unsigned short state;
    unsigned char pad2[2];
    unsigned short status;
};

struct Struct_020d66dc_2 {
    unsigned short flagsA;
    unsigned char pad[0x1fe];
};

struct Struct_020d5fd0_2 {
    Struct_020d66dc_2 blocks[4];
    Struct_020d66dc sub;
};

// USA: func_020d66dc
extern "C" ARM void func_020d66dc(Struct_020d5fd0_2* obj, int mode) {
    unsigned int state = DisableIRQInterrupts();
    if (obj->blocks[obj->sub.cur].flagsA == 0) {
        unsigned short var1 = func_020d46fc();
        unsigned short var2 = obj->sub.cur;
        unsigned short var3 = (var2 + 1) & 3;
        int var4 = (obj->sub.state == 1) ? ((var3 + 1) & 3) : var3;

        func_020ca390(0, &obj->blocks[var4], 0x200);

        obj->blocks[var4].flagsA = obj->sub.flags & (var1 | 1);
        obj->sub.cur = var3;
        unsigned short var5 = obj->sub.flags;
        obj->blocks[var2].flagsA = var5;
        if (mode == 1) {
            obj->blocks[var2].flagsA &= ~1;
        }

        SetIRQInterruptState(state);

        unsigned short var6 = (unsigned short)(obj->sub.flags & var1);
        unsigned short var7 = obj->sub.unknown_16_;
        unsigned short f14 = obj->sub.field14;
        int result = func_020d59bc((void*)func_020d6318, obj, &obj->blocks[var2], f14, var6, var7, 1);

        if (result == 7) {
            obj->sub.unknown_0_[var2] = 0xffff;
            obj->sub.counter = (obj->sub.counter + 1) & 3;
        } else {
            if (result == 0 || result == 2) {
                return;
            }
            obj->sub.status = 5;
        }
    } else {
        SetIRQInterruptState(state);
    }
}
