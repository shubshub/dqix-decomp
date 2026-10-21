#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02011b24;
struct Struct_02093428_5;

extern "C" void func_02012fe4();
extern "C" int func_020457e0(char* g);
extern "C" void func_020531f0(GameObject* c);
extern "C" void func_02043124(char* g);
extern "C" void func_020945ac(struct Ctx0209459c* ctx);
void ClearSubstructBytes_0200fb40(void* obj);
void ReinitController02043204(char* obj);
void ResetAndEnableFieldFlag_02011b24(struct FieldFlagBlock* obj);
void ClearFieldKeepBit0x10_02011af0(void* obj);
void InitAndInsertNode_021acd30(char* self, unsigned char a, unsigned char b, unsigned char c);
void EnqueueEventTag57WithAB_021cf4b0(int a, int b);
void EnqueueEventTag173_021d1810(int, int, signed char);
int GetField0x3acValue_020100a8(GameState* gs);
int* GetGlobal02109030_020936f8(void);
char* GetGlobalField0x1c020421a0(void);
int CheckSubstructByte0x7cPositive_020535c8(signed char* p);

struct Struct_02093428_6 {
    char unknown_0_[0x30];
    short unknown_30_;
    char unknown_32_[0x34 - 0x32];
    unsigned char unknown_34_;
    unsigned char unknown_35_;
};

struct Struct_02093428 {
    char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
};

struct Struct_02093428_2 {
#if defined(jpn)
    char unknown_0_[0x868];
#else
    char unknown1_0_[0x998];
#endif
    int unknown_998_;
    char unknown_99c_[0x9a0 - 0x99c];
    int unknown_9a0_;
};

struct Struct_02093428_3 {
#if defined(jpn)
    char unknown_0_[0x7ca0];
#else
    char unknown1_0_[0x7f74];
#endif
    unsigned char unknown_7f74_;
    unsigned char unknown_7f75_;
};

struct Struct_02093428_4 {
    char unknown_0_[0xbe];
    unsigned char unknown_be_;
#if defined(jpn)
    char unknown_bf_[0x1a6 - 0xbf];
#else
    char unknown1_bf_[0x1b2 - 0xbf];
#endif
    unsigned short unknown_1b2_;
};

// USA: func_02093428
extern "C" ARM void func_02093428(struct Struct_02093428_6* arg0) {
    GameState* var0 = GameState::GetInstance();
    char* var1 = func_020421a0();
    func_02012fe4();
    unsigned char var2 = func_020100a8(var0);
    unsigned char var3 = arg0->unknown_35_;

    if (var3 == 0) {
        struct Struct_02093428* var4 = (struct Struct_02093428*)func_02010828(var0);
        unsigned char var5 = var4->unknown_f7c_;
        for (unsigned char var6 = 0; var6 < var5; var6++) {
            GameObject* var7 = func_0200ff1c(var0, var4->unknown_f78_[var6]);
            if (var7 != 0 && func_020535c8((signed char*)var7) != 0) {
                func_020531f0(var7);
            }
        }
        arg0->unknown_30_ = 10;
        arg0->unknown_35_++;
        return;
    }

    if (var3 == 1) {
        if (((struct Struct_02093428_3*)var0)->unknown_7f74_ == 0) {
            arg0->unknown_35_ = 3;
            return;
        }
        if (((struct Struct_02093428_2*)var1)->unknown_9a0_ != 0) return;
        int var8 = func_020457e0(var1);
        if (var8 == 0) {
            arg0->unknown_35_++;
            return;
        }
        if (var8 != 1) return;
        arg0->unknown_30_ = 3;
        arg0->unknown_35_ = 4;
        func_ov017_021cf4b0(var2, 3);
        func_ov017_021d1810(10000, -1, (signed char)func_020100a8(var0));
        return;
    }

    if (var3 == 2) {
        if (((struct Struct_02093428_3*)var0)->unknown_7f74_ == 0) {
            arg0->unknown_30_ = 11;
            arg0->unknown_35_ = 4;
            return;
        }
        func_ov017_021cf4b0(var2, 2);
        unsigned char var9 = 0;
        GameObject* var10 = func_0200ff1c(var0, 0);
        if (var10 != 0) {
            if (((struct Struct_02093428_4*)var10)->unknown_be_ == 2 || var10->obj3D_.GetField06() == 0x170c) {
                unsigned short var11 = ((struct Struct_02093428_4*)var10)->unknown_1b2_;
                if (var11 != 0) {
                    if (var11 >= 1 && var11 <= 0x7fff) {
                        var9 = 1;
                    } else if (var11 >= 0x8005 && var11 <= 0x83ed) {
                        var9 = 1;
                    }
                }
            }
        }
        InitAndInsertNode_021acd30((char*)bs->GetResources(), 1, flag, 0);
        ClearFieldKeepBit0x10_02011af0(bs);
        if (((struct GameStateFlags02093428*)bs)->field7f75 != 0) {
            ResetAndEnableFieldFlag_02011b24((struct FieldFlagBlock*)bs);
        }
        func_020945ac((struct Struct_02093428_5*)func_020936f8());
        arg0->unknown_34_ = 4;
        arg0->unknown_35_ = 0;
        return;
    }

    if (var3 == 3) {
        func_02043204(var1);
        func_02043124(var1);
        func_020945ac((struct Struct_02093428_5*)func_020936f8());
        arg0->unknown_34_ = 4;
        arg0->unknown_35_ = 0;
        func_0200fb40(var0);
        return;
    }

    if (var3 == 4) {
        if (((struct Struct_02093428_2*)var1)->unknown_998_ == 0) {
            arg0->unknown_35_ = 3;
        }
    }
}
