#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov003_0215da0c_152 = 0xb0 };
enum { Enum_ov003_0215da0c_952 = 0x3d0 };
enum { Enum_ov003_0215da0c_1008 = 0x408 };
enum { Enum_ov003_0215da0c_957 = 0x3d5 };
enum { Enum_ov003_0215da0c_2456 = 0x868 };
#else
enum { Enum_ov003_0215da0c_152 = 0x98 };
enum { Enum_ov003_0215da0c_952 = 0x3b8 };
enum { Enum_ov003_0215da0c_1008 = 0x3f0 };
enum { Enum_ov003_0215da0c_957 = 0x3bd };
enum { Enum_ov003_0215da0c_2456 = 0x998 };
#endif

struct Struct_0201099c_3;
struct Struct_0205d6a0;

char* MessageSystem_GetInstance();
void MessageSystem_Reset(char* ctrl);
int KeyTable_Get(struct Container020e0310* c, int key);
void Window_ClosePane(struct Entry_0205d6a0* list, int flag);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" void func_ov003_0215cab0(void* self, int msg);

struct Struct_ov003_0215da0c {
    char unknown_0_[0x64];
    char unknown_64_[Enum_ov003_0215da0c_152 - 0x64];
    char unknown_98_[Enum_ov003_0215da0c_952 - Enum_ov003_0215da0c_152];
    unsigned char unknown_3b8_;
    char unknown_3b9_[3];
    unsigned char unknown_3bc_;
    char unknown_3bd_[Enum_ov003_0215da0c_1008 - Enum_ov003_0215da0c_957];
    unsigned char unknown_3f0_;
    unsigned char unknown_3f1_;
    unsigned char unknown_3f2_;
    unsigned char unknown_3f3_;
};

// USA: func_ov003_0215da0c
extern "C" ARM void func_ov003_0215da0c(struct Struct_ov003_0215da0c* arg0) {
    char* var0;
    GameState* var1;
    void* var2;
    unsigned char var3;
    int var4;
    int var5;

    gs = GameState::GetInstance();
    global = MessageSystem_GetInstance();
    ctx = LinkSession_GetInstance();

    zero = 0;
    if (LinkSession_IsHostOrSolo(ctx) && gs->GetLeader()->obj3D_.actorIndex_ == 0) {
        zero = 1;
    }
    nonZero = 0;
    if (LinkSession_IsHostOrSolo(ctx) && gs->GetLeader()->obj3D_.actorIndex_ != 0) {
        nonZero = 1;
    }

    step = self->step;
    if (step == 0) {
        if (self->skipMessage) {
            MessageSystem_Reset(global);
            self->step++;
            return;
        }
        int var6 = 0x442;
        if (arg0->unknown_3f0_) {
            if (var4) {
                arg0->unknown_3f1_ = 1;
                var6 = 0x6e;
            } else if (var5) {
                var6 = 0x74;
            } else {
                var6 = 0x73;
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
