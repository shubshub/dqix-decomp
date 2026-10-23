#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "std_library_functions.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

#if defined(jpn)
#define func_0206df6c func_0206f0c0
#endif

struct Struct_0201099c_16;
struct Struct_02033834;
struct Struct_02038598_4;
struct Struct_02015438;
struct Struct_02082d6c;
struct Struct_02082d6c_2;
struct Struct_ov003_02166a90_5 {
#if defined(jpn)
    unsigned char unknown_0_[0x2ca];
    signed char unknown_4a2_;
    unsigned char unknown_2cb_[0x2e4 - 0x2cb];
#else
    unsigned char unknown1_0_[0x4a2];
    signed char unknown_4a2_;
    unsigned char unknown_4a3_[0x4bc - 0x4a3];
#endif
    unsigned char unknown_4bc_;
};
struct Struct_ov003_02166a90_6 {
    unsigned char unknown_0_[2];
    unsigned char unknown_2_[13];
    unsigned char unknown_f_[0x13f - 0xf];
    unsigned char unknown_13f_0_ : 3;
    unsigned char unknown_13f_3_ : 5;
    unsigned char unknown_140_[0x34];
};
struct Struct_ov003_02166a90_7 {
    unsigned char unknown_0_[0x568];
    short unknown_568_;
};
struct Struct_ov003_02166a90 {
    Object3D unknown_0_;
    unsigned char unknown_ac_[0x134 - 0xac];
    char* unknown_134_;
};
struct Struct_ov003_02166a90_2 {
    unsigned char unknown_0_[0x16c];
    unsigned short unknown_16c_[16];
};
struct Struct_ov003_02166a90_3 {
    unsigned char unknown_0_[0xb];
    unsigned char unknown_b_;
};
struct Struct_ov003_02166a90_4 {
    unsigned char unknown_0_[0x8c];
    unsigned char unknown_8c_[1];
};
extern Vector3i data_ov003_0217f4b8[3];

extern "C" SelectedEntry02166a90* func_ov003_02160bf8(SelectionPage02166a90*, int);
extern "C" void* func_02012fe4(void);
extern "C" void* func_020108f0(void*, int);
extern "C" void* func_02010954(char*);
extern "C" void func_02086380(unsigned char*);
extern "C" void func_02082d6c(Struct_02082d6c*, Struct_02082d6c_2*);
extern "C" void func_ov017_0218f064(GameResources*, int, int, int, int);
extern "C" GameObject* func_0200ff58(GameState*, int);
extern "C" void func_02033874(Struct_02033834*, int);
extern "C" unsigned char* func_ov017_021a4658(unsigned char*, int);
extern "C" int func_020100a8(GameState*);
extern "C" void func_020546a0(void*, int);
extern "C" int func_020546a8(void*);
extern "C" void func_020546b4(void*, int);
typedef void (*Type_ov003_02166a90)(void*, int);
extern "C" int func_02053c6c(unsigned char*);
extern "C" void func_02042764(unsigned char*, char*, int);
int GetFieldAt0x50(Struct020865b0*);
void PartyMember_SetVocation(unsigned char*, int);
void* GetDataPtr02114e04_020d6c00(void);
void OrBitsIntoField0_020466e4(unsigned int*, unsigned int);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24**);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202b7d8(int*);
extern "C" void func_ov017_021cc340(int, int, int);
extern "C" void func_ov017_021cf078(int, unsigned short, unsigned char);
extern "C" void func_ov017_021cc97c(int);
extern "C" void func_ov017_021cca5c(int, int);
extern "C" void func_ov017_021ccb58(int, int);
extern "C" void* func_0205ec34(void);
extern "C" void func_0206e424(void*, int);
extern "C" void func_0206df6c(void*, unsigned char*, int, int);
extern "C" void func_020466f4(Struct_02038598_4*, unsigned int);
extern "C" void func_ov017_02191234(unsigned char*);
extern "C" void func_020dc2d0(int);
extern "C" void func_ov017_02191108(void*, int, int, int, int);
extern "C" void func_020dc7e8(int, int);
extern "C" void func_ov017_021d0dbc(void);
extern "C" void func_ov017_021cee78(int, unsigned char);

// USA: func_ov003_02166a90
extern "C" ARM int func_ov003_02166a90(Struct_ov003_02166a90_5* arg0, int arg1) {
    Struct_ov003_02166a90_6* var0 = func_ov003_02160bf8(arg0, arg1);
    if (var0 == 0) {
        return 0;
    }
    int var1 = 0;
    if (var0->unknown_13f_0_ == 2 || var0->unknown_13f_0_ == 3 || var0->unknown_13f_0_ == 4) {
        var1 = 1;
    }
    GameState* state = GameState::GetInstance();
    GameResources* resources = state->GetResources();
    unsigned short* field06 = (unsigned short*)func_02012fe4();
    if (self->step == 0) {
        int freeSlot = -1;
        for (int slot = 3; slot >= 0; slot--) {
            if (state->GetGameObjectByIndex(slot) == 0) {
                freeSlot = slot;
                break;
            }
        }
        if (var5 >= 0) {
            arg0->unknown_4a2_ = var5;
            SetSubBrightness(var3, -16, 20);
            arg0->unknown_4bc_++;
        } else {
            arg0->unknown_4bc_ = 0;
            return -1;
        }
    }
    if (arg0->unknown_4bc_ == 1) {
        if (IsSubBrightnessTransitionActive(var3) != 0) {
            return 0;
        }
        Struct_ov003_02166a90_7* var7 = (Struct_ov003_02166a90_7*)func_020108f0(var2, arg0->unknown_4a2_);
        if (var7 == 0) {
            var7 = (Struct_ov003_02166a90_7*)func_02010954((char*)var2);
        }
        var7->unknown_568_ = arg0->unknown_4a2_;
        func_02086380((unsigned char*)var7);
        func_02082d6c((Struct_02082d6c*)var7, (Struct_02082d6c_2*)var0);
        func_ov017_0218f064(var3, arg0->unknown_4a2_, 0x1000, 1, 0);
        GameObject* var8 = func_0200ff58(var2, arg0->unknown_4a2_);
        if (var8 == 0) {
            return 0;
        }
        var8->obj3D_.SetField06(*var4);
        var2->GetProtagonist();
        var8->obj3D_.position_ = data_ov003_0217f4b8[arg0->unknown_4a2_ - 1];
        func_02033874((Struct_02033834*)var8, 0x323d);
        Struct_ov003_02166a90_3* var9 = (Struct_ov003_02166a90_3*)func_ov017_021a4658((unsigned char*)var3, arg0->unknown_4a2_);
        if (var1 == 0) {
            var9->unknown_b_ |= 8;
        }
        int var10 = func_020100a8(var2);
        ((Type_ov003_02166a90)func_020546a0)(var8, var10);
        int var11 = 0;
        for (int var12 = 0; var12 < 4; var12++) {
            GameObject* var13 = func_0200ff58(var2, var12);
            if (var13 != 0 && var12 != arg0->unknown_4a2_) {
                if (var10 == func_020546a8(var13)) {
                    var11++;
                }
            }
        }
        ((Type_ov003_02166a90)func_020546b4)(var8, var11);
        func_02010828(var2);
        Struct_ov003_02166a90_2* var14 = (Struct_ov003_02166a90_2*)func_02053c6c((unsigned char*)var8);
#if defined(jpn)
        strcpy(((Struct_ov003_02166a90*)var8)->unknown_134_, (char*)var0->unknown_140_);
#else
        char var15[0x30] = {0};
        func_02042764(var0->unknown_140_, var15, 1);
        strcpy(((Struct_ov003_02166a90*)var8)->unknown_134_, var15);
#endif
        int index = GetFieldAt0x50((Struct020865b0*)entry);
        appearance->values[index] = entry->metadataValues[GetFieldAt0x50((Struct020865b0*)entry)];
        PartyMember_SetVocation((unsigned char*)appearance, GetFieldAt0x50((Struct020865b0*)entry));
        self->step++;
    }
    if (arg0->unknown_4bc_ == 2) {
        Struct_02015438** var17 = (Struct_02015438**)var3->unknown_ptr_array_36fc[1];
        func_020466e4((unsigned int*)func_020d6c00(), 0x41);
        if (func_02046b24(var17) != 0x13) {
            arg0->unknown_4bc_++;
        }
    }
    if (arg0->unknown_4bc_ == 3) {
        if (func_0202b7d8((int*)func_0202ae18()) != 0) {
            func_ov017_021cc340(arg0->unknown_4a2_, 1, -1);
            for (int var18 = 0; var18 < 13; var18++) {
                func_ov017_021cf078(arg0->unknown_4a2_, (unsigned char)var18, 0);
            }
            func_ov017_021cc97c(arg0->unknown_4a2_);
            func_ov017_021cca5c(arg0->unknown_4a2_, 0);
            func_ov017_021cca5c(arg0->unknown_4a2_, 1);
            func_ov017_021ccb58(arg0->unknown_4a2_, 1);
            func_ov017_021ccb58(arg0->unknown_4a2_, 4);
            func_ov017_021ccb58(arg0->unknown_4a2_, 7);
            func_ov017_021ccb58(arg0->unknown_4a2_, 10);
        }
        func_0206e424(func_0205ec34(), arg0->unknown_4a2_);
        var2->GetPartyMemberByIndex(arg0->unknown_4a2_);
        Struct_ov003_02166a90_4* var19 = (Struct_ov003_02166a90_4*)func_0205ec34();
        func_0206df6c(var19, var19->unknown_8c_, 0x784, 1);
        arg0->unknown_4bc_ = 0;
        func_020466f4((Struct_02038598_4*)func_020d6c00(), 0x41);
        func_ov017_02191234((unsigned char*)var3);
        if (var1 != 0) {
            func_020dc2d0(0);
        }
        func_ov017_02191108(var3, 1, 1, 1, 1);
        func_020dc7e8(6, -1);
        func_020dc7e8(7, -1);
        int* var20 = (int*)func_0202ae18();
        if (var20 != 0 && func_0202b7d8(var20) != 0) {
            func_ov017_021d0dbc();
        }
        if (func_0202b7d8((int*)func_0202ae18()) != 0) {
            func_ov017_021cee78(arg0->unknown_4a2_, 1);
        }
        return 1;
    }
    return 0;
}
