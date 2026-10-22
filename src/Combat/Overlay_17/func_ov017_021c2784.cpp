#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Resource/TextQueue.h"

#if defined(jpn)
extern "C" int sprintf(char* arg0, const char* arg1, ...);
extern "C" void func_020d7e10(void* arg0, void* arg1, int arg2, int arg3, unsigned char arg4);
extern "C" char data_ov017_021d70e0[];
extern "C" char data_ov017_021d7108[];
enum { Enum_ov017_021c2784_17128 = 0x40c8, Enum_ov017_021c2784_10132 = 0x27d4 };
#else
enum { Enum_ov017_021c2784_17128 = 0x42e8, Enum_ov017_021c2784_10132 = 0x2794 };
#endif

struct Struct_0202b2f0;
extern "C" struct Struct_0202b2f0* func_0202ae18(void);
extern "C" int func_0202c508(struct Struct_0202b2f0* arg0);
extern "C" unsigned short* func_02012fe4(void);
extern "C" void func_02046608(void* arg0, int arg1, int arg2, void* arg3, int arg4, int arg5, int arg6);
extern "C" int func_ov017_021959b4(void);
extern "C" int func_ov017_021a23e4(char* arg0, int arg1, unsigned int arg2, unsigned int arg3);

extern "C" void* func_020d7a50(void);
extern "C" unsigned char func_020100b0(GameState* arg0);
extern "C" void* func_020421a0(void);
extern "C" void func_020e4bf4(void* arg0, int arg1);
extern "C" int func_020e51cc(int arg0);
extern "C" void func_0205ebc0(void* arg0, int arg1, int arg2);
extern "C" void func_0205ebfc(void* arg0, int arg1, int arg2);
extern "C" void func_020e1154(void* arg0);
struct Struct_02018300_3;
extern "C" void func_020397cc(struct Struct_02018300_3* arg0, int arg1);
struct Struct_020d7aa0_2;
extern "C" void func_020d7aa0(struct Struct_020d7aa0_2* arg0);
struct Struct_02059cfc_4;
struct Struct_ov008_021870e4;
extern "C" void func_0205ebec(void* arg0);
extern "C" void func_020397c0(void* arg0);
extern "C" int func_ov017_021a26e8(GameResources* arg0, int arg1);
extern "C" void func_ov017_021d09cc(int arg0, int arg1, int arg2, int arg3);
extern "C" GameObject* func_0200ffe0(GameState* arg0, int arg1);

extern int g_sePlayer;

struct Struct_ov017_021c2784 {
    unsigned char unknown_0_[0x1];
    unsigned char unknown_1_;
    unsigned char unknown_2_[0x6];
    unsigned short unknown_8_;
    unsigned char unknown_a_[0x2];
    int unknown_c_;
    unsigned char unknown_10_;
    unsigned char unknown_11_;
    unsigned short unknown_12_;
    int unknown_14_;
    int unknown_18_;
};

// USA: func_ov017_021c2784
extern "C" ARM void func_ov017_021c2784(Struct_ov017_021c2784* arg0) {
    GameState* var0 = GameState::GetInstance();
    GameResources* var1 = GetGameResources();
    struct Struct_0202b2f0* var2 = func_0202ae18();
    void* var3 = func_020d7a50();

    GameObject* var4 = var0->GetPartyMemberByIndex(arg0->unknown_14_);
    int var5 = func_020100b0(var0);
    GameObject* var6 = var0->GetPartyMemberByIndex(var5);
    if (!var4 || !var6) {
        arg0->unknown_1_ = 1;
    }
    if (func_ov017_021959b4()) {
        arg0->unknown_1_ = 1;
        return;
    }

    if (arg0->unknown_10_ == 0) {
        *(unsigned char*)((char*)var1 + Enum_ov017_021c2784_17128) = 1;
        func_020397cc((struct Struct_02018300_3*)var6, 1);
        *(unsigned short*)((char*)var6 + 0xb2) = 0;
        if (arg0->unknown_11_ != 0) {
            arg0->unknown_8_ = 0;
        } else {
#if defined(jpn)
            char var7[0x50];
            sprintf(var7, data_ov017_021d70e0, *(char**)((char*)var4 + 0x134));
            func_020d7e10(var3, var7, 0, 0, 1);
#else
            void* var8 = func_020421a0();
            char var9[0xc];
            char var10[0x50];
            func_020e4bf4(var9, arg0->unknown_14_);
            *(void**)var8 = var9;
            int var11 = func_020e51cc(0x26);
            func_02046608(var8, 0xc, var11, var10, 0xe3, 0, 1);
            func_020d7e10(var3, var10, 0, 0, 1, 1);
#endif
            SetForwardAndStore0205ebc0(&g_sePlayer, 0x79, 0x79);
            DispatchIfField0xc4NonNeg_0205ebfc(&g_sePlayer, 0, 0);
            obj->field8 = 0x3e8;
        }
        arg0->unknown_10_ = 1;
        return;
    } else if (arg0->unknown_10_ == 1) {
        unsigned int var12 = (unsigned int)var0->GetEffectiveDeltaTime();
        if (var12 < arg0->unknown_8_) {
            arg0->unknown_8_ -= var12;
            return;
        }
        arg0->unknown_8_ = (arg0->unknown_11_ != 0) ? 0x64 : 0x384;

        unsigned short* var13 = func_02012fe4();
        if (*var13 == 0x2710) {
            *(int*)((char*)var13 + Enum_ov017_021c2784_10132) = 0;
            func_020e1154((void*)0x7d0);
            arg0->unknown_10_ = 5;
            return;
        }
        if (func_0202c508(var2)) {
            int var14 = func_020100b0(var0);
            int var15 = func_ov017_021a23e4((char*)var1, var14, 0, arg0->unknown_18_);
            arg0->unknown_12_ = (unsigned short)var15;
            if (arg0->unknown_12_ != 0) {
                arg0->unknown_10_ = 5;
                return;
            }
            arg0->unknown_10_ = 2;
            return;
        }
        int var16 = func_020100b0(var0);
        int var17 = func_ov017_021a26e8(var1, var16);
        func_ov017_021d09cc(0, 0, var17, arg0->unknown_18_);
        arg0->unknown_10_ = 4;
        return;
    } else if (arg0->unknown_10_ == 2) {
        int var18;
        if (arg0->unknown_11_ != 0) {
            var18 = 0;
        } else {
            func_020d7aa0((struct Struct_020d7aa0_2*)var3);
#if defined(jpn)
            func_020d7e10(var3, data_ov017_021d7108, 0, 0, 1);
#else
            int var19 = func_020e51cc(0x27);
            func_020d7e10(var3, (void*)var19, 0, 0, 1, 1);
#endif
            var18 = 0xbb8;
        }
        arg0->unknown_8_ = var18;
        arg0->unknown_10_ = 3;
        return;
    } else if (arg0->unknown_10_ == 3) {
        unsigned int var20 = (unsigned int)var0->GetEffectiveDeltaTime();
        if (var20 < arg0->unknown_8_) {
            arg0->unknown_8_ -= var20;
            return;
        }
        GameObject* var21 = var0->GetMaybeFieldMonsterByIndex(arg0->unknown_c_);
        if (arg0->unknown_c_ > 0 && var21 != NULL) {
            if (((Object3D*)((struct Struct_02059cfc_4*)var21))->HasAnimationStopped() == 0) {
                if (((Object3D*)((struct Struct_ov008_021870e4*)var21))->HasAnimationReachedEnd() == 0) {
                    return;
                }
            }
        }
        ForwardField0xc0_0205ebec(&g_sePlayer);
        SetByteField0x253_020397c0(c);
        obj->field1 = 1;
        return;
    } else if (arg0->unknown_10_ == 4) {
        unsigned int var22 = (unsigned int)var0->GetEffectiveDeltaTime();
        if (var22 < arg0->unknown_8_) {
            arg0->unknown_8_ -= var22;
            return;
        }
        arg0->unknown_8_ = 0;
        return;
    } else if (arg0->unknown_10_ == 5) {
        GameObject* var23 = func_0200ffe0(var0, arg0->unknown_12_);
        if (arg0->unknown_12_ != 0) {
            if (var23 == NULL) {
                return;
            }
            arg0->unknown_c_ = var23->obj3D_.unknown_4_;
        }
        *(unsigned char*)((char*)var6 + 0xc3) = 0;
        arg0->unknown_10_ = 3;
    }
}
