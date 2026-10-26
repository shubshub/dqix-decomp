#if defined(jpn)
enum { Enum_ov017_021b88d0_348 = 0x150 };
#else
enum { Enum_ov017_021b88d0_348 = 0x15c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_0215fab0;

struct Struct_ov017_021b88d0 {
    GameObject base;
    char unknown_13c_[Enum_ov017_021b88d0_348 - 0x13c];
    int unknown_15c_;
    Vector3i unknown_160_;
    Vector3i unknown_16c_;
};

struct Struct_ov017_021b88d0_2 {
    unsigned char data[3];
    unsigned char count;
};

struct Struct_ov017_021b88d0_3 {
    unsigned char field_0x0;
    unsigned char done;
    char unknown_2_[0x20 - 0x02];
    unsigned char unknown_20_;
    char pad21[0x24 - 0x21];
    unsigned short key;
    char unknown_26_[0x4c - 0x26];
    int unknown_4c_;
    char unknown_50_[0x6b0 - 0x50];
    struct Struct_ov000_0215fab0* unknown_6b0_;
    unsigned short state;
    char unknown_6b6_[0x6c0 - 0x6b6];
    struct Struct_ov017_021b88d0_2 unknown_6c0_;
};

extern "C" void __clear(void* buf, int n);
extern "C" int GameState_GetProtagonistIndex(GameState* gs);
extern "C" GameObject* func_0200ff58(GameState* gs, int id);
extern "C" int func_020546a8(void* obj);
extern "C" void func_ov000_0215fab0(struct Struct_ov000_0215fab0* arg0, unsigned char val);
extern "C" void func_ov017_021b6f9c(struct Struct_ov017_021b88d0_3* self);

// USA: func_ov017_021b88d0
extern "C" ARM void func_ov017_021b88d0(struct Struct_ov017_021b88d0_3* self, int id, int key) {
    if (self->key != key) {
        return;
    }

    GameState* gs = GameState::GetInstance();
    if (id == GameState_GetProtagonistIndex(gs)) {
        if (self->state == 1) {
            self->unknown_4c_ = 1;
            self->state = 2;
        }
        return;
    }

    unsigned short state = self->state;
    if (state != 3 && state != 5) {
        int ids[4];
        __clear(ids, sizeof(ids));
        ids[0] = id;
        int count = 1;
        for (int i = 0; i < 4; i++) {
            GameObject* c = func_0200ff58(gs, i);
            if (c != 0 && id == func_020546a8(c)) {
                ids[count++] = i;
            }
        }

        for (int j = 0; j < count; j++) {
            if (self->unknown_6b0_ != 0) {
                func_ov000_0215fab0(self->unknown_6b0_, ids[j]);
            } else {
                self->unknown_6c0_.data[self->unknown_6c0_.count++] = ids[j];
            }
            struct Struct_ov017_021b88d0* c =
                (struct Struct_ov017_021b88d0*)func_0200ff1c(gs, ids[j]);
            if (c != 0) {
                c->unknown_160_ = c->base.obj3D_.position_;
                c->unknown_16c_ = c->base.obj3D_.rotation_;
                c->unknown_15c_ = c->base.obj3D_.GetField06();
            }
        }
    } else if (self->unknown_20_ == 0) {
        func_ov017_021b6f9c(self);
        self->done = 1;
    }
}
