#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"
#include "Resource/GameResources.h"
#include "NitroSDK/Memory.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "std_library_functions.h"


struct Struct_020a99d0_3 {
    unsigned short unknown_0_[70];
    unsigned char unknown_8c_[0x15f];
    unsigned char unknown_1eb_[0xd5];
    unsigned short unknown_2c0_[6];
    unsigned char unknown_2cc_[102];
    unsigned char unknown_332_;
};

struct Struct_020a95a4_7 {
    signed char unknown_0_0_ : 6;
    unsigned char unknown_1_[0x23c - 1];
};

struct Struct_020a95a4_8 {
    unsigned char unknown_0_[0x1d4];
    unsigned char unknown_1d4_[0xe04 - 0x1d4];
    unsigned char unknown_e04_[0x128];
    unsigned char unknown_f2c_[0xf68 - 0xf2c];
    int unknown_f68_;
    int unknown_f6c_;
    int unknown_f70_;
    int unknown_f74_;
    unsigned char unknown_f78_[5];
    unsigned char unknown_f7d_;
    unsigned char unknown_f7e_[2];
    Struct_020a95a4_7 unknown_f80_[13];
    unsigned char unknown_2c8c_;
    unsigned char unknown_2c8d_[7];
    unsigned int unknown_2c94_;
};

struct Struct_020a95a4 {
    unsigned char unknown_0_[0xd98];
    unsigned char unknown_d98_[0xd98];
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

struct Struct_020a95a4_2 {
    unsigned short unknown_0_;
#if defined(jpn)
    unsigned char unknown_2_[0x860 - 2];
#else
    unsigned char unknown1_2_[0x840 - 2];
#endif
    Struct_020a95a4 unknown_840_;
#if defined(jpn)
    unsigned char unknown_23c4_[0x2774 - 0x23a4 + 0x20];
#else
    unsigned char unknown_23a4_[0x2774 - 0x23a4];
#endif
    Vector3i unknown_2774_;
    int unknown_2780_;
    short unknown_2784_;
    unsigned short unknown_2786_;
    unsigned char unknown_2788_;
    unsigned char unknown_2789_[0x2794 - 0x2789];
    int unknown_2794_;
    Vector3i unknown_2798_;
    int unknown_27a4_;
    short unknown_27a8_;
    unsigned short unknown_27aa_;
    unsigned char unknown_27ac_;
    unsigned char unknown_27ad_[3];
    int unknown_27b0_;
    unsigned short unknown_27b4_;
    unsigned short unknown_27b6_;
    unsigned char unknown_27b8_[0x27d0 - 0x27b8];
    unsigned char unknown_27d0_;
    unsigned char unknown_27d1_;
    unsigned short unknown_27d2_;
    unsigned short unknown_27d4_;
};

struct Struct_ov031_0224e6e0 {
    int unknown_0_;
    unsigned char unknown_4_[0x100d - 4];
    unsigned char unknown_100d_;
};

struct Struct_020a95a4_3 {
    unsigned char unknown_0_[0xa0];
    unsigned char unknown_a0_[0x178 - 0xa0];
    unsigned char unknown_178_[0x330];
    unsigned char unknown_4a8_[0x1a];
};

struct Struct_02109bf4_7 {
    unsigned char unknown_0_[0xc8];
    unsigned char unknown_c8_0_ : 1;
    unsigned char unknown_c8_1_ : 1;
    unsigned char unknown_c8_2_ : 1;
};

struct Struct_020a9eb8 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    TreasureMapMetadata unknown_2_[99];
};

struct Struct_020a9eb8_2 {
    unsigned char unknown_0_[0x3e4];
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
    struct Struct_020a9eb8_3 { unsigned char unknown_0_[6]; } unknown_74fe_;
    unsigned char unknown_7504_[0xec];
    unsigned char unknown_75f0_[0x4d0];
    unsigned char unknown_7ac0_[0x3b4];
    int unknown_7e74_;
};

struct Struct_020a95a4_5 {
    unsigned char unknown_0_[0x454];
    unsigned char unknown_454_[0x10];
};

struct Struct_020fdd44 {
    unsigned short unknown_0_;
    unsigned short unknown_2_0_ : 4;
    unsigned short unknown_2_4_ : 12;
    unsigned short unknown_4_;
};

struct Struct_0203dce4_2;
struct Struct_02028460_3;
struct Struct_0203e524 {
    short unknown_0_, unknown_2_, unknown_4_;
};
struct Struct_02087574;
struct Struct_02087574_2 {
    unsigned char unknown_0_[0x14];
};

struct Struct_020a95a4_6 {
    Struct_020a95a4_7 unknown_0_[13];
    unsigned char unknown_1d0c_;
    unsigned char unknown_1d0d_[4];
    unsigned char unknown_1d11_;
    struct Struct_01ff85b8 { unsigned char unknown_0_[0x12]; } unknown_1d12_[4];
    unsigned char unknown_1d5a_[2];
    unsigned char unknown_1d5c_[0x1d4];
    unsigned short unknown_1f30_[0x3f0];
    unsigned char unknown_2710_[0x3f0];
    unsigned char unknown_2b00_[8];
    unsigned char unknown_2b08_[0x128];
    int unknown_2c30_;
    int unknown_2c34_;
    int unknown_2c38_;
    int unknown_2c3c_;
    int unknown_2c40_;
    unsigned char unknown_2c44_[7];
    unsigned char unknown_2c4b_;
    unsigned short unknown_2c4c_;
    unsigned short unknown_2c4e_;
    unsigned short unknown_2c50_[4];
    unsigned char unknown_2c58_;
    unsigned char unknown_2c59_;
    unsigned char unknown_2c5a_;
    unsigned char unknown_2c5b_;
    unsigned short unknown_2c5c_;
    short unknown_2c5e_;
    Vector3i unknown_2c60_;
    int unknown_2c6c_;
    int unknown_2c70_;
    unsigned char unknown_2c74_;
    unsigned char unknown_2c75_;
    unsigned char unknown_2c76_;
    unsigned char unknown_2c77_;
    Struct_020a9eb8_2::Struct_020a9eb8_3 unknown_2c78_;
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
        unsigned char unknown_0_;
        unsigned char unknown_1_;
        unsigned char unknown_2_[2];
        char unknown_4_[8];
        float unknown_c_;
    } unknown_4_;
};

struct Struct_020a9eb8_6 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
    Struct_020a99d0_3 unknown_10_;
};

struct Struct_020a9eb8_7 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    unsigned char unknown_4_[0x190];
};

struct Struct_020a9eb8_8 {
    unsigned char unknown_0_[0xd98];
    int unknown_d98_;
    int unknown_d9c_;
    int unknown_da0_;
    unsigned short unknown_da4_;
    unsigned char unknown_da6_;
    unsigned char unknown_da7_;
};

struct Struct_020a9eb8_9 {
    unsigned char unknown_0_[0x200];
    unsigned char unknown_200_[0x200];
    int unknown_400_;
};

struct Struct_020a9eb8_10 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    Vector3i unknown_4_;
    unsigned short unknown_10_;
    unsigned short unknown_12_;
    unsigned char unknown_14_;
    unsigned char unknown_15_;
    Struct_0203e524 unknown_16_;
};

struct Struct_020a9eb8_11 {
    unsigned char unknown_0_[0x200];
    unsigned int unknown_200_;
    unsigned char unknown_204_[10];
};

struct Struct_020a9eb8_12 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    Struct_02087574_2 unknown_4_[3];
};

struct Struct_020a9eb8_13 {
    unsigned int unknown_0_;
    Struct_020a95a4_6 unknown_4_;
    Struct_020a9eb8_6 unknown_2cac_;
    unsigned char unknown_2ff0_[0xa0];
    unsigned char unknown_3090_[0x330];
    Struct_020a9eb8_7 unknown_33c0_;
    unsigned char unknown_3554_[0x4d0];
    unsigned char unknown_3a24_[0x3b4];
    unsigned char unknown_3dd8_[0xec];
    unsigned char unknown_3ec4_[0xd98];
    Struct_020a9eb8_8 unknown_4c5c_;
    Struct_020a9eb8_9 unknown_5a04_;
    Struct_020a9eb8 unknown_5e08_;
    unsigned char unknown_68de_[2];
    unsigned char unknown_68e0_[0x7c];
    Struct_020a9eb8_10 unknown_695c_;
    unsigned char unknown_6978_[0x2c4];
    unsigned char unknown_6c3c_[0x110];
    Struct_020a9eb8_11 unknown_6d4c_;
    unsigned char unknown_6f5c_[4];
};

struct Struct_020a9eb8_14 {
    unsigned char unknown_0_[0x84];
    Struct_020a9eb8_13 unknown_84_;
};

struct Struct_020a9eb8_15 {
    unsigned char unknown_0_;
    Struct_020a9eb8_14* unknown_4_;
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

Global02109418* GetGlobal02109418_02094d6c(void);
int GameState_GetProtagonistIndex(GameState* gs);
int LinkSession_IsActive(int* p);
int LinkSession_GetState(int* p);
int Scenario_TestFlag(int base, unsigned char* bits, int bit);
MonsterRecord* GetFieldAt0x150_02053c6c(unsigned char* obj);
unsigned short* GetPointerFromArray0xbd0_0207c5f8(unsigned char* roster, unsigned int idx);
unsigned char* GetPointerAt0xbf0_0207c60c(void* roster, unsigned int idx);
short GetShortFromArray0xc10_0207c620(unsigned char* roster, unsigned int idx);
unsigned char GetByteFromArray0xc28_0207c694(unsigned char* roster, unsigned int idx);
unsigned short* GameState_GetPlayerLocation(char* gs, unsigned int idx);
unsigned char GetField0xcc0209ca98(char* p);
unsigned char GetByteFieldAt0xcc_0205ea18(unsigned char* p);
int GameState_GetStoryChapter(char* gs);
int GameState_GetStoryPart(char* gs);
int GameState_GetStoryStep(char* gs);
int GetField5cbcValue_0201081c(char* gs);
void GameState_UpdatePlayClocks(int running);
int ZoneId_IsGrotto(int mapId);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* p);
int GameState_GetOwnPartyOrder(char* gs, void* out);
void CopyStruct020a99d0(Struct020a99d0* dst, Struct020a99d0* src);
int SendBattleSaveBufferOrSetFlag020ac7b4(int flag);
void EnqueueEventTag23Field_021d0d58(void);
Entry_02028bd0* ZoneRecords_GetInstance(void);
Entry_02028bd0* ZoneRecords_Find(Entry_02028bd0* base, int id);
EntryList_203dce4* GetGlobalPtr021075f4_0203cf4c(void);
int FindNearestEntryDistance0203e524(EntryList_203dce4* list, Vec3s32_020c3030* pos, OutVec3s16_0203e524* out);
Entry02087574* FindEntryBySignedId02087574(EntryTable02087574* table, int id);

extern char data_020f1bf0[];
extern AllocatorUnion g_mainAllocator;
extern Global02109bf4 g_bgmPlayer;
extern unsigned char g_sePlayer[];

static inline int inline_020a9eb8(void* arg0, unsigned int arg1) {
    return func_01ff85b8((unsigned char*)arg0 + 4, arg1 - 4);
}

// USA: func_020a9eb8
extern "C" ARM int func_020a9eb8(Struct_020a9eb8_15* arg0, Struct_020a9eb8_13* arg1, unsigned int arg2, int arg3) {
    GameState* var0;
    Struct_020a99d0_3* var1;
    Struct_020a95a4_3* var2;
    Struct_020a95a4_8* var3;
    bool var4;
    unsigned short var5;
#if defined(jpn)
    char* var21;
#else
    int var6;
#endif
    int k;
    int total;
    int j;
    int slot;
    int i;
    Global02109418* global2;
    SessionState* session2;
    int keepTimer;
    int idCount;
    gs = GameState::GetInstance();
    FieldState* field = Zone3D_GetInstance();
    SessionState* session = LinkSession_GetInstance();
    record = Scenario_GetInstance();
    global = GetGlobal02109418_02094d6c();
    battle = static_cast<BattleData*>(GameState_GetParty(gs));
    reinterpret_cast<GameStateSaveView*>(gs)->saving = 1;

    useArea = false;
    savedArea = 0;
    if ((flags & 1) || (flags & 8)) {
        useArea = true;
        if (LinkSession_IsActive(&session->state)) {
            if (LinkSession_IsGuest(session)) {
                useArea = false;
            }
        }
        if (arg2 & 8) {
            var4 = true;
        }
        if (useArea) {
            if (Scenario_TestFlag((int)record, record->flagBits, 0x113c)) {
                savedArea = battle->areaId;
            }
            var3->unknown_2c94_ = var16->unknown_0_;
            if (arg2 & 8) {
                var3->unknown_2c94_ = 0x6d;
            }
        }
    }

    Struct_020a9eb8_2* var18 = reinterpret_cast<Struct_020a9eb8_2*>(GameState::GetInstance());
    Struct_020a9eb8_4 var19;
    strcpy(var19.unknown_4_.unknown_4_, data_020f1bf0);
    var14 = arg2 & 4;
    float var20;
    if (var14) {
        var20 = var18->unknown_3e4_;
    } else {
        var20 = reinterpret_cast<GameState*>(var18)->GetDayTimer();
    }
    var19.unknown_4_.unknown_c_ = var20;
    if (!var14) {
        var18->unknown_3e4_ = var20;
    }
    var19.unknown_4_.unknown_0_ = arg3 != 0;
    var19.unknown_4_.unknown_1_ = 1;
    var19.unknown_0_ = inline_020a9eb8(&var19, sizeof(var19));
    func_02075acc(0x10, &var19, sizeof(var19), 0);
    func_020ac7b4(0);

#if defined(jpn)
    var21 = (char*)arg1 - 0x84;
#else
    char* var21 = (char*)arg1 - 0x84;
#endif
#if !defined(jpn)
    var6 = 0;
    if (arg3 == 0 && (arg2 & 0x10)) {
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
        global2 = GetGlobal02109418_02094d6c();
        func_020a0cc4(sizeof(BattleSave));
        save = (BattleSave*)AllocatorUnion_AllocateRounded(&g_mainAllocator, sizeof(BattleSave));
        if (save != NULL) {
            memset(save, 0, sizeof(BattleSave));
            GameStateSaveView::Bytes6 name;
            unsigned char ids[4];
            idCount = GameState_GetOwnPartyOrder((char*)gs2, ids);
            memcpy(save->members, battle2->members, battle2->memberCount * sizeof(BattleMemberData));
            for (i = 0; i < idCount; i++) {
                slot = i + battle2->memberCount;
                GameObject* obj = GetCombatantWithFlag0x100_0200ff1c(gs2, ids[i]);
                if (obj != NULL) {
                    MonsterRecord* rec = GetFieldAt0x150_02053c6c((unsigned char*)obj);
                    if (rec != NULL) {
                        PartyMember_WriteRecord(rec, &save->members[slot]);
                    }
                }
            }
            var22->unknown_1d0c_ = var25->unknown_2c8c_;
            for (var9 = 0; var9 < var15; var9++) {
                GameObject* var30 = func_0200ff1c(var24, var27[var9]);
                if (var30 != NULL) {
                    memcpy(&var22->unknown_1d12_[var9], func_02053c6c((unsigned char*)var30)->unknown_454_, 0x10);
                }
            }
            memcpy(save->ids, ids, 4);
            save->idCount = idCount;
            if (GameState_GetProtagonistIndex(gs2) != 0 || LinkSession_IsGuest(session2) != 0) {
                save->ids[0] = 0;
                save->idCount = 1;
            }
            memcpy(var22->unknown_1d5c_, var25->unknown_0_, sizeof(var25->unknown_0_));
            var8 = 0;
            for (var7 = 0; var7 < 8; var7++) {
                unsigned short* var31 = func_0207c5f8(var25->unknown_1d4_, var7);
                unsigned char* var32 = func_0207c60c(var25->unknown_1d4_, var7);
                short var33 = func_0207c620(var25->unknown_1d4_, var7);
                memcpy(&var22->unknown_1f30_[var8], var31, var33 * 2);
                memcpy(&var22->unknown_2710_[var8], var32, var33);
                var8 += var33;
                var22->unknown_2b00_[var7] = func_0207c694(var25->unknown_1d4_, var7);
            }
            memcpy(save->tactics, battle2->tactics, sizeof(battle2->tactics));
            save->valueF6c = battle2->valueF6c;
            save->valueF68 = battle2->valueF68;
            save->valueF70 = battle2->valueF70;
            save->valueF74 = battle2->valueF74;
            save->zero = 0;
            memcpy(save->extraIds, battle2->extraIds, sizeof(battle2->extraIds));
            GameStateSaveView* view2 = reinterpret_cast<GameStateSaveView*>(gs2);
            if (useArea) {
                save->areaId = battle2->areaId;
                view2->value7e74 = battle2->areaId;
                if (LinkSession_IsHostOrSolo(session2)) {
                    EnqueueEventTag23Field_021d0d58();
                }
            } else {
                var22->unknown_2c4c_ = var34->unknown_7e74_;
            }
            save->zero2 = 0;
            unsigned short* words = GameState_GetPlayerLocation((char*)gs2, GameState_GetProtagonistIndex(gs2));
            save->words[0] = words[0];
            save->words[1] = words[1];
            save->words[2] = words[2];
            save->words[3] = words[3];
            save->globalByte = GetField0xcc0209ca98((char*)&g_bgmPlayer);
            save->globalByte2 = GetByteFieldAt0xcc_0205ea18(g_sePlayer);
            save->byteF7d = battle2->byteF7d;
            save->byte63dc = view2->byte63dc;
            GameStateSaveView::Bytes6* namePtr = &name;
            *namePtr = view2->name74fe;
            save->name = *namePtr;
#if defined(jpn)
            Struct_020a95a4* var37 = &var23->unknown_840_;
#endif
            if (LinkSession_IsGuest(session2)) {
#if !defined(jpn)
                Struct_020a95a4* var37 = &var23->unknown_840_;
#endif
                var22->unknown_2c80_ = var37->unknown_1b50_;
                var22->unknown_2c84_ = var37->unknown_1b54_;
                var22->unknown_2c5c_ = var23->unknown_27aa_;
                var22->unknown_2c5e_ = var23->unknown_27a8_;
                var22->unknown_2c60_ = var23->unknown_2798_;
                var22->unknown_2c6c_ = var23->unknown_27a4_;
                var22->unknown_2c74_ = var23->unknown_27ac_;
                var22->unknown_2c70_ = var23->unknown_27b0_;
                var22->unknown_2c75_ = var23->unknown_27d2_;
                var22->unknown_2c76_ = var23->unknown_27d4_;
                var22->unknown_2c77_ = var23->unknown_27d1_;
            } else {
#if !defined(jpn)
                Struct_020a95a4* var37 = &var23->unknown_840_;
#endif
                var22->unknown_2c80_ = var37->unknown_1b48_;
                var22->unknown_2c84_ = var37->unknown_1b4c_;
                var37->unknown_1b50_ = var22->unknown_2c80_;
                var37->unknown_1b54_ = var22->unknown_2c84_;
                var22->unknown_2c5c_ = var23->unknown_2786_;
                var22->unknown_2c5e_ = var23->unknown_2784_;
                var22->unknown_2c60_ = var23->unknown_2774_;
                var22->unknown_2c6c_ = var23->unknown_2780_;
                var22->unknown_2c74_ = var23->unknown_2788_;
                var22->unknown_2c70_ = var23->unknown_2794_;
                var23->unknown_27aa_ = var22->unknown_2c5c_;
                var23->unknown_27a8_ = var22->unknown_2c5e_;
                var23->unknown_2798_ = var22->unknown_2c60_;
                var23->unknown_27a4_ = var22->unknown_2c6c_;
                var23->unknown_27ac_ = var22->unknown_2c74_;
                var23->unknown_27b0_ = var22->unknown_2c70_;
                var22->unknown_2c75_ = var23->unknown_27b4_;
                var22->unknown_2c76_ = var23->unknown_27b6_;
                var22->unknown_2c77_ = var23->unknown_27d0_;
                var23->unknown_27d2_ = var22->unknown_2c75_;
                var23->unknown_27d4_ = var22->unknown_2c76_;
                var23->unknown_27d1_ = var22->unknown_2c77_;
            }
            memcpy(var22->unknown_2c88_, var12->unknown_4a8_, sizeof(var12->unknown_4a8_));
#if !defined(jpn)
            var22->unknown_2ca2_ = var6;
#endif
            func_02075acc((char*)&body->battle - base, save, sizeof(BattleSave), 0);
            AllocatorUnion_Free(&g_mainAllocator, save);
        }
        ROMFilesystem_InitFileTables();
        if (Scenario_TestFlag((int)record, record->flagBits, 0x113c)) {
            battle->areaId = savedArea;
        }
    }

    {
        GameState* gs3 = GameState::GetInstance();
        LinkSession_GetInstance();
        if (keepTimer) {
            func_02075acc((char*)&body->stats - base + 0x1fb, record->block, sizeof(record->block), 0);
        } else {
            StatsSave stats;
            stats.value5cb0 = GameState_GetStoryChapter((char*)gs3);
            stats.value5cb4 = GameState_GetStoryPart((char*)gs3);
            stats.value5cb8 = GameState_GetStoryStep((char*)gs3);
            stats.value5cbc = GetField5cbcValue_0201081c((char*)gs3);
            CopyStruct020a99d0(&stats.record, record);
            func_02075acc((char*)&body->stats - base, &stats, sizeof(stats), 0);
        }
    }

    if (!keepTimer) {
        GameStateSaveView* view4 = reinterpret_cast<GameStateSaveView*>(GameState::GetInstance());
        Block194* block = (Block194*)AllocatorUnion_AllocateRounded(&g_mainAllocator, sizeof(Block194));
        if (block != NULL) {
            block->value = view4->byte5cda;
            memcpy(block->data, view4->block5cdc, sizeof(block->data));
            func_02075acc((char*)&body->block194 - base, block, sizeof(Block194), 0);
            AllocatorUnion_Free(&g_mainAllocator, block);
        }
        int offset = (char*)body->field - base;
        FieldSubState* sub = &Zone3D_GetInstance()->sub;
        func_02075acc(offset, sub->current, sizeof(sub->current), 0);
        func_020a0cc4(sizeof(FieldSave));
        FieldSave* fieldSave = (FieldSave*)AllocatorUnion_AllocateRounded(&g_mainAllocator, sizeof(FieldSave));
        if (fieldSave != NULL) {
            VectorizedInvertedMemcpy(sub->saved, fieldSave->data, sizeof(sub->saved));
            fieldSave->value1b38 = sub->value1b38;
            fieldSave->value1b34 = sub->value1b34;
            fieldSave->value1b44 = sub->value1b44;
            fieldSave->value1b3c = sub->value1b3c;
            fieldSave->byte1b61 = sub->byte1b61;
            fieldSave->zero = 0;
            func_02075acc(offset + sizeof(sub->current), fieldSave, sizeof(FieldSave), 0);
            AllocatorUnion_Free(&g_mainAllocator, fieldSave);
        }
        ROMFilesystem_InitFileTables();
        GameStateSaveView* view5 = reinterpret_cast<GameStateSaveView*>(GameState::GetInstance());
        ItemSave items;
        items.value = view5->value5f7c;
        memcpy(items.blockA, view5->block5f80, sizeof(items.blockA));
        memcpy(items.blockB, view5->block6180, sizeof(items.blockB));
        func_02075acc((char*)&body->items - base, &items, sizeof(items), 0);
        func_02075acc((char*)body->block5e6c - base, reinterpret_cast<GameStateSaveView*>(GameState::GetInstance())->block5e6c, 0x110, 0);
    }
    func_02075acc((char*)arg1->unknown_2ff0_ - var21, var2->unknown_0_, sizeof(var2->unknown_0_), 0);
    func_02075acc((char*)arg1->unknown_3090_ - var21, func_02094d6c()->unknown_178_, 0x330, 0);
    func_02075acc((char*)arg1->unknown_3554_ - var21, reinterpret_cast<Struct_020a9eb8_2*>(var0)->unknown_75f0_, 0x4d0, 0);
    func_02075acc((char*)arg1->unknown_3a24_ - var21, reinterpret_cast<Struct_020a9eb8_2*>(var0)->unknown_7ac0_, 0x3b4, 0);

    SessionState* session3 = LinkSession_GetInstance();
    int state = LinkSession_GetState(&session3->state);
    int subState = session3->subState;
    int running = 0;
    if ((state == 5 && subState > 1) || state == 6) {
        running = 1;
    }
    GameState_UpdatePlayClocks(running);

    func_02075acc((char*)arg1->unknown_3dd8_ - var21, reinterpret_cast<Struct_020a9eb8_2*>(GameState::GetInstance())->unknown_7504_, 0xec, 0);

    {
        int var51;
        int var52;
        var51 = (char*)&arg1->unknown_5e08_ - var21;
#if defined(jpn)
        FieldState* field5;
        GameState* gs5 = GameState::GetInstance();
        field5 = Zone3D_GetInstance();
#else
        GameState* gs5 = GameState::GetInstance();
        FieldState* field5 = Zone3D_GetInstance();
#endif
        Struct_020a9eb8 var55;
        if (arg3) {
            var51 += 0x8000;
        }
        VectorizedInvertedMemcpy(&reinterpret_cast<GameStateSaveView*>(gs5)->treasureMaps, &maps, sizeof(maps));
        if (!ZoneId_IsGrotto(field5->mapId)) {
            TreasureMapMetadata* map = maps.maps;
            for (n = 0; n < maps.numMaps; n++) {
                map->ClearInitialByteUnknownBit();
                map++;
            }
        }
        func_02075acc(var51, &var55, sizeof(var55), 0);
    }

    unsigned char* var57 = reinterpret_cast<Struct_020a9eb8_2*>(GameState::GetInstance())->unknown_569c_;
    func_02075acc((char*)arg1->unknown_68e0_ - var21, var57, 0x7c, 0);

    if (mode) {
        PositionSave position;
        GameObject* obj = GameState::GetInstance()->GetLeader();
        if (obj != NULL) {
            position.objectId = obj->obj3D_.GetField06();
            position.pos = obj->obj3D_.position_;
            position.rotation = obj->obj3D_.rotation_.y;
        }
        FieldState* field6 = Zone3D_GetInstance();
        Entry_02028bd0* entry = ZoneRecords_Find(ZoneRecords_GetInstance(), field6->mapId);
        if (entry == NULL) {
            position.entryValue = 0;
            position.area = 0;
        } else {
            var58.unknown_12_ = var61->unknown_4_;
            var58.unknown_10_ = var61->unknown_2_4_;
        }
        position.globalBit = g_bgmPlayer.bit2;
        position.distance = FindNearestEntryDistance0203e524(GetGlobalPtr021075f4_0203cf4c(), (Vec3s32_020c3030*)&obj->obj3D_.position_, &position.nearest);
        func_02075acc((char*)&body->position - base, &position, sizeof(position), 0);
    }

    unsigned char* var62 = reinterpret_cast<Struct_020a9eb8_2*>(GameState::GetInstance())->unknown_71fc_;
    func_02075acc((char*)arg1->unknown_6978_ - var21, var62, 0x2c4, 0);

    if (arg3) {
        if (arg3) {
            GameState* var63 = GameState::GetInstance();
            Struct_020a9eb8_2* var64 = reinterpret_cast<Struct_020a9eb8_2*>(var63);
            GetGameResources();
            Struct_020a9eb8_11 var65;
            VectorizedInvertedMemcpy(var64->unknown_6fcc_, var65.unknown_0_, sizeof(var65.unknown_0_));
            VectorizedInvertedMemcpy(var64->unknown_5cd0_, var65.unknown_204_, sizeof(var65.unknown_204_));
            var65.unknown_200_ = var64->unknown_71cc_;
            if (var63->GetGrottoStruct()->unknown_0[3]) {
                var65.unknown_200_ |= 1;
            }
            func_02075acc((char*)&arg1->unknown_6d4c_ - var21, &var65, sizeof(var65), 0);
        }
    } else if ((flags & 0x10) && mode == 0) {
        int i;
        int count;
        BattleData* battle8 = static_cast<BattleData*>(GameState_GetParty(GameState::GetInstance()));
        EntrySave entries;
        memset(&entries, 0, sizeof(entries));
        count = 0;
        for (i = 0; i < battle8->memberCount; i++) {
            Entry02087574* entry = FindEntryBySignedId02087574((EntryTable02087574*)battle8, battle8->members[i].entryId);
            if (entry != NULL) {
                memcpy(&entries.entries[count], entry, sizeof(Entry02087574));
                count++;
            }
        }
        if (var67) {
            var69.unknown_0_ = 1;
            var69.unknown_2_ = var67;
        }
        func_02075acc((char*)&arg1->unknown_6d4c_ - var21, &var69, sizeof(var69), 0);
    }

    Struct_020a9eb8_14* var71 = arg0->unknown_4_;
    if (var71 != NULL) {
        arg1->unknown_0_ = inline_020a9eb8(&var71->unknown_84_, sizeof(var71->unknown_84_));
        func_02075acc((char*)&arg1->unknown_0_ - var21, arg1, sizeof(arg1->unknown_0_), 0);
    }
    return 1;
}
