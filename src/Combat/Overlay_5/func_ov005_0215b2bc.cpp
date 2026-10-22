#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/Brightness.h>
#include "Resource/GameResources.h"
#include "Input/Input.h"

struct Struct_ov005_0215b2bc_2 {
#if defined(jpn)
    char unknown_0_[0x4f8];
#else
    char unknown1_0_[0x4fc];
#endif
    int unknown_4fc_;
};

struct SePlayer;
extern SePlayer g_sePlayer;

struct Struct_ov005_02156ecc_2;
struct Struct_ov005_02156ecc;
extern "C" void func_ov005_02157174(Struct_ov005_02156ecc*, Struct_ov005_02156ecc_2*);

struct Struct_0205bb84;
int GridCursor_GetSelectedIndex(Struct_0205bb84*);
extern "C" int func_0205bf58(void*, int);
int CheckFlag30Or401_02157190(void*);
char* GetField1c_021a193c(int*);
void DispatchByIdxAndCond021551fc(char*, int, int);
void SePlayer_Play(SePlayer*, int, int);
extern "C" void func_ov005_021555c0(void*);
extern "C" void func_ov005_0215792c(void*, unsigned char);
extern "C" unsigned char func_ov005_021586c4(void*, int, int);

struct Struct_ov005_02153ba4 {
    short unknown_0_;
    signed char unknown_2_;
    unsigned char unknown_3_;
    void* unknown_4_;
    void* unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    short unknown_18_;
};

struct Struct_ov005_0215b2bc {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
};

struct Struct_ov000_0217ab8c {
    char unknown_0_[0xd90];
#if defined(jpn)
    char unknown_d90_[0x196c - 0xd90];
#else
    char unknown1_d90_[0x19f4 - 0xd90];
#endif
    char unknown_19f4_[0x2d90 - 0x19f4];
    Struct_ov005_02153ba4 unknown_2d90_[24];
    char unknown_3030_[0x3d78 - 0x2d90 - sizeof(Struct_ov005_02153ba4) * 24];
    short unknown_3d78_;
    char unknown_3d7a_[0x3daa - 0x3d7a];
    unsigned char unknown_3daa_;
    char unknown_3dab_[0x3db8 - 0x3dab];
    unsigned char unknown_3db8_;
    char unknown_3db9_[0x3dba - 0x3db9];
    unsigned char unknown_3dba_;
    unsigned char unknown_3dbb_;
    unsigned char unknown_3dbc_;
    signed char unknown_3dbd_;
    unsigned char unknown_3dbe_;
    unsigned char unknown_3dbf_;
    char unknown_3dc0_[0x3dcc - 0x3dc0];
    unsigned int unknown_3dcc_;
    char unknown_3dd0_[0x3dfc - 0x3dd0];
    unsigned char unknown_3dfc_[8];
};

// USA: func_ov005_0215b2bc
extern "C" ARM void func_ov005_0215b2bc(Struct_ov000_0217ab8c* arg0) {
    if (arg0->unknown_3dba_ == 0) {
        if (!IsBrightnessTransitionActive(GetGameResources())) {
            arg0->unknown_3dba_++;
        }
    } else if (arg0->unknown_3dba_ == 1) {
        int var0 = 0;
        int var1 = 0;
        unsigned char var2 = 255;
        int var3 = 0;
        int var4;
        int var5;
        if (g_touchInput.pressed_ != 0) {
            var3 = 1;
            g_touchInput.GetTouchPoint(&var4, &var5);
            var2 = func_ov005_021586c4(arg0, var4, var5);
            if (var2 != 255) {
                var0 = var3;
                var1 = var0;
            } else if (var4 > 0x80) {
                for (int var6 = var0; var6 < 8; var6++) {
                    int var7 = var6 * 0x18;
                    int var8 = var7 + 0x18;
                    if (var5 > var7 && var5 < var8) {
                        var0 = 1;
                        var1 = var0;
                        var2 = var6;
                        break;
                    }
                }
            }
        }
        if (hasCoords == 0) {
            found = 1;
            unsigned int tick = GameState::GetInstance()->GetTickCount();
            func_0205bf58(self->scale_, tick ? tick : found);
            sel = GridCursor_GetSelectedIndex((Struct_0205bb84*)&self->scale_[0]);
            if (CheckFlag30Or401_02157190(self)) flag2 = 1;
        }
        if (var0 != 0 && arg0->unknown_3dbc_ != var2) {
            arg0->unknown_3dbe_ = arg0->unknown_3dbc_;
            arg0->unknown_3dbf_ = arg0->unknown_3dbd_;
            arg0->unknown_3dfc_[arg0->unknown_3dbc_] = arg0->unknown_3dbd_;
            arg0->unknown_3dbc_ = var2;
            arg0->unknown_3dbd_ = arg0->unknown_3dfc_[var2 & 0xff];
        }
        self->f3dbb_ = self->kind_;
        MenuTail* hold = (MenuTail*)GetField1c_021a193c((int*)GetGameResources()->unknown_ptr_array_36fc[3]);
        DispatchByIdxAndCond021551fc((char*)self, hold->index, 0);
        if (flag2 == 0) return;
        SePlayer_Play(&g_sePlayer, 1, 0);
        func_ov005_021555c0(self);
        self->flags_ |= 0x40;
        self->f3daa_ = 0;
        func_ov005_0215792c(self, 1);
        EquipmentSlot* slots;
        int j = 0;
        for (; j < 8; j++) {
            slots = self->slots_;
            EquipmentSlot* s = &slots[j];
            if (j == self->count_) continue;
            if (s->item_ < 0) continue;
            Src02157174* m = (Src02157174*)s->model_;
            Triplet t = *(Triplet*)((char*)m + 0x1c);
            t.b = 0x17000;
            CopyThreeFields02157174((Dst02157174*)m, (Src02157174*)&t);
        }
    }
}
