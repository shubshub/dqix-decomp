#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void __clear(void* buf, int size);
int CollectCombatantsWithFlag0x1000_02010038(GameState* battleStruct, unsigned char* out);
struct Obj02053f7c;
void SetField0x1b2IfMatchOrFlag02053f7c(Obj02053f7c*, unsigned short, int);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* search);
void EnqueueEventTag147_021cdaa0(void);
int CheckByteAtIndex_021c5bf8(int index, int key);
void MaybeResetEntry_021c5e28(int, int);
extern "C" void func_ov017_021c5a8c(int a, int key);
int IsValidCombatantValue_021c5a1c(int val);
void* GetData02108ea8_0207d78c(void);
extern "C" int func_0207d7f4(void* entries, unsigned short id, int charId, int flag,
                             signed char field4, unsigned short field2, unsigned char field5);
extern "C" int func_ov017_021c5c5c(int index, int id, int arg);
extern "C" void func_ov017_021c5b44(unsigned char arg0, int combatantId, unsigned int arg2, unsigned char arg3, unsigned char arg4);
extern "C" void func_0207dcf0(unsigned short id);
GameObject* FindCombatantByField16a_021a278c(void* base, int val);
void TrySetMode02076ccc(void* obj, int mode);
struct Event021c530c;
extern "C" Event021c530c* func_ov017_021b8478(void* node);
int FieldTaskQueue_IsEmpty(void** list);
struct Src021c5f00 { unsigned short w0; unsigned short w2; unsigned char b4; unsigned char b5; unsigned char b6; };
void EnqueueEventTag63_021c5f00(Src021c5f00* src);
struct ListHead02046b38;
struct ListNode02046b38;
int ListContainsNode(struct ListHead02046b38* list, struct ListNode02046b38* target);
extern "C" void func_ov017_021b6f18(void* node);
void InitStruct_02196c08(unsigned char* obj);
extern "C" bool func_ov017_021b6e70(void* obj, int combatantId);
extern "C" void func_ov017_021b7104(void* node, void* src);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);
extern "C" void func_ov017_021a7a74(void* unused, void* src);
int HasMatchingHalfword_0219735c(unsigned char* obj, unsigned short key);
void EnqueueHalfword_021972f8(void* obj, unsigned short val);
struct ListHead02046b60;
int ListContainsId(struct ListHead02046b60* list, int id);
unsigned short GetFieldA_021bb9f4(void* obj);
short GetField14e_021bb9fc(void* obj);
void SetFieldA_021bb9ec(void* obj, unsigned short v);
extern "C" void* Zone3D_GetInstance(void);

struct Struct_ov017_021c530c_3 {
    unsigned char unknown_0_[4];
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned char unknown_8_;
    unsigned char unknown_9_;
    unsigned short unknown_a_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned short unknown_e_;
    unsigned char unknown_10_;
};

struct Struct_ov017_021c530c {
    unsigned char unknown_0_[8];
    unsigned short unknown_8_;
};

struct Struct_ov017_021c530c_4 {
    unsigned char unknown_0_[2];
    unsigned char unknown_2_;
};

struct Struct_ov017_021c530c_5 {
    Object3D unknown_0_;
    unsigned char unknown_ac_[0xb2 - 0xac];
    unsigned short unknown_b2_;
    unsigned char unknown_b4_[0xc3 - 0xb4];
    unsigned char unknown_c3_;
};

struct Struct_ov017_021c530c_6 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
};

struct Struct_ov017_021c530c_7 {
#if defined(jpn)
    unsigned char unknown_0_[0x34ec];
#else
    unsigned char unknown1_0_[0x36fc];
#endif
    void* unknown_36fc_;
    unsigned char unknown_3700_[0x3718 - 0x3700];
    Struct_ov017_021c530c_4* unknown_3718_;
    unsigned char unknown_371c_[0x3734 - 0x371c];
    void* unknown_3734_;
#if defined(jpn)
    unsigned char unknown_3528_[0x38f4 - 0x3528];
#else
    unsigned char unknown_3738_[0x3b14 - 0x3738];
#endif
    void* unknown_3b14_;
    unsigned char unknown_3b18_[0x3b90 - 0x3b18];
    void* unknown_3b90_;
#if defined(jpn)
    unsigned char unknown_3974_[0x41fe - 0x3974];
#else
    unsigned char unknown_3b94_[0x44ae - 0x3b94];
#endif
    Struct_ov017_021c530c_6 unknown_44ae_;
};

struct Struct_ov017_021c530c_8 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned char unknown_6_[2];
    int unknown_8_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
    unsigned char unknown_f_;
    short unknown_10_;
    unsigned char unknown_12_;
    unsigned char unknown_13_;
    int unknown_14_;
};

struct Struct_ov017_021c530c_9 {
    unsigned short unknown_0_;
};

static inline int inline_ov017_021c530c(int arg0) {
    return arg0 >= 0x8005 && arg0 <= 0x8005 + 1000;
}

static inline unsigned short inline_ov004_02163304(Struct_ov017_021c530c_9* arg0) {
    return arg0->unknown_0_;
}

// USA: func_ov017_021c530c
extern "C" ARM void func_ov017_021c530c(int arg0, Struct_ov017_021c530c_3* arg1, GameState* arg2, unsigned char* arg3, void* arg4) {
    unsigned char var0[4] = {0};
    GameObject* var1;
    bool var2;
    GameObject* var3;
    int var4;
    Struct_ov017_021c530c_5* var5;
    Struct_ov017_021c530c* var6;
    Struct_ov017_021c530c_7* var7;
    Struct_ov017_021c530c_4* var8;
    void* var9;
    unsigned short var10;
    Struct_ov017_021c530c_7* var11;
    Struct_ov017_021c530c_5* var12;
    GameObject* var13;
    int var14;
    int var15;
    Struct_ov017_021c530c_7* var16;
    void* var17;
    int var18;
    GameObject* var19;
    Struct_ov017_021c530c_9* var20;
    int var21;
    int var22;
    Struct_ov017_021c530c_6* var23;
    int var24;
    int var25;
    void* var26;
    int var27;
    int var28;
    void* var29;
    unsigned char var30;
    unsigned short var31;
    short var32;
    unsigned char var33;
    unsigned char var34;
    void* var35;
    void* var36;

    var0[0] = arg0;
    var24 = 1;
    if (arg0 == 0) {
        var24 = func_02010038(arg2, var0);
    }
    for (var25 = 0; var25 < var24; var25++) {
        var1 = arg2->GetPartyMemberByIndex(var0[var25]);
        if (var1 != NULL) {
            func_02053f7c((Struct_02053f7c_3*)var1, arg1->unknown_4_, 1);
        }
    }

    if (LinkSession_IsHostOrSolo(search)) {
        EnqueueEventTag147_021cdaa0();
        if (!IsSpecialId(cmd->id)) {
            if (cmd->field9 != 0) {
                if (CheckByteAtIndex_021c5bf8(index, cmd->id) == 0) {
                    MaybeResetEntry_021c5e28(index, cmd->id);
                } else {
                    func_ov017_021c5a8c(arg0, arg1->unknown_4_);
                }
            } else if (IsValidCombatantValue_021c5a1c(cmd->id)) {
                if (CheckByteAtIndex_021c5bf8(index, cmd->id) == 0) {
                    if (!LinkSession_IsHostOrSolo(LinkSession_GetInstance())) {
                        ok = false;
                    } else {
                        var26 = func_0207d78c();
                        func_0207d7f4(var26, arg1->unknown_4_, arg0, 1, arg0, arg1->unknown_6_, arg1->unknown_c_);
                        var2 = func_ov017_021c5c5c(arg0, arg1->unknown_4_, arg0) != 0;
                        func_0207d7f4(var26, arg1->unknown_4_, 0, var2, arg0, arg1->unknown_6_, arg1->unknown_c_);
                    }
                    if (var2) {
                        func_ov017_021c5b44(arg1->unknown_8_, arg1->unknown_4_, -1, arg1->unknown_c_, arg1->unknown_10_);
                    }
                    func_0207dcf0(arg1->unknown_4_);
                    var3 = func_ov017_021a278c(arg3, arg1->unknown_4_);
                    if (var3 != NULL) {
                        func_02076ccc(var3, 9);
                    }
                } else {
                    func_ov017_021c5a8c(arg0, arg1->unknown_4_);
                }
            } else {
                func_ov017_021c5e28(arg0, arg1->unknown_4_);
            }
        } else {
            func_ov017_021c5a8c(arg0, arg1->unknown_4_);
        }
        return;
    }

    if (arg1->unknown_d_ != 0) {
        return;
    }

    id = cmd->id;
    if (!IsSpecialId(cmd->id)) {
        if (cmd->field9 != 0) {
            Desc021c530c event;
            leader = (Leader021c530c*)GameState::GetInstance()->GetLeader();
            if (leader == NULL) {
                state = 0;
            } else {
                var7 = (Struct_ov017_021c530c_7*)GetGameResources();
                var8 = var7->unknown_3718_;
                var9 = var7->unknown_36fc_;
                var6 = NULL;
                if (var8->unknown_2_ != 0 && (var6 = func_ov017_021b8478(var8), var6->unknown_8_ == var4)) {
                    var27 = 1;
                } else {
                    zone = leader->obj3D.GetField06();
                    if (zone != 0x170c && zone != 0x170d && zone != 0x170e && zone != 0x170f) {
                        state = 0;
                    } else if ((int)leader->fieldC3 > 0) {
                        state = 0;
                    } else if (FieldTaskQueue_IsEmpty((void**)list1) == 0) {
                        state = 2;
                    } else {
                        var27 = 1;
                    }
                }
            }

            Struct_ov017_021c530c_2 var38;
            var38.unknown_0_ = arg1->unknown_4_;
            var38.unknown_2_ = arg1->unknown_6_;
            var38.unknown_5_ = 0;
            var38.unknown_6_ = 1;
            if (var27 == 1) {
                var38.unknown_4_ = 1;
            } else {
                var38.unknown_4_ = 0;
            }
            func_ov017_021c5f00(&var38);

            if (var27 == 1) {
                var34 = arg1->unknown_10_;
                var33 = arg1->unknown_c_;
                var32 = arg1->unknown_a_;
                var31 = arg1->unknown_4_;
                var30 = arg1->unknown_8_;
                var11 = (Struct_ov017_021c530c_7*)GetGameResources();
                var35 = var11->unknown_36fc_;
                var36 = var11->unknown_3718_;
                if (!func_02046b38((Struct_02046b38*)var35, (Struct_02046b38_2*)var36)) {
                    func_ov017_021b6f18(var36);
                    Struct_ov017_021c530c_8 var39;
                    func_ov017_02196c08((unsigned char*)&var39);
                    var39.unknown_0_ = 0;
                    var39.unknown_1_ = var30;
                    var39.unknown_4_ = var31;
                    var39.unknown_2_ = 0xffff;
                    var39.unknown_8_ = -1;
                    var39.unknown_e_ = 1;
                    var39.unknown_10_ = var32;
                    var39.unknown_f_ = var33;
                    func_ov017_021b6e70(&var39, var39.unknown_2_);
                    var39.unknown_12_ = var34;
                    func_ov017_021b7104(var36, &var39);
                    func_020469b4((Struct_0201bdac_2*)var35, (Struct_0201bdac*)var36);
                }
                leader2 = (Leader021c530c*)gs->GetLeader();
                if (leader2 != NULL) {
                    leader2->fieldB2 = 0;
                }
            } else if (var27 == 2 || var27 == 0) {
                func_ov017_02196c08((unsigned char*)&var37);
                var37.unknown_0_ = 1;
                var37.unknown_1_ = arg1->unknown_8_;
                var37.unknown_4_ = arg1->unknown_4_;
                var37.unknown_2_ = 0xffff;
                var37.unknown_8_ = -1;
                var37.unknown_e_ = 1;
                var37.unknown_10_ = arg1->unknown_a_;
                func_ov017_021b6e70(&var37, var37.unknown_2_);
                if (var27 == 2) {
                    func_ov017_021a7a74(arg3, &var37);
                }
            }
        } else if (func_ov017_021c5a1c(var4)) {
            if (!func_ov017_0219735c(arg3, arg1->unknown_4_)) {
                func_ov017_021972f8(arg3, arg1->unknown_4_);
                var28 = func_ov017_021c5c5c(arg0, arg1->unknown_4_, arg1->unknown_8_);
                Struct_ov017_021c530c_2 var40;
                var40.unknown_0_ = arg1->unknown_4_;
                var40.unknown_2_ = arg1->unknown_6_;
                var40.unknown_4_ = var28;
                var40.unknown_5_ = 0;
                var40.unknown_6_ = 0;
                func_ov017_021c5f00(&var40);
                if (var28) {
                    func_ov017_021c5b44(arg1->unknown_8_, arg1->unknown_4_, -1, arg1->unknown_c_, arg1->unknown_10_);
                } else {
                    var13 = func_ov017_021a278c(arg3, arg1->unknown_4_);
                    if (var13 != NULL) {
                        func_02076ccc(var13, 9);
                    }
                }
            }
        } else {
#if !defined(jpn)
            if (!func_ov017_0219735c(arg3, arg1->unknown_4_)) {
                func_ov017_021972f8(arg3, arg1->unknown_4_);
            }
#endif
            var14 = arg1->unknown_4_;
            if (var14 < 1) {
                var15 = 0;
            } else if (var14 > 0x7fff) {
                var15 = 0;
            } else {
                var15 = 1;
            }
            if (var15) {
                Struct_ov017_021c530c_2 var41;
                var41.unknown_0_ = arg1->unknown_4_;
                var41.unknown_2_ = arg1->unknown_6_;
                var41.unknown_4_ = 0;
                var41.unknown_5_ = 0;
                func_ov017_021c5f00(&var41);
            }
        }
        return;
    }

    var16 = (Struct_ov017_021c530c_7*)GetGameResources();
    var17 = var16->unknown_36fc_;
    var29 = var16->unknown_3734_;
    var18 = 0;
    if (func_02046b60((Struct_02038598_5*)var17, 4)) {
        if (func_ov017_021bb9f4(var29) == 5 && arg1->unknown_4_ == func_ov017_021bb9fc(var29) + 0x8005) {
            func_ov017_021bb9ec(var29, 6);
            func_ov017_021c5b44(arg1->unknown_8_, arg1->unknown_4_, func_ov017_021bb9fc(var29), arg1->unknown_c_, arg1->unknown_10_);
            var18 = 1;
        }
    } else {
        combatant = GetCombatantWithFlag0x100_0200ff1c(gs, cmd->field8);
        zoneInfo = (Zone021c530c*)Zone3D_GetInstance();
        if (index != 0) {
            return;
        }
        if (combatant != NULL) {
            if (FieldTaskQueue_IsEmpty((void**)list3) && combatant->obj3D_.GetField06() == GetZoneId(zoneInfo)) {
                func_ov017_021c5b44(cmd->field8, cmd->id, GetField14e_021bb9fc(fieldObj), cmd->fieldc, cmd->field10);
                found = 1;
            } else if (combatant->obj3D_.GetField06() == GetZoneId(zoneInfo)) {
                list1 = ctx3->nodeB14;
                void* nodeB90 = ctx3->nodeB90;
                inB14 = ListContainsNode((ListHead02046b38*)list3, (ListNode02046b38*)list1);
                inB90 = ListContainsNode((ListHead02046b38*)list3, (ListNode02046b38*)nodeB90);
                if (!(inB14 | inB90)) {
                    pending = &ctx3->pending;
                    pending->id = cmd->id;
                    pending->value = cmd->fielde;
                }
            }
        }
    }
    Struct_ov017_021c530c_2 var43;
    var43.unknown_0_ = arg1->unknown_4_;
    var43.unknown_2_ = arg1->unknown_6_;
    var43.unknown_4_ = var18;
    var43.unknown_5_ = 1;
    func_ov017_021c5f00(&var43);
}
