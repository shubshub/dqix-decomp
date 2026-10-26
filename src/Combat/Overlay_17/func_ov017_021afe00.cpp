#include <globaldefs.h>
#include "Combat/SearchEntry.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "NitroSDK/Graphics.h"

struct SearchStruct;
struct SearchStruct0202c1a4;
struct S_e830;
struct AllocatorUnion;

struct Struct_ov017_021afe00_3 {
    char pad0[0x1b2];
    unsigned short unknown_1b2_;
};

struct Alloc021afe00 {
    unsigned char b0;
    char pad1[3];
    char a4[0x190];
    char unknown_194_[0x110];
    char a2a4[0x20];
    unsigned int unknown_2c4_;
    unsigned int unknown_2c8_;
    unsigned int unknown_2cc_;
    unsigned short unknown_2d0_;
    unsigned short unknown_2d2_;
    unsigned char unknown_2d4_;
    unsigned char unknown_2d5_;
    unsigned short unknown_2d6_[4];
};

struct Struct_ov017_021afe00_5 {
    char unk0[4];
    signed char* unknown_4_;
    char unknown_8_;
    unsigned char state;
    unsigned char unknown_a_;
    unsigned char unknown_b_;
    unsigned char unknown_c_;
    char unknown_d_[0x1b - 0xd];
    unsigned char slots[0x38 - 0x1b];
    unsigned int unknown_38_;
    int axis;
    unsigned short clearColor;
    unsigned char unknown_42_;
    char unknown_43_[0x288 - 0x43];
    Alloc021afe00* alloc;
};

struct Struct_ov017_021afe00 {
    char pad0[0x1b34];
    unsigned int unknown_1b34_;
    unsigned int unknown_1b38_;
    unsigned int unknown_1b3c_;
    char unknown_1b40_[0x1b48 - 0x1b40];
    unsigned int unknown_1b48_;
    char unknown_1b4c_[0x1b62 - 0x1b4c];
    unsigned char unknown_1b62_;
};

struct Struct_ov017_021afe00_2 {
    unsigned char flag;
};

extern "C" void* LinkSession_GetInstance();
extern "C" void* Zone3D_GetInstance();
extern "C" void func_020531f0(void* p);
extern "C" void func_ov017_021cff8c(int a, int b);
extern "C" void func_ov017_021d0b30(int a, int b, int c);

extern "C" int LinkSession_IsSlotMember(SearchStruct* obj, int index);
extern "C" signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4* obj);
extern "C" unsigned short func_0201e830(S_e830* obj);
extern "C" void Set3DClearColor(int a, int b, int c, int d, int e);
extern "C" int GameObject_IsGesturing(signed char* obj);
extern "C" int func_ov017_021a193c(int* obj);
extern "C" int GameState_GetProtagonistIndex(GameState* gs);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void* GameState_GetPlayerLocation(char* gs, unsigned int idx);
extern "C" unsigned int func_02012078(void* gs);
extern "C" void func_020116c8(void* gs);
extern "C" void func_020dc2d0(int v);

extern AllocatorUnion g_mainAllocator;

// USA: func_ov017_021afe00
extern "C" ARM int func_ov017_021afe00(Struct_ov017_021afe00_5* self) {
    GameState* gs = GameState::GetInstance();
    SearchStruct* search = (SearchStruct*)LinkSession_GetInstance();
    for (int i = 0; i < 4; i++) {
        if (LinkSession_IsSlotMember(search, i) == 0) {
            continue;
        }
        if (i == LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search)) {
            continue;
        }
        SearchEntry0202c178* e = LinkSession_GetReceivedRecord(search, i);
        if (e == 0) {
            continue;
        }
        if (e->active == 0) {
            return self->unknown_a_;
        }
    }
    self->unknown_b_ = 1;
    char* g = (char*)Zone3D_GetInstance();
    Struct_ov017_021afe00* sub = (Struct_ov017_021afe00*)(g + 0x840);
    if (self->state != 2) {
        GameResources* res = GetGameResources();
        if (IsBrightnessTransitionActive(res) != 0) {
            return 1;
        }
        self->axis = GetBrightness((GameResources*)res, false);
        if (IsScreenFullyFaded((GameResources*)res, false) != 0) {
            self->unknown_42_ = 1;
            DISPCNT = (DISPCNT & ~0x1f00) | 0x100;
            char* info = (char*)Zone3D_GetInstance();
            if (info != 0) {
                S_e830* color = (S_e830*)(info + 0x6c);
                if (color != 0) {
                    self->clearColor = func_0201e830(color);
                }
            }
            int clear = 0;
            if (self->axis == 0x10) {
                clear = 0x7fff;
            }
            Set3DClearColor(clear, 0x1f, 0x7fff, 0, 0);
            self->unknown_38_ = GetFlags04(res);
            ClearFlags04(res, 0xffffffff);
            SetFlags04(res, 0x8de);
            SetMainBrightness(res, 0, 2);
        }
        for (int i = 0; i < 4; i++) {
            GameObject* m = gs->GetPartyMemberByIndex(i);
            if (m != 0) {
                if (GameObject_IsGesturing((signed char*)m) != 0) {
                    func_020531f0(m);
                }
            }
        }
        if (self->unknown_4_ != 0) {
            if (*self->unknown_4_ == 2) {
                if (func_ov017_021a193c(*(int**)((char*)GetGameResources() + 0x3708)) != 0) {
                    DISPCNT = (DISPCNT & ~0x1f00) | 0x700;
                }
            } else {
                DISPCNT = (DISPCNT & ~0x1f00) | 0x100;
            }
        } else {
            DISPCNT = (DISPCNT & ~0x1f00) | 0x100;
        }
    }
    if (self->state == 1) {
        func_ov017_021cff8c(GameState_GetProtagonistIndex(gs), 0);
    }
    if (self->state == 2 || self->state == 0) {
        self->alloc = (Alloc021afe00*)AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x2e0);
    }
    if (self->state == 0) {
        Alloc021afe00* a = self->alloc;
        if (self->alloc != 0) {
            a->b0 = *(unsigned char*)((char*)gs + 0x5cda);
            memcpy(a->a4, (char*)gs + 0x5cdc, 0x190);
            memcpy(a->unknown_194_, (char*)gs + 0x5e6c, 0x110);
            memcpy(a->a2a4, GameState_GetPlayerLocation((char*)gs, 0), 0x20);
            a->unknown_2c4_ = func_02012078(gs);
            a->unknown_2c8_ = sub->unknown_1b34_;
            a->unknown_2d0_ = sub->unknown_1b38_;
            a->unknown_2d2_ = sub->unknown_1b3c_;
            a->unknown_2cc_ = sub->unknown_1b48_;
            a->unknown_2d4_ = *(unsigned short*)(g + 0x27b4);
            a->unknown_2d5_ = *(unsigned short*)(g + 0x27b6);
            for (int i = 0; i < 4; i++) {
                Struct_ov017_021afe00_3* m = (Struct_ov017_021afe00_3*)gs->GetPartyMemberByIndex(i);
                if (m != 0) {
                    a->unknown_2d6_[i] = m->unknown_1b2_;
                } else {
                    a->unknown_2d6_[i] = 0;
                }
            }
        }
    }
    if (self->state == 0) {
        memset(&self->slots[0], 0, 4);
        for (int i = 0; i < 4; i++) {
            GameObject* o = gs->GetGameObjectByIndex(i);
            if (o != 0) {
                if ((o->obj3D_.unknown_0_ & 0x200) != 0) {
                    self->slots[i] = 1;
                } else {
                    self->slots[i] = 2;
                }
            }
        }
        self->slots[self->unknown_c_] = 1;
        return 2;
    }
    if (self->state == 2) {
        sub->unknown_1b62_ = 0;
    }
    Struct_ov017_021afe00_2* grotto = (Struct_ov017_021afe00_2*)gs->GetGrottoStruct();
    if (grotto->flag != 0 && self->state == 2) {
        func_020116c8(gs);
        func_020dc2d0(0);
    }
    func_ov017_021d0b30(1, 0, 0);
    return 3;
}
