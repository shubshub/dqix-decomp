#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021c2b6c_434 = 0x1a6 };
#else
enum { Enum_ov017_021c2b6c_434 = 0x1b2 };
#endif

#include "Memory/SafeAllocator.h"
#include "Filesystem/FileIO.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_02114e20;
struct Struct_02015ef4_5;

extern "C" void* func_02057924(void);
extern "C" void func_020a0cc4(unsigned int);
extern "C" int func_02057e6c(void* list, int p1, SafeAllocator* alloc, int p2, int p3, State0207dfc8* p4);
unsigned int AllocatorUnion_GetMaxPossibleAllocation(Struct02012dd0*);
void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
void VramState_CopyCurrentTo(State0207dfc8*, State0207dfc8*);
void FindNodeAndProcess02057fb4(void*, int, void*);
void EnqueueEventTag30_021d24a8(int);

extern AllocatorUnion g_mainAllocator;
extern char data_ov017_021d7f6c[];

struct Struct_ov017_021c2b6c_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[0xf];
    unsigned char unknown_10_;
    unsigned char unknown_11_0_ : 1;
    unsigned char unknown_11_1_ : 1;
    unsigned char unknown_11_2_ : 1;
    unsigned char unknown_11_3_ : 1;
    unsigned char unknown_11_4_ : 1;
    unsigned char unknown_11_5_ : 1;
    unsigned char unknown_11_6_ : 1;
    unsigned char unknown_11_7_ : 1;
    unsigned short unknown_12_;
    short unknown_14_, unknown_16_, unknown_18_, unknown_1a_, unknown_1c_;
    short unknown_1e_;
    int unknown_20_[3];
    Vector3fix unknown_2c_;
    int unknown_38_[3];
    Vector3fix unknown_44_;
};

struct Struct_ov017_021c2b6c {
    unsigned char unknown_0_[8];
    SafeAllocator unknown_8_;
    unsigned char unknown_1c_[0x70];
    unsigned char unknown_8c_;
    unsigned char unknown_8d_;
    unsigned char unknown_8e_[2];
    int unknown_90_;
    unsigned char unknown_94_;
    unsigned char unknown_95_;
    unsigned char unknown_96_;
};

// USA: func_ov017_021c2b6c
extern "C" ARM void func_ov017_021c2b6c(Obj021c2b6c* self) {
    GameState* game = GameState::GetInstance();
    GameResources* res = GetGameResources();
    void* list = func_02057924();
    PartyEntry021c2b6c entries[4];
    unsigned int len;
    if (self->step == 0) {
        if (AllocatorUnion_GetMaxPossibleAllocation((Struct02012dd0*)&g_mainAllocator) < 0x8000) {
            func_020a0cc4(0x8000);
            arg0->unknown_96_ = 1;
        }
        void* buf = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x8000);
        self->alloc.CreateTypeA(buf, 0x8000);
        self->alloc.Reset();
        char* pool = res->vramStates_;
        VramState_CopyCurrentTo((State0207dfc8*)(pool + 0xc40), (State0207dfc8*)self->state);
        len = 0;
        void* data = LoadFileIntoNewAllocation(data_ov017_021d7f6c, self->alloc, &len);
        if (data == 0) {
            self->mode = 3;
            return;
        }
        func_02057e6c(var2, 0x11, &arg0->unknown_8_, (int)var7, var4, (Struct_02015ef4_5*)arg0->unknown_1c_);
        arg0->unknown_8d_++;
    } else if (arg0->unknown_8d_ == 1) {
        GameObject* var8 = var0->GetPartyMemberByIndex(arg0->unknown_95_);
        if (var8 == 0) {
            arg0->unknown_8c_ = 3;
            return;
        }
        for (int var9 = 0; var9 < 4; var9++) {
            GameObject* var10 = var0->GetPartyMemberByIndex(var9);
            if (var10 == 0) continue;
            if (var10->obj3D_.GetInheritedAlpha() == 0) continue;
            if (var8->obj3D_.GetField06() != var10->obj3D_.GetField06()) continue;
            if (*(unsigned short*)((char*)var10 + Enum_ov017_021c2b6c_434) != 0) continue;
            if (**(unsigned int**)((char*)var10 + 0x130) & 1) continue;
            var3[var9].unknown_0_ = 0;
            var3[var9].unknown_10_ = 1;
            var3[var9].unknown_12_ = 0;
            var3[var9].unknown_14_ = -1;
            var3[var9].unknown_16_ = -1;
            var3[var9].unknown_18_ = -1;
            var3[var9].unknown_1a_ = -1;
            var3[var9].unknown_1c_ = -0x1000;
            var3[var9].unknown_20_[0] = 0;
            var3[var9].unknown_20_[1] = 0;
            var3[var9].unknown_20_[2] = 0;
            var3[var9].unknown_2c_.x = 0;
            var3[var9].unknown_2c_.y = 0;
            var3[var9].unknown_2c_.z = 0;
            var3[var9].unknown_38_[0] = 0;
            var3[var9].unknown_38_[1] = 0;
            var3[var9].unknown_38_[2] = 0;
            var3[var9].unknown_44_.x = 0x1000;
            var3[var9].unknown_44_.y = 0x1000;
            var3[var9].unknown_44_.z = 0x1000;
            Struct_ov017_021c2b6c_2* var11 = &var3[var9];
            var11->unknown_11_0_ = 0;
            var11->unknown_11_1_ = 0;
            var11->unknown_11_2_ = 1;
            var11->unknown_11_3_ = 0;
            var11->unknown_11_4_ = 0;
            var11->unknown_11_5_ = 0;
            var11->unknown_11_6_ = 0;
            var11->unknown_11_7_ = 0;
            var11->unknown_2c_ = var10->obj3D_.position_;
            var11->unknown_44_ = var10->obj3D_.GetScale();
            func_02057fb4(var2, 0x11, var11);
        }
        arg0->unknown_90_ = 1;
        func_ov017_021d24a8(arg0->unknown_95_);
    }
}
