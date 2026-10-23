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

extern unsigned char data_0211e33c[0x30000] __attribute__((aligned(4)));
void* LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outLength);
unsigned int FindFilesInNarcBySubstring(const void* narcBuffer, const char* substr, const void** pOutFilePtrs, unsigned int* pOutFileSizes, unsigned int maxOutputs);
struct Struct_020545b8;
struct Struct_02013fb4;
struct Struct_0203d028_11 { int unknown_0_[8]; };
union Struct_ov000_02166e5c_9 { Struct_0203d028_11 unknown_0_; ObjectArchiveLoadInfo unknown1_0_; };
struct Struct_ov000_02166e5c_10 { char unknown_0_[0x70]; };
struct Struct_02053da0 { unsigned char unknown_0_[0x578]; };
struct Struct_02000c9c_34 { unsigned char unknown_0_[0x70]; };
struct Struct_ov000_02166e5c {
#if defined(jpn)
    char unknown_0_[0x21c];
    unsigned char* unknown_2a0_;
    char unknown_220_[0x5924 - 0x220];
#else
    char unknown1_0_[0x2a0];
    unsigned char* unknown_2a0_;
    char unknown_2a4_[0x5734 - 0x2a4];
#endif
    Struct_02053da0 unknown_5734_;
    Struct_02000c9c_34 unknown_5cac_;
};
struct Struct_ov000_02166e5c_2 {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 10;
    unsigned int unknown_2_4_ : 10;
    unsigned int unknown_3_6_ : 2;
};
struct Struct_ov000_02166e5c_3 {
#if defined(jpn)
    char unknown_0_[0xb];
#else
    char unknown1_0_[0x10];
#endif
    unsigned char unknown_10_0_ : 3;
    unsigned char unknown_10_3_ : 5;
    unsigned char unknown_11_;
    unsigned char unknown_12_;
    unsigned char unknown_13_;
    Struct_ov000_02166e5c_2 unknown_14_[3];
};
#if defined(jpn)
struct Struct_ov000_02166e5c_4 { unsigned char unknown_0_[0xa4]; };
#else
struct Struct_ov000_02166e5c_4 { unsigned char unknown_0_[0xb8]; };
#endif
struct Struct_ov000_02166e5c_5 {
    unsigned int unknown_0_0_ : 32;
    unsigned short unknown_4_0_ : 7;
    unsigned short unknown_4_7_ : 9;
    unsigned short unknown_6_;
    Struct_ov000_02166e5c_2 unknown_8_[3];
};
struct Struct_ov000_02166e5c_6 {
    char unknown_0_[0x3c];
    char unknown_3c_[0x16c - 0x3c];
    unsigned short unknown_16c_[0xd];
    unsigned char unknown_186_[0x56a - 0x186];
    unsigned char unknown_56a_;
    unsigned char unknown_56b_0_ : 4;
    unsigned char unknown_56b_4_ : 4;
#if defined(jpn)
    unsigned char unknown_56c_[0x8b4 - 0x56c];
#else
    unsigned char unknown1_56c_[0x94c - 0x56c];
#endif
    int unknown_94c_;
};
struct Struct_ov000_02166e5c_7 {
    Object3D unknown_0_;
    char unknown_ac_[0xc2 - 0xac];
    unsigned char unknown_c2_;
    char unknown_c3_[0x130 - 0xc3];
    PrimaryCombatStats* unknown_130_;
    BaseCombatStats* unknown_134_;
    char* unknown_138_;
#if defined(jpn)
    char unknown_13c_[0x144 - 0x13c];
#else
    char unknown1_13c_[0x150 - 0x13c];
#endif
    Struct_ov000_02166e5c_6* unknown_150_;
};
struct Struct_ov000_02166e5c_8 {
    char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
};
struct Struct_ov000_02183014 { unsigned char unknown_0_[4]; };

void DestroyAllocators020545b8(T020545b8*);
struct Foo0207df50;
void CopyInternalFields0207df50(Foo0207df50*);
void VramState_Restore(char*);
void VramState_Save(char*);
void ClearEightWords_0203dafc(Struct_203dafc*);
struct Obj02054664;
void ResetSelectionState02054664(Obj02054664*);
void SetAndClearField0x19c_02053da0(char*, Field0x19cData*);
extern "C" void func_02049c88(Combatant02166e5c*, CombatantModelState02166e5c*);
void RunOverlayScript0216d1c4(int, StreamHeader*, int, int*);
void SetPtrFieldIfNonNull0x13c_ov000_02165480(void*, int);
void RegisterCombatantSlot_0200fd38(GameState*, int, GameObject*);
void RegisterOrAllocateCombatant02053c74(char*, int);
CombatantData02166e5c* GetFieldAt0x150_02053c6c(unsigned char*);
void ResetStruct020d3c08(char*);
struct Obj020d3c28;
void InitAndMaybeStartStream020d3c28(Obj020d3c28*);
struct FindEntryByKindContainer020d3d90;
ClassEntry02166e5c* FindEntryByKind(FindEntryByKindContainer020d3d90*, int);
extern "C" int sprintf(char*, const char*, ...);
extern "C" void PartyMember_ApplyLevelStats(CombatantData02166e5c*, Growth02166e5c*, void*);
extern "C" void func_02083e28(CombatantData02166e5c*, int);
void PartyMember_SetVocation(unsigned char*, int);
void ClearTwoRegions02083c18(char*);
void PartyMember_LearnSpell(unsigned char*, int);
void SetBitInField0x34_020a35cc(unsigned char*, unsigned char);
struct Bytes02033b88;
void SetByte0xbeShiftPrev(Bytes02033b88*, int);
struct Obj020397cc;
void CancelPendingAction020397cc(Obj020397cc*, int);
void CopyCombatantStats0208936c(char*, char*, char*);
void CopyInRegion0x571d_020114c0(char*, int, void*);
void SetCombatWorkFlags0x55f4_ov000_02160fa8(void*, int);
extern const char data_ov000_02183aa5[], data_ov000_021839e2[], data_ov000_02183abe[];
extern const char g_stringFormat[];
extern const RegionCode02166e5c data_ov000_02183014;

// USA: func_ov000_02166e5c
extern "C" ARM void func_ov000_02166e5c(Struct_ov000_02166e5c* arg0) {
    Struct_ov000_02166e5c_10* var0;
    GameState* var1 = GameState::GetInstance();
    GameResources* var2 = GetGameResources();
    SafeAllocator* var3 = &var2->allocator_array_38[3];
    var0 = (Struct_ov000_02166e5c_10*)var2->unknown_2cc_;
#if defined(jpn)
    Struct_ov000_02166e5c_10* var4 = &var0[3];
#define blocks_3 (*var4)
#else
#define blocks_3 var0[3]
#endif
    DestroyAllocators020545b8((T020545b8*)GetIndexedEntry_021a11f4(resources, 2));
    allocator->Reset();
    CopyInternalFields0207df50((Foo0207df50*)&blocks_3);
    VramState_Restore(blocks_3.bytes);
    BackgroundLoader::AddLockGlobal();
    unsigned int var5;
    if (!LoadFileIntoMemory(data_ov000_02183aa5, data_0211e33c, &var5)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    Struct_ov000_02166e5c_7* var6 = (Struct_ov000_02166e5c_7*)var3->Allocate(Enum_ov000_02166e5c_724);
    if (!var6) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    Struct_ov000_02166e5c_9 var7;
    func_0203dafc(&var7.unknown_0_);
    var7.unknown1_0_.fileData = data_0211e33c;
    var7.unknown1_0_.unk_8 = var5;
    var7.unknown1_0_.allocator = var3;
    var7.unknown1_0_.unk_10 = 1;
    func_02054664((Struct_02054664*)var6);
    if (!var6->unknown_0_.LoadFromCCHROrCMOTArchive(&var7.unknown1_0_, 0)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    var6->unknown_0_.SetScale(0x10a, 0x10a, 0x10a);
    func_02053da0((char*)var6, &arg0->unknown_5734_);
    func_02049c88(var6, &arg0->unknown_5cac_);
    const void* var8;
    unsigned int var9;
    if (FindFilesInNarcBySubstring(data_0211e33c, data_ov000_021839e2, &var8, &var9, 1)) {
        int var10 = 0;
        func_ov000_0216d1c4((int)var3, (Struct_02013fb4*)var8, var9, &var10);
        func_ov000_02165480(var6, var10);
    }
    if (!LoadFileIntoMemory(data_ov000_02183abe, data_0211e33c, &var5)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    func_0203dafc(&var7.unknown_0_);
    var7.unknown1_0_.fileData = data_0211e33c;
    var7.unknown1_0_.unk_8 = var5;
    var7.unknown1_0_.allocator = var3;
    var7.unknown1_0_.unk_10 = 1;
    if (!var6->unknown_0_.LoadFromCCHROrCMOTArchive(&var7.unknown1_0_, 0)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    func_0200fd38(var1, 1, (GameObject*)var6);
    func_02053c74((char*)var6, 1);
    Struct_ov000_02166e5c_6* var11 = func_02053c6c((unsigned char*)var6);
    if (!var11) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    ClassTable02166e5c table;
    ResetStruct020d3c08((char*)&table);
    InitAndMaybeStartStream020d3c28((Obj020d3c28*)&table);
    ClassEntry02166e5c* entry = FindEntryByKind((FindEntryByKindContainer020d3d90*)&table, 1);
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
    func_02083e28(data, 0);
    combatant->stats->maxHP = combatant->baseStats->primaryStats.maxHP;
    combatant->stats->maxMP = combatant->baseStats->primaryStats.maxMP;
    PartyMember_SetVocation((unsigned char*)data, 0);
    ClearTwoRegions02083c18((char*)data);
    PartyMember_LearnSpell((unsigned char*)data, entry->emblem);
    data->vocationTable[0] = entry->vocation;
    data->mode = 0xb;
    data->phase = 3;
    SetBitInField0x34_020a35cc(self->roster, 1);
    PartyLog02166e5c* log = (PartyLog02166e5c*)GetPtrField0x2a04_02010828(game);
    log->entries[log->count++] = 1;
    SetByte0xbeShiftPrev((Bytes02033b88*)combatant, 0);
    CancelPendingAction020397cc((Obj020397cc*)combatant, 1);
    CopyCombatantStats0208936c(combatant->savedStats, (char*)combatant->stats, (char*)combatant->baseStats);
    combatant->flags |= 0x20;
    VramState_Save(blocks_3.bytes);
    int level = entry->level;
    CombatantData02166e5c* levelData = combatant->data;
    if (levelData) levelData->level = (unsigned char)level;
    int codeLength = 2;
    RegionCode02166e5c code = data_ov000_02183014;
    CopyInRegion0x571d_020114c0((char*)game, codeLength, &code);
    SetCombatWorkFlags0x55f4_ov000_02160fa8(self, 0x400000);
    BackgroundLoader::RemoveLockGlobal();
#undef blocks_3
}
