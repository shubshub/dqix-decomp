#include <globaldefs.h>
#include "Combat/BufferedScriptResult.h"
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

struct Struct_01ff91ac_22;

struct Struct_01ff91ac_23 {
    unsigned char kind;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
};

struct Struct_ov017_021b7284_9 {
    unsigned char pad0[0x8];
    SafeAllocator allocator;
    unsigned char unknown_1c_[0x1c - 0x8 - sizeof(SafeAllocator)];
    Struct_01ff91ac_23 info;
    unsigned char unknown_20_;
    unsigned char unknown_21_;
    unsigned short unknown_22_;
    unsigned short id;
    unsigned char unknown_26_[2];
    int encounter;
    Struct_02074060 decoded;
    unsigned char unknown_40_[2];
    unsigned char unknown_42_;
    unsigned char unknown_43_;
    short group;
    unsigned char unknown_46_[2];
    int unknown_48_;
    int unknown_4c_;
    unsigned char unknown_50_;
    unsigned char unknown_51_;
    unsigned char unknown_52_[0x6ac - 0x52];
    void* unknown_6ac_;
    Struct_01ff91ac_22* context;
    unsigned short state;
    unsigned short flags;
};

union Struct_ov017_021b7284 {
    struct {
        unsigned short unknown_0_[3];
        unsigned short key;
        unsigned char bytes[3];
    };
    unsigned short raw[6];
};

struct Struct_ov017_021b7284_2 {
    short unknown_0_[3];
    short bytes[3];
};

struct Struct_ov017_021b7284_3 {
    Struct_01ff91ac_23* info;
    unsigned short unknown_4_[3];
    unsigned short key;
    unsigned char bytes[3];
};

struct Struct_ov000_021605d0 {
    Struct_01ff91ac_22* context;
    Struct_01ff91ac_23* info;
    SafeAllocator* allocator;
};

struct Holder021b7284 {
#if defined(jpn)
    unsigned char pad0[0x125];
#else
    unsigned char pad0[0x105];
#endif
    unsigned char flags;
};

struct Struct_0209afd4_5;
struct Struct_0209bdc8;
struct ColorHolder0204bd7c;
struct SearchList02099a68;
struct Struct_0205859c;

struct Struct_ov017_021b7284_5 {
    unsigned short value;
};

struct BattleTable021b7284 {
#if defined(jpn)
    unsigned char pad0[0x5c];
    unsigned char active[0x120 - 0x5c];
#else
    unsigned char pad0[0x60];
    unsigned char active[0x124 - 0x60];
#endif
    unsigned char rows[4];
};

struct Struct_ov017_021b7284_7 {
    unsigned char pad0[2];
    short key;
    unsigned char pad4[0x168 - 0x4];
    unsigned short group;
};

struct Obj020397cc {
    unsigned char pad0[0xb2];
    unsigned short fieldB2;
};

struct Struct_02053f7c_3;

struct Party021b7284 {
    unsigned char pad0[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

struct SearchStruct0202c1a4 {
    int active;
    unsigned char pad4[0x100d - 0x4];
    unsigned char depth;
};

struct Entry0207d9bc {
    unsigned char pad0[2];
    unsigned short value;
    signed char a;
    signed char b;
    unsigned char pad6[2];
    signed char flags[4];
};

extern "C" Holder021b7284* Zone3D_GetInstance(void);
extern "C" BattleTable021b7284* ZoneRecords_FindCurrent(void);
extern "C" Struct_ov017_021b7284_7* func_ov017_021a278c(void* unused, int val);
extern "C" int func_ov017_021b8a34(Struct_0209afd4_5* table, int id, int arg2);
extern "C" int func_ov017_021b8abc(int id, Struct_ov017_021b7284* out);
extern "C" void func_ov017_021b8b34(Struct_ov017_021b7284_2* obj);
extern "C" void func_0209b448(Struct_0209afd4_5* table, int group, Struct_ov017_021b7284_2* out, BattleTable021b7284* entry);
extern "C" ColorHolder0204bd7c* GameObject_GetFloorAttribute(void* obj);
extern "C" unsigned short func_0204bd7c(ColorHolder0204bd7c* obj);
extern "C" SearchList02099a68* GameState_GetZoneTable(void* obj);
extern "C" int func_02099a68(SearchList02099a68* list, unsigned short key);
extern "C" Struct_ov017_021b7284_5* func_0209bdc8(Struct_0209bdc8* c, int flag, unsigned int mask);
extern "C" void func_0209afd4(Struct_0209afd4_5* table, short key, short value, short group, Struct_ov017_021b7284_2* out, BattleTable021b7284* entry);
extern "C" void func_ov000_0215d414(Struct_01ff91ac_22* context, Struct_ov017_021b7284_3* req);
extern "C" void func_ov000_02160140(void* p);
extern "C" void func_ov017_02195540(unsigned char* obj);
extern "C" void func_ov000_021605d0(unsigned char* obj, Struct_ov000_021605d0* params);
extern "C" Struct_0205859c* func_02057924(void);
extern "C" void func_0205859c(Struct_0205859c* p);
extern "C" SearchStruct0202c1a4* LinkSession_GetInstance(void);
struct PointerField32c_ffc0;
extern "C" void* GameState_GetShip(PointerField32c_ffc0* obj);
extern "C" void GameObject_DisableControl(Obj020397cc* obj, int arg1);
extern "C" void func_02053f7c(Struct_02053f7c_3* obj, unsigned short a, int b);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" void __clear(void* buf, int n);
extern "C" int GameState_GetProtagonistIndex(GameState* gs);
extern "C" void func_ov017_021b848c(Struct_ov017_021b7284_9* self, signed char* flags, signed char idx, int val, unsigned short color, signed char arg5, int arg6, int encounter);
extern "C" Entry0207d9bc* func_0207d78c(void);
extern "C" int func_0207d978(Entry0207d9bc* arr, unsigned short key);
extern "C" int func_0207da30(unsigned char* arr, int id, int offset);
extern "C" signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4* obj);
extern "C" void func_0207d7f4(Entry0207d9bc* arr, unsigned short key, int a, int flag, signed char b, unsigned short color, unsigned char c);
extern "C" Entry0207d9bc* func_0207d9bc(Entry0207d9bc* arr, unsigned short key);
extern "C" void func_ov017_021ca2a0(int a, int b);

struct Struct_ov017_021b7284_10 {
    unsigned short id;
    unsigned short color;
    unsigned char unknown_4_;
    unsigned char unknown_5_;
    short group;
    unsigned char unknown_8_;
    unsigned char unknown_9_;
    unsigned short encounter;
    unsigned char unknown_c_;
};

extern "C" void func_ov017_021c5284(Struct_ov017_021b7284_10* src);
extern "C" void func_ov017_021cff8c(int id, int a);

// USA: func_ov017_021b7284
// JPN: func_ov017_021b7834
extern "C" ARM void func_ov017_021b7284(Struct_ov017_021b7284_9* self) {
    int i;
    int sub;
    int group;
    GameState* gs = GameState::GetInstance();
    Holder021b7284* holder = Zone3D_GetInstance();
    Struct_ov017_021b7284_3 req;
    Struct_ov000_021605d0 params;
    Struct_ov017_021b7284_10 src;
    Struct_ov017_021b7284 result;
    Struct_ov017_021b7284_2 var9;
    Struct_ov017_021b7284_2 var10;
    Struct_ov017_021b7284 out;
    signed char present[4];
    req.info = &self->info;
    int encounter = self->encounter;
    group = self->group;
    unsigned char var14 = self->unknown_42_;
    unsigned short id = self->id;
    GameState* state = GameState::GetInstance();
    GameResources* res = GetGameResources();
    memset(&out, 0, sizeof(out));

    if (encounter >= 0) {
        func_02074114(&self->decoded, encounter);
        Struct_02074060* decoded = &self->decoded;
        for (i = 0; i < 3; i++) {
            out.unknown_0_[i] = decoded->values[i];
            out.bytes[i] = decoded->attributes[i];
        }
    } else {
        sub = -1;
        if (var14 != 0) {
            BattleTable021b7284* table = ZoneRecords_FindCurrent();
            if (table == NULL) {
                goto done;
            }
            Struct_ov017_021b7284_7* comb = func_ov017_021a278c(res, id);
            if (comb != NULL) {
                sub = func_ov017_021b8a34((Struct_0209afd4_5*)table->rows, group, comb->key);
            }
            if (func_ov017_021b8abc(sub, &out) != 0) {
                goto done;
            }
            func_ov017_021b8b34(&var10);
            func_ov017_021b8b34(&var10);
            func_0209b448((Struct_0209afd4_5*)table->rows, (short)group, &var10, table);
            for (int i = 0; i < 3; i++) {
                out.unknown_0_[i] = var10.unknown_0_[i];
                out.bytes[i] = var10.bytes[i];
            }
        } else {
            Struct_ov017_021b7284_7* comb;
            LightingManager* lighting = LightingManager::GetInstance();
            BattleTable021b7284* table = ZoneRecords_FindCurrent();
            comb = func_ov017_021a278c(res, id);
            void* obj = state->GetLeader();
            if (table == NULL || comb == NULL) {
                goto done;
            }
            int key = comb->key;
            unsigned short color = func_0204bd7c(GameObject_GetFloorAttribute(obj));
            int bit = func_02099a68(GameState_GetZoneTable(state), color);
            Struct_ov017_021b7284_5* active = func_0209bdc8((Struct_0209bdc8*)table->active, lighting->timeOfDayIndex_, bit);
            unsigned short value;
            if (active != NULL) {
                value = active->value;
            } else {
                value = comb->group;
            }
            sub = func_ov017_021b8a34((Struct_0209afd4_5*)table->rows, comb->group, key);
            if (func_ov017_021b8abc(sub, &out) != 0) {
                goto done;
            }
            func_ov017_021b8b34(&var9);
            func_ov017_021b8b34(&var9);
            func_0209afd4((Struct_0209afd4_5*)table->rows, (short)key, (short)value, (short)comb->group, &var9, table);
            for (int i = 0; i < 3; i++) {
                out.unknown_0_[i] = var9.unknown_0_[i];
                out.bytes[i] = var9.bytes[i];
                out.key = key;
            }
        }
    }
done:
    result = out;
    req.unknown_4_[0] = result.unknown_0_[0];
    req.unknown_4_[1] = result.unknown_0_[1];
    req.unknown_4_[2] = result.unknown_0_[2];
    req.key = result.key;
    req.bytes[0] = result.bytes[0];
    req.bytes[1] = result.bytes[1];
    req.bytes[2] = result.bytes[2];
    func_ov000_0215d414(self->context, &req);
#if defined(jpn)
    self->unknown_6ac_ = self->allocator.Allocate(0x79fc);
#else
    self->unknown_6ac_ = self->allocator.Allocate(0x780c);
#endif
    func_ov000_02160140(self->unknown_6ac_);
    func_ov017_02195540((unsigned char*)GetGameResources());
    params.context = self->context;
    params.allocator = &self->allocator;
    params.info = &self->info;
    func_ov000_021605d0((unsigned char*)self->unknown_6ac_, &params);
    holder->flags |= 1;
    func_0205859c(func_02057924());
    SearchStruct0202c1a4* search = LinkSession_GetInstance();

    if (self->unknown_20_ != 0) {
        Obj020397cc* leader = (Obj020397cc*)gs->GetLeader();
        void* other = GameState_GetShip((PointerField32c_ffc0*)gs);
        Party021b7284* party = (Party021b7284*)GameState_GetParty(gs);
        GameObject_DisableControl(leader, 1);
        leader->fieldB2 = 0;
        ColorHolder0204bd7c* colorHolder;
        if (self->unknown_42_ != 0 && other != NULL) {
            colorHolder = GameObject_GetFloorAttribute(other);
        } else {
            colorHolder = GameObject_GetFloorAttribute(leader);
        }
        for (int i = 0; i < party->count; i++) {
            func_02053f7c((Struct_02053f7c_3*)gs->GetPartyMemberByIndex(party->ids[i]), self->id, 1);
        }
        if (LinkSession_IsActive(&search->active) == 0) {
            __clear(present, sizeof(present));
            for (int i = 0; i < party->count; i++) {
                present[party->ids[i]] = 1;
            }
            int idx = GameState_GetProtagonistIndex(gs);
            func_ov017_021b848c(self, present, idx, 0, func_0204bd7c(colorHolder), self->unknown_51_, 1, self->encounter);
        } else {
            Entry0207d9bc* entries = func_0207d78c();
            int found = func_0207d978(entries, self->id) != 0 ? 1 : 0;
            if (func_0207da30((unsigned char*)entries, self->id, GameState_GetProtagonistIndex(gs))) {
                found = 0;
            }
            if (LinkSession_GetOwnSlot(search) == 0) {
                int a = GameState_GetProtagonistIndex(gs);
                int b = GameState_GetProtagonistIndex(gs);
                func_0207d7f4(entries, self->id, a, 1, b, func_0204bd7c(colorHolder), self->unknown_51_);
                if (func_0207d978(entries, self->id)) {
                    Entry0207d9bc* entry = func_0207d9bc(entries, self->id);
                    if (entry != NULL) {
                        func_ov017_021b848c(self, entry->flags, entry->a, found, entry->value, entry->b, found == 0, self->encounter);
                    }
                }
            }
            int depth = search->depth;
            if (depth > 1) {
                if (LinkSession_GetOwnSlot(search) == 0 && found != 0) {
                    func_ov017_021ca2a0(0, self->id);
                    self->unknown_4c_ = 1;
                    self->state = 2;
                } else {
                    src.unknown_4_ = self->unknown_22_;
                    src.id = self->id;
                    src.color = func_0204bd7c(colorHolder);
                    src.unknown_5_ = self->unknown_42_;
                    src.group = self->group;
                    src.unknown_8_ = self->unknown_51_;
                    src.unknown_9_ = self->unknown_48_ != 0;
                    src.encounter = self->encounter;
                    src.unknown_c_ = self->unknown_21_;
                    func_ov017_021c5284(&src);
                    if (self->unknown_48_ != 0) {
                        self->unknown_4c_ = 1;
                        self->state = 2;
                    }
                }
            }
        }
    }

    if (LinkSession_IsActive(&search->active)) {
        Party021b7284* party = (Party021b7284*)GameState_GetParty(gs);
        for (int i = 0; i < party->count; i++) {
            func_ov017_021cff8c(party->ids[i], 0);
        }
    }
    self->flags |= 0x100;
}
