#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
#include <GameState/GameState.h>
#include <Resource/IndexedResourceEntry.h>
#include "Resource/GameResources.h"

#if defined(jpn)
#define data_ov000_02183aa5 data_ov000_02184bd8
#define data_ov000_02183abe data_ov000_02184bf1
#define data_ov000_02183014 data_ov000_021840cc
enum { Enum_ov000_02166e5c_724 = 0x2c8 };
#else
enum { Enum_ov000_02166e5c_724 = 0x2d4 };
#endif

extern unsigned char g_fileLoadBuffer[0x30000] __attribute__((aligned(4)));
void* LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outLength);
unsigned int FindFilesInNarcBySubstring(const void* narcBuffer, const char* substr, const void** pOutFilePtrs, unsigned int* pOutFileSizes, unsigned int maxOutputs);
struct Struct_020545b8;
struct StreamHeader;
struct Struct_203dafc { int words[8]; };
union Struct_ov000_02166e5c_9 { Struct_203dafc words; ObjectArchiveLoadInfo archive; };
struct InternalBlock02166e5c { char bytes[0x70]; };
struct Struct_02053da0 { unsigned char data[0x578]; };
struct Struct_02000c9c_34 { unsigned char data[0x70]; };
struct Struct_ov000_02166e5c {
#if defined(jpn)
    char unknown_0_[0x21c];
    unsigned char* roster;
    char unknown_220_[0x5924 - 0x220];
#else
    char unknown1_0_[0x2a0];
    unsigned char* roster;
    char unknown_2a4_[0x5734 - 0x2a4];
#endif
    Struct_02053da0 selection;
    Struct_02000c9c_34 model;
};
struct Struct_ov000_02166e5c_2 {
    unsigned int first : 10;
    unsigned int second : 10;
    unsigned int third : 10;
    unsigned int rest : 2;
};
struct Struct_ov000_02166e5c_3 {
#if defined(jpn)
    char name[0xb];
#else
    char name[0x10];
#endif
    unsigned char level : 3;
    unsigned char unknown_10_3_ : 5;
    unsigned char unknown_11_;
    unsigned char vocation;
    unsigned char emblem;
    Struct_ov000_02166e5c_2 stats[3];
};
#if defined(jpn)
struct Struct_ov000_02166e5c_4 { unsigned char data[0xa4]; };
#else
struct Struct_ov000_02166e5c_4 { unsigned char data[0xb8]; };
#endif
struct Growth02166e5c {
    unsigned int experience : 32;
    unsigned short vocation : 7;
    unsigned short rank : 9;
    unsigned short unknown_6_;
    Struct_ov000_02166e5c_2 stats[3];
};
struct CombatantData02166e5c {
    char unknown_0_[0x3c];
    char name[0x16c - 0x3c];
    unsigned short unknown_16c_[0xd];
    unsigned char unknown_186_[0x56a - 0x186];
    unsigned char mode;
    unsigned char level : 4;
    unsigned char unknown_56b_4_ : 4;
#if defined(jpn)
    unsigned char unknown_56c_[0x8b4 - 0x56c];
#else
    unsigned char unknown1_56c_[0x94c - 0x56c];
#endif
    int phase;
};
struct Struct_ov000_02166e5c_7 {
    Object3D object;
    char unknown_ac_[0xc2 - 0xac];
    unsigned char flags;
    char unknown_c3_[0x130 - 0xc3];
    PrimaryCombatStats* stats;
    BaseCombatStats* baseStats;
    char* unknown_138_;
#if defined(jpn)
    char unknown_13c_[0x144 - 0x13c];
#else
    char unknown1_13c_[0x150 - 0x13c];
#endif
    CombatantData02166e5c* data;
};
struct PartyLog02166e5c {
    char unknown_0_[0xf78];
    unsigned char entries[4];
    unsigned char count;
};
struct Struct_ov000_02183014 { unsigned char bytes[4]; };

extern "C" void func_020545b8(Struct_020545b8*);
struct Foo0207df50;
extern "C" void VramState_Rewind(Foo0207df50*);
extern "C" void VramState_Restore(char*);
extern "C" void VramState_Save(char*);
extern "C" void func_0203dafc(Struct_203dafc*);
struct Struct_02054664;
extern "C" void func_02054664(Struct_02054664*);
extern "C" void func_02053da0(char*, Struct_02053da0*);
extern "C" void func_02049c88(Struct_ov000_02166e5c_7*, Struct_02000c9c_34*);
extern "C" void func_ov000_0216d1c4(int, StreamHeader*, int, int*);
extern "C" void func_ov000_02165480(void*, int);
extern "C" void func_0200fd38(GameState*, int, GameObject*);
extern "C" void func_02053c74(char*, int);
extern "C" CombatantData02166e5c* func_02053c6c(unsigned char*);
extern "C" void func_020d3c08(char*);
struct Struct_02061c04_12;
extern "C" void func_020d3c28(Struct_02061c04_12*);
struct Struct_020d3d90;
extern "C" Struct_ov000_02166e5c_3* func_020d3d90(Struct_020d3d90*, int);
extern "C" int sprintf(char*, const char*, ...);
extern "C" void PartyMember_ApplyLevelStats(CombatantData02166e5c*, Growth02166e5c*, void*);
extern "C" void PartyMember_RecalculateStats(CombatantData02166e5c*, int);
extern "C" void PartyMember_SetVocation(unsigned char*, int);
extern "C" void func_02083c18(char*);
extern "C" void PartyMember_LearnSpell(unsigned char*, int);
extern "C" void func_020a35cc(unsigned char*, unsigned char);
struct Bytes02033b88;
extern "C" void GameObject_ForceMotionState(Bytes02033b88*, int);
struct Obj020397cc;
extern "C" void GameObject_DisableControl(Obj020397cc*, int);
extern "C" void func_0208936c(char*, char*, char*);
extern "C" void GameState_SetPartyOrder(char*, int, void*);
extern "C" void func_ov000_02160fa8(void*, int);
extern const char data_ov000_02183aa5[], data_ov000_021839e2[], data_ov000_02183abe[];
extern const char g_stringFormat[];
extern const Struct_ov000_02183014 data_ov000_02183014;

// USA: func_ov000_02166e5c
extern "C" ARM void func_ov000_02166e5c(Struct_ov000_02166e5c* self) {
    InternalBlock02166e5c* blocks;
    GameState* game = GameState::GetInstance();
    GameResources* resources = GetGameResources();
    SafeAllocator* allocator = &resources->allocator_array_38[3];
    blocks = (InternalBlock02166e5c*)resources->vramStates_;
#if defined(jpn)
    InternalBlock02166e5c* pairs = &blocks[3];
#define blocks_3 (*pairs)
#else
#define blocks_3 blocks[3]
#endif
    func_020545b8((Struct_020545b8*)func_ov017_021a11f4(resources, 2));
    allocator->Reset();
    VramState_Rewind((Foo0207df50*)&blocks_3);
    VramState_Restore(blocks_3.bytes);
    BackgroundLoader::AddLockGlobal();
    unsigned int size;
    if (!LoadFileIntoMemory(data_ov000_02183aa5, g_fileLoadBuffer, &size)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    Struct_ov000_02166e5c_7* combatant = (Struct_ov000_02166e5c_7*)allocator->Allocate(Enum_ov000_02166e5c_724);
    if (!combatant) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    Struct_ov000_02166e5c_9 loadInfo;
    func_0203dafc(&loadInfo.words);
    loadInfo.archive.fileData = g_fileLoadBuffer;
    loadInfo.archive.fileSize = size;
    loadInfo.archive.allocator = allocator;
    loadInfo.archive.unk_10 = 1;
    func_02054664((Struct_02054664*)combatant);
    if (!combatant->object.LoadFromCCHROrCMOTArchive(&loadInfo.archive, 0)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    combatant->object.SetScale(0x10a, 0x10a, 0x10a);
    func_02053da0((char*)combatant, &self->selection);
    func_02049c88(combatant, &self->model);
    const void* script;
    unsigned int scriptSize;
    if (FindFilesInNarcBySubstring(g_fileLoadBuffer, data_ov000_021839e2, &script, &scriptSize, 1)) {
        int scriptState = 0;
        func_ov000_0216d1c4((int)allocator, (StreamHeader*)script, scriptSize, &scriptState);
        func_ov000_02165480(combatant, scriptState);
    }
    if (!LoadFileIntoMemory(data_ov000_02183abe, g_fileLoadBuffer, &size)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    func_0203dafc(&loadInfo.words);
    loadInfo.archive.fileData = g_fileLoadBuffer;
    loadInfo.archive.fileSize = size;
    loadInfo.archive.allocator = allocator;
    loadInfo.archive.unk_10 = 1;
    if (!combatant->object.LoadFromCCHROrCMOTArchive(&loadInfo.archive, 0)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    func_0200fd38(game, 1, (GameObject*)combatant);
    func_02053c74((char*)combatant, 1);
    CombatantData02166e5c* data = func_02053c6c((unsigned char*)combatant);
    if (!data) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    Struct_ov000_02166e5c_4 table;
    func_020d3c08((char*)&table);
    func_020d3c28((Struct_02061c04_12*)&table);
    Struct_ov000_02166e5c_3* entry = func_020d3d90((Struct_020d3d90*)&table, 1);
    sprintf(data->name, g_stringFormat, entry);
    Growth02166e5c growth;
    growth.experience = 0;
    growth.rank = 0;
    growth.vocation = entry->vocation;
    growth.stats[0].first = entry->stats[0].first;
    growth.stats[0].second = entry->stats[0].second;
    growth.stats[0].third = entry->stats[0].third;
    growth.stats[1].first = entry->stats[1].first;
    growth.stats[1].second = entry->stats[1].second;
    growth.stats[1].third = entry->stats[1].third;
    growth.stats[2].first = entry->stats[2].first;
    growth.stats[2].second = entry->stats[2].second;
    growth.stats[2].third = entry->stats[2].third;
    PartyMember_ApplyLevelStats(data, &growth, 0);
    PartyMember_RecalculateStats(data, 0);
    combatant->stats->maxHP = combatant->baseStats->primaryStats.maxHP;
    combatant->stats->maxMP = combatant->baseStats->primaryStats.maxMP;
    PartyMember_SetVocation((unsigned char*)data, 0);
    func_02083c18((char*)data);
    PartyMember_LearnSpell((unsigned char*)data, entry->emblem);
    data->unknown_16c_[0] = entry->vocation;
    data->mode = 0xb;
    data->phase = 3;
    func_020a35cc(self->roster, 1);
    PartyLog02166e5c* log = (PartyLog02166e5c*)GameState_GetParty(game);
    log->entries[log->count++] = 1;
    GameObject_ForceMotionState((Bytes02033b88*)combatant, 0);
    GameObject_DisableControl((Obj020397cc*)combatant, 1);
    func_0208936c(combatant->unknown_138_, (char*)combatant->stats, (char*)combatant->baseStats);
    combatant->flags |= 0x20;
    VramState_Save(blocks_3.bytes);
    int level = entry->level;
    CombatantData02166e5c* levelData = combatant->data;
    if (levelData) levelData->level = (unsigned char)level;
    int codeLength = 2;
    Struct_ov000_02183014 code = data_ov000_02183014;
    GameState_SetPartyOrder((char*)game, codeLength, &code);
    func_ov000_02160fa8(self, 0x400000);
    BackgroundLoader::RemoveLockGlobal();
#undef blocks_3
}
