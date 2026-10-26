#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define data_ov025_021ef538 data_ov025_021ef818
#define data_ov025_021ef8de data_ov025_021efba0
#endif

struct Struct_02078398_2 {
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
    short unknown_12_;
    short unknown_14_;
    short unknown_16_;
    short unknown_18_;
    short unknown_1a_;
    short unknown_1c_;
    short unknown_1e_;
    int unknown_20_; int unknown_24_; int unknown_28_; int unknown_2c_; int unknown_30_;
    int unknown_34_; int unknown_38_; int unknown_3c_; int unknown_40_;
    int unknown_44_; int unknown_48_; int unknown_4c_;
};

struct Struct_ov025_021e9778_7 {
    int unknown_0_;
    struct Struct_ov025_021e9778_7* unknown_4_;
};

struct Struct_ov025_021e9778_8 {
    unsigned short unknown_0_;
    unsigned char unknown_2_[8];
    unsigned char unknown_a_;
};

struct Struct_ov000_0215440c_2;
struct Struct_ov000_02160094;
struct Struct_ov025_021e9778_9;
struct Struct_ov025_021e9778;
struct Struct_ov025_021e9778_2;
struct Struct_ov025_021e9778_3;
struct Struct_ov025_021e9778_4;
struct Struct_ov025_021e9778_5;
struct Struct_ov025_021e9778_6 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int unknown_2_0_ : 16;
};

typedef int (*Type_02000c9c_17)(struct Struct_ov025_021e9778_7*, struct Struct_ov025_021e9778_8*, void*, int);

void* GetActiveCombatWork_ov000_02160130(void);
void* GetOffsetPtr02160f00(void* obj);
void* GetSlotPtr02160f20(void* obj);
ListNode02160094* GetNodeAtIndex02160094(List02160094* list, int index);
void InitStruct02078484(InitStruct02078484Struct* p);
extern "C" void* func_ov000_02160f14(void* obj);
void Camera_Shake(unsigned char* obj, int a, int b);
short ClampScaledStat_0216352c(int id, float a, float b);
void FindNodeAndProcess02057fb4(void* list, int id, void* argument);
extern "C" void* func_02057924(void);
extern "C" GameObject* func_0200fea4(GameState* arg0, int arg1);
extern "C" void func_ov025_021eb6fc(Struct_ov025_021e9778_9* arg0, int arg1);
extern "C" int func_ov025_021eb46c(Struct_ov025_021e9778* arg0);
extern "C" int func_ov025_021eb204(Struct_ov025_021e9778_2* arg0);
extern "C" void func_ov025_021e9b2c(Struct_ov025_021e9778_3* arg0);
extern "C" void func_ov025_021ebb90(Struct_ov025_021e9778_4* arg0);
extern "C" void func_ov025_021e9a94(Struct_ov025_021e9778_5* arg0);
extern "C" char* strcpy(char* arg0, const char* arg1);

extern void* data_ov025_021ef994;
extern Type_02000c9c_17 data_ov025_021ef538[];
extern unsigned int data_ov025_021ef9a4;
extern char data_ov025_021ef8de[];

// USA: func_ov025_021e9778
extern "C" ARM void func_ov025_021e9778(void* arg0) {
    unsigned char* var0 = (unsigned char*)arg0;
    GameState* var1 = GameState::GetInstance();
    void* var2 = func_ov000_02160130();
    void* var3 = func_ov000_02160f00(var2);
    struct Struct_ov025_021e9778_8* var4 = (struct Struct_ov025_021e9778_8*)func_ov000_02160f20(var2);
    data_ov025_021ef994 = arg0;
    if ((*(unsigned short*)(var0 + 0x5ce)) != 0) {
        unsigned int var5 = var1->GetEffectiveDeltaTime();
        if (var5 < (unsigned int)(*(unsigned short*)(var0 + 0x5ce))) {
            (*(unsigned short*)(var0 + 0x5ce)) = (unsigned short)((*(unsigned short*)(var0 + 0x5ce)) - var5);
            return;
        }
        (*(unsigned short*)(var0 + 0x5ce)) = 0;
        func_ov025_021eb6fc((Struct_ov025_021e9778_9*)arg0, 0);
    }
    if ((*(unsigned char*)(var0 + 0x839)) == 0) {
        return;
    }
    if (func_ov025_021eb46c((Struct_ov025_021e9778*)arg0) != 0) {
        return;
    }
    if (func_ov025_021eb204((Struct_ov025_021e9778_2*)arg0) != 0) {
        return;
    }
    while ((*(Struct_ov025_021e9778_7**)(var0 + 0x4)) != 0) {
        int var6;
        if ((*(unsigned short*)(var0 + 0x57c)) != 0) {
            if ((*(Struct_ov025_021e9778_7**)(var0 + 0x4))->unknown_0_ == 0xa) {
                var6 = data_ov025_021ef538[(*(Struct_ov025_021e9778_7**)(var0 + 0x4))->unknown_0_]((*(Struct_ov025_021e9778_7**)(var0 + 0x4)), var4, var3, (*(int*)(var0 + 0xc)));
            } else {
                var6 = 1;
            }
        } else {
            if ((*(Struct_ov025_021e9778_7**)(var0 + 0x4))->unknown_0_ == 0xb) {
                var6 = 0;
                (*(Struct_ov025_021e9778_7**)(var0 + 0x4)) = 0;
            } else {
                var6 = data_ov025_021ef538[(*(Struct_ov025_021e9778_7**)(var0 + 0x4))->unknown_0_]((*(Struct_ov025_021e9778_7**)(var0 + 0x4)), var4, var3, (*(int*)(var0 + 0xc)));
            }
        }
        if (var6 == 0) {
            break;
        }
        if (var6 == -1) {
            (*(Struct_ov025_021e9778_7**)(var0 + 0x4)) = (*(Struct_ov025_021e9778_7**)(var0 + 0x4))->unknown_4_;
            break;
        }
        (*(Struct_ov025_021e9778_7**)(var0 + 0x4)) = (*(Struct_ov025_021e9778_7**)(var0 + 0x4))->unknown_4_;
    }
    func_ov025_021e9b2c((Struct_ov025_021e9778_3*)arg0);
    func_ov025_021ebb90((Struct_ov025_021e9778_4*)(var0 + 0x22c));
    data_ov025_021ef9a4 &= ~4;
    if ((*(int*)(var0 + 0x224)) != 0) {
        func_ov025_021e9a94((Struct_ov025_021e9778_5*)arg0);
    }
    if (*(void**)(var0 + 8) != NULL && ((Struct_ov025_021e9778_6*)((char*)*(void**)(var0 + 8) + 0x18))->unknown_1_4_ == 2) {
        int var7 = *(unsigned short*)((char*)func_ov000_02160094((Struct_ov000_0215440c_2*)var4, 0) + 0x20);
        int var8 = 0;
        GameState* var9 = GameState::GetInstance();
        int var10 = (var7 >= 0xc0 && var7 <= 0xc7);
        if (var10 != 0) {
            GameObject* var11 = func_0200fea4(var9, var7);
            if (var11 != 0) {
                short var12 = var11->obj3D_.unknown_2_;
                if (var12 == 0x200 || (unsigned int)(var12 - 0x289) <= 4) {
                    var8 = 1;
                } else {
                    if (var12 == 0xb9 && var4->unknown_0_ == 0x247) {
                        var8 = 1;
                    }
                }
            }
        }
        if (flag == 0 && (data_ov025_021ef9a4 & 0x200) && !(data_ov025_021ef9a4 & 0x400)) {
            void* list = func_02057924();
            struct InitStruct02078484Struct s;
            InitStruct02078484(&s);
            s.f14 = *(unsigned short*)((char*)GetNodeAtIndex02160094((List02160094*)slot, 0) + 0x20);
            if (slot->kind & 1) {
                strcpy((char*)&s, data_ov025_021ef8de);
                unsigned char* p = (unsigned char*)func_ov000_02160f14(work);
                Camera_Shake(p, 0x199, 0x3e8);
            }
            int var16 = (var7 >= 0xc0 && var7 <= 0xc7);
            if (var16 != 0) {
                short var17 = func_ov000_0216352c(var7, 1.0f, 0.5f);
                var14.unknown_44_ = var17;
                var14.unknown_48_ = var17;
                var14.unknown_4c_ = var17;
            }
            func_02057fb4(var13, 4, &var14);
            data_ov025_021ef9a4 |= 0x400;
        }
    }
    data_ov025_021ef9a4 &= ~8;
}
