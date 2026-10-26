#include <globaldefs.h>

#include "NitroSDK/Interrupts.h"

struct Struct_020d5fd0;

struct Struct_020d63f0_3 {
    unsigned short flagsA;
    unsigned char pad[0x1fe];
};

struct Struct_020d63f0 {
    unsigned short unknown_0_[4];
    unsigned short cur;
    unsigned char pad0[0xe];
    unsigned short state;
    unsigned char pad1[2];
    unsigned short status;
};

struct Struct_020d5fd0_2 {
    Struct_020d63f0_3 blocks[4];
    Struct_020d63f0 sub;
};

struct Struct_020d63f0_2 {
    unsigned char pad0[2];
    unsigned short unknown_2_;
    unsigned short event;
    unsigned char pad6[6];
    int param;
    unsigned char pad10[2];
    unsigned short bit;
    unsigned char unknown_14_[8];
    Struct_020d5fd0_2* obj;
};

extern "C" void func_020d6610(Struct_020d5fd0* obj, int bit, int extra);
extern "C" void func_020d66dc(Struct_020d5fd0_2* obj, int mode);

// USA: func_020d63f0
extern "C" ARM void func_020d63f0(Struct_020d63f0_2* msg) {
    Struct_020d5fd0_2* obj = msg->obj;
    if (obj == 0) return;
    if (msg->unknown_2_ == 0) {
        switch (msg->event) {
        case 0x15:
            func_020d6610((Struct_020d5fd0*)obj, msg->bit, msg->param);
            func_020d66dc(obj, 0);
            break;
        case 7:
            func_020d66dc(obj, 0);
            break;
        case 0x19:
            break;
        case 9:
        case 0x1a: {
            unsigned short bit = msg->bit;
            unsigned int mask = 1U << bit;
            int state = DisableIRQInterrupts();
            unsigned short cur = obj->sub.cur;
            mask = ~mask;
            obj->blocks[cur].flagsA &= mask;
            if (obj->sub.state == 1) {
                unsigned short next = (cur + 1) & 3;
                obj->blocks[next].flagsA &= mask;
            }
            SetIRQInterruptState(state);
            func_020d66dc(obj, 0);
            if (obj->sub.state == 1) {
                func_020d66dc(obj, 0);
            }
            break;
        }
        }
    } else {
        obj->sub.status = 5;
    }
}
