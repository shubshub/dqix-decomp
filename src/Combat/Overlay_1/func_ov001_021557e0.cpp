#include <globaldefs.h>
#include "Combat/ActorAction.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

// USA: func_ov001_021557e0

extern "C" int func_ov001_02153994(void);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* obj);
extern "C" int func_0202c508(void* obj);
void* GetData02153637_020e2ff8(void);
struct Flags02033fcc;
void SetFlag0x4At0xe0(struct Flags02033fcc* obj);
unsigned char GetByte0x26c_02039d7c(char* obj);
void ClearBytesAndZeroBlock02039d24(unsigned char* obj);
int GameState_GetProtagonistIndex(GameState* battleStruct);
struct Base02010834;
void CopyCountedBytesToIntArray02010834(struct Base02010834* base, int index, int* out, int* outCount);
void ClearFlag0x1ceBit0x4_02039d58(unsigned char* obj);
void* GlobalFlags_GetInstance(void);
void* GameState_GetParty(GameState* battleStruct);
struct ArrayContainsByteStruct;
int ArrayContainsByte_02086ef0(struct ArrayContainsByteStruct* s, int val);
struct T0205420c;
void MaybeCall0205420c(struct T0205420c* obj, int a, int b);
void DispatchOrSetupCombatant_02191f4c(int a, int b);
extern "C" void func_ov017_02192400(int a, int b);
void FlagWord_SetBits(unsigned int* p, unsigned int mask);
int CheckField0NonZero_0202b7d8(int* obj);
unsigned char GameState_GetLeaderIndex(GameState* battleStruct);
extern "C" void func_ov017_021917f0(int a, int b);
void StoreInFirstEmptySlot_020e3368(unsigned char* base, unsigned char val);
struct Self02154de4;
int ProcessAndDispatchState_02154de4(struct Self02154de4* self);

#if defined(jpn)
#define data_ov001_02164bd1 data_ov001_02166171
#endif
extern const char data_ov001_02164bd1[];

#if defined(jpn)
#define COMBATANT_FLAGS_021557e0 0x180
#else
#define COMBATANT_FLAGS_021557e0 0x18c
#endif

struct Struct_ov001_021557e0 {
    char unknown_0_[0xc1];
    unsigned char unknown_c1_0_ : 2;
    char unknown_c2_[0x130 - 0xc2];
    unsigned int* unknown_130_;
    char unknown_134_[COMBATANT_FLAGS_021557e0 - 0x134];
    unsigned int unknown_18c_;
};

struct Struct_ov001_021557e0_2 {
    char unknown_0_[0xa];
    unsigned short unknown_a_;
    char unknown_c_[0x12 - 0xc];
    unsigned char unknown_12_;
    char unknown_13_[0x50 - 0x13];
    unsigned short unknown_50_;
#if defined(jpn)
    char unknown_52_[0xf4 - 0x52];
#else
    char unknown1_52_[0xf8 - 0x52];
#endif
    unsigned int unknown_f8_0_ : 27;
    unsigned int unknown_fb_3_ : 5;
    char unknown_fc_[0x101 - 0xfc];
    unsigned char unknown_101_;
    char unknown_102_[0x103 - 0x102];
    unsigned char unknown_103_;
    char unknown_104_[0x116 - 0x104];
    signed char unknown_116_;
};

extern "C" ARM int func_ov001_021557e0(struct Struct_ov001_021557e0_2* arg0) {
    GameResources* var0 = GetGameResources();
    if (IsBrightnessOutsideValidRange((GameResources*)var0, false) != 0) {
        arg0->unknown_101_ = 1;
    }
    if (func_ov001_02153994() != 1) {
        return arg0->unknown_a_;
    }

    void* var1 = func_0202ae18();
    GameState* var2 = GameState::GetInstance();

    if (arg0->unknown_12_ != 0 && func_0202c540(var1) != 0) {
        arg0->unknown_103_ = 1;
        if (arg0->unknown_f8_0_ & 0x10) {
            GameObject* var3 = func_0200ff1c(var2, 0);
            ((unsigned int*)((char*)var3 + COMBATANT_FLAGS_021557e0))[0] |= 2;
        }
    }

    if (arg0->unknown_101_ != 0) {
        for (int var4 = 0; var4 < 4; var4++) {
            GameObject* var5 = var2->GetPartyMemberByIndex(var4);
            if (var5 == 0) {
                continue;
            }
            SetFlag0x4At0xe0((struct Flags02033fcc*)m);
            if (GetByte0x26c_02039d7c((char*)m) == 0 || GetFieldPtrAt0x26c_020399a8(m)->command != 2) {
                m->obj3D_.SetAnimationByName(data_ov001_02164bd1, 0x10);
            }
            func_02039d24((unsigned char*)var5);
            var5->obj3D_.EnableFlag(0x800000);
        }

        int list[4];
        int count;
        CopyCountedBytesToIntArray02010834((struct Base02010834*)bs, GameState_GetProtagonistIndex(bs), list, &count);
        for (int j = 0; j < count; j++) {
            GameObject* m = bs->GetPartyMemberByIndex(list[j]);
            if (m == 0) {
                continue;
            }
            var9->obj3D_.SetInheritedAlpha(0x1f);
            func_02039d58((unsigned char*)var9);
        }

        unsigned int* data = (unsigned int*)GlobalFlags_GetInstance();
        void* arr = GameState_GetParty(bs);
        for (int k = 0; k < 4; k++) {
            struct Combatant021557e0* c = (struct Combatant021557e0*)GetCombatantWithFlag0x100_0200ff1c(bs, k);
            if (c == 0) {
                continue;
            }
            if (func_02086ef0((struct Struct_02048150*)var11, var12) != 0) {
                func_0205420c((struct Struct_0205420c*)var13, 1, 0);
            }
            func_ov017_02191f4c((int)var0, var12);
            func_ov017_02192400((int)var0, var12);
        }
        FlagWord_SetBits(data, 0x20000);
    }

    if (CheckField0NonZero_0202b7d8((int*)search) != 0 && self->f12 != 0 && self->f116 < 0) {
        if (self->f101 != 0) {
            int limit = GameState_GetLeaderIndex(bs);
            for (int n = 0; n < 4; n++) {
                if (n == limit) {
                    continue;
                }
                struct Struct_ov001_021557e0* var16 = (struct Struct_ov001_021557e0*)func_0200ff1c(var2, var15);
                if (var16 == 0) {
                    continue;
                }
                var16->unknown_c1_0_ |= 1;
                var16->unknown_c1_0_ |= 2;
                func_ov017_021917f0(var15, 0);
                if (!(*var16->unknown_130_ & 1)) {
                    var16->unknown_18c_ |= 2;
                }
            }
        }
    } else if (arg0->unknown_116_ >= 0) {
        struct Struct_ov001_021557e0* var17 = (struct Struct_ov001_021557e0*)func_0200ff1c(var2, arg0->unknown_116_);
        if (var17 != 0) {
            var17->unknown_c1_0_ |= 1;
            var17->unknown_c1_0_ |= 2;
            var17->unknown_18c_ |= 2;
            func_ov017_021917f0(arg0->unknown_116_, 0);
        }
    }

    SetFlags04(var0, 0x1000);

    if (arg0->unknown_50_ & 0x200) {
        volatile unsigned int* var18 = (volatile unsigned int*)0x4000000;
        *var18 = (*var18 & ~0x1f00) | 0x1100;
    }

    if ((arg0->unknown_f8_0_ & 0x10) && func_0202c508(var1) != 0) {
        func_020e3368((unsigned char*)func_020e2ff8(), 1);
        return 0x12;
    }
    return func_ov001_02154de4((struct Struct_ov001_02154de4*)arg0);
}
