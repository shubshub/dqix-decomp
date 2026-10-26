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

struct Struct02012dd0;
struct State0207dfc8;

extern "C" void* func_02057924(void);
extern "C" void func_020a0cc4(unsigned int);
extern "C" int func_02057e6c(void* list, int p1, SafeAllocator* alloc, int p2, int p3, State0207dfc8* p4);
extern "C" unsigned int AllocatorUnion_GetMaxPossibleAllocation(Struct02012dd0*);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern "C" void VramState_CopyCurrentTo(State0207dfc8*, State0207dfc8*);
extern "C" void func_02057fb4(void*, int, void*);
extern "C" void func_ov017_021d24a8(int);

extern AllocatorUnion g_mainAllocator;
extern char data_ov017_021d7f6c[];

struct Struct_ov017_021c2b6c_2 {
    unsigned char kind;
    unsigned char unknown_1_[0xf];
    unsigned char enabled;
    unsigned char bit0 : 1;
    unsigned char unknown_11_1_ : 1;
    unsigned char bit2 : 1;
    unsigned char unknown_11_3_ : 1;
    unsigned char unknown_11_4_ : 1;
    unsigned char unknown_11_5_ : 1;
    unsigned char unknown_11_6_ : 1;
    unsigned char unknown_11_7_ : 1;
    unsigned short unknown_12_;
    short unknown_14_, unknown_16_, s18, unknown_1a_, unknown_1c_;
    short pad1e;
    int unknown_20_[3];
    Vector3fix pos;
    int unknown_38_[3];
    Vector3fix scale;
};

struct Struct_ov017_021c2b6c {
    unsigned char pad[8];
    SafeAllocator alloc;
    unsigned char state[0x70];
    unsigned char mode;
    unsigned char step;
    unsigned char unknown_8e_[2];
    int done;
    unsigned char unknown_94_;
    unsigned char memberIndex;
    unsigned char unknown_96_;
};

// USA: func_ov017_021c2b6c
extern "C" ARM void func_ov017_021c2b6c(Struct_ov017_021c2b6c* self) {
    GameState* game = GameState::GetInstance();
    GameResources* res = GetGameResources();
    void* list = func_02057924();
    Struct_ov017_021c2b6c_2 entries[4];
    unsigned int len;
    if (self->step == 0) {
        if (AllocatorUnion_GetMaxPossibleAllocation((Struct02012dd0*)&g_mainAllocator) < 0x8000) {
            func_020a0cc4(0x8000);
            self->unknown_96_ = 1;
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
        func_02057e6c(list, 0x11, &self->alloc, (int)data, len, (State0207dfc8*)self->state);
        self->step++;
    } else if (self->step == 1) {
        GameObject* leader = game->GetPartyMemberByIndex(self->memberIndex);
        if (leader == 0) {
            self->mode = 3;
            return;
        }
        for (int i = 0; i < 4; i++) {
            GameObject* m = game->GetPartyMemberByIndex(i);
            if (m == 0) continue;
            if (m->obj3D_.GetInheritedAlpha() == 0) continue;
            if (leader->obj3D_.GetField06() != m->obj3D_.GetField06()) continue;
            if (*(unsigned short*)((char*)m + Enum_ov017_021c2b6c_434) != 0) continue;
            if (**(unsigned int**)((char*)m + 0x130) & 1) continue;
            entries[i].kind = 0;
            entries[i].enabled = 1;
            entries[i].unknown_12_ = 0;
            entries[i].unknown_14_ = -1;
            entries[i].unknown_16_ = -1;
            entries[i].s18 = -1;
            entries[i].unknown_1a_ = -1;
            entries[i].unknown_1c_ = -0x1000;
            entries[i].unknown_20_[0] = 0;
            entries[i].unknown_20_[1] = 0;
            entries[i].unknown_20_[2] = 0;
            entries[i].pos.x = 0;
            entries[i].pos.y = 0;
            entries[i].pos.z = 0;
            entries[i].unknown_38_[0] = 0;
            entries[i].unknown_38_[1] = 0;
            entries[i].unknown_38_[2] = 0;
            entries[i].scale.x = 0x1000;
            entries[i].scale.y = 0x1000;
            entries[i].scale.z = 0x1000;
            Struct_ov017_021c2b6c_2* e = &entries[i];
            e->bit0 = 0;
            e->unknown_11_1_ = 0;
            e->bit2 = 1;
            e->unknown_11_3_ = 0;
            e->unknown_11_4_ = 0;
            e->unknown_11_5_ = 0;
            e->unknown_11_6_ = 0;
            e->unknown_11_7_ = 0;
            e->pos = m->obj3D_.position_;
            e->scale = m->obj3D_.GetScale();
            func_02057fb4(list, 0x11, e);
        }
        self->done = 1;
        func_ov017_021d24a8(self->memberIndex);
    }
}
