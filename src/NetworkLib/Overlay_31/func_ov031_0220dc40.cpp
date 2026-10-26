#include <globaldefs.h>

extern "C" int func_020d4efc(int arg);
extern "C" int func_020d3fdc(void);
extern "C" int func_020d4ebc(int value);
extern "C" int func_020d6a84(int arg, int mode);
extern "C" int func_020d6950(int a0, int a1, int a2, int a3);
extern "C" int func_020d54d0(void* fn, void* a, void* b, int c, unsigned short flag);
extern "C" void func_ov031_0220da1c(int);
extern "C" void func_ov031_0220d984(int, void*, int, int);
extern "C" void func_ov031_0220e258(void*);

struct Struct_ov031_0220dc40 {
    unsigned short command;
    unsigned short type;
};

struct Struct_ov031_0220dc40_2 {
    char unknown_0_[0x2140];
    char unknown_2140_[0xc0];
    char unknown_2200_[0x50];
    unsigned char unknown_2250_;
    unsigned char unknown_2251_;
    char unknown_2252_[0x12];
    unsigned int flags;
    char unknown_2268_[0x18];
    short state;
};

extern Struct_ov031_0220dc40_2* data_ov031_0224e53c;

// USA: func_ov031_0220dc40
extern "C" ARM void func_ov031_0220dc40(Struct_ov031_0220dc40* event) {
    int result = 0x14;
    switch (event->type) {
    case 0:
        switch (event->command) {
        case 3:
            result = func_020d4efc((int)func_ov031_0220dc40);
            break;
        case 4:
            switch (func_020d3fdc()) {
            case 0:
                func_ov031_0220da1c(1);
                func_ov031_0220d984(0, 0, 0, 0x663);
                return;
            case 4:
            default:
                func_ov031_0220da1c(0xb);
                func_ov031_0220d984(7, 0, 0, 0x66c);
                return;
            }
        case 5:
            func_ov031_0220da1c(3);
            func_ov031_0220d984(0, 0, 0, 0x673);
            return;
        case 6:
            result = func_020d4ebc((int)func_ov031_0220dc40);
            break;
        case 0x1d:
            result = func_020d6a84((int)func_ov031_0220dc40, 0);
            break;
        case 0x19: {
            Struct_ov031_0220dc40_2* work = data_ov031_0224e53c;
            result = func_020d6950((int)func_ov031_0220dc40, work->unknown_2250_, work->unknown_2251_, (int)work->unknown_2200_);
            break;
        }
        case 0x27: {
            Struct_ov031_0220dc40_2* work = data_ov031_0224e53c;
            unsigned int flags = work->flags;
            unsigned short var4 = (flags & 0xc0000) == 0xc0000 ? 1 : 0;
            result = func_020d54d0((void*)func_ov031_0220e258, work->unknown_2140_, 0,
                                   (flags & 0x30000) == 0x30000 ? 0 : 1, var4);
            break;
        }
        }
        switch (result) {
        case 2:
            return;
        case 8:
            func_ov031_0220da1c(0xc);
            func_ov031_0220d984(1, data_ov031_0224e53c->state == 5 ? data_ov031_0224e53c->unknown_2140_ : 0, 0, 0x6af);
            return;
        case 3:
        default:
            func_ov031_0220da1c(0xb);
            func_ov031_0220d984(7, data_ov031_0224e53c->state == 5 ? data_ov031_0224e53c->unknown_2140_ : 0, 0, 0x6b8);
            return;
        }
    case 1:
        func_ov031_0220da1c(0xc);
        func_ov031_0220d984(1, data_ov031_0224e53c->state == 5 ? data_ov031_0224e53c->unknown_2140_ : 0, 0, 0x6de);
        break;
    case 2:
    case 3:
    case 4:
    default:
        func_ov031_0220da1c(0xb);
        func_ov031_0220d984(7, data_ov031_0224e53c->state == 5 ? data_ov031_0224e53c->unknown_2140_ : 0, 0, 0x6e8);
        break;
    }
}
