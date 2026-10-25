#include <globaldefs.h>
#include "Combat/CombatantRecovery.h"
#include "GameState/GameState.h"

struct Struct_02048150;
struct Struct_02038598_5;
struct Struct_020d805c;
struct Struct_020465c0;
struct Struct_02000c9c_62;
struct Struct_ov017_021d2d64_2 { unsigned char unknown_0_; unsigned short unknown_2_; unsigned char unknown_4_; };

struct Struct_ov017_021d2d64_3 {
    short unknown_0_0_ : 11;
    short unknown_1_3_ : 5;
};

struct Struct_ov017_021d2d64_4 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    signed char unknown_3_;
    signed char unknown_4_[3];
    signed char unknown_7_;
    Struct_ov017_021d2d64_3 unknown_8_[3];
    signed char unknown_e_;
};

struct Struct_ov017_021d2d64_5 {
    char unknown_0_[4];
    Struct_ov017_021d2d64_4 unknown_4_;
};

struct Struct_ov017_021d2d64_6 {
    Object3D unknown_0_;
    short unknown_ac_;
};

struct Struct_ov017_021d2d64_7 {
    char unknown_0_[0x150];
    unsigned char unknown_150_0_ : 6;
};

struct Struct_ov017_021d2d64_8 {
    char unknown_0_[0x59f];
    unsigned char unknown_59f_;
};

struct Struct_ov017_021d2d64_9 {
    char unknown_0_[0x1c];
    Struct_ov017_021d2d64_8* unknown_1c_;
};

struct Struct_ov017_021d2d64_10 {
    char unknown_0_[0x64];
    int unknown_64_;
};

struct Struct_ov017_021d2d64 {
    short unknown_0_[2];
};

struct Struct_ov017_021d6ce8_2 {
    char unknown_0_[0x18];
    Struct_ov017_021d2d64 unknown_18_;
};

int GameState_GetProtagonistIndex(GameState* gs);
void* GameState_GetParty(GameState* gameState);
extern "C" void func_ov017_021d2d00(void* dst, void* src);
void ClearFields0_2_4_021d35f8(Obj_021d35f8* obj);
extern "C" void* memset(void* dst, int c, unsigned int n);
int ArrayContainsByte_02086ef0(ArrayContainsByteStruct* s, int val);
int ListContainsId(ListHead02046b60* list, int id);
void* TextQueue_GetInstance(void);
int IsField0Null_02046b08(void** obj);
int CheckSubstructByte0x7cPositive_020535c8(signed char* obj);
int MessageSystem_GetInstance(void);
int GetByte0x150Bit6(BitFlags020d805c* obj);
int TestFlagBit55dIfActive_0218b628(signed char);
extern "C" void func_ov017_0218b5c0(int set, signed char bit);
void SetIndexedFieldsIfValid_02191ba0(char*, int, int);
void InitContext020e1154(void* obj);
int TryClearFlags0x130_02048418(unsigned char* obj, unsigned short flag);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" void __clear(void* dst, unsigned int size);
int ComputeAndApplyWithCounter020e04f4(int p0, void* p1, int p2, int p3, unsigned char p4, int p5);
extern "C" void func_02046380(void* g);
void Clear12Bytes020e46c4(void* p);
void NameText_InitFromPartyMember(void* obj, int combatantId);
void SetByteInRange_020465f0(unsigned char* base, int index, unsigned char value);
void StoreInArray0x8b0_020465c0(StoreStruct* base, int index, int value);
extern "C" void MessageSystem_FormatText(void* g, int mode, char* fmt, char* out, int size, int a, int b);
extern "C" void TextQueue_Push(void* receiver, void* input, int style, int flag, int a, int b);
void EnqueueEventTag37_021d2cc0(void* src);
void CallHelperIfFlag_021a5a88(int a, int b, int c, int d, unsigned char e);

extern const Struct_ov017_021d6ce8_2 data_ov017_021d6ce8;
extern char data_ov017_021d8298[];
extern char data_ov017_021d8288[];

// USA: func_ov017_021d2d64
extern "C" ARM void func_ov017_021d2d64(void* unused, Msg021d2d64* msg, GameState* gs, GameResources* res) {
    void* g;
    int v3ac;
    ArrayContainsByteStruct* party;
    Reset021d2d64* reset;
    int saved;
    ListHead02046b60* list;
    short msgId;
    Entry021d2d64* entry = &msg->entry;
    v3ac = GameState_GetProtagonistIndex(gs);
    party = (ArrayContainsByteStruct*)GameState_GetParty(gs);
    Entry021d2d64 local;
    Obj_021d35f8 slotsA[4];
    Obj_021d35f8 slotsB[4];
    func_ov017_021d2d00(&local, entry);
    unsigned char count = local.count;
    signed char* ids = local.ids;
    for (int i = 0; i < 4; i++) {
        ClearFields0_2_4_021d35f8(&slotsA[i]);
        ClearFields0_2_4_021d35f8(&slotsB[i]);
    }
    int var14 = (int)arg3->unknown_ptr_array_371c[0];

    switch (var7->unknown_0_) {
    case 1: {
        var8.unknown_7_ = 0;
        memset(var8.unknown_4_, 0, 3);
        memset(var8.unknown_8_, 0, 6);
        signed char var15 = 0;
        for (int var16 = 0; var16 < var7->unknown_7_; var16++) {
            int var17 = var7->unknown_4_[var16];
            if (func_02086ef0(var2, var17) != 0) {
                var8.unknown_4_[var15] = var17;
                Struct_ov017_021d2d64_3* var18 = &var8.unknown_8_[var15];
                var18->unknown_0_0_ = var7->unknown_8_[var16].unknown_0_0_;
                var18->unknown_1_3_ = var7->unknown_8_[var16].unknown_1_3_;
                var15++;
            }
        }
        var8.unknown_7_ = var15;
        if (var8.unknown_7_ == 0) {
            return;
        }

        list = (ListHead02046b60*)res->fieldTaskQueue_;
        int ok = 1;
        if (ListContainsId(list, 10)) ok = 0;
        if (ListContainsId(list, 3)) ok = 0;
        if (ListContainsId(list, 0x27)) ok = 0;
        if (ListContainsId(list, 0x10) && ((Owner021d2d64*)res->unknown_ptr_array_371c[4])->flags != 0 &&
            (((Owner021d2d64*)res->unknown_ptr_array_371c[4])->flags->flags & 4)) {
            ok = 0;
        }

        if (ok) {
            reset = (Reset021d2d64*)TextQueue_GetInstance();
            ok = 1;
            if (IsField0Null_02046b08((void**)list) == 0) ok = 0;
            if (ListContainsId(list, 0x1a)) ok = 1;
            GameObject* leader = gs->GetUnknownGameObject();
            if (leader != 0 && CheckSubstructByte0x7cPositive_020535c8((signed char*)leader)) ok = 0;
            if (*(int*)(MessageSystem_GetInstance() + 0x998) != 0 && GetByte0x150Bit6((BitFlags020d805c*)reset) == 0) ok = 0;

            for (int var21 = 0; var21 < var8.unknown_7_; var21++) {
                if (var3->unknown_150_0_ >= 3) var19 = 0;
                int var22 = var8.unknown_4_[var21];
                Struct_ov017_021d2d64 var23 = data_ov017_021d6ce8.unknown_18_;
                GameObject* var24 = func_0200ff1c(arg2, var22);
                if (var24 == 0) continue;
                var4 = func_ov017_0218b628(var22);
                if (var19) func_ov017_0218b5c0(0, var22);
                Struct_ov017_021d2d64_3* var25 = &var8.unknown_8_[var21];
                int var26 = 0;
                if (var8.unknown_1_ == 1) {
                    int var27 = var24->baseStats_->primaryStats.maxHP;
                    int var28 = var24->unknown_ac_.unknown_84_->unknown_4_;
                    int var29 = var28 + var25->unknown_0_0_;
                    int var30;
                    if (var29 >= var27) {
                        var30 = var27 - var28;
                    } else {
                        var30 = var29 - var28;
                    }
                    var24->unknown_ac_.unknown_84_->unknown_4_ = var28 + var30;
                    var25->unknown_0_0_ = var30;
                    if (var30 > 0) {
                        var23.unknown_0_[0] = 0x232c;
                        var26 = 1;
                    }
                } else if (var8.unknown_1_ == 2) {
                    int var31 = var24->baseStats_->primaryStats.maxMP;
                    int var32 = var24->unknown_ac_.unknown_84_->unknown_6_;
                    int var33 = var32 + var25->unknown_0_0_;
                    int var34;
                    if (var33 >= var31) {
                        var34 = var31 - var32;
                    } else {
                        var34 = var33 - var32;
                    }
                    var24->unknown_ac_.unknown_84_->unknown_6_ = var32 + var34;
                    var25->unknown_0_0_ = var34;
                    if (var34 > 0) {
                        var23.unknown_0_[0] = 0x795f;
                        var26 = 1;
                    }
                } else if (local.type == 4) {
                    int canRevive = 1;
                    if (ListContainsId(list, 0x1a) && ((Revive021d2d64*)res->fieldTasks_[4])->busy != 0) {
                        canRevive = 0;
                    }
                    if ((int)var24->unknown_ac_.unknown_84_->unknown_4_ > 0 || var25->unknown_0_0_ == 0 || var35 == 0) {
                        var25->unknown_0_0_ = 0;
                    } else {
                        Struct_ov017_021d2d64_6* var36 = (Struct_ov017_021d2d64_6*)arg2->GetUnknownGameObject();
                        if (var36 != 0 && (var36->unknown_ac_ != 0 || var36->unknown_0_.GetFlag(0x8000000) != 0)) {
                            func_ov017_02191ba0((char*)arg3, var22, var25->unknown_0_0_);
                            var26 = 0;
                        } else {
                            func_02053fe4(var24, var25->unknown_0_0_, 1);
                            if (var24->baseStats_->primaryStats.maxHP < var25->unknown_0_0_) {
                                var25->unknown_0_0_ = var24->baseStats_->primaryStats.maxHP;
                            }
                            var26 = 1;
                            if (func_02046b60(var5, 0x1a)) {
                                func_020e1154((void*)0x1f4);
                            }
                            var23.unknown_0_[0] = 0x7955;
                        }
                    }
                } else if (var8.unknown_1_ == 3) {
                    if (func_02048418((unsigned char*)var24, 2) == 0) {
                        var25->unknown_0_0_ = 0;
                    } else {
                        var25->unknown_0_0_ = 1;
                        var23.unknown_0_[0] = 0x794b;
                        var26 = 1;
                    }
                }
                if (var8.unknown_2_ == 3) {
                    if (func_02048418((unsigned char*)var24, 2) == 0) {
                        var25->unknown_1_3_ = 0;
                    } else {
                        var25->unknown_1_3_ = 1;
                        var23.unknown_0_[1] = 0x794b;
                        var26 = 1;
                    }
                }
                if (var26) {
                    func_ov017_021c9e00(var22, 0, 0, 1);
                }
                if (ok) {
                    for (int k = 0; k < 2; k++) {
                        if (reset->state >= 3) continue;
                        g = (void*)MessageSystem_GetInstance();
                        msgId = msgs.v[k];
                        if (msgId < 0) continue;
                        char text[0x100];
                        __clear(text, 0x100);
                        ComputeAndApplyWithCounter020e04f4((int)text, data_ov017_021d8288, msgId, 0, 1, (int)data_ov017_021d8298);
                        func_02046380(g);
                        char who[0xc];
                        Clear12Bytes020e46c4(who);
                        NameText_InitFromPartyMember(who, unit->obj3D_.actorIndex_);
                        *(char**)((char*)g + 0x10) = who;
                        SetByteInRange_020465f0((unsigned char*)g, 0, 0);
                        StoreInArray0x8b0_020465c0((StoreStruct*)g, 0, v->lo);
                        SetByteInRange_020465f0((unsigned char*)g, 9, 0);
                        StoreInArray0x8b0_020465c0((StoreStruct*)g, 9, unit->obj3D_.actorIndex_);
                        char out[0x80];
                        __clear(out, 0x80);
                        MessageSystem_FormatText(g, 0xc, text, out, 0xe3, 0, 1);
                        TextQueue_Push(reset, out, 0, 0, 1, 1);
                    }
                }
                if (!var19 || !var26) {
                    func_ov017_0218b5c0(var4, var22);
                }
            }
            var8.unknown_0_ = 2;
        } else {
            var8.unknown_0_ = 4;
            Struct_ov017_021d2d64_3* var41;
            for (int var42 = 0; var42 < 3; var42++) {
                var41 = var8.unknown_8_;
                var41[var42].unknown_0_0_ = 0;
                var41[var42].unknown_1_3_ = 0;
            }
        }
        var8.unknown_e_ = var1;
        func_ov017_021d2cc0(&var8);
        break;
    }
    case 2:
    case 3:
        for (int var43 = 0; var43 < var11; var43++) {
            Struct_ov017_021d2d64_3* var44 = &var8.unknown_8_[var43];
            int var45 = var43 * sizeof(Struct_ov017_021d2d64_2);
            int var46 = var44->unknown_0_0_;
            *(unsigned short*)((char*)var9 + 2 + var45) = var46;
            if (var46 > 0) {
                *((unsigned char*)var9 + var45) = 3;
            } else {
                *((unsigned char*)var9 + var45) = 0;
            }
            int var47 = var44->unknown_1_3_;
            *(unsigned short*)((char*)var10 + 2 + var45) = var47;
            if (var47 > 0) {
                *((unsigned char*)var10 + var45) = 3;
            } else {
                *((unsigned char*)var10 + var45) = 0;
            }
        }
        func_ov017_021a5a88(var14, (int)var12, (int)var9, (int)var10, var11);
        break;
    case 4:
        for (int var48 = 0; var48 < var11; var48++) {
            var9[var48].unknown_2_ = 0;
            var9[var48].unknown_0_ = 2;
            var10[var48].unknown_2_ = 0;
            var10[var48].unknown_0_ = 2;
        }
        func_ov017_021a5a88(var14, (int)var12, (int)var9, (int)var10, var11);
        break;
    }
}
