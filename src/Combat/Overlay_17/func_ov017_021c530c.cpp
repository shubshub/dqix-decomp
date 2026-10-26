#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void __clear(void* buf, int size);
extern "C" int func_02010038(GameState* battleStruct, unsigned char* out);
struct Struct_02053f7c_3;
extern "C" void func_02053f7c(Struct_02053f7c_3*, unsigned short, int);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* search);
extern "C" void func_ov017_021cdaa0(void);
extern "C" int func_ov017_021c5bf8(int index, int key);
extern "C" void func_ov017_021c5e28(int, int);
extern "C" void func_ov017_021c5a8c(int a, int key);
extern "C" int func_ov017_021c5a1c(int val);
extern "C" void* func_0207d78c(void);
extern "C" int func_0207d7f4(void* entries, unsigned short id, int arg2, int flag,
                             signed char field4, unsigned short field2, unsigned char field5);
extern "C" int func_ov017_021c5c5c(int index, int id, int arg);
extern "C" void func_ov017_021c5b44(unsigned char arg0, int combatantId, unsigned int arg2, unsigned char arg3, unsigned char arg4);
extern "C" void func_0207dcf0(unsigned short id);
extern "C" GameObject* func_ov017_021a278c(void* base, int val);
extern "C" void func_02076ccc(void* obj, int mode);
struct Struct_ov017_021c530c;
extern "C" Struct_ov017_021c530c* func_ov017_021b8478(void* node);
extern "C" int FieldTaskQueue_IsEmpty(void** list);
struct Struct_ov017_021c530c_2 { unsigned short unknown_0_; unsigned short w2; unsigned char unknown_4_; unsigned char unknown_5_; unsigned char unknown_6_; };
extern "C" void func_ov017_021c5f00(Struct_ov017_021c530c_2* src);
struct ListHead02046b38;
struct ListNode02046b38;
extern "C" int func_02046b38(struct ListHead02046b38* list, struct ListNode02046b38* target);
extern "C" void func_ov017_021b6f18(void* node);
extern "C" void func_ov017_02196c08(unsigned char* obj);
extern "C" bool func_ov017_021b6e70(void* obj, int combatantId);
extern "C" void func_ov017_021b7104(void* node, void* src);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);
extern "C" void func_ov017_021a7a74(void* unused, void* src);
extern "C" int func_ov017_0219735c(unsigned char* obj, unsigned short key);
extern "C" void func_ov017_021972f8(void* obj, unsigned short val);
struct ListHead02046b60;
extern "C" int func_02046b60(struct ListHead02046b60* list, int id);
extern "C" unsigned short func_ov017_021bb9f4(void* obj);
extern "C" short func_ov017_021bb9fc(void* obj);
extern "C" void func_ov017_021bb9ec(void* obj, unsigned short v);
extern "C" void* Zone3D_GetInstance(void);

struct Struct_ov017_021c530c_3 {
    unsigned char pad0[4];
    unsigned short id;
    unsigned short field6;
    unsigned char field8;
    unsigned char field9;
    unsigned short fielda;
    unsigned char fieldc;
    unsigned char unknown_d_;
    unsigned short unknown_e_;
    unsigned char field10;
};

struct Struct_ov017_021c530c {
    unsigned char pad0[8];
    unsigned short targetId;
};

struct Struct_ov017_021c530c_4 {
    unsigned char pad0[2];
    unsigned char active;
};

struct Leader021c530c {
    Object3D obj3D;
    unsigned char unknown_ac_[0xb2 - 0xac];
    unsigned short fieldB2;
    unsigned char padB4[0xc3 - 0xb4];
    unsigned char fieldC3;
};

struct Struct_ov017_021c530c_6 {
    unsigned short id;
    unsigned short value;
};

struct Struct_ov017_021c530c_7 {
#if defined(jpn)
    unsigned char pad0[0x34ec];
#else
    unsigned char pad0[0x36fc];
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
    Struct_ov017_021c530c_6 pending;
};

struct Struct_ov017_021c530c_8 {
    unsigned char field0;
    unsigned char field1;
    unsigned short field2;
    unsigned short field4;
    unsigned char pad6[2];
    int field8;
    unsigned char fieldc;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
    unsigned char unknown_f_;
    short field10;
    unsigned char field12;
    unsigned char unknown_13_;
    int field14;
};

struct Zone021c530c {
    unsigned short id;
};

static inline int inline_ov017_021c530c(int id) {
    return id >= 0x8005 && id <= 0x8005 + 1000;
}

static inline unsigned short GetZoneId(Zone021c530c* zone) {
    return zone->id;
}

// USA: func_ov017_021c530c
extern "C" ARM void func_ov017_021c530c(int index, Struct_ov017_021c530c_3* cmd, GameState* gs, unsigned char* work, void* search) {
    unsigned char members[4] = {0};
    GameObject* member;
    bool ok;
    GameObject* var3;
    int id;
    Leader021c530c* leader;
    Struct_ov017_021c530c* evt;
    Struct_ov017_021c530c_7* var7;
    Struct_ov017_021c530c_4* var8;
    void* list1;
    unsigned short zone;
    Struct_ov017_021c530c_7* ctx2;
    Leader021c530c* leader2;
    GameObject* var13;
    int var14;
    int normal;
    Struct_ov017_021c530c_7* var16;
    void* list3;
    int found;
    GameObject* combatant;
    Zone021c530c* zoneInfo;
    int var21;
    int var22;
    Struct_ov017_021c530c_6* pending;
    int count;
    int i;
    void* entries;
    int state;
    int queued;
    void* fieldObj;
    unsigned char field8;
    unsigned short cid;
    short fielda;
    unsigned char fieldc;
    unsigned char field10;
    void* list2;
    void* node2;

    members[0] = index;
    count = 1;
    if (index == 0) {
        count = func_02010038(gs, members);
    }
    for (i = 0; i < count; i++) {
        member = gs->GetPartyMemberByIndex(members[i]);
        if (member != NULL) {
            func_02053f7c((Struct_02053f7c_3*)member, cmd->id, 1);
        }
    }

    if (LinkSession_IsHostOrSolo(search)) {
        func_ov017_021cdaa0();
        if (!inline_ov017_021c530c(cmd->id)) {
            if (cmd->field9 != 0) {
                if (func_ov017_021c5bf8(index, cmd->id) == 0) {
                    func_ov017_021c5e28(index, cmd->id);
                } else {
                    func_ov017_021c5a8c(index, cmd->id);
                }
            } else if (func_ov017_021c5a1c(cmd->id)) {
                if (func_ov017_021c5bf8(index, cmd->id) == 0) {
                    if (!LinkSession_IsHostOrSolo(LinkSession_GetInstance())) {
                        ok = false;
                    } else {
                        entries = func_0207d78c();
                        func_0207d7f4(entries, cmd->id, index, 1, index, cmd->field6, cmd->fieldc);
                        ok = func_ov017_021c5c5c(index, cmd->id, index) != 0;
                        func_0207d7f4(entries, cmd->id, 0, ok, index, cmd->field6, cmd->fieldc);
                    }
                    if (ok) {
                        func_ov017_021c5b44(cmd->field8, cmd->id, -1, cmd->fieldc, cmd->field10);
                    }
                    func_0207dcf0(cmd->id);
                    var3 = func_ov017_021a278c(work, cmd->id);
                    if (var3 != NULL) {
                        func_02076ccc(var3, 9);
                    }
                } else {
                    func_ov017_021c5a8c(index, cmd->id);
                }
            } else {
                func_ov017_021c5e28(index, cmd->id);
            }
        } else {
            func_ov017_021c5a8c(index, cmd->id);
        }
        return;
    }

    if (cmd->unknown_d_ != 0) {
        return;
    }

    id = cmd->id;
    if (!inline_ov017_021c530c(cmd->id)) {
        if (cmd->field9 != 0) {
            Struct_ov017_021c530c_8 event;
            leader = (Leader021c530c*)GameState::GetInstance()->GetLeader();
            if (leader == NULL) {
                state = 0;
            } else {
                var7 = (Struct_ov017_021c530c_7*)GetGameResources();
                var8 = var7->unknown_3718_;
                list1 = var7->unknown_36fc_;
                evt = NULL;
                if (var8->active != 0 && (evt = func_ov017_021b8478(var8), evt->targetId == id)) {
                    state = 1;
                } else {
                    zone = leader->obj3D.GetField06();
                    if (zone != 0x170c && zone != 0x170d && zone != 0x170e && zone != 0x170f) {
                        state = 0;
                    } else if ((int)leader->fieldC3 > 0) {
                        state = 0;
                    } else if (FieldTaskQueue_IsEmpty((void**)list1) == 0) {
                        state = 2;
                    } else {
                        state = 1;
                    }
                }
            }

            Struct_ov017_021c530c_2 src;
            src.unknown_0_ = cmd->id;
            src.w2 = cmd->field6;
            src.unknown_5_ = 0;
            src.unknown_6_ = 1;
            if (state == 1) {
                src.unknown_4_ = 1;
            } else {
                src.unknown_4_ = 0;
            }
            func_ov017_021c5f00(&src);

            if (state == 1) {
                field10 = cmd->field10;
                fieldc = cmd->fieldc;
                fielda = cmd->fielda;
                cid = cmd->id;
                field8 = cmd->field8;
                ctx2 = (Struct_ov017_021c530c_7*)GetGameResources();
                list2 = ctx2->unknown_36fc_;
                node2 = ctx2->unknown_3718_;
                if (!func_02046b38((ListHead02046b38*)list2, (ListNode02046b38*)node2)) {
                    func_ov017_021b6f18(node2);
                    Struct_ov017_021c530c_8 desc;
                    func_ov017_02196c08((unsigned char*)&desc);
                    desc.field0 = 0;
                    desc.field1 = field8;
                    desc.field4 = cid;
                    desc.field2 = 0xffff;
                    desc.field8 = -1;
                    desc.unknown_e_ = 1;
                    desc.field10 = fielda;
                    desc.unknown_f_ = fieldc;
                    func_ov017_021b6e70(&desc, desc.field2);
                    desc.field12 = field10;
                    func_ov017_021b7104(node2, &desc);
                    func_020469b4((TailList020469b4*)list2, (TailNode020469b4*)node2);
                }
                leader2 = (Leader021c530c*)gs->GetLeader();
                if (leader2 != NULL) {
                    leader2->fieldB2 = 0;
                }
            } else if (state == 2 || state == 0) {
                func_ov017_02196c08((unsigned char*)&event);
                event.field0 = 1;
                event.field1 = cmd->field8;
                event.field4 = cmd->id;
                event.field2 = 0xffff;
                event.field8 = -1;
                event.unknown_e_ = 1;
                event.field10 = cmd->fielda;
                func_ov017_021b6e70(&event, event.field2);
                if (state == 2) {
                    func_ov017_021a7a74(work, &event);
                }
            }
        } else if (func_ov017_021c5a1c(id)) {
            if (!func_ov017_0219735c(work, cmd->id)) {
                func_ov017_021972f8(work, cmd->id);
                queued = func_ov017_021c5c5c(index, cmd->id, cmd->field8);
                Struct_ov017_021c530c_2 src;
                src.unknown_0_ = cmd->id;
                src.w2 = cmd->field6;
                src.unknown_4_ = queued;
                src.unknown_5_ = 0;
                src.unknown_6_ = 0;
                func_ov017_021c5f00(&src);
                if (queued) {
                    func_ov017_021c5b44(cmd->field8, cmd->id, -1, cmd->fieldc, cmd->field10);
                } else {
                    var13 = func_ov017_021a278c(work, cmd->id);
                    if (var13 != NULL) {
                        func_02076ccc(var13, 9);
                    }
                }
            }
        } else {
#if !defined(jpn)
            if (!func_ov017_0219735c(work, cmd->id)) {
                func_ov017_021972f8(work, cmd->id);
            }
#endif
            var14 = cmd->id;
            if (var14 < 1) {
                normal = 0;
            } else if (var14 > 0x7fff) {
                normal = 0;
            } else {
                normal = 1;
            }
            if (normal) {
                Struct_ov017_021c530c_2 src;
                src.unknown_0_ = cmd->id;
                src.w2 = cmd->field6;
                src.unknown_4_ = 0;
                src.unknown_5_ = 0;
                func_ov017_021c5f00(&src);
            }
        }
        return;
    }

    var16 = (Struct_ov017_021c530c_7*)GetGameResources();
    list3 = var16->unknown_36fc_;
    fieldObj = var16->unknown_3734_;
    found = 0;
    if (func_02046b60((ListHead02046b60*)list3, 4)) {
        if (func_ov017_021bb9f4(fieldObj) == 5 && cmd->id == func_ov017_021bb9fc(fieldObj) + 0x8005) {
            func_ov017_021bb9ec(fieldObj, 6);
            func_ov017_021c5b44(cmd->field8, cmd->id, func_ov017_021bb9fc(fieldObj), cmd->fieldc, cmd->field10);
            found = 1;
        }
    } else {
        combatant = func_0200ff1c(gs, cmd->field8);
        zoneInfo = (Zone021c530c*)Zone3D_GetInstance();
        if (index != 0) {
            return;
        }
        if (combatant != NULL) {
            if (FieldTaskQueue_IsEmpty((void**)list3) && combatant->obj3D_.GetField06() == GetZoneId(zoneInfo)) {
                func_ov017_021c5b44(cmd->field8, cmd->id, func_ov017_021bb9fc(fieldObj), cmd->fieldc, cmd->field10);
                found = 1;
            } else if (combatant->obj3D_.GetField06() == GetZoneId(zoneInfo)) {
                list1 = var16->unknown_3b14_;
                void* var42 = var16->unknown_3b90_;
                var21 = func_02046b38((ListHead02046b38*)list3, (ListNode02046b38*)list1);
                var22 = func_02046b38((ListHead02046b38*)list3, (ListNode02046b38*)var42);
                if (!(var21 | var22)) {
                    pending = &var16->pending;
                    pending->id = cmd->id;
                    pending->value = cmd->unknown_e_;
                }
            }
        }
    }
    Struct_ov017_021c530c_2 src;
    src.unknown_0_ = cmd->id;
    src.w2 = cmd->field6;
    src.unknown_4_ = found;
    src.unknown_5_ = 1;
    func_ov017_021c5f00(&src);
}
