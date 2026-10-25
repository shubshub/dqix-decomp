#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02011b24;
struct Struct_02093428_5;

extern "C" void Zone3D_GetInstance();
extern "C" int func_020457e0(char* g);
extern "C" void func_020531f0(GameObject* c);
extern "C" void MessageSystem_Stop(char* g);
extern "C" void func_020945ac(struct Ctx0209459c* ctx);
void ClearSubstructBytes_0200fb40(void* obj);
void MessageSystem_Reset(char* obj);
void ResetAndEnableFieldFlag_02011b24(struct FieldFlagBlock* obj);
void ClearFieldKeepBit0x10_02011af0(void* obj);
void InitAndInsertNode_021acd30(char* self, unsigned char a, unsigned char b, unsigned char c);
void EnqueueEventTag57WithAB_021cf4b0(int a, int b);
void EnqueueEventTag173_021d1810(int, int, signed char);
int GameState_GetProtagonistIndex(GameState* gs);
int* GetGlobal02109030_020936f8(void);
char* MessageSystem_GetInstance(void);
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
extern "C" ARM void func_02093428(struct BattlePhaseState02093428* s) {
    GameState* bs = GameState::GetInstance();
    char* gf = MessageSystem_GetInstance();
    Zone3D_GetInstance();
    unsigned char v = GameState_GetProtagonistIndex(bs);
    unsigned char state = s->field35;

    if (state == 0) {
        struct CombatantIndexList02093428* list = (struct CombatantIndexList02093428*)GameState_GetParty(bs);
        unsigned char count = list->count;
        for (unsigned char i = 0; i < count; i++) {
            GameObject* c = GetCombatantWithFlag0x100_0200ff1c(bs, list->entries[i]);
            if (c != 0 && CheckSubstructByte0x7cPositive_020535c8((signed char*)c) != 0) {
                func_020531f0(c);
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
        if (r != 1) return;
        s->field30 = 3;
        s->field35 = 4;
        EnqueueEventTag57WithAB_021cf4b0(v, 3);
        EnqueueEventTag173_021d1810(10000, -1, (signed char)GameState_GetProtagonistIndex(bs));
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

    if (state == 3) {
        MessageSystem_Reset(gf);
        MessageSystem_Stop(gf);
        func_020945ac((struct Ctx0209459c*)GetGlobal02109030_020936f8());
        s->field34 = 4;
        s->field35 = 0;
        ClearSubstructBytes_0200fb40(bs);
        return;
    }

    if (var3 == 4) {
        if (((struct Struct_02093428_2*)var1)->unknown_998_ == 0) {
            arg0->unknown_35_ = 3;
        }
    }
}
