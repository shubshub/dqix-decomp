#include <globaldefs.h>
#include "Resource/ItemTable.h"
#include "Resource/KeyTable.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Util/Random.h"
#include "Combat/ResourceScriptEntry.h"
#include "Resource/SpellTable.h"
#include "std_library_functions.h"

struct PartyMemberRecord {
    signed char id : 6;
    unsigned char active : 1;
    unsigned char reserved : 1;
    unsigned char count : 4;
    unsigned char ready : 1;
    unsigned char mode : 3;
    unsigned char levels[Vocation_Count];
    unsigned char status[Vocation_Count];
    int experience[Vocation_Count];
    int vocation;
    unsigned short vocationMask;
    char pad56[2];
    PackedStats0218742c triples[Vocation_Count][3];
    unsigned short skillPoints;
    unsigned char flags[27];
    unsigned char learnedSpells[9];
    unsigned char commandFlags[36];
    unsigned char field13e;
    unsigned char cursor : 3;
    unsigned char capacity : 5;
    unsigned char name[12];
    PackedStats0218742c stats[5];
    PartyMemberAppearance appearance;
    unsigned char history[0xc0];
};

struct GameStatePartyRecords {
#if defined(jpn)
    unsigned char pad[0x3724];
#else
    unsigned char pad[0x3984];
#endif
    PartyMemberRecord memberRecords[13];
    unsigned char memberRecordCount;
};

struct PresetCharacter {
    unsigned char pad0[8];
    unsigned char female;
    unsigned char pad9;
    short defaultArms;
    unsigned char padc[0x10];
    short models[10];
    unsigned char levels[Vocation_Count];
    unsigned char vocation;
    unsigned char count;
};

struct ResetFieldsStruct {
    PresetCharacter* entries;
    short count;
    short f6;
    short f8;
    char pad0a[2];
#if defined(jpn)
    const char** maleNames;
#else
    int fc;
#endif
    short f10;
    char pad12[2];
#if defined(jpn)
    const char** femaleNames;
#else
    int f14;
#endif
    short f18;
};

struct Element020de650 {
    unsigned int v[8];
};

struct PartyMemberProfile {
    char name_[0x30];
    unsigned short maxHp_;
    unsigned short maxMp_;
    unsigned short attack_;
    unsigned short defence_;
};

struct PartyMemberDataStorage {
    PackedStats0218742c stats_[4];
    unsigned char pad10[0x2c];
    PartyMemberProfile profile;
    unsigned char pad74[0x120];
    Element020de650 equipment_[8];
#if defined(jpn)
    unsigned char pad294[0x638];
#else
    unsigned char pad294[0x6d0];
#endif
};

struct BodySize {
    short width;
    short height;
};

struct NameIdPair {
    short ids[2];
};

struct EquipmentSlotMap {
    unsigned char modelIndex;
    unsigned char equipmentIndex;
};

struct Container020e0310;
struct SetFlagBitStruct;
struct Struct020865b0;
struct SetBitArrayStruct020865b8;
struct Ctx0209a810 {
    int handle;
};

void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
void KeyTable_Construct(void* p);
void KeyTable_Reset(Struct020dfc40* p);
void KeyTable_Destroy(Struct020dfc40* p);
extern "C" void KeyTable_Load(Struct020dfc40* table, SafeAllocator* alloc, void* data, unsigned int size);
void PresetTable_Reset(ResetFieldsStruct* s);
void PresetTable_Destroy(ResetFieldsStruct* s);
void PresetTable_Load(void* param0, void* param1, const char* param2);
void* PresetTable_GetEntry(unsigned char* obj, int index);
extern "C" void PartyMemberRecord_Init(PartyMemberRecord* record);
void PartyMemberRecord_SetVocation(SetFlagBitStruct* s, int n);
char* KeyTable_Get(Container020e0310* c, int key);
extern "C" void __clear(void* dst, unsigned int size);
extern "C" int Font_EncodeText(void* a, void* b, int flag);
void ClearField00209a804(int* p);
void SpellTable_Load(Ctx0209a810* ctx, void* value);
int PartyMemberRecord_GetVocation(Struct020865b0* p);
void PartyMemberRecord_LearnSpell(SetBitArrayStruct020865b8* s, int n);
void ItemTable_Construct(void* p);
void ItemTable_Init(void* p);
extern "C" int func_020dea64(void* a, void* b, void* c, unsigned int d, const void* e, short f);
void* ResourceScriptEntry_Init(void* obj);
extern "C" void func_02082828(PartyMemberDataStorage* memberData);
extern "C" void PartyMember_ApplyLevelStats(void* dst, void* src, void* tail);
Element020de650* ItemTable_Find(ItemTable* c, int key);
extern "C" void PartyMember_RecalculateStats(void* a, int arg2);

extern AllocatorUnion g_mainAllocator;
extern char data_020ef08c[];
extern char data_020ef0a5[];
extern const NameIdPair data_020e6d64;
extern const BodySize data_020e6d98[];
extern const char* g_itemDataArchive;
extern const char* g_itemDataFile;
extern const char data_020e6d6c[];
extern const char data_020ef0b5[];
extern unsigned char g_fileLoadBuffer[];
extern const EquipmentSlotMap data_020e6d74[];
#if defined(jpn)
extern const BodySize data_020e763c[];
extern const EquipmentSlotMap data_020e7618[];
extern unsigned char data_020e7610[];
extern const char data_020eeff3[];
extern "C" int func_020e052c(void*, void*, const char*, void*, short, unsigned char);
int STD_GetStringLength(const char*);
#endif

static inline const BodySize* GetBodySize(int index) {
#if defined(jpn)
    return &data_020e763c[index];
#else
    return &data_020e6d98[index];
#endif
}

static inline const EquipmentSlotMap* GetEquipmentSlotMap(int index) {
#if defined(jpn)
    return &data_020e7618[index];
#else
    return &data_020e6d74[index];
#endif
}

static inline unsigned short GetMaxHp(const PartyMemberProfile* profile) { SDK_NULL_ASSERT(profile); return profile->maxHp_; }

static inline unsigned short GetMaxMp(const PartyMemberProfile* profile) { SDK_NULL_ASSERT(profile); return profile->maxMp_; }

static inline unsigned short GetAttack(const PartyMemberProfile* profile) { SDK_NULL_ASSERT(profile); return profile->attack_; }

static inline unsigned short GetDefence(const PartyMemberProfile* profile) { SDK_NULL_ASSERT(profile); return profile->defence_; }

// Main, originally func_0201099c (USA 0x0201099c, EUR 0x020109ac, JPN 0x020107f8)
extern "C" ARM void GameState_CreatePresetCharacters(GameStatePartyRecords* gameState) {
    SpellTable spellTable;
    ResourceScriptEntry levelStats;
    Random* rng = GetBTRandom();
    PresetCharacter* preset;
    PartyMemberRecord* member;
    long i;
    int slot;
    unsigned char presetIndices[3];
    presetIndices[0] = NextRandomMax(rng, 4);
    presetIndices[1] = NextRandomMax(rng, 2) + 4;
    unsigned char oddCount = presetIndices[0] % 2 + presetIndices[1] % 2;
    if (oddCount == 0) {
        presetIndices[2] = 7;
    } else if (oddCount == 2) {
        presetIndices[2] = 6;
    } else {
        presetIndices[2] = NextRandomMax(rng, 2) + 6;
    }

#if !defined(jpn)
    SafeAllocator nameAlloc;
    nameAlloc.ResetAllocatorPointer();
    nameAlloc.ResetAllocatorPointer();
    nameAlloc.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x5000), 0x5000);
    Struct020dfc40 names;
    KeyTable_Construct(&names);
    KeyTable_Reset(&names);
    BackgroundLoader::AddLockGlobal();
    unsigned int nameSize = 0;
    void* nameData = ExtractFileFromGP2(data_020ef08c, data_020ef0a5, &nameSize);
    if (nameData != NULL) {
        KeyTable_Load(&names, &nameAlloc, nameData, nameSize);
    }
    BackgroundLoader::RemoveLockGlobal();

    NameIdPair usedNameIds = data_020e6d64;
#endif
    ResetFieldsStruct presets;
    SafeAllocator presetAlloc;
    presetAlloc.ResetAllocatorPointer();
#if defined(jpn)
    presetAlloc.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x1400), 0x1400);
#else
    presetAlloc.ResetAllocatorPointer();
    presetAlloc.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x800), 0x800);
#endif
    PresetTable_Reset(&presets);
    PresetTable_Load(&presets, &presetAlloc, NULL);
    int presetCount = presets.count;

    for (i = 0; i < 3; i++) {
        preset = (PresetCharacter*)PresetTable_GetEntry((unsigned char*)&presets, presetIndices[i]);
        if (preset == NULL) {
            break;
        }
        slot = -1;
        if (preset->vocation == 1) {
            slot = 0;
        } else if (preset->vocation == 4) {
            slot = 0;
        } else if (preset->vocation == 2) {
            slot = 1;
        } else if (preset->vocation == 3) {
            slot = 2;
        }
        if (slot < 0) {
            continue;
        }
        member = &gameState->memberRecords[slot];
        PartyMemberRecord_Init(member);
        member->id = slot;
        member->active = 0;
        member->reserved = 0;
        member->count = preset->count;
        PartyMemberAppearance* appearance = &member->appearance;
        appearance->defaultArms_ = preset->defaultArms;
        appearance->skinColor_ = NextRandomMax(rng, 8);
        appearance->eyeColor_ = NextRandomMax(rng, 8);
        appearance->hairColor_ = NextRandomMax(rng, 10);
        appearance->female_ = preset->female;
        int bodySize = appearance->female_ * 5 + NextRandomMax(rng, 5);
        appearance->width_ = GetBodySize(bodySize)->width;
        appearance->height_ = GetBodySize(bodySize)->height;
        PartyMemberRecord_SetVocation((SetFlagBitStruct*)member, preset->vocation);
        for (int j = 0; j < Vocation_Count; j++) {
            member->levels[j] = preset->levels[j];
        }
#if defined(jpn)
        const char** name = appearance->female_ == 0 ? presets.maleNames : presets.femaleNames;
        unsigned char vocation = PartyMemberRecord_GetVocation((Struct020865b0*)member);
        if (vocation == 1) {
            name += NextRandomMax(rng, 5);
        } else if (vocation == 4) {
            name += NextRandomMax(rng, 5) + 5;
        } else if (vocation == 2) {
            name += NextRandomMax(rng, 5) + 10;
        } else if (vocation == 3) {
            name += NextRandomMax(rng, 5) + 15;
        } else {
            name += NextRandomMax(rng, 5);
        }
        memcpy(member->name, *name, STD_GetStringLength(*name));
#else
        short nameBase = 20000;
        if (appearance->female_ == 1) {
            nameBase += 1000;
        }
        short nameId;
        int found;
        do {
            found = 0;
            nameId = nameBase + NextRandomMax(rng, 101);
            for (int k = i - 1; k >= 0; k--) {
                if (nameId == usedNameIds.ids[k]) {
                    found = 1;
                }
            }
        } while (found);
        usedNameIds.ids[i] = nameId;
        char* nameStr = KeyTable_Get((Container020e0310*)&names, nameId);
        unsigned char nameBuf[12];
        __clear(nameBuf, sizeof(nameBuf));
        Font_EncodeText(nameStr, nameBuf, 1);
        memcpy(member->name, nameBuf, sizeof(nameBuf));
#endif
        short* models = &member->appearance.body_;
        for (int k = 0; k < 10; k++) {
            if (k == 2) {
                models[k] = NextRandomMax(rng, 10) + 0x233c;
            } else if (k == 3) {
                models[k] = NextRandomMax(rng, 10) + 0x2328;
            } else {
                models[k] = preset->models[k];
            }
        }
        gameState->memberRecordCount++;
    }

    PresetTable_Destroy(&presets);
    SignedAllocatorHeader* presetHeader = presetAlloc.GetSignedAllocator();
    presetAlloc.Destroy();
    AllocatorUnion_Free(&g_mainAllocator, presetHeader);
#if !defined(jpn)
    KeyTable_Destroy(&names);
    SignedAllocatorHeader* nameHeader = nameAlloc.GetSignedAllocator();
    if (nameHeader != NULL) {
        nameAlloc.Destroy();
        AllocatorUnion_Free(&g_mainAllocator, nameHeader);
    }

#endif

    if (presetCount > 0) {
        PartyMemberDataStorage record;
        Ctx0209a810 spellTableContext;
        ClearField00209a804(&spellTableContext.handle);
        SpellTable_Load(&spellTableContext, &spellTable);
        for (int j = 0; j < gameState->memberRecordCount; j++) {
            member = &gameState->memberRecords[j];
            unsigned char vocation = PartyMemberRecord_GetVocation((Struct020865b0*)member);
            unsigned char level = member->levels[vocation];
            SpellTableEntry* spells = spellTable.spells[vocation];
            for (int k = 0; k < SpellTable_SpellsPerVocation; k++) {
                if (level >= spells[k].level && spells[k].level != 0) {
                    PartyMemberRecord_LearnSpell((SetBitArrayStruct020865b8*)member, spells[k].spell);
                }
            }
        }

        SafeAllocator itemAlloc;
        itemAlloc.ResetAllocatorPointer();
        itemAlloc.ResetAllocatorPointer();
#if defined(jpn)
        itemAlloc.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x12c00), 0x12c00);
#else
        itemAlloc.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x13800), 0x13800);
#endif
        itemAlloc.Reset();
        ItemTable items;
        ItemTable_Construct(&items);
        ItemTable_Init(&items);
#if defined(jpn)
        func_020e052c(&items, &itemAlloc, g_itemDataArchive, data_020e7610, 8, 1);
#else
        BackgroundLoader::AddLockGlobal();
        unsigned int itemSize = 0;
        void* itemData = ExtractFileFromGP2(g_itemDataArchive, g_itemDataFile, &itemSize);
        if (itemData != NULL) {
            func_020dea64(&items, &itemAlloc, itemData, itemSize, data_020e6d6c, 8);
        }
        BackgroundLoader::RemoveLockGlobal();
#endif
        BackgroundLoader::AddLockGlobal();
        PartyMemberDataStorage* memberData;
        for (int vocation = 0; vocation < Vocation_Count; vocation++) {
            char path[0x19];
            unsigned int size;
#if defined(jpn)
            sprintf(path, data_020eeff3, vocation);
#else
            sprintf(path, data_020ef0b5, vocation);
#endif
            if (LoadFileIntoMemory(path, g_fileLoadBuffer, &size) != NULL) {
                ResourceScriptEntry* levelEntry = &levelStats;
                for (int j = 0; j < gameState->memberRecordCount; j++) {
                    member = &gameState->memberRecords[j];
                    ResourceScriptEntry_Init(levelEntry);
                    ResourceScriptEntry_LoadLevel(levelEntry, g_fileLoadBuffer, size, member->levels[vocation], 0);
                    member->experience[vocation] = levelEntry->initial.value0;
                    member->skillPoints += levelEntry->initial.value4High;
                    if (vocation == PartyMemberRecord_GetVocation((Struct020865b0*)member)) {
                        memberData = &record;
                        PartyMemberProfile* profile = &memberData->profile;
                        func_02082828(memberData);
                        PartyMember_ApplyLevelStats(memberData, &levelStats, levelStats.variants);
                        short* models = &member->appearance.body_;
                        for (int k = 0; k < 8; k++) {
                            Element020de650* item = ItemTable_Find(&items, models[GetEquipmentSlotMap(k)->modelIndex]);
                            if (item != NULL) {
                                memcpy(&record.equipment_[GetEquipmentSlotMap(k)->equipmentIndex], item, sizeof(Element020de650));
                            }
                        }
                        PartyMember_RecalculateStats(&record, 0);
                        member->stats[0].first = memberData->stats_[0].first;
                        member->stats[0].second = memberData->stats_[0].second;
                        member->stats[0].third = memberData->stats_[0].third;
                        member->stats[1].first = memberData->stats_[1].first;
                        member->stats[1].second = memberData->stats_[1].second;
                        member->stats[1].third = memberData->stats_[1].third;
                        member->stats[2].first = memberData->stats_[2].first;
                        member->stats[2].second = GetMaxHp(profile);
                        member->stats[2].third = GetMaxMp(profile);
                        PackedStats0218742c* currentStats = &member->stats[3];
                        currentStats->first = GetMaxHp(profile);
                        currentStats->second = GetMaxMp(profile);
                        currentStats->third = GetAttack(profile);
                        member->stats[4].first = GetDefence(profile);
                        member->stats[4].second = memberData->stats_[3].first;
                    }
                }
            }
        }
        BackgroundLoader::RemoveLockGlobal();
        SignedAllocatorHeader* itemHeader = itemAlloc.GetSignedAllocator();
        itemAlloc.Destroy();
        AllocatorUnion_Free(&g_mainAllocator, itemHeader);
    }
}
