#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "World/Zone3D.h"
#include "Resource/MessageSystem.h"
#include "Resource/Brightness.h"


struct Struct_ov017_0219d250_6 {
    unsigned short unknown_0_;
    unsigned char unknown_2_[3];
    signed char unknown_5_;
    signed char unknown_6_;
    signed char unknown_7_;
    unsigned char unknown_8_[4];
    unsigned char unknown_c_0_ : 4;
};

struct Struct_ov017_0219d250_7 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned char unknown_4_;
    unsigned char unknown_5_[5];
    unsigned char unknown_a_;
    unsigned char unknown_b_[0x15];
    int unknown_20_;
    unsigned char unknown_24_[0x3c];
    unsigned char unknown_60_;
    unsigned char unknown_61_;
    unsigned char unknown_62_;
    unsigned char unknown_63_[4];
    unsigned char unknown_67_;
    unsigned char unknown_68_[6];
    unsigned char unknown_6e_;
};

struct Struct_ov017_0219d250_9 {
    unsigned char unknown_0_[2];
    unsigned char unknown_2_;
#if defined(jpn)
    unsigned char unknown_3_[0x174 - 3];
#else
    unsigned char unknown1_3_[0x178 - 3];
#endif
    unsigned char unknown_178_0_ : 1;
    unsigned char unknown_178_1_ : 7;
    unsigned char unknown_179_;
    unsigned char unknown_17a_;
    unsigned char unknown_17b_;
    float unknown_17c_;
};

struct Struct_ov017_0219d250 {
    Object3D unknown_0_;
#if defined(jpn)
    char unknown_ac_[0x150 - 0xac];
#else
    char unknown1_ac_[0x15c - 0xac];
#endif
    int unknown_15c_;
};

struct Struct_ov017_0219d250_2 {
    Object3D unknown_0_;
    char unknown_ac_[0xb8 - 0xac];
    unsigned short unknown_b8_;
    char unknown_ba_[0x130 - 0xba];
    unsigned char* unknown_130_;
};

struct Struct_ov017_0219d250_3 {
    char unknown_0_[4];
    short unknown_4_;
};

struct Struct_ov017_0219d250_4 {
    unsigned char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
};

struct Struct_ov017_0219d250_5 {
#if defined(jpn)
    char unknown_0_[0x3448];
#else
    char unknown1_0_[0x3658];
#endif
    unsigned char unknown_3658_;
    char unknown_3659_[0x36f0 - 0x3659];
    int unknown_36f0_;
    int unknown_36f4_;
    char unknown_36f8_[0x370c - 0x36f8];
    unsigned char* unknown_370c_;
    char unknown_3710_[0x3734 - 0x3710];
    Struct_ov017_0219d250_9* unknown_3734_;
#if defined(jpn)
    char unknown_3528_[0x40c9 - 0x3528];
#else
    char unknown_3738_[0x42e9 - 0x3738];
#endif
    unsigned char unknown_42e9_;
    unsigned char unknown_42ea_;
    char unknown_42eb_;
    unsigned short unknown_42ec_;
#if defined(jpn)
    char unknown_40ce_[0x4214 - 0x40ce];
#else
    char unknown_42ee_[0x44c4 - 0x42ee];
#endif
    void* unknown_44c4_;
};

extern "C" char* Zone3D_GetInstance(void);
char* MessageSystem_GetInstance(void);
void* ZoneRecords_GetInstance(void);
extern "C" void* func_02057924(void);
void* GameState_GetZoneTable(void*);
Request0219d250* GameState_GetZoneTransition(GameState* gs);
extern "C" void* LinkSession_GetInstance(void);
void* GetGlobalPtr021075f4_0203cf4c(void);
extern "C" void* Scenario_GetInstance(void);
void ClearMonsterFlagEntries_02191bdc(unsigned char*, int);
struct SearchTable;
Entry0219d250* ZoneTable_FindEntry(SearchTable*, int);
extern "C" int LinkSession_IsGuest(void* search);
void GameState_SetStoryChapter(char*, int);
void GameState_SetStoryPart(char*, int);
void GameState_SetStoryStep(char*, int);
struct SearchStruct;
int LinkSession_IsSlotMember(SearchStruct*, int);
struct SearchStruct0202c1a4;
int LinkSession_GetOwnSlot(SearchStruct0202c1a4*);
extern "C" int func_0206e558(void* flags);
extern "C" int func_ov017_0219c774(Entry0219d250* entry, int a, int b);
void* GetGlobal02109030_020936f8(void);
extern "C" void func_02094030(void* p, int a, int b, int c);
void InitStruct0203e074(char*);
extern "C" int func_0209cd50(int id);
struct ShortField0xb8_0209cae8;
int GetShortAt0xb8(ShortField0xb8_0209cae8*);
struct Actor0209c678;
void BgmPlayer_FadeOut(Actor0209c678*, int);
Entry0219d250* GetElementStride0x10_020999d8(unsigned char*, unsigned int);
extern "C" void func_ov017_0219cdc0(unsigned short value, int a1, signed char id);
extern "C" void _ZN8Object3D10SetField06Et(Object3D* obj, int value);
void GameObject_ResetTrail(unsigned char*);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
int GameObject_IsGesturing(signed char* obj);
extern "C" void func_020531f0(void* obj);
void GameObject_StopSinking(unsigned char* obj);
void MessageSystem_Reset(char* c);
extern "C" void MessageSystem_Stop(char* c);
void SetBitIfValueInTable_0219e290(void*, unsigned short);
void Clear0x80Bytes0206ebc8(void* p);
void Clear0x80BytesAt0x800206ebdc(unsigned char*);
extern "C" void func_ov017_021a316c(Battle0219d250* self);
extern "C" void func_ov017_0219de70(Battle0219d250* self, Entry0219d250* other, Entry0219d250* entry);
void SetByte0x63d5_02012040(void*);
unsigned char GameState_GetProtagonistIndex(GameState* gs);
extern "C" void func_ov017_0218f5a4(Battle0219d250* self, int id, int b, int c, int d);
extern "C" void func_0208fa8c(void* p);
struct Entry_02028bd0;
void* ZoneRecords_Find(Entry_02028bd0*, int);
struct EntryArg_0219e014;
void ProcessEntryFlagsAndCombatants_0219e014(unsigned char*, EntryArg_0219e014*);
extern "C" void ZoneRecords_ReleaseUnoccupied(void* table);
void SetFlagsForFlaggedCombatants_0219e0ec(void* self);
struct Struct_0203cfb4;
void Init0203cfb4(Struct_0203cfb4*);
struct MainBlock0205859c;
void ResetBattleEncounterState0205859c(MainBlock0205859c*);
void UpdateFlagsFromField12_0219e234(Battle0219d250*, Request0219d250*, Entry0219d250*, void*);
extern "C" void func_ov017_0219fda0(Battle0219d250* self);
void InitEntriesAndAllocators_0219fec0(void* self);
int IsIdInRange020981e4(int, int);
int LinkSession_IsActive(int* obj);
extern "C" void Party_ReformLine(Battle0219d250* self, int a, int b, int c, int d);
extern "C" int LinkSession_IsHostOrSolo(void* search);
void CallHelperWithBuf_021907dc(int, int, int, int, int);

extern char g_bgmPlayer;

#if defined(jpn)
enum { Enum_ov017_0219d250_10198 = 0x2816 };
#else
enum { Enum_ov017_0219d250_10198 = 0x27d6 };
#endif

// USA: func_ov017_0219d250
extern "C" ARM void func_ov017_0219d250(Struct_ov017_0219d250_5* arg0, unsigned char arg1) {
    Struct_ov017_0219d250_9* var0;
    Struct_ov017_0219d250_7* var1;
    int var2;
    Struct_ov017_0219d250_6* var3;
    Struct_ov017_0219d250_6* var4;
    GameState* var5;
    char* var6;
    void* var7;
    void* var8;
    GameObject* var9;
    GameObject* var10;
    void* var11;
    void* var12;
    void* var13;
    Struct_ov017_0219d250_4* var14;
    int var15;
    TimeOfDay var16;
    Struct_ov017_0219d250_2* var17;
    int var18;
    int var19;
    void* var20;
    void* var21;
    GameState* var22;
    unsigned char* var23;
    int var24;
    int var25;
    unsigned short var26;

    gs = GameState::GetInstance();
    char* field = Zone3D_GetInstance();
    controller = MessageSystem_GetInstance();
    entryTable = ZoneRecords_GetInstance();
    combatants = func_02057924();
    hero = gs->GetProtagonist();
    unknown = gs->GetLeader();
    searchTable = GameState_GetZoneTable(gs);
    request = GameState_GetZoneTransition(gs);
    search = LinkSession_GetInstance();
    extRegion = GetGlobalPtr021075f4_0203cf4c();
    party = (GrottoIds0219d250*)GameState_GetParty(gs);
    char* status = (char*)&((Zone3D*)field)->grotto_;
    Scenario_GetInstance();
    header = self->header;
    if (hero == NULL || unknown == NULL) {
        return;
    }

    ClearMonsterFlagEntries_02191bdc((unsigned char*)self, 1);
    id = request->id;
    heroZone = hero->obj3D_.GetField06();
    entry = ZoneTable_FindEntry((SearchTable*)searchTable, id);
    other = ZoneTable_FindEntry((SearchTable*)searchTable, heroZone);
    node = self->node;

    if (node->active != 0 && node->set && LinkSession_IsGuest(search)) {
        GameState_SetStoryChapter((char*)gs, node->a);
        GameState_SetStoryPart((char*)gs, node->b);
        GameState_SetStoryStep((char*)gs, node->c);
    } else {
        before = gs->GetTimeOfDay();
        if (LinkSession_IsGuest(search) && request->f60 == 0 && self->node->active == 0) {
            GameObject* lead = gs->GetPartyMemberByIndex(0);
            if ((lead != NULL && id == lead->obj3D_.GetField06()) || request->f62 != 0) {
                if (request->f62 != 0) {
                    forced = 1;
                } else {
                    var25 = 0;
                }
                gs2 = GameState::GetInstance();
                search2 = LinkSession_GetInstance();
                flags = Scenario_GetInstance();
                present = 1;
                key = entry->id;
                changed = 0;
                for (i = 1; i < 4; i++) {
                    if (LinkSession_IsSlotMember((SearchStruct*)search2, i) &&
                        i != LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search2)) {
                        Combatant0219d250* c = (Combatant0219d250*)GetCombatantWithFlag0x100_0200ff1c(gs2, i);
                        if (c != NULL && (key == c->obj3D.GetField06() || key == c->field15c)) {
                            present = 0;
                            break;
                        }
                    }
                }
                Struct_ov017_0219d250* var31 = (Struct_ov017_0219d250*)func_0200ff1c(var22, 0);
                if (var31 != NULL && (var26 == var31->unknown_0_.GetField06() || var26 == var31->unknown_15c_)) {
                    var19 = 1;
                }
                if (var25) {
                    var19 = 1;
                }
                if (var19) {
                    int var32 = func_0206e558(var20) ? 1 : 0;
                    int var33 = func_ov017_0219c774(var3, 1, 0);
                    var24 = (var32 | var33) ? 1 : 0;
                }
                if (var24) {
                    if (arg0->unknown_42e9_ != 0) {
                        func_02094030(func_020936f8(), 0x4e23, -1, 0);
                    }
                    var1->unknown_6e_ &= ~2;
                    func_0203e074((char*)var13);
                }
                if (func_0209cd50(id) != GetShortAt0xb8((ShortField0xb8_0209cae8*)&g_bgmPlayer) &&
                    request->f20 <= 0) {
                    BgmPlayer_FadeOut((Actor0209c678*)&g_bgmPlayer, 0);
                    header[0xa] = 1;
                }
            }
        }
        arg0->unknown_42e9_ = 0;
        TimeOfDay var34 = var5->GetTimeOfDay();
        if ((var16 == 0 && var34 != 0) || (var16 != 0 && var34 == 0)) {
            var1->unknown_6e_ &= ~2;
            func_0203e074((char*)var13);
        }
    }

    var0->unknown_178_0_ = 0;
    var0->unknown_178_1_ = 0;
    var0->unknown_179_ = 0;
    var0->unknown_17a_ = 0;
    var0->unknown_17b_ = 0;
    var0->unknown_17c_ = -1.0f;
    if (var1->unknown_67_ != 0) {
        var1->unknown_6e_ &= ~2;
        func_0203e074((char*)var13);
    }
    if (var3 == NULL) {
        var3 = func_020999d8((unsigned char*)var11, 0);
        var2 = var3->unknown_0_;
        var1->unknown_0_ = var2;
    }
    func_ov017_0219cdc0(var2, 1, -1);

    for (int n = 0; n < party->count; n++) {
        member = (Member0219d250*)gs->GetPartyMemberByIndex(party->ids[n]);
        if (member != NULL) {
            _ZN8Object3D10SetField06Et(&member->obj3D, id);
            member->obj3D.SetInheritedAlpha(0x1f);
            member->b8 = 0;
            GameObject_ResetTrail((unsigned char*)member);
            if (id != heroZone) {
                member->p130[8] = 0;
                func_ov017_021c9e00(party->ids[n], 1, 0, 1);
            }
        }
    }

    if (GameObject_IsGesturing((signed char*)unknown)) {
        func_020531f0(unknown);
    }
    GameObject_StopSinking((unsigned char*)hero);
    if (((MessageSystem*)controller)->active != NULL) {
        MessageSystem_Reset(controller);
    }
    MessageSystem_Stop(controller);

    int var36;
    if (var4 == NULL) {
        var36 = 1;
    } else {
        var36 = var4->unknown_5_ != var3->unknown_5_ || var4->unknown_6_ != var3->unknown_6_ || var4->unknown_7_ != var3->unknown_7_;
    }
    func_ov017_0219e290(arg0, var1->unknown_0_);
    if (var1->unknown_a_ == 0) {
        if (var36) {
            func_0206ebc8(arg0->unknown_44c4_);
        }
        if (var2 != var15) {
            func_0206ebdc((unsigned char*)arg0->unknown_44c4_);
        }
    }
    if (var2 != var15) {
        var1->unknown_6e_ &= ~2;
    }
    if (!(var1->unknown_6e_ & 2)) {
        func_ov017_021a316c(arg0);
        if (((Zone3D*)var27)->internalAllocator_.GetSignedAllocator()) {
            ((Zone3D*)var27)->internalAllocator_.Destroy();
            ((Zone3D*)var27)->internalAllocator_.ResetAllocatorPointer();
        }
        func_ov017_0219de70(arg0, var4, var3);
    }
    if (var3->unknown_c_0_ == 2 && var3->unknown_0_ != 0x170c) {
        func_02012040(var5);
    }
    if (request->pending != 0) {
        func_ov017_0218f5a4(self, GameState_GetProtagonistIndex(gs), 1, 0, 0);
        request->pending = 0;
    }
    func_0208fa8c(status);
    ProcessEntryFlagsAndCombatants_0219e014((unsigned char*)self, (EntryArg_0219e014*)(ZoneRecords_Find((Entry_02028bd0*)entryTable, heroZone)));
    ZoneRecords_ReleaseUnoccupied(entryTable);
    SetFlagsForFlaggedCombatants_0219e0ec(self);
    Init0203cfb4((Struct_0203cfb4*)extRegion);
    ResetBattleEncounterState0205859c((MainBlock0205859c*)combatants);
    UpdateFlagsFromField12_0219e234(self, request, other, entry);
    self->f36f0 = 0;
    self->f36f4 = 0;
    self->b42ea = gs->GetTimeOfDay();
    self->h42ec = 0;
    if (!(request->flags6e & 1)) {
        SetFlags04((GameResources*)self, 1);
    }
    if ((var4 == NULL || var4->unknown_0_ != 3) && var3->unknown_0_ == 3) {
        func_ov017_0219fda0(arg0);
    } else if (var4 != NULL && var4->unknown_0_ == 3 && var3->unknown_0_ != 3) {
        func_ov017_0219fec0(arg0);
    }
    self->b3658 = 0;
    ((Zone3D*)field)->SwitchZone(request->id, request->mode);
    if (IsIdInRange020981e4((int)(((Zone3D*)field)->unk_840), id) || IsIdInRange020981e4((int)(((Zone3D*)field)->unk_840), heroZone)) {
        if (LinkSession_IsActive((int*)search) == 0) {
            Party_ReformLine(self, 1, 1, 1, 1);
        } else {
            for (int k = 0; k < 4; k++) {
                if (LinkSession_IsHostOrSolo(search)) {
                    Party_ReformLine(self, 1, 1, 1, 1);
                } else {
                    func_ov017_021907dc((int)arg0, 0, 1, 1, 1);
                }
            }
        }
    }
    *(unsigned short*)(var27 + Enum_ov017_0219d250_10198) = 0;
    for (int var38 = 0; var38 < 4; var38++) {
        if (var17 != NULL && var38 != ((Struct_ov017_0219d250_3*)var10)->unknown_4_) {
            var17->unknown_0_.DisableFlag(0x1010);
        }
    }
}
