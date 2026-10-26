#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"
#include "Resource/GameResources.h"
#include "NitroSDK/Memory.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "std_library_functions.h"


struct Struct020a99d0 {
    unsigned short header[70];
    unsigned char flagBits[0x15f];
    unsigned char block[0xd5];
    unsigned short unknown_2c0_[6];
    unsigned char extra[102];
    unsigned char last;
};

struct BattleMemberData {
    signed char entryId : 6;
    unsigned char unknown_1_[0x23c - 1];
};

struct BattleData {
    unsigned char head[0x1d4];
    unsigned char roster[0xe04 - 0x1d4];
    unsigned char unknown_e04_[0x128];
    unsigned char unknown_f2c_[0xf68 - 0xf2c];
    int unknown_f68_;
    int unknown_f6c_;
    int unknown_f70_;
    int unknown_f74_;
    unsigned char unknown_f78_[5];
    unsigned char unknown_f7d_;
    unsigned char unknown_f7e_[2];
    BattleMemberData members[13];
    unsigned char memberCount;
    unsigned char unknown_2c8d_[7];
    unsigned int areaId;
};

struct FieldSubState {
    unsigned char current[0xd98];
    unsigned char saved[0xd98];
    unsigned char unknown_1b30_[4];
    int unknown_1b34_;
    int unknown_1b38_;
    int unknown_1b3c_;
    unsigned char unknown_1b40_[4];
    int unknown_1b44_;
    int unknown_1b48_;
    int unknown_1b4c_;
    int unknown_1b50_;
    int unknown_1b54_;
    unsigned char unknown_1b58_[9];
    unsigned char unknown_1b61_;
};

struct FieldState {
    unsigned short mapId;
#if defined(jpn)
    unsigned char unk2[0x860 - 2];
#else
    unsigned char unk2[0x840 - 2];
#endif
    FieldSubState sub;
#if defined(jpn)
    unsigned char unknown_23c4_[0x2774 - 0x23a4 + 0x20];
#else
    unsigned char unknown_23a4_[0x2774 - 0x23a4];
#endif
    Vector3i savedPos;
    int unknown_2780_;
    short unknown_2784_;
    unsigned short unknown_2786_;
    unsigned char unknown_2788_;
    unsigned char unknown_2789_[0x2794 - 0x2789];
    int unknown_2794_;
    Vector3i pos;
    int value;
    short angle;
    unsigned short dir;
    unsigned char flag;
    unsigned char unknown_27ad_[3];
    int extra;
    unsigned short unknown_27b4_;
    unsigned short unknown_27b6_;
    unsigned char unknown_27b8_[0x27d0 - 0x27b8];
    unsigned char unknown_27d0_;
    unsigned char unknown_27d1_;
    unsigned short countA;
    unsigned short countB;
};

struct SessionState {
    int state;
    unsigned char unk4[0x100d - 4];
    unsigned char unknown_100d_;
};

struct Struct_020a95a4_3 {
    unsigned char unknown_0_[0xa0];
    unsigned char unknown_a0_[0x178 - 0xa0];
    unsigned char unknown_178_[0x330];
    unsigned char unknown_4a8_[0x1a];
};

struct Global02109bf4 {
    unsigned char unk0[0xc8];
    unsigned char bit0 : 1;
    unsigned char unknown_c8_1_ : 1;
    unsigned char bit2 : 1;
};

struct Struct_020a9eb8 {
    unsigned char unknown_0_;
    unsigned char padding;
    TreasureMapMetadata unknown_2_[99];
};

struct Struct_020a9eb8_2 {
    unsigned char unk0[0x3e4];
    float unknown_3e4_;
#if defined(jpn)
    unsigned char unknown_3e8_[0x569c - 0x3e8 - 0x260];
#else
    unsigned char unknown1_3e8_[0x569c - 0x3e8];
#endif
    unsigned char unknown_569c_[0x7c];
    unsigned char unknown_5718_[0x5cc8 - 0x5718];
    unsigned char unknown_5cc8_;
    unsigned char unknown_5cc9_[7];
    unsigned char unknown_5cd0_[10];
    unsigned char unknown_5cda_;
    unsigned char unknown_5cdb_;
    unsigned char unknown_5cdc_[0x190];
    unsigned char unknown_5e6c_[0x110];
    int unknown_5f7c_;
    unsigned char unknown_5f80_[0x200];
    unsigned char unknown_6180_[0x200];
    unsigned char unknown_6380_[0x63dc - 0x6380];
    unsigned char unknown_63dc_;
#if defined(jpn)
    unsigned char unknown_617d_[0x64f4 - 0x63dd + 0x20];
#else
    unsigned char unknown_63dd_[0x64f4 - 0x63dd];
#endif
    Struct_020a9eb8 unknown_64f4_;
    unsigned char unknown_6fca_[2];
    unsigned char unknown_6fcc_[0x200];
    unsigned int unknown_71cc_;
    unsigned char unknown_71d0_[0x71fc - 0x71d0];
    unsigned char unknown_71fc_[0x2c4];
    unsigned char unknown_74c0_[0x74fe - 0x74c0];
    struct Struct_020a9eb8_3 { unsigned char v[6]; } unknown_74fe_;
    unsigned char unknown_7504_[0xec];
    unsigned char unknown_75f0_[0x4d0];
    unsigned char unknown_7ac0_[0x3b4];
    int unknown_7e74_;
};

struct MonsterRecord {
    unsigned char unk0[0x454];
    unsigned char name[0x10];
};

struct Entry_02028bd0 {
    unsigned short id;
    unsigned short low : 4;
    unsigned short area : 12;
    unsigned short value;
};

struct Struct_0203dce4_2;
struct Struct_02028460_3;
struct Struct_0203e524 {
    short x, y, z;
};
struct Struct_02087574;
struct Struct_02087574_2 {
    unsigned char data[0x14];
};

struct BattleSave {
    BattleMemberData members[13];
    unsigned char memberCount;
    unsigned char ids[4];
    unsigned char idCount;
    struct Name { unsigned char v[0x12]; } names[4];
    unsigned char unknown_1d5a_[2];
    unsigned char head[0x1d4];
    unsigned short unknown_1f30_[0x3f0];
    unsigned char unknown_2710_[0x3f0];
    unsigned char unknown_2b00_[8];
    unsigned char unknown_2b08_[0x128];
    int unknown_2c30_;
    int unknown_2c34_;
    int unknown_2c38_;
    int unknown_2c3c_;
    int zero;
    unsigned char unknown_2c44_[7];
    unsigned char unknown_2c4b_;
    unsigned short areaId;
    unsigned short unknown_2c4e_;
    unsigned short words[4];
    unsigned char globalByte;
    unsigned char globalByte2;
    unsigned char unknown_2c5a_;
    unsigned char unknown_2c5b_;
    unsigned short dir;
    short angle;
    Vector3i pos;
    int value;
    int extra;
    unsigned char flag;
    unsigned char countA;
    unsigned char countB;
    unsigned char unknown_2c77_;
    Struct_020a9eb8_2::Struct_020a9eb8_3 name;
    unsigned char unknown_2c7e_[2];
    int unknown_2c80_;
    int unknown_2c84_;
    unsigned char unknown_2c88_[0x1a];
    unsigned char unknown_2ca2_;
    unsigned char unknown_2ca3_[5];
};

struct Struct_020a9eb8_4 {
    int unknown_0_;
    struct Struct_020a9eb8_5 {
        unsigned char resumed;
        unsigned char unknown_1_;
        unsigned char unk2[2];
        char name[8];
        float dayTimer;
    } info;
};

struct Struct_020a9eb8_6 {
    int value5cb0;
    int value5cb4;
    int value5cb8;
    int unknown_c_;
    Struct020a99d0 record;
};

struct Block194 {
    unsigned char value;
    unsigned char unknown_1_[3];
    unsigned char data[0x190];
};

struct FieldSave {
    unsigned char data[0xd98];
    int unknown_d98_;
    int unknown_d9c_;
    int unknown_da0_;
    unsigned short unknown_da4_;
    unsigned char unknown_da6_;
    unsigned char zero;
};

struct Struct_020a9eb8_9 {
    unsigned char blockA[0x200];
    unsigned char blockB[0x200];
    int value;
};

struct Struct_020a9eb8_10 {
    unsigned short objectId;
    unsigned short rotation;
    Vector3i pos;
    unsigned short area;
    unsigned short unknown_12_;
    unsigned char globalBit;
    unsigned char distance;
    Struct_0203e524 unknown_16_;
};

struct Struct_020a9eb8_11 {
    unsigned char unknown_0_[0x200];
    unsigned int flags;
    unsigned char bits[10];
};

struct Struct_020a9eb8_12 {
    unsigned short unknown_0_;
    unsigned short count;
    Struct_02087574_2 entries[3];
};

struct Struct_020a9eb8_13 {
    unsigned int unknown_0_;
    BattleSave battle;
    Struct_020a9eb8_6 stats;
    unsigned char unknown_2ff0_[0xa0];
    unsigned char unknown_3090_[0x330];
    Block194 unknown_33c0_;
    unsigned char unknown_3554_[0x4d0];
    unsigned char unknown_3a24_[0x3b4];
    unsigned char unknown_3dd8_[0xec];
    unsigned char field[0xd98];
    FieldSave unknown_4c5c_;
    Struct_020a9eb8_9 items;
    Struct_020a9eb8 unknown_5e08_;
    unsigned char unknown_68de_[2];
    unsigned char unknown_68e0_[0x7c];
    Struct_020a9eb8_10 position;
    unsigned char unknown_6978_[0x2c4];
    unsigned char unknown_6c3c_[0x110];
    Struct_020a9eb8_11 grotto;
    unsigned char unknown_6f5c_[4];
};

struct Struct_020a9eb8_14 {
    unsigned char header[0x84];
    Struct_020a9eb8_13 body;
};

struct Struct_020a9eb8_15 {
    unsigned char state;
    Struct_020a9eb8_14* file;
};

extern "C" int func_01ff85b8(void* buf, int size);
extern "C" FieldState* Zone3D_GetInstance(void);
extern "C" SessionState* LinkSession_GetInstance(void);
extern "C" Struct020a99d0* Scenario_GetInstance(void);
extern "C" int LinkSession_IsGuest(SessionState* session);
extern "C" int LinkSession_IsHostOrSolo(SessionState* session);
extern "C" int func_02075acc(int offset, void* buf, unsigned int size, int flag);
extern "C" void PartyMember_WriteRecord(MonsterRecord* record, BattleMemberData* dst);
extern "C" void ROMFilesystem_InitFileTables(void);
extern "C" void func_020a0cc4(unsigned int size);

extern "C" Struct_020a95a4_3* func_02094d6c(void);
extern "C" int GameState_GetProtagonistIndex(GameState* gs);
extern "C" int LinkSession_IsActive(int* p);
extern "C" int LinkSession_GetState(int* p);
extern "C" int Scenario_TestFlag(int base, unsigned char* bits, int bit);
extern "C" MonsterRecord* func_02053c6c(unsigned char* obj);
extern "C" unsigned short* func_0207c5f8(unsigned char* roster, unsigned int idx);
extern "C" unsigned char* func_0207c60c(void* roster, unsigned int idx);
extern "C" short func_0207c620(unsigned char* roster, unsigned int idx);
extern "C" unsigned char func_0207c694(unsigned char* roster, unsigned int idx);
extern "C" unsigned short* GameState_GetPlayerLocation(char* gs, unsigned int idx);
extern "C" unsigned char func_0209ca98(char* p);
extern "C" unsigned char func_0205ea18(unsigned char* p);
extern "C" int GameState_GetStoryChapter(char* gs);
extern "C" int GameState_GetStoryPart(char* gs);
extern "C" int GameState_GetStoryStep(char* gs);
extern "C" int func_0201081c(char* gs);
extern "C" void GameState_UpdatePlayClocks(int running);
extern "C" int ZoneId_IsGrotto(int mapId);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* p);
extern "C" int GameState_GetOwnPartyOrder(char* gs, void* out);
extern "C" void func_020a99d0(Struct020a99d0* dst, Struct020a99d0* src);
extern "C" int func_020ac7b4(int flag);
extern "C" void func_ov017_021d0d58(void);
extern "C" Entry_02028bd0* ZoneRecords_GetInstance(void);
extern "C" Entry_02028bd0* ZoneRecords_Find(Entry_02028bd0* base, int id);
extern "C" Struct_0203dce4_2* func_0203cf4c(void);
extern "C" int func_0203e524(Struct_0203dce4_2* list, Struct_02028460_3* pos, Struct_0203e524* out);
extern "C" Struct_02087574_2* func_02087574(Struct_02087574* table, int id);

extern char data_020f1bf0[];
extern AllocatorUnion g_mainAllocator;
extern Global02109bf4 g_bgmPlayer;
extern unsigned char g_sePlayer[];

static inline int inline_020a9eb8(void* data, unsigned int size) {
    return func_01ff85b8((unsigned char*)data + 4, size - 4);
}

// USA: func_020a9eb8
extern "C" ARM int func_020a9eb8(Struct_020a9eb8_15* task, Struct_020a9eb8_13* body, unsigned int flags, int mode) {
    GameState* gs;
    Struct020a99d0* record;
    Struct_020a95a4_3* global;
    BattleData* battle;
    bool var4;
    unsigned short var5;
#if defined(jpn)
    char* base;
#else
    int var6;
#endif
    int k;
    int total;
    int j;
    int slot;
    int i;
    Struct_020a95a4_3* global2;
    SessionState* session2;
    int var14;
    int idCount;
    gs = GameState::GetInstance();
    FieldState* field = Zone3D_GetInstance();
    SessionState* session = LinkSession_GetInstance();
    record = Scenario_GetInstance();
    global = func_02094d6c();
    battle = static_cast<BattleData*>(GameState_GetParty(gs));
    reinterpret_cast<Struct_020a9eb8_2*>(gs)->unknown_5cc8_ = 1;

    var4 = false;
    var5 = 0;
    if ((flags & 1) || (flags & 8)) {
        var4 = true;
        if (LinkSession_IsActive(&session->state)) {
            if (LinkSession_IsGuest(session)) {
                var4 = false;
            }
        }
        if (flags & 8) {
            var4 = true;
        }
        if (var4) {
            if (Scenario_TestFlag((int)record, record->flagBits, 0x113c)) {
                var5 = battle->areaId;
            }
            battle->areaId = field->mapId;
            if (flags & 8) {
                battle->areaId = 0x6d;
            }
        }
    }

    Struct_020a9eb8_2* view = reinterpret_cast<Struct_020a9eb8_2*>(GameState::GetInstance());
    Struct_020a9eb8_4 header;
    strcpy(header.info.name, data_020f1bf0);
    var14 = flags & 4;
    float dayTimer;
    if (var14) {
        dayTimer = view->unknown_3e4_;
    } else {
        dayTimer = reinterpret_cast<GameState*>(view)->GetDayTimer();
    }
    header.info.dayTimer = dayTimer;
    if (!var14) {
        view->unknown_3e4_ = dayTimer;
    }
    header.info.resumed = mode != 0;
    header.info.unknown_1_ = 1;
    header.unknown_0_ = inline_020a9eb8(&header, sizeof(header));
    func_02075acc(0x10, &header, sizeof(header), 0);
    func_020ac7b4(0);

#if defined(jpn)
    base = (char*)body - 0x84;
#else
    char* base = (char*)body - 0x84;
#endif
#if !defined(jpn)
    var6 = 0;
    if (mode == 0 && (flags & 0x10)) {
        var6 = 1;
    }
#endif

    {
        BattleSave* save;
        FieldState* field2;
        GameState* gs2 = GameState::GetInstance();
        BattleData* battle2 = static_cast<BattleData*>(GameState_GetParty(gs2));
        session2 = LinkSession_GetInstance();
        field2 = Zone3D_GetInstance();
        GetGameResources();
        global2 = func_02094d6c();
        func_020a0cc4(sizeof(BattleSave));
        save = (BattleSave*)AllocatorUnion_AllocateRounded(&g_mainAllocator, sizeof(BattleSave));
        if (save != NULL) {
            memset(save, 0, sizeof(BattleSave));
            Struct_020a9eb8_2::Struct_020a9eb8_3 name;
            unsigned char ids[4];
            idCount = GameState_GetOwnPartyOrder((char*)gs2, ids);
            memcpy(save->members, battle2->members, battle2->memberCount * sizeof(BattleMemberData));
            for (i = 0; i < idCount; i++) {
                slot = i + battle2->memberCount;
                GameObject* obj = func_0200ff1c(gs2, ids[i]);
                if (obj != NULL) {
                    MonsterRecord* rec = func_02053c6c((unsigned char*)obj);
                    if (rec != NULL) {
                        PartyMember_WriteRecord(rec, &save->members[slot]);
                    }
                }
            }
            save->memberCount = battle2->memberCount;
            for (j = 0; j < idCount; j++) {
                GameObject* obj = func_0200ff1c(gs2, ids[j]);
                if (obj != NULL) {
                    memcpy(&save->names[j], func_02053c6c((unsigned char*)obj)->name, 0x10);
                }
            }
            memcpy(save->ids, ids, 4);
            save->idCount = idCount;
            if (GameState_GetProtagonistIndex(gs2) != 0 || LinkSession_IsGuest(session2) != 0) {
                save->ids[0] = 0;
                save->idCount = 1;
            }
            memcpy(save->head, battle2->head, sizeof(battle2->head));
            total = 0;
            for (k = 0; k < 8; k++) {
                unsigned short* words = func_0207c5f8(battle2->roster, k);
                unsigned char* bytes = func_0207c60c(battle2->roster, k);
                short count = func_0207c620(battle2->roster, k);
                memcpy(&save->unknown_1f30_[total], words, count * 2);
                memcpy(&save->unknown_2710_[total], bytes, count);
                total += count;
                save->unknown_2b00_[k] = func_0207c694(battle2->roster, k);
            }
            memcpy(save->unknown_2b08_, battle2->unknown_e04_, sizeof(battle2->unknown_e04_));
            save->unknown_2c30_ = battle2->unknown_f6c_;
            save->unknown_2c34_ = battle2->unknown_f68_;
            save->unknown_2c38_ = battle2->unknown_f70_;
            save->unknown_2c3c_ = battle2->unknown_f74_;
            save->zero = 0;
            memcpy(save->unknown_2c44_, battle2->unknown_2c8d_, sizeof(battle2->unknown_2c8d_));
            Struct_020a9eb8_2* var34 = reinterpret_cast<Struct_020a9eb8_2*>(gs2);
            if (var4) {
                save->areaId = battle2->areaId;
                var34->unknown_7e74_ = battle2->areaId;
                if (LinkSession_IsHostOrSolo(session2)) {
                    func_ov017_021d0d58();
                }
            } else {
                save->areaId = var34->unknown_7e74_;
            }
            save->unknown_2c4e_ = 0;
            unsigned short* words = GameState_GetPlayerLocation((char*)gs2, GameState_GetProtagonistIndex(gs2));
            save->words[0] = words[0];
            save->words[1] = words[1];
            save->words[2] = words[2];
            save->words[3] = words[3];
            save->globalByte = func_0209ca98((char*)&g_bgmPlayer);
            save->globalByte2 = func_0205ea18(g_sePlayer);
            save->unknown_2c5a_ = battle2->unknown_f7d_;
            save->unknown_2c5b_ = var34->unknown_63dc_;
            Struct_020a9eb8_2::Struct_020a9eb8_3* var36 = &name;
            *var36 = var34->unknown_74fe_;
            save->name = *var36;
#if defined(jpn)
            FieldSubState* sub = &field2->sub;
#endif
            if (LinkSession_IsGuest(session2)) {
#if !defined(jpn)
                FieldSubState* sub = &field2->sub;
#endif
                save->unknown_2c80_ = sub->unknown_1b50_;
                save->unknown_2c84_ = sub->unknown_1b54_;
                save->dir = field2->dir;
                save->angle = field2->angle;
                save->pos = field2->pos;
                save->value = field2->value;
                save->flag = field2->flag;
                save->extra = field2->extra;
                save->countA = field2->countA;
                save->countB = field2->countB;
                save->unknown_2c77_ = field2->unknown_27d1_;
            } else {
#if !defined(jpn)
                FieldSubState* sub = &field2->sub;
#endif
                save->unknown_2c80_ = sub->unknown_1b48_;
                save->unknown_2c84_ = sub->unknown_1b4c_;
                sub->unknown_1b50_ = save->unknown_2c80_;
                sub->unknown_1b54_ = save->unknown_2c84_;
                save->dir = field2->unknown_2786_;
                save->angle = field2->unknown_2784_;
                save->pos = field2->savedPos;
                save->value = field2->unknown_2780_;
                save->flag = field2->unknown_2788_;
                save->extra = field2->unknown_2794_;
                field2->dir = save->dir;
                field2->angle = save->angle;
                field2->pos = save->pos;
                field2->value = save->value;
                field2->flag = save->flag;
                field2->extra = save->extra;
                save->countA = field2->unknown_27b4_;
                save->countB = field2->unknown_27b6_;
                save->unknown_2c77_ = field2->unknown_27d0_;
                field2->countA = save->countA;
                field2->countB = save->countB;
                field2->unknown_27d1_ = save->unknown_2c77_;
            }
            memcpy(save->unknown_2c88_, global2->unknown_4a8_, sizeof(global2->unknown_4a8_));
#if !defined(jpn)
            save->unknown_2ca2_ = var6;
#endif
            func_02075acc((char*)&body->battle - base, save, sizeof(BattleSave), 0);
            AllocatorUnion_Free(&g_mainAllocator, save);
        }
        ROMFilesystem_InitFileTables();
        if (Scenario_TestFlag((int)record, record->flagBits, 0x113c)) {
            battle->areaId = var5;
        }
    }

    {
        GameState* gs3 = GameState::GetInstance();
        LinkSession_GetInstance();
        if (var14) {
            func_02075acc((char*)&body->stats - base + 0x1fb, record->block, sizeof(record->block), 0);
        } else {
            Struct_020a9eb8_6 stats;
            stats.value5cb0 = GameState_GetStoryChapter((char*)gs3);
            stats.value5cb4 = GameState_GetStoryPart((char*)gs3);
            stats.value5cb8 = GameState_GetStoryStep((char*)gs3);
            stats.unknown_c_ = func_0201081c((char*)gs3);
            func_020a99d0(&stats.record, record);
            func_02075acc((char*)&body->stats - base, &stats, sizeof(stats), 0);
        }
    }

    if (!var14) {
        Struct_020a9eb8_2* var40 = reinterpret_cast<Struct_020a9eb8_2*>(GameState::GetInstance());
        Block194* block = (Block194*)AllocatorUnion_AllocateRounded(&g_mainAllocator, sizeof(Block194));
        if (block != NULL) {
            block->value = var40->unknown_5cda_;
            memcpy(block->data, var40->unknown_5cdc_, sizeof(block->data));
            func_02075acc((char*)&body->unknown_33c0_ - base, block, sizeof(Block194), 0);
            AllocatorUnion_Free(&g_mainAllocator, block);
        }
        int offset = (char*)body->field - base;
        FieldSubState* sub = &Zone3D_GetInstance()->sub;
        func_02075acc(offset, sub->current, sizeof(sub->current), 0);
        func_020a0cc4(sizeof(FieldSave));
        FieldSave* fieldSave = (FieldSave*)AllocatorUnion_AllocateRounded(&g_mainAllocator, sizeof(FieldSave));
        if (fieldSave != NULL) {
            VectorizedInvertedMemcpy(sub->saved, fieldSave->data, sizeof(sub->saved));
            fieldSave->unknown_d98_ = sub->unknown_1b38_;
            fieldSave->unknown_d9c_ = sub->unknown_1b34_;
            fieldSave->unknown_da0_ = sub->unknown_1b44_;
            fieldSave->unknown_da4_ = sub->unknown_1b3c_;
            fieldSave->unknown_da6_ = sub->unknown_1b61_;
            fieldSave->zero = 0;
            func_02075acc(offset + sizeof(sub->current), fieldSave, sizeof(FieldSave), 0);
            AllocatorUnion_Free(&g_mainAllocator, fieldSave);
        }
        ROMFilesystem_InitFileTables();
        Struct_020a9eb8_2* var45 = reinterpret_cast<Struct_020a9eb8_2*>(GameState::GetInstance());
        Struct_020a9eb8_9 items;
        items.value = var45->unknown_5f7c_;
        memcpy(items.blockA, var45->unknown_5f80_, sizeof(items.blockA));
        memcpy(items.blockB, var45->unknown_6180_, sizeof(items.blockB));
        func_02075acc((char*)&body->items - base, &items, sizeof(items), 0);
        func_02075acc((char*)body->unknown_6c3c_ - base, reinterpret_cast<Struct_020a9eb8_2*>(GameState::GetInstance())->unknown_5e6c_, 0x110, 0);
    }
    func_02075acc((char*)body->unknown_2ff0_ - base, global->unknown_0_, sizeof(global->unknown_0_), 0);
    func_02075acc((char*)body->unknown_3090_ - base, func_02094d6c()->unknown_178_, 0x330, 0);
    func_02075acc((char*)body->unknown_3554_ - base, reinterpret_cast<Struct_020a9eb8_2*>(gs)->unknown_75f0_, 0x4d0, 0);
    func_02075acc((char*)body->unknown_3a24_ - base, reinterpret_cast<Struct_020a9eb8_2*>(gs)->unknown_7ac0_, 0x3b4, 0);

    SessionState* session3 = LinkSession_GetInstance();
    int state = LinkSession_GetState(&session3->state);
    int var49 = session3->unknown_100d_;
    int running = 0;
    if ((state == 5 && var49 > 1) || state == 6) {
        running = 1;
    }
    GameState_UpdatePlayClocks(running);

    func_02075acc((char*)body->unknown_3dd8_ - base, reinterpret_cast<Struct_020a9eb8_2*>(GameState::GetInstance())->unknown_7504_, 0xec, 0);

    {
        int offset;
        int n;
        offset = (char*)&body->unknown_5e08_ - base;
#if defined(jpn)
        FieldState* field5;
        GameState* var53 = GameState::GetInstance();
        field5 = Zone3D_GetInstance();
#else
        GameState* var53 = GameState::GetInstance();
        FieldState* field5 = Zone3D_GetInstance();
#endif
        Struct_020a9eb8 var55;
        if (mode) {
            offset += 0x8000;
        }
        VectorizedInvertedMemcpy(&reinterpret_cast<Struct_020a9eb8_2*>(var53)->unknown_64f4_, &var55, sizeof(var55));
        if (!ZoneId_IsGrotto(field5->mapId)) {
            TreasureMapMetadata* map = var55.unknown_2_;
            for (n = 0; n < var55.unknown_0_; n++) {
                map->ClearInitialByteUnknownBit();
                map++;
            }
        }
        func_02075acc(offset, &var55, sizeof(var55), 0);
    }

    unsigned char* var57 = reinterpret_cast<Struct_020a9eb8_2*>(GameState::GetInstance())->unknown_569c_;
    func_02075acc((char*)body->unknown_68e0_ - base, var57, 0x7c, 0);

    if (mode) {
        Struct_020a9eb8_10 position;
        GameObject* obj = GameState::GetInstance()->GetLeader();
        if (obj != NULL) {
            position.objectId = obj->obj3D_.GetField06();
            position.pos = obj->obj3D_.position_;
            position.rotation = obj->obj3D_.rotation_.y;
        }
        FieldState* field6 = Zone3D_GetInstance();
        Entry_02028bd0* entry = ZoneRecords_Find(ZoneRecords_GetInstance(), field6->mapId);
        if (entry == NULL) {
            position.unknown_12_ = 0;
            position.area = 0;
        } else {
            position.unknown_12_ = entry->value;
            position.area = entry->area;
        }
        position.globalBit = g_bgmPlayer.bit2;
        position.distance = func_0203e524(func_0203cf4c(), (Struct_02028460_3*)&obj->obj3D_.position_, &position.unknown_16_);
        func_02075acc((char*)&body->position - base, &position, sizeof(position), 0);
    }

    unsigned char* var62 = reinterpret_cast<Struct_020a9eb8_2*>(GameState::GetInstance())->unknown_71fc_;
    func_02075acc((char*)body->unknown_6978_ - base, var62, 0x2c4, 0);

    if (mode) {
        if (mode) {
            GameState* var63 = GameState::GetInstance();
            Struct_020a9eb8_2* var64 = reinterpret_cast<Struct_020a9eb8_2*>(var63);
            GetGameResources();
            Struct_020a9eb8_11 grotto;
            VectorizedInvertedMemcpy(var64->unknown_6fcc_, grotto.unknown_0_, sizeof(grotto.unknown_0_));
            VectorizedInvertedMemcpy(var64->unknown_5cd0_, grotto.bits, sizeof(grotto.bits));
            grotto.flags = var64->unknown_71cc_;
            if (var63->GetGrottoStruct()->unknown_0[3]) {
                grotto.flags |= 1;
            }
            func_02075acc((char*)&body->grotto - base, &grotto, sizeof(grotto), 0);
        }
    } else if ((flags & 0x10) && mode == 0) {
        int i;
        int count;
        BattleData* battle8 = static_cast<BattleData*>(GameState_GetParty(GameState::GetInstance()));
        Struct_020a9eb8_12 entries;
        memset(&entries, 0, sizeof(entries));
        count = 0;
        for (i = 0; i < battle8->memberCount; i++) {
            Struct_02087574_2* entry = func_02087574((Struct_02087574*)battle8, battle8->members[i].entryId);
            if (entry != NULL) {
                memcpy(&entries.entries[count], entry, sizeof(Struct_02087574_2));
                count++;
            }
        }
        if (count) {
            entries.unknown_0_ = 1;
            entries.count = count;
        }
        func_02075acc((char*)&body->grotto - base, &entries, sizeof(entries), 0);
    }

    Struct_020a9eb8_14* file = task->file;
    if (file != NULL) {
        body->unknown_0_ = inline_020a9eb8(&file->body, sizeof(file->body));
        func_02075acc((char*)&body->unknown_0_ - base, body, sizeof(body->unknown_0_), 0);
    }
    return 1;
}
