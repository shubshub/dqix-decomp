#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "World/Zone3D.h"
#include "Resource/MessageSystem.h"
#include "Resource/Brightness.h"


struct Entry0219d250 {
    unsigned short id;
    unsigned char unk2[3];
    signed char x;
    signed char y;
    signed char z;
    unsigned char unknown_8_[4];
    unsigned char kind : 4;
};

struct Request0219d250 {
    unsigned short id;
    unsigned char unk2;
    unsigned char pending;
    unsigned char mode;
    unsigned char unknown_5_[5];
    unsigned char active;
    unsigned char unknown_b_[0x15];
    int f20;
    unsigned char unknown_24_[0x3c];
    unsigned char f60;
    unsigned char unknown_61_;
    unsigned char unknown_62_;
    unsigned char unknown_63_[4];
    unsigned char f67;
    unsigned char unk68[6];
    unsigned char flags6e;
};

struct Struct_ov017_0219d250_9 {
    unsigned char unk0[2];
    unsigned char active;
#if defined(jpn)
    unsigned char unknown_3_[0x174 - 3];
#else
    unsigned char unknown1_3_[0x178 - 3];
#endif
    unsigned char set : 1;
    unsigned char rest : 7;
    unsigned char a;
    unsigned char b;
    unsigned char c;
    float unknown_17c_;
};

struct Struct_ov017_0219d250 {
    Object3D obj3D;
#if defined(jpn)
    char unknown_ac_[0x150 - 0xac];
#else
    char unknown1_ac_[0x15c - 0xac];
#endif
    int field15c;
};

struct Struct_ov017_0219d250_2 {
    Object3D obj3D;
    char unknown_ac_[0xb8 - 0xac];
    unsigned short b8;
    char unknown_ba_[0x130 - 0xba];
    unsigned char* unknown_130_;
};

struct Struct_ov017_0219d250_3 {
    char pad0[4];
    short unknown_4_;
};

struct GrottoIds0219d250 {
    unsigned char unk0[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

struct Battle0219d250 {
#if defined(jpn)
    char pad0[0x3448];
#else
    char pad0[0x3658];
#endif
    unsigned char unknown_3658_;
    char unknown_3659_[0x36f0 - 0x3659];
    int unknown_36f0_;
    int unknown_36f4_;
    char unknown_36f8_[0x370c - 0x36f8];
    unsigned char* header;
    char unknown_3710_[0x3734 - 0x3710];
    Struct_ov017_0219d250_9* node;
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
extern "C" char* MessageSystem_GetInstance(void);
extern "C" void* ZoneRecords_GetInstance(void);
extern "C" void* func_02057924(void);
extern "C" void* GameState_GetZoneTable(void*);
extern "C" Request0219d250* GameState_GetZoneTransition(GameState* gs);
extern "C" void* LinkSession_GetInstance(void);
extern "C" void* func_0203cf4c(void);
extern "C" void* Scenario_GetInstance(void);
extern "C" void func_ov017_02191bdc(unsigned char*, int);
struct SearchTable;
extern "C" Entry0219d250* ZoneTable_FindEntry(SearchTable*, int);
extern "C" int LinkSession_IsGuest(void* search);
extern "C" void GameState_SetStoryChapter(char*, int);
extern "C" void GameState_SetStoryPart(char*, int);
extern "C" void GameState_SetStoryStep(char*, int);
struct SearchStruct;
extern "C" int LinkSession_IsSlotMember(SearchStruct*, int);
struct SearchStruct0202c1a4;
extern "C" int LinkSession_GetOwnSlot(SearchStruct0202c1a4*);
extern "C" int func_0206e558(void* flags);
extern "C" int func_ov017_0219c774(Entry0219d250* entry, int a, int b);
extern "C" void* func_020936f8(void);
extern "C" void func_02094030(void* p, int a, int b, int c);
extern "C" void func_0203e074(char*);
extern "C" int func_0209cd50(int id);
struct ShortField0xb8_0209cae8;
extern "C" int func_0209cae8(ShortField0xb8_0209cae8*);
struct Actor0209c678;
extern "C" void BgmPlayer_FadeOut(Actor0209c678*, int);
extern "C" Entry0219d250* func_020999d8(unsigned char*, unsigned int);
extern "C" void func_ov017_0219cdc0(unsigned short value, int a1, signed char id);
extern "C" void _ZN8Object3D10SetField06Et(Object3D* obj, int value);
extern "C" void GameObject_ResetTrail(unsigned char*);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" int GameObject_IsGesturing(signed char* obj);
extern "C" void func_020531f0(void* obj);
extern "C" void GameObject_StopSinking(unsigned char* obj);
extern "C" void MessageSystem_Reset(char* c);
extern "C" void MessageSystem_Stop(char* c);
extern "C" void func_ov017_0219e290(void*, unsigned short);
extern "C" void func_0206ebc8(void* p);
extern "C" void func_0206ebdc(unsigned char*);
extern "C" void func_ov017_021a316c(Battle0219d250* self);
extern "C" void func_ov017_0219de70(Battle0219d250* self, Entry0219d250* other, Entry0219d250* entry);
extern "C" void func_02012040(void*);
extern "C" unsigned char GameState_GetProtagonistIndex(GameState* gs);
extern "C" void func_ov017_0218f5a4(Battle0219d250* self, int id, int b, int c, int d);
extern "C" void func_0208fa8c(void* p);
struct Entry_02028bd0;
extern "C" void* ZoneRecords_Find(Entry_02028bd0*, int);
struct EntryArg_0219e014;
extern "C" void func_ov017_0219e014(unsigned char*, EntryArg_0219e014*);
extern "C" void ZoneRecords_ReleaseUnoccupied(void* table);
extern "C" void func_ov017_0219e0ec(void* self);
struct Struct_0203cfb4;
extern "C" void func_0203cfb4(Struct_0203cfb4*);
struct Struct_0205859c;
extern "C" void func_0205859c(Struct_0205859c*);
extern "C" void func_ov017_0219e234(Battle0219d250*, Request0219d250*, Entry0219d250*, void*);
extern "C" void func_ov017_0219fda0(Battle0219d250* self);
extern "C" void func_ov017_0219fec0(void* self);
extern "C" int func_020981e4(int, int);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" void Party_ReformLine(Battle0219d250* self, int a, int b, int c, int d);
extern "C" int LinkSession_IsHostOrSolo(void* search);
extern "C" void func_ov017_021907dc(int, int, int, int, int);

extern char g_bgmPlayer;

#if defined(jpn)
enum { Enum_ov017_0219d250_10198 = 0x2816 };
#else
enum { Enum_ov017_0219d250_10198 = 0x27d6 };
#endif

// USA: func_ov017_0219d250
extern "C" ARM void func_ov017_0219d250(Battle0219d250* self, unsigned char arg) {
    Struct_ov017_0219d250_9* node;
    Request0219d250* request;
    int id;
    Entry0219d250* entry;
    Entry0219d250* other;
    GameState* gs;
    char* controller;
    void* entryTable;
    void* var8;
    GameObject* hero;
    GameObject* unknown;
    void* searchTable;
    void* search;
    void* var13;
    GrottoIds0219d250* party;
    int heroZone;
    TimeOfDay before;
    Struct_ov017_0219d250_2* member;
    int i;
    int present;
    void* flags;
    void* search2;
    GameState* gs2;
    unsigned char* header;
    int changed;
    int forced;
    unsigned short key;

    gs = GameState::GetInstance();
    char* field = Zone3D_GetInstance();
    controller = MessageSystem_GetInstance();
    entryTable = ZoneRecords_GetInstance();
    var8 = func_02057924();
    hero = gs->GetProtagonist();
    unknown = gs->GetLeader();
    searchTable = GameState_GetZoneTable(gs);
    request = GameState_GetZoneTransition(gs);
    search = LinkSession_GetInstance();
    var13 = func_0203cf4c();
    party = (GrottoIds0219d250*)GameState_GetParty(gs);
    char* status = (char*)&((Zone3D*)field)->grotto_;
    Scenario_GetInstance();
    header = self->header;
    if (hero == NULL || unknown == NULL) {
        return;
    }

    func_ov017_02191bdc((unsigned char*)self, 1);
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
            GameObject* var29 = gs->GetPartyMemberByIndex(0);
            if ((var29 != NULL && id == var29->obj3D_.GetField06()) || request->unknown_62_ != 0) {
                if (request->unknown_62_ != 0) {
                    forced = 1;
                } else {
                    forced = 0;
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
                        Struct_ov017_0219d250* c = (Struct_ov017_0219d250*)func_0200ff1c(gs2, i);
                        if (c != NULL && (key == c->obj3D.GetField06() || key == c->field15c)) {
                            present = 0;
                            break;
                        }
                    }
                }
                Struct_ov017_0219d250* c0 = (Struct_ov017_0219d250*)func_0200ff1c(gs2, 0);
                if (c0 != NULL && (key == c0->obj3D.GetField06() || key == c0->field15c)) {
                    present = 1;
                }
                if (forced) {
                    present = 1;
                }
                if (present) {
                    int a = func_0206e558(flags) ? 1 : 0;
                    int b = func_ov017_0219c774(entry, 1, 0);
                    changed = (a | b) ? 1 : 0;
                }
                if (changed) {
                    if (self->unknown_42e9_ != 0) {
                        func_02094030(func_020936f8(), 0x4e23, -1, 0);
                    }
                    request->flags6e &= ~2;
                    func_0203e074((char*)var13);
                }
                if (func_0209cd50(id) != func_0209cae8((ShortField0xb8_0209cae8*)&g_bgmPlayer) &&
                    request->f20 <= 0) {
                    BgmPlayer_FadeOut((Actor0209c678*)&g_bgmPlayer, 0);
                    header[0xa] = 1;
                }
            }
        }
        self->unknown_42e9_ = 0;
        TimeOfDay after = gs->GetTimeOfDay();
        if ((before == 0 && after != 0) || (before != 0 && after == 0)) {
            request->flags6e &= ~2;
            func_0203e074((char*)var13);
        }
    }

    node->set = 0;
    node->rest = 0;
    node->a = 0;
    node->b = 0;
    node->c = 0;
    node->unknown_17c_ = -1.0f;
    if (request->f67 != 0) {
        request->flags6e &= ~2;
        func_0203e074((char*)var13);
    }
    if (entry == NULL) {
        entry = func_020999d8((unsigned char*)searchTable, 0);
        id = entry->id;
        request->id = id;
    }
    func_ov017_0219cdc0(id, 1, -1);

    for (int n = 0; n < party->count; n++) {
        member = (Struct_ov017_0219d250_2*)gs->GetPartyMemberByIndex(party->ids[n]);
        if (member != NULL) {
            _ZN8Object3D10SetField06Et(&member->obj3D, id);
            member->obj3D.SetInheritedAlpha(0x1f);
            member->b8 = 0;
            GameObject_ResetTrail((unsigned char*)member);
            if (id != heroZone) {
                member->unknown_130_[8] = 0;
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

    int moved;
    if (other == NULL) {
        moved = 1;
    } else {
        moved = other->x != entry->x || other->y != entry->y || other->z != entry->z;
    }
    func_ov017_0219e290(self, request->id);
    if (request->active == 0) {
        if (moved) {
            func_0206ebc8(self->unknown_44c4_);
        }
        if (id != heroZone) {
            func_0206ebdc((unsigned char*)self->unknown_44c4_);
        }
    }
    if (id != heroZone) {
        request->flags6e &= ~2;
    }
    if (!(request->flags6e & 2)) {
        func_ov017_021a316c(self);
        if (((Zone3D*)field)->internalAllocator_.GetSignedAllocator()) {
            ((Zone3D*)field)->internalAllocator_.Destroy();
            ((Zone3D*)field)->internalAllocator_.ResetAllocatorPointer();
        }
        func_ov017_0219de70(self, other, entry);
    }
    if (entry->kind == 2 && entry->id != 0x170c) {
        func_02012040(gs);
    }
    if (request->pending != 0) {
        func_ov017_0218f5a4(self, GameState_GetProtagonistIndex(gs), 1, 0, 0);
        request->pending = 0;
    }
    func_0208fa8c(status);
    func_ov017_0219e014((unsigned char*)self, (EntryArg_0219e014*)(ZoneRecords_Find((Entry_02028bd0*)entryTable, heroZone)));
    ZoneRecords_ReleaseUnoccupied(entryTable);
    func_ov017_0219e0ec(self);
    func_0203cfb4((Struct_0203cfb4*)var13);
    func_0205859c((Struct_0205859c*)var8);
    func_ov017_0219e234(self, request, other, entry);
    self->unknown_36f0_ = 0;
    self->unknown_36f4_ = 0;
    self->unknown_42ea_ = gs->GetTimeOfDay();
    self->unknown_42ec_ = 0;
    if (!(request->flags6e & 1)) {
        SetFlags04((GameResources*)self, 1);
    }
    if ((other == NULL || other->id != 3) && entry->id == 3) {
        func_ov017_0219fda0(self);
    } else if (other != NULL && other->id == 3 && entry->id != 3) {
        func_ov017_0219fec0(self);
    }
    self->unknown_3658_ = 0;
    ((Zone3D*)field)->SwitchZone(request->id, request->mode);
    if (func_020981e4((int)(((Zone3D*)field)->unk_840), id) || func_020981e4((int)(((Zone3D*)field)->unk_840), heroZone)) {
        if (LinkSession_IsActive((int*)search) == 0) {
            Party_ReformLine(self, 1, 1, 1, 1);
        } else {
            for (int k = 0; k < 4; k++) {
                if (LinkSession_IsHostOrSolo(search)) {
                    Party_ReformLine(self, 1, 1, 1, 1);
                } else {
                    func_ov017_021907dc((int)self, 0, 1, 1, 1);
                }
            }
        }
    }
    *(unsigned short*)(field + Enum_ov017_0219d250_10198) = 0;
    for (int j = 0; j < 4; j++) {
        if (member != NULL && j != ((Struct_ov017_0219d250_3*)unknown)->unknown_4_) {
            member->obj3D.DisableFlag(0x1010);
        }
    }
}
