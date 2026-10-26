#include <globaldefs.h>
#include "Combat/SearchEntry.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "NitroSDK/Graphics.h"

struct Struct_0202b2f0;
struct Struct_0202c1a4;
struct Struct_0201e830;
struct AllocatorUnion;

struct Struct_ov017_021afe00_3 {
    char unknown_0_[0x1b2];
    unsigned short unknown_1b2_;
};

struct Struct_ov017_021afe00_4 {
    unsigned char unknown_0_;
    char unknown_1_[3];
    char unknown_4_[0x190];
    char unknown_194_[0x110];
    char unknown_2a4_[0x20];
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
    char unknown_0_[4];
    signed char* unknown_4_;
    char unknown_8_;
    unsigned char unknown_9_;
    unsigned char unknown_a_;
    unsigned char unknown_b_;
    unsigned char unknown_c_;
    char unknown_d_[0x1b - 0xd];
    unsigned char unknown_1b_[0x38 - 0x1b];
    unsigned int unknown_38_;
    int unknown_3c_;
    unsigned short unknown_40_;
    unsigned char unknown_42_;
    char unknown_43_[0x288 - 0x43];
    Struct_ov017_021afe00_4* unknown_288_;
};

struct Struct_ov017_021afe00 {
    char unknown_0_[0x1b34];
    unsigned int unknown_1b34_;
    unsigned int unknown_1b38_;
    unsigned int unknown_1b3c_;
    char unknown_1b40_[0x1b48 - 0x1b40];
    unsigned int unknown_1b48_;
    char unknown_1b4c_[0x1b62 - 0x1b4c];
    unsigned char unknown_1b62_;
};

struct Struct_ov017_021afe00_2 {
    unsigned char unknown_0_;
};

extern "C" void* LinkSession_GetInstance();
extern "C" void* Zone3D_GetInstance();
extern "C" void func_020531f0(void* p);
extern "C" void func_ov017_021cff8c(int a, int b);
extern "C" void func_ov017_021d0b30(int a, int b, int c);

int LinkSession_IsSlotMember(SearchStruct* obj, int index);
signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4* obj);
unsigned short GetFieldAt0x7e_0201e830(S_e830* obj);
void Set3DClearColor(int a, int b, int c, int d, int e);
int GameObject_IsGesturing(signed char* obj);
int GetField1c_021a193c(int* obj);
int GameState_GetProtagonistIndex(GameState* gs);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
void* GameState_GetPlayerLocation(char* gs, unsigned int idx);
unsigned int GetWord0x71f8_02012078(void* gs);
void ClearAllTreasureMapUnknownBits_020116c8(void* gs);
void SetCombatModeFromCase020dc2d0(int v);

extern AllocatorUnion g_mainAllocator;

// USA: func_ov017_021afe00
extern "C" ARM int func_ov017_021afe00(Step021afe00* self) {
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
        if (var3->unknown_2_0_ == 0) {
            return arg0->unknown_a_;
        }
    }
    self->unkB = 1;
    char* g = (char*)Zone3D_GetInstance();
    Sub021afe00* sub = (Sub021afe00*)(g + 0x840);
    if (self->state != 2) {
        GameResources* res = GetGameResources();
        if (IsBrightnessTransitionActive(res) != 0) {
            return 1;
        }
        self->axis = GetBrightness((GameResources*)res, false);
        if (IsScreenFullyFaded((GameResources*)res, false) != 0) {
            self->restoreDisplay = 1;
            DISPCNT = (DISPCNT & ~0x1f00) | 0x100;
            char* info = (char*)Zone3D_GetInstance();
            if (info != 0) {
                S_e830* color = (S_e830*)(info + 0x6c);
                if (color != 0) {
                    self->clearColor = GetFieldAt0x7e_0201e830(color);
                }
            }
            int var9 = 0;
            if (arg0->unknown_3c_ == 0x10) {
                var9 = 0x7fff;
            }
            Set3DClearColor(clear, 0x1f, 0x7fff, 0, 0);
            self->field4Bits = GetFlags04(res);
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
        if (arg0->unknown_4_ != 0) {
            if (*arg0->unknown_4_ == 2) {
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
            memcpy(a->a194, (char*)gs + 0x5e6c, 0x110);
            memcpy(a->a2a4, GameState_GetPlayerLocation((char*)gs, 0), 0x20);
            a->w2c4 = GetWord0x71f8_02012078(gs);
            a->w2c8 = sub->w34;
            a->h2d0 = sub->w38;
            a->h2d2 = sub->w3c;
            a->w2cc = sub->w48;
            a->b2d4 = *(unsigned short*)(g + 0x27b4);
            a->b2d5 = *(unsigned short*)(g + 0x27b6);
            for (int i = 0; i < 4; i++) {
                PartyView021afe00* m = (PartyView021afe00*)gs->GetPartyMemberByIndex(i);
                if (m != 0) {
                    a->h2d6[i] = m->f1b2;
                } else {
                    var12->unknown_2d6_[var13] = 0;
                }
            }
        }
    }
    if (arg0->unknown_9_ == 0) {
        memset(&arg0->unknown_1b_[0], 0, 4);
        for (int var15 = 0; var15 < 4; var15++) {
            GameObject* var16 = var0->GetGameObjectByIndex(var15);
            if (var16 != 0) {
                if ((var16->obj3D_.unknown_0_ & 0x200) != 0) {
                    arg0->unknown_1b_[var15] = 1;
                } else {
                    arg0->unknown_1b_[var15] = 2;
                }
            }
        }
        arg0->unknown_1b_[arg0->unknown_c_] = 1;
        return 2;
    }
    if (arg0->unknown_9_ == 2) {
        var5->unknown_1b62_ = 0;
    }
    Struct_ov017_021afe00_2* var17 = (Struct_ov017_021afe00_2*)var0->GetGrottoStruct();
    if (var17->unknown_0_ != 0 && arg0->unknown_9_ == 2) {
        func_020116c8(var0);
        func_020dc2d0(0);
    }
    func_ov017_021d0b30(1, 0, 0);
    return 3;
}
