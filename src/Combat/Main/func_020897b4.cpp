#include <globaldefs.h>

#include "Combat/Main/BattleList.h"
#include "Combat/ResourceScriptEntry.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { Enum_020897b4_2384 = 0x8b8 };
#else
enum { Enum_020897b4_2384 = 0x950 };
#endif

struct StreamHeader;
struct Ctx0209a8b4 { void* field0; };

extern char data_020f1019[];
extern char data_020f102e[];
extern unsigned char g_fileLoadBuffer[0x30000];

extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void* ResourceScriptEntry_Init(void* obj);
extern "C" int func_0208274c(void* spellTable, StreamHeader* script, int size, int arg3);
extern "C" void PartyMember_ApplyLevelStats(void* dst, void* src, void* tail);
extern "C" void PartyMember_RecalculateStats(void* model, int arg);
extern "C" void func_02083b8c(unsigned char* obj, unsigned char* learnedSpells, unsigned int count);
extern "C" void func_0209a804(int* field);
extern "C" void func_0209a8b4(Ctx0209a8b4* spellTable, SafeAllocator* arg1, StreamHeader* buffer, int length);
extern "C" int func_0209aa54(void* holder, unsigned char* path, unsigned char* out, int threshold);
extern "C" void func_ov017_021ce614(unsigned char combatantId, unsigned char level, unsigned char vocation);

struct Struct_020897b4 {
    unsigned char unknown0[0x138];
    unsigned int experience[13];
    unsigned short levels[13];
    unsigned char unknown_186_[0x564 - 0x186];
    unsigned short unknown_564_;
    unsigned char unknown_566_[Enum_020897b4_2384 - 0x566];
    int unknown_950_;
    unsigned short unknown_954_;
};

struct Struct_020897b4_2 {
    unsigned int flags;
    unsigned short hp;
    unsigned short mp;
};

struct Struct_020897b4_3 {
    unsigned char unknown0[0x130];
    Struct_020897b4_2* unknown_130_;
};

// USA: func_020897b4
extern "C" ARM void func_020897b4(unsigned char combatantId, unsigned char level, int vocation, unsigned char arg3,
                                 unsigned char arg4, void* levelScript, unsigned int arg6, void* spellScript, unsigned int arg8) {
    char path[0x50];
    ResourceScriptEntry entry;
    char heap[0x600];
    SafeAllocator var3;
    unsigned char learnedSpells[0x14];
    unsigned int size;
    Ctx0209a8b4 spellTable;

    GameObject* combatant = func_0200ff1c(GameState::GetInstance(), combatantId);
    if (combatant == 0) {
        return;
    }
    BackgroundLoader::AddLockGlobal();

    if (levelScript == 0) {
        sprintf(path, data_020f1019, vocation);
        if (LoadFileIntoMemory(path, &g_fileLoadBuffer, &size) == 0) {
            BackgroundLoader::RemoveLockGlobal();
            return;
        }
        levelScript = &g_fileLoadBuffer;
        arg6 = size;
    }

    ResourceScriptEntry_Init(&entry);
    func_0208274c(&entry, (StreamHeader*)levelScript, arg6, level);

    ResourceScriptEntry* const levelData = &entry;
    Struct_020897b4* record = reinterpret_cast<Struct_020897b4*>(func_02053c6c((unsigned char*)combatant));
    record->unknown_954_ |= 1 << vocation;
    record->unknown_950_ = vocation;
    record->levels[vocation] = level;
    record->experience[vocation] = levelData->initial.value0;
    record->unknown_564_ = levelData->initial.value4High;
    PartyMember_ApplyLevelStats(record, levelData, entry.variants);

    if (arg4 != 0) {
        PartyMember_RecalculateStats(record, 0);
        Struct_020897b4_3* actor = reinterpret_cast<Struct_020897b4_3*>(combatant);
        actor->unknown_130_->hp = combatant->baseStats_->primaryStats.maxHP;
        actor->unknown_130_->mp = combatant->baseStats_->primaryStats.maxMP;
    }

    if (spellScript == 0) {
        if (LoadFileIntoMemory(data_020f102e, &g_fileLoadBuffer, &size) != 0) {
            spellScript = &g_fileLoadBuffer;
            arg8 = size;
        }
    }

    if (spellScript != 0) {
        var3.ResetAllocatorPointer();
        var3.CreateTypeA(heap, 0x600);
        func_0209a804((int*)&spellTable);
        func_0209a8b4(&spellTable, &var3, (StreamHeader*)spellScript, arg8);
        unsigned int count = func_0209aa54(&spellTable, (unsigned char*)combatant, learnedSpells, 0);
        func_02083b8c(reinterpret_cast<unsigned char*>(record), learnedSpells, count);
        var3.Destroy();
    }

    if (arg3 != 0) {
        func_ov017_021ce614(combatantId, level, arg4);
    }

    BackgroundLoader::RemoveLockGlobal();
}
