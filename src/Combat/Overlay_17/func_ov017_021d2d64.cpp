#include <globaldefs.h>
#include "Combat/CombatantRecovery.h"
#include "GameState/GameState.h"

struct ArrayContainsByteStruct;
struct ListHead02046b60;
struct BitFlags020d805c;
struct StoreStruct;
struct Struct_02000c9c_62;
struct Struct_ov017_021d2d64_2 { unsigned char b0; unsigned short h2; unsigned char unknown_4_; };

struct Struct_ov017_021d2d64_3 {
    short lo : 11;
    short hi : 5;
};

struct Struct_ov017_021d2d64_4 {
    unsigned char kind;
    unsigned char type;
    unsigned char sub;
    signed char f3;
    signed char ids[3];
    signed char count;
    Struct_ov017_021d2d64_3 unknown_8_[3];
    signed char fe;
};

struct Struct_ov017_021d2d64_5 {
    char pad0[4];
    Struct_ov017_021d2d64_4 entry;
};

struct Leader021d2d64 {
    Object3D obj;
    short unknown_ac_;
};

struct Reset021d2d64 {
    char pad0[0x150];
    unsigned char state : 6;
};

struct Struct_ov017_021d2d64_8 {
    char pad0[0x59f];
    unsigned char flags;
};

struct Struct_ov017_021d2d64_9 {
    char pad0[0x1c];
    Struct_ov017_021d2d64_8* flags;
};

struct Revive021d2d64 {
    char pad0[0x64];
    int busy;
};

struct Struct_ov017_021d2d64 {
    short v[2];
};

struct Struct_ov017_021d6ce8_2 {
    char pad0[0x18];
    Struct_ov017_021d2d64 msgs;
};

extern "C" int GameState_GetProtagonistIndex(GameState* gs);
extern "C" void* GameState_GetParty(GameState* gameState);
extern "C" void func_ov017_021d2d00(void* dst, void* src);
extern "C" void func_ov017_021d35f8(Struct_ov017_021d2d64_2* obj);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" int func_02086ef0(ArrayContainsByteStruct* s, int val);
extern "C" int func_02046b60(ListHead02046b60* list, int id);
extern "C" void* TextQueue_GetInstance(void);
extern "C" int FieldTaskQueue_IsEmpty(void** obj);
extern "C" int GameObject_IsGesturing(signed char* obj);
extern "C" int MessageSystem_GetInstance(void);
extern "C" int func_020d805c(BitFlags020d805c* obj);
extern "C" int func_ov017_0218b628(signed char);
extern "C" void func_ov017_0218b5c0(int set, signed char bit);
extern "C" void func_ov017_02191ba0(char*, int, int);
extern "C" void func_020e1154(void* obj);
extern "C" int func_02048418(unsigned char* obj, unsigned short flag);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" void __clear(void* dst, unsigned int size);
extern "C" int func_020e04f4(int p0, void* p1, int p2, int p3, unsigned char p4, int p5);
extern "C" void func_02046380(void* g);
extern "C" void NameText_Clear(void* p);
extern "C" void NameText_InitFromPartyMember(void* obj, int combatantId);
extern "C" void func_020465f0(unsigned char* base, int index, unsigned char value);
extern "C" void func_020465c0(StoreStruct* base, int index, int value);
extern "C" void MessageSystem_FormatText(void* g, int mode, char* fmt, char* out, int size, int a, int b);
extern "C" void TextQueue_Push(void* receiver, void* input, int style, int flag, int a, int b);
extern "C" void func_ov017_021d2cc0(void* src);
extern "C" void func_ov017_021a5a88(int a, int b, int c, int d, unsigned char e);

extern const Struct_ov017_021d6ce8_2 data_ov017_021d6ce8;
extern char data_ov017_021d8298[];
extern char data_ov017_021d8288[];

// USA: func_ov017_021d2d64
extern "C" ARM void func_ov017_021d2d64(void* unused, Struct_ov017_021d2d64_5* msg, GameState* gs, GameResources* res) {
    void* g;
    int v3ac;
    ArrayContainsByteStruct* party;
    Reset021d2d64* reset;
    int saved;
    ListHead02046b60* list;
    short msgId;
    Struct_ov017_021d2d64_4* entry = &msg->entry;
    v3ac = GameState_GetProtagonistIndex(gs);
    party = (ArrayContainsByteStruct*)GameState_GetParty(gs);
    Struct_ov017_021d2d64_4 local;
    Struct_ov017_021d2d64_2 var9[4];
    Struct_ov017_021d2d64_2 var10[4];
    func_ov017_021d2d00(&local, entry);
    unsigned char count = local.count;
    signed char* ids = local.ids;
    for (int i = 0; i < 4; i++) {
        func_ov017_021d35f8(&var9[i]);
        func_ov017_021d35f8(&var10[i]);
    }
    int hud = (int)res->unknown_ptr_array_371c[0];

    switch (entry->kind) {
    case 1: {
        local.count = 0;
        memset(local.ids, 0, 3);
        memset(local.unknown_8_, 0, 6);
        signed char n = 0;
        for (int i = 0; i < entry->count; i++) {
            int id = entry->ids[i];
            if (func_02086ef0(party, id) != 0) {
                local.ids[n] = id;
                Struct_ov017_021d2d64_3* d = &local.unknown_8_[n];
                d->lo = entry->unknown_8_[i].lo;
                d->hi = entry->unknown_8_[i].hi;
                n++;
            }
        }
        local.count = n;
        if (local.count == 0) {
            return;
        }

        list = (ListHead02046b60*)res->fieldTaskQueue_;
        int ok = 1;
        if (func_02046b60(list, 10)) ok = 0;
        if (func_02046b60(list, 3)) ok = 0;
        if (func_02046b60(list, 0x27)) ok = 0;
        if (func_02046b60(list, 0x10) && ((Struct_ov017_021d2d64_9*)res->unknown_ptr_array_371c[4])->flags != 0 &&
            (((Struct_ov017_021d2d64_9*)res->unknown_ptr_array_371c[4])->flags->flags & 4)) {
            ok = 0;
        }

        if (ok) {
            reset = (Reset021d2d64*)TextQueue_GetInstance();
            ok = 1;
            if (FieldTaskQueue_IsEmpty((void**)list) == 0) ok = 0;
            if (func_02046b60(list, 0x1a)) ok = 1;
            GameObject* leader = gs->GetLeader();
            if (leader != 0 && GameObject_IsGesturing((signed char*)leader)) ok = 0;
            if (*(int*)(MessageSystem_GetInstance() + 0x998) != 0 && func_020d805c((BitFlags020d805c*)reset) == 0) ok = 0;

            for (int i = 0; i < local.count; i++) {
                if (reset->state >= 3) ok = 0;
                int id = local.ids[i];
                Struct_ov017_021d2d64 msgs = data_ov017_021d6ce8.msgs;
                GameObject* unit = func_0200ff1c(gs, id);
                if (unit == 0) continue;
                saved = func_ov017_0218b628(id);
                if (ok) func_ov017_0218b5c0(0, id);
                Struct_ov017_021d2d64_3* v = &local.unknown_8_[i];
                int shown = 0;
                if (local.type == 1) {
                    int max = unit->baseStats_->primaryStats.maxHP;
                    int value = unit->combatFields_.savedState_130_->hp;
                    int sum = value + v->lo;
                    int delta;
                    if (sum >= max) {
                        delta = max - value;
                    } else {
                        delta = sum - value;
                    }
                    unit->combatFields_.savedState_130_->hp = value + delta;
                    v->lo = delta;
                    if (delta > 0) {
                        msgs.v[0] = 0x232c;
                        shown = 1;
                    }
                } else if (local.type == 2) {
                    int max = unit->baseStats_->primaryStats.maxMP;
                    int value = unit->combatFields_.savedState_130_->mp;
                    int sum = value + v->lo;
                    int delta;
                    if (sum >= max) {
                        delta = max - value;
                    } else {
                        delta = sum - value;
                    }
                    unit->combatFields_.savedState_130_->mp = value + delta;
                    v->lo = delta;
                    if (delta > 0) {
                        msgs.v[0] = 0x795f;
                        shown = 1;
                    }
                } else if (local.type == 4) {
                    int var35 = 1;
                    if (func_02046b60(list, 0x1a) && ((Revive021d2d64*)res->fieldTasks_[4])->busy != 0) {
                        var35 = 0;
                    }
                    if ((int)unit->combatFields_.savedState_130_->hp > 0 || v->lo == 0 || var35 == 0) {
                        v->lo = 0;
                    } else {
                        Leader021d2d64* l = (Leader021d2d64*)gs->GetLeader();
                        if (l != 0 && (l->unknown_ac_ != 0 || l->obj.GetFlag(0x8000000) != 0)) {
                            func_ov017_02191ba0((char*)res, id, v->lo);
                            shown = 0;
                        } else {
                            func_02053fe4(unit, v->lo, 1);
                            if (unit->baseStats_->primaryStats.maxHP < v->lo) {
                                v->lo = unit->baseStats_->primaryStats.maxHP;
                            }
                            shown = 1;
                            if (func_02046b60(list, 0x1a)) {
                                func_020e1154((void*)0x1f4);
                            }
                            msgs.v[0] = 0x7955;
                        }
                    }
                } else if (local.type == 3) {
                    if (func_02048418((unsigned char*)unit, 2) == 0) {
                        v->lo = 0;
                    } else {
                        v->lo = 1;
                        msgs.v[0] = 0x794b;
                        shown = 1;
                    }
                }
                if (local.sub == 3) {
                    if (func_02048418((unsigned char*)unit, 2) == 0) {
                        v->hi = 0;
                    } else {
                        v->hi = 1;
                        msgs.v[1] = 0x794b;
                        shown = 1;
                    }
                }
                if (shown) {
                    func_ov017_021c9e00(id, 0, 0, 1);
                }
                if (ok) {
                    for (int k = 0; k < 2; k++) {
                        if (reset->state >= 3) continue;
                        g = (void*)MessageSystem_GetInstance();
                        msgId = msgs.v[k];
                        if (msgId < 0) continue;
                        char text[0x100];
                        __clear(text, 0x100);
                        func_020e04f4((int)text, data_ov017_021d8288, msgId, 0, 1, (int)data_ov017_021d8298);
                        func_02046380(g);
                        char who[0xc];
                        NameText_Clear(who);
                        NameText_InitFromPartyMember(who, unit->obj3D_.actorIndex_);
                        *(char**)((char*)g + 0x10) = who;
                        func_020465f0((unsigned char*)g, 0, 0);
                        func_020465c0((StoreStruct*)g, 0, v->lo);
                        func_020465f0((unsigned char*)g, 9, 0);
                        func_020465c0((StoreStruct*)g, 9, unit->obj3D_.actorIndex_);
                        char out[0x80];
                        __clear(out, 0x80);
                        MessageSystem_FormatText(g, 0xc, text, out, 0xe3, 0, 1);
                        TextQueue_Push(reset, out, 0, 0, 1, 1);
                    }
                }
                if (!ok || !shown) {
                    func_ov017_0218b5c0(saved, id);
                }
            }
            local.kind = 2;
        } else {
            local.kind = 4;
            Struct_ov017_021d2d64_3* var41;
            for (int i = 0; i < 3; i++) {
                var41 = local.unknown_8_;
                var41[i].lo = 0;
                var41[i].hi = 0;
            }
        }
        local.fe = v3ac;
        func_ov017_021d2cc0(&local);
        break;
    }
    case 2:
    case 3:
        for (int i = 0; i < count; i++) {
            Struct_ov017_021d2d64_3* v = &local.unknown_8_[i];
            int off = i * sizeof(Struct_ov017_021d2d64_2);
            int lo = v->lo;
            *(unsigned short*)((char*)var9 + 2 + off) = lo;
            if (lo > 0) {
                *((unsigned char*)var9 + off) = 3;
            } else {
                *((unsigned char*)var9 + off) = 0;
            }
            int hi = v->hi;
            *(unsigned short*)((char*)var10 + 2 + off) = hi;
            if (hi > 0) {
                *((unsigned char*)var10 + off) = 3;
            } else {
                *((unsigned char*)var10 + off) = 0;
            }
        }
        func_ov017_021a5a88(hud, (int)ids, (int)var9, (int)var10, count);
        break;
    case 4:
        for (int i = 0; i < count; i++) {
            var9[i].h2 = 0;
            var9[i].b0 = 2;
            var10[i].h2 = 0;
            var10[i].b0 = 2;
        }
        func_ov017_021a5a88(hud, (int)ids, (int)var9, (int)var10, count);
        break;
    }
}
