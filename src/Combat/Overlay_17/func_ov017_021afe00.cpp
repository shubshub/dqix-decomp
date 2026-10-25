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

extern "C" void* func_0202ae18();
extern "C" void* Zone3D_GetInstance();
extern "C" void func_020531f0(void* p);
extern "C" void func_ov017_021cff8c(int a, int b);
extern "C" void func_ov017_021d0b30(int a, int b, int c);

int TestBitBySignedByteIndex_0202c1c0(SearchStruct* obj, int index);
signed char GetSearchStructCurrentArrEntry(SearchStruct0202c1a4* obj);
unsigned short GetFieldAt0x7e_0201e830(S_e830* obj);
void Set3DClearColor_020c5588(int a, int b, int c, int d, int e);
int CheckSubstructByte0x7cPositive_020535c8(signed char* obj);
int GetField1c_021a193c(int* obj);
int GameState_GetProtagonistIndex(GameState* gs);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
void* GetField0x74deForValidIndex_020120a0(char* gs, unsigned int idx);
unsigned int GetWord0x71f8_02012078(void* gs);
void ClearAllTreasureMapUnknownBits_020116c8(void* gs);
void SetCombatModeFromCase020dc2d0(int v);

extern AllocatorUnion g_mainAllocator;

// USA: func_ov017_021afe00
extern "C" ARM int func_ov017_021afe00(Struct_ov017_021afe00_5* arg0) {
    GameState* var0 = GameState::GetInstance();
    Struct_0202b2f0* var1 = (Struct_0202b2f0*)func_0202ae18();
    for (int var2 = 0; var2 < 4; var2++) {
        if (func_0202c1c0(var1, var2) == 0) {
            continue;
        }
        if (var2 == func_0202c1a4((Struct_0202c1a4*)var1)) {
            continue;
        }
        Struct_0202b2f0_2* var3 = func_0202c178(var1, var2);
        if (var3 == 0) {
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
        arg0->unknown_3c_ = GetBrightness((GameResources*)var6, false);
        if (IsBrightnessOutsideValidRange((GameResources*)var6, false) != 0) {
            arg0->unknown_42_ = 1;
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
            func_020c5588(var9, 0x1f, 0x7fff, 0, 0);
            arg0->unknown_38_ = GetFlags04(var6);
            ClearFlags04(var6, 0xffffffff);
            SetFlags04(var6, 0x8de);
            SetMainBrightness(var6, 0, 2);
        }
        for (int var10 = 0; var10 < 4; var10++) {
            GameObject* var11 = var0->GetPartyMemberByIndex(var10);
            if (var11 != 0) {
                if (func_020535c8((signed char*)var11) != 0) {
                    func_020531f0(var11);
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
    if (arg0->unknown_9_ == 0) {
        Struct_ov017_021afe00_4* var12 = arg0->unknown_288_;
        if (arg0->unknown_288_ != 0) {
            var12->unknown_0_ = *(unsigned char*)((char*)var0 + 0x5cda);
            memcpy(var12->unknown_4_, (char*)var0 + 0x5cdc, 0x190);
            memcpy(var12->unknown_194_, (char*)var0 + 0x5e6c, 0x110);
            memcpy(var12->unknown_2a4_, func_020120a0((char*)var0, 0), 0x20);
            var12->unknown_2c4_ = func_02012078(var0);
            var12->unknown_2c8_ = var5->unknown_1b34_;
            var12->unknown_2d0_ = var5->unknown_1b38_;
            var12->unknown_2d2_ = var5->unknown_1b3c_;
            var12->unknown_2cc_ = var5->unknown_1b48_;
            var12->unknown_2d4_ = *(unsigned short*)(var4 + 0x27b4);
            var12->unknown_2d5_ = *(unsigned short*)(var4 + 0x27b6);
            for (int var13 = 0; var13 < 4; var13++) {
                Struct_ov017_021afe00_3* var14 = (Struct_ov017_021afe00_3*)var0->GetPartyMemberByIndex(var13);
                if (var14 != 0) {
                    var12->unknown_2d6_[var13] = var14->unknown_1b2_;
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
