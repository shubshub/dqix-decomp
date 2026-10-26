#include <globaldefs.h>
#include "Combat/BufferedScriptResult.h"
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

struct Struct_01ff91ac_22;

struct Struct_01ff91ac_23 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
};

struct Struct_ov017_021b7284_9 {
    unsigned char unknown_0_[0x8];
    SafeAllocator unknown_8_;
    unsigned char unknown_1c_[0x1c - 0x8 - sizeof(SafeAllocator)];
    Struct_01ff91ac_23 unknown1_1c_;
    unsigned char unknown_20_;
    unsigned char unknown_21_;
    unsigned short unknown_22_;
    unsigned short unknown_24_;
    unsigned char unknown_26_[2];
    int unknown_28_;
    Struct_02074060 unknown_2c_;
    unsigned char unknown_40_[2];
    unsigned char unknown_42_;
    unsigned char unknown_43_;
    short unknown_44_;
    unsigned char unknown_46_[2];
    int unknown_48_;
    int unknown_4c_;
    unsigned char unknown_50_;
    unsigned char unknown_51_;
    unsigned char unknown_52_[0x6ac - 0x52];
    void* unknown_6ac_;
    Struct_01ff91ac_22* unknown_6b0_;
    unsigned short unknown_6b4_;
    unsigned short unknown_6b6_;
};

union Struct_ov017_021b7284 {
    struct {
        unsigned short unknown_0_[3];
        unsigned short unknown_6_;
        unsigned char unknown_8_[3];
    };
    unsigned short unknown1_0_[6];
};

struct Struct_ov017_021b7284_2 {
    short unknown_0_[3];
    short unknown_6_[3];
};

struct Struct_ov017_021b7284_3 {
    Struct_01ff91ac_23* unknown_0_;
    unsigned short unknown_4_[3];
    unsigned short unknown_a_;
    unsigned char unknown_c_[3];
};

struct Struct_ov000_021605d0 {
    Struct_01ff91ac_22* unknown_0_;
    Struct_01ff91ac_23* unknown_4_;
    SafeAllocator* unknown_8_;
};

struct Struct_ov017_021b7284_4 {
#if defined(jpn)
    unsigned char unknown_0_[0x125];
#else
    unsigned char unknown1_0_[0x105];
#endif
    unsigned char unknown_105_;
};

struct Struct_0209afd4_5;
struct Struct_0209bdc8;
struct Struct_0204bd7c;
struct Struct_02099a68;
struct Struct_0205859c;

struct Struct_ov017_021b7284_5 {
    unsigned short unknown_0_;
};

struct Struct_ov017_021b7284_6 {
#if defined(jpn)
    unsigned char unknown_0_[0x5c];
    unsigned char unknown_60_[0x120 - 0x5c];
#else
    unsigned char unknown1_0_[0x60];
    unsigned char unknown_60_[0x124 - 0x60];
#endif
    unsigned char unknown_124_[4];
};

struct Struct_ov017_021b7284_7 {
    unsigned char unknown_0_[2];
    short unknown_2_;
    unsigned char unknown_4_[0x168 - 0x4];
    unsigned short unknown_168_;
};

struct Struct_02018300_3 {
    unsigned char unknown_0_[0xb2];
    unsigned short unknown_b2_;
};

struct Struct_02053f7c_3;

struct Struct_ov017_021b7284_8 {
    unsigned char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
};

struct Struct_0202c1a4 {
    int unknown_0_;
    unsigned char unknown_4_[0x100d - 0x4];
    unsigned char unknown_100d_;
};

struct Struct_0207d7f4 {
    unsigned char unknown_0_[2];
    unsigned short unknown_2_;
    signed char unknown_4_;
    signed char unknown_5_;
    unsigned char unknown_6_[2];
    signed char unknown_8_[4];
};

extern "C" Holder021b7284* Zone3D_GetInstance(void);
BattleTable021b7284* ZoneRecords_FindCurrent(void);
Combatant021b7284* FindCombatantByField16a_021a278c(void* unused, int val);
int PickWeightedSubEntry_021b8a34(FindRowByIdRow* table, int id, int key12);
int DecodeEntry_021b8abc(int id, Out021b8abc* out);
void ClearSixHalfwords_021b8b34(Halfwords6_021b8b34* obj);
extern "C" void func_0209b448(FindRowByIdRow* table, int group, Halfwords6_021b8b34* out, BattleTable021b7284* entry);
ColorHolder0204bd7c* GameObject_GetFloorAttribute(void* obj);
unsigned short ConvertColorToDecimalOffset30000(ColorHolder0204bd7c* obj);
SearchList02099a68* GameState_GetZoneTable(void* obj);
int FindKeyGetBitflag02099a68(SearchList02099a68* list, unsigned short key);
ActiveEntry021b7284* FindActiveEntry0209bdc8(Container0209bdc8* c, int flag, unsigned int mask);
extern "C" void func_0209afd4(FindRowByIdRow* table, short key, short value, short group, Halfwords6_021b8b34* out, BattleTable021b7284* entry);
extern "C" void func_ov000_0215d414(BattleContext021b7284* context, Request021b7284* req);
extern "C" void func_ov000_02160140(void* p);
void ClearFlag320_02195540(unsigned char* obj);
void SetParamsAndRandomState021605d0(unsigned char* obj, Params021605d0* params);
extern "C" MainBlock0205859c* func_02057924(void);
void ResetBattleEncounterState0205859c(MainBlock0205859c* p);
extern "C" SearchStruct0202c1a4* LinkSession_GetInstance(void);
struct PointerField32c_ffc0;
void* GameState_GetShip(PointerField32c_ffc0* obj);
void GameObject_DisableControl(Obj020397cc* obj, int arg1);
void SetField0x1b2IfMatchOrFlag02053f7c(Obj02053f7c* obj, unsigned short a, int b);
int LinkSession_IsActive(int* obj);
extern "C" void __clear(void* buf, int n);
int GameState_GetProtagonistIndex(GameState* gs);
extern "C" void func_ov017_021b848c(BattleScene021b7284* self, signed char* flags, signed char idx, int val, unsigned short color, signed char arg5, int arg6, int encounter);
Entry0207d9bc* GetData02108ea8_0207d78c(void);
int CheckEntryBytes0207d978(Entry0207d9bc* arr, unsigned short key);
int HasActiveEntryForId_0207da30(unsigned char* arr, int id, int offset);
signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4* obj);
extern "C" void func_0207d7f4(Entry0207d9bc* arr, unsigned short key, int a, int flag, signed char b, unsigned short color, unsigned char c);
Entry0207d9bc* FindEntryByHalfword(Entry0207d9bc* arr, unsigned short key);
void EnqueueEventTag90_021ca2a0(int a, int b);

struct Struct_ov017_021b7284_10 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned char unknown_4_;
    unsigned char unknown_5_;
    short unknown_6_;
    unsigned char unknown_8_;
    unsigned char unknown_9_;
    unsigned short unknown_a_;
    unsigned char unknown_c_;
};

extern "C" void func_ov017_021c5284(Struct_ov017_021b7284_10* arg0);
extern "C" void func_ov017_021cff8c(int arg0, int arg1);

// USA: func_ov017_021b7284
// JPN: func_ov017_021b7834
extern "C" ARM void func_ov017_021b7284(BattleScene021b7284* self) {
    int i;
    int sub;
    int group;
    GameState* gs = GameState::GetInstance();
    Holder021b7284* holder = Zone3D_GetInstance();
    Request021b7284 req;
    Params021605d0 params;
    Src021c5284 src;
    Out021b8abc result;
    Halfwords6_021b8b34 alt2;
    Halfwords6_021b8b34 alt;
    Out021b8abc out;
    signed char present[4];
    req.info = &self->info;
    int encounter = self->encounter;
    group = self->group;
    unsigned char useAlt = self->useAlt;
    unsigned short id = self->id;
    GameState* state = GameState::GetInstance();
    GameResources* res = GetGameResources();
    memset(&out, 0, sizeof(out));

    if (var13 >= 0) {
        func_02074114(&arg0->unknown_2c_, var13);
        Struct_02074060* var18 = &arg0->unknown_2c_;
        for (var0 = 0; var0 < 3; var0++) {
            var11.unknown_0_[var0] = var18->unknown_2_[var0];
            var11.unknown_8_[var0] = var18->unknown_8_[var0];
        }
    } else {
        sub = -1;
        if (useAlt != 0) {
            BattleTable021b7284* table = ZoneRecords_FindCurrent();
            if (table == NULL) {
                goto done;
            }
            Struct_ov017_021b7284_7* var20 = func_ov017_021a278c(var17, var15);
            if (var20 != NULL) {
                var1 = func_ov017_021b8a34((Struct_0209afd4_5*)var19->unknown_124_, var2, var20->unknown_2_);
            }
            if (func_ov017_021b8abc(var1, &var11) != 0) {
                goto done;
            }
            func_ov017_021b8b34(&var10);
            func_ov017_021b8b34(&var10);
            func_0209b448((Struct_0209afd4_5*)var19->unknown_124_, (short)var2, &var10, var19);
            for (int var21 = 0; var21 < 3; var21++) {
                var11.unknown_0_[var21] = var10.unknown_0_[var21];
                var11.unknown_8_[var21] = var10.unknown_6_[var21];
            }
        } else {
            Combatant021b7284* comb;
            LightingManager* lighting = LightingManager::GetInstance();
            BattleTable021b7284* table = ZoneRecords_FindCurrent();
            comb = FindCombatantByField16a_021a278c(res, id);
            void* obj = state->GetLeader();
            if (table == NULL || comb == NULL) {
                goto done;
            }
            int key = comb->key;
            unsigned short color = ConvertColorToDecimalOffset30000(GameObject_GetFloorAttribute(obj));
            int bit = FindKeyGetBitflag02099a68(GameState_GetZoneTable(state), color);
            ActiveEntry021b7284* active = FindActiveEntry0209bdc8((Container0209bdc8*)table->active, lighting->timeOfDayIndex_, bit);
            unsigned short value;
            if (active != NULL) {
                value = active->value;
            } else {
                var30 = var22->unknown_168_;
            }
            var1 = func_ov017_021b8a34((Struct_0209afd4_5*)var24->unknown_124_, var22->unknown_168_, var26);
            if (func_ov017_021b8abc(var1, &var11) != 0) {
                goto done;
            }
            func_ov017_021b8b34(&var9);
            func_ov017_021b8b34(&var9);
            func_0209afd4((Struct_0209afd4_5*)var24->unknown_124_, (short)var26, (short)var30, (short)var22->unknown_168_, &var9, var24);
            for (int var31 = 0; var31 < 3; var31++) {
                var11.unknown_0_[var31] = var9.unknown_0_[var31];
                var11.unknown_8_[var31] = var9.unknown_6_[var31];
                var11.unknown_6_ = var26;
            }
        }
    }
done:
    var8 = var11;
    var5.unknown_4_[0] = var8.unknown_0_[0];
    var5.unknown_4_[1] = var8.unknown_0_[1];
    var5.unknown_4_[2] = var8.unknown_0_[2];
    var5.unknown_a_ = var8.unknown_6_;
    var5.unknown_c_[0] = var8.unknown_8_[0];
    var5.unknown_c_[1] = var8.unknown_8_[1];
    var5.unknown_c_[2] = var8.unknown_8_[2];
    func_ov000_0215d414(arg0->unknown_6b0_, &var5);
#if defined(jpn)
    arg0->unknown_6ac_ = arg0->unknown_8_.Allocate(0x79fc);
#else
    arg0->unknown_6ac_ = arg0->unknown_8_.Allocate(0x780c);
#endif
    func_ov000_02160140(self->field_6ac);
    ClearFlag320_02195540((unsigned char*)GetGameResources());
    params.context = self->context;
    params.allocator = &self->allocator;
    params.info = &self->info;
    SetParamsAndRandomState021605d0((unsigned char*)self->field_6ac, &params);
    holder->flags |= 1;
    ResetBattleEncounterState0205859c(func_02057924());
    SearchStruct0202c1a4* search = LinkSession_GetInstance();

    if (self->hasParty != 0) {
        Obj020397cc* leader = (Obj020397cc*)gs->GetLeader();
        void* other = GameState_GetShip((PointerField32c_ffc0*)gs);
        Party021b7284* party = (Party021b7284*)GameState_GetParty(gs);
        GameObject_DisableControl(leader, 1);
        leader->fieldB2 = 0;
        ColorHolder0204bd7c* colorHolder;
        if (self->useAlt != 0 && other != NULL) {
            colorHolder = GameObject_GetFloorAttribute(other);
        } else {
            colorHolder = GameObject_GetFloorAttribute(leader);
        }
        for (int var37 = 0; var37 < var35->unknown_f7c_; var37++) {
            func_02053f7c((Struct_02053f7c_3*)var3->GetPartyMemberByIndex(var35->unknown_f78_[var37]), arg0->unknown_24_, 1);
        }
        if (LinkSession_IsActive(&search->active) == 0) {
            __clear(present, sizeof(present));
            for (int i = 0; i < party->count; i++) {
                present[party->ids[i]] = 1;
            }
            int idx = GameState_GetProtagonistIndex(gs);
            func_ov017_021b848c(self, present, idx, 0, ConvertColorToDecimalOffset30000(colorHolder), self->field_51, 1, self->encounter);
        } else {
            Entry0207d9bc* entries = GetData02108ea8_0207d78c();
            int found = CheckEntryBytes0207d978(entries, self->id) != 0 ? 1 : 0;
            if (HasActiveEntryForId_0207da30((unsigned char*)entries, self->id, GameState_GetProtagonistIndex(gs))) {
                found = 0;
            }
            if (LinkSession_GetOwnSlot(search) == 0) {
                int a = GameState_GetProtagonistIndex(gs);
                int b = GameState_GetProtagonistIndex(gs);
                func_0207d7f4(entries, self->id, a, 1, b, ConvertColorToDecimalOffset30000(colorHolder), self->field_51);
                if (CheckEntryBytes0207d978(entries, self->id)) {
                    Entry0207d9bc* entry = FindEntryByHalfword(entries, self->id);
                    if (entry != NULL) {
                        func_ov017_021b848c(self, entry->flags, entry->a, found, entry->value, entry->b, found == 0, self->encounter);
                    }
                }
            }
            int depth = search->depth;
            if (depth > 1) {
                if (LinkSession_GetOwnSlot(search) == 0 && found != 0) {
                    EnqueueEventTag90_021ca2a0(0, self->id);
                    self->field_4c = 1;
                    self->state = 2;
                } else {
                    var7.unknown_4_ = arg0->unknown_22_;
                    var7.unknown_0_ = arg0->unknown_24_;
                    var7.unknown_2_ = func_0204bd7c(var36);
                    var7.unknown_5_ = arg0->unknown_42_;
                    var7.unknown_6_ = arg0->unknown_44_;
                    var7.unknown_8_ = arg0->unknown_51_;
                    var7.unknown_9_ = arg0->unknown_48_ != 0;
                    var7.unknown_a_ = arg0->unknown_28_;
                    var7.unknown_c_ = arg0->unknown_21_;
                    func_ov017_021c5284(&var7);
                    if (arg0->unknown_48_ != 0) {
                        arg0->unknown_4c_ = 1;
                        arg0->unknown_6b4_ = 2;
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
    arg0->unknown_6b6_ |= 0x100;
}
