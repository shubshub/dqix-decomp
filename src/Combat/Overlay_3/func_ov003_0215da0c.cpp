#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue98_B0 = 0xb0 };
enum { Enum_ov003_0215da0c_952 = 0x3d0 };
enum { Enum_ov003_0215da0c_1008 = 0x408 };
enum { Enum_ov003_0215da0c_957 = 0x3d5 };
enum { kRegionValue998_868 = 0x868 };
#else
enum { kRegionValue98_B0 = 0x98 };
enum { Enum_ov003_0215da0c_952 = 0x3b8 };
enum { Enum_ov003_0215da0c_1008 = 0x3f0 };
enum { Enum_ov003_0215da0c_957 = 0x3bd };
enum { kRegionValue998_868 = 0x998 };
#endif

struct Container020e0310;
struct Entry_0205d6a0;

extern "C" char* MessageSystem_GetInstance();
extern "C" void MessageSystem_Reset(char* ctrl);
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" void Window_ClosePane(struct Entry_0205d6a0* list, int flag);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" void func_ov003_0215cab0(void* self, int msg);

struct Struct_ov003_0215da0c {
    char unk_0[0x64];
    char messages[kRegionValue98_B0 - 0x64];
    char entries[Enum_ov003_0215da0c_952 - kRegionValue98_B0];
    unsigned char step;
    char unknown_3b9_[3];
    unsigned char mode;
    char unknown_3bd_[Enum_ov003_0215da0c_1008 - Enum_ov003_0215da0c_957];
    unsigned char unknown_3f0_;
    unsigned char unknown_3f1_;
    unsigned char unknown_3f2_;
    unsigned char unknown_3f3_;
};

// USA: func_ov003_0215da0c
extern "C" ARM void func_ov003_0215da0c(struct Struct_ov003_0215da0c* self) {
    char* global;
    GameState* gs;
    void* ctx;
    unsigned char step;
    int zero;
    int var5;

    gs = GameState::GetInstance();
    global = MessageSystem_GetInstance();
    ctx = LinkSession_GetInstance();

    zero = 0;
    if (LinkSession_IsHostOrSolo(ctx) && gs->GetLeader()->obj3D_.actorIndex_ == 0) {
        zero = 1;
    }
    var5 = 0;
    if (LinkSession_IsHostOrSolo(ctx) && gs->GetLeader()->obj3D_.actorIndex_ != 0) {
        var5 = 1;
    }

    step = self->step;
    if (step == 0) {
        if (self->unknown_3f3_) {
            MessageSystem_Reset(global);
            self->step++;
            return;
        }
        int key = 0x442;
        if (self->unknown_3f0_) {
            if (zero) {
                self->unknown_3f1_ = 1;
                key = 0x6e;
            } else if (var5) {
                key = 0x74;
            } else {
                key = 0x73;
            }
        }
        func_ov003_0215cab0(self, KeyTable_Get((struct Container020e0310*)self->messages, key));
        self->step++;
    }
    if (step == 1 && *(int*)(global + kRegionValue998_868) == 0) {
        Window_ClosePane((struct Entry_0205d6a0*)self->entries, 1);
        self->mode = 5;
        self->step = 0;
    }
}
