#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" int func_ov001_021539d8(void* self);
extern "C" void func_ov001_02154c64(void* self);
extern "C" int func_ov001_02153948(unsigned short arg);

struct Struct_ov001_02155bb8 {
    char pad0[0x2c];
    int unknown_2c_;
    char pad1[0x31 - 0x30];
    unsigned char unknown_31_;
    char pad2[0x34 - 0x32];
    struct Struct_ov001_02155bb8* next;
};

struct Struct_ov001_02155bb8_2 {
    char pad0[0x24];
    int unknown_24_;
    struct Struct_ov001_02155bb8_2* next;
    unsigned char unknown_2c_;
};

struct Struct_ov001_02155bb8_3 {
    char pad0[0xa];
    unsigned short unknown_a_;
    char pad1[0x4a - 0xc];
    unsigned short unknown_4a_;
#if defined(jpn)
    char pad2[0xcc - 0x4c];
#else
    char pad2[0xd0 - 0x4c];
#endif
    struct Struct_ov001_02155bb8* unknown_d0_;
    struct Struct_ov001_02155bb8_2* unknown_d4_;
    char pad3[0xf4 - 0xd8];
    int unknown_f4_;
    char pad4[0x100 - 0xf8];
    unsigned char unknown_100_;
};

// USA: func_ov001_02155bb8
extern "C" ARM int func_ov001_02155bb8(struct Struct_ov001_02155bb8_3* self) {
    int val = (int)BackgroundLoader::GetInstance();

    struct Struct_ov001_02155bb8* n = self->unknown_d0_;
    while (n) {
        if (n->unknown_2c_ > -1 && n->unknown_31_ == 0) {
            if (((BackgroundLoader*)((void*)val))->GetTaskStatus((int)(n->unknown_2c_)) == 0) {
                return self->unknown_a_;
            }
        }
        n = n->next;
    }

    struct Struct_ov001_02155bb8_2* m = self->unknown_d4_;
    while (m) {
        if (m->unknown_24_ > -1 && m->unknown_2c_ == 0) {
            if (((BackgroundLoader*)((void*)val))->GetTaskStatus((int)(m->unknown_24_)) == 0) {
                return self->unknown_a_;
            }
        }
        m = m->next;
    }

    if (self->unknown_f4_ > -1) {
        if (((BackgroundLoader*)((void*)val))->GetTaskStatus((int)(self->unknown_f4_)) == 0) {
            return self->unknown_a_;
        }
    }

    func_ov001_021539d8(self);
    if (self->unknown_100_ == 0) {
        func_ov001_02154c64(self);
        return self->unknown_a_;
    }
    func_ov001_02153948(self->unknown_4a_);
    return 4;
}
