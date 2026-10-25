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

struct Struct_02013fb4;
struct Struct_02086f24_6 { void* unknown_0_; };

extern char data_020f1019[];
extern char data_020f102e[];
extern unsigned char g_fileLoadBuffer[0x30000];

int GetFieldAt0x150_02053c6c(unsigned char* obj);
void* ResourceScriptEntry_Init(void* obj);
int InitAndRunScript0208274c(void* spellTable, StreamHeader* script, int size, int arg3);
extern "C" void PartyMember_ApplyLevelStats(void* dst, void* src, void* tail);
extern "C" void PartyMember_RecalculateStats(void* model, int arg);
void SetBitsFromIndexList02083b8c(unsigned char* obj, unsigned char* learnedSpells, unsigned int count);
void ClearField00209a804(int* field);
void SetupAndRunBufferedScript0209a8b4(Ctx0209a8b4* spellTable, SafeAllocator* spellAllocator, StreamHeader* buffer, int length);
extern "C" int func_0209aa54(void* holder, unsigned char* path, unsigned char* out, int threshold);
void EnqueueEventTag176_021ce614(unsigned char combatantId, unsigned char level, unsigned char vocation);

struct Struct_020897b4 {
    unsigned char unknown_0_[0x138];
    unsigned int unknown_138_[13];
    unsigned short unknown_16c_[13];
    unsigned char unknown_186_[0x564 - 0x186];
    unsigned short unknown_564_;
    unsigned char unknown_566_[Enum_020897b4_2384 - 0x566];
    int unknown_950_;
    unsigned short unknown_954_;
};

struct Struct_020897b4_2 {
    unsigned int unknown_0_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
};

struct Struct_020897b4_3 {
    unsigned char unknown_0_[0x130];
    Struct_020897b4_2* unknown_130_;
};

// USA: func_020897b4
extern "C" ARM void func_020897b4(unsigned char arg0, unsigned char arg1, int arg2, unsigned char arg3,
                                 unsigned char arg4, void* arg5, unsigned int arg6, void* arg7, unsigned int arg8) {
    char var0[0x50];
    Struct_0201099c_2 var1;
    char var2[0x600];
    SafeAllocator var3;
    unsigned char var4[0x14];
    unsigned int var5;
    Struct_02086f24_6 var6;

    GameObject* var7 = func_0200ff1c(GameState::GetInstance(), arg0);
    if (var7 == 0) {
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
        levelScriptSize = size;
    }

    ResourceScriptEntry_Init(&entry);
    InitAndRunScript0208274c(&entry, (StreamHeader*)levelScript, levelScriptSize, level);

    ResourceScriptEntry* const levelData = &entry;
    VocationRecord* record = reinterpret_cast<VocationRecord*>(GetFieldAt0x150_02053c6c((unsigned char*)combatant));
    record->unlockedVocations |= 1 << vocation;
    record->currentVocation = vocation;
    record->levels[vocation] = level;
    record->experience[vocation] = levelData->initial.value0;
    record->unknown564 = levelData->initial.value4High;
    PartyMember_ApplyLevelStats(record, levelData, entry.variants);

    if (restoreHpMp != 0) {
        PartyMember_RecalculateStats(record, 0);
        CombatantRestorationView* actor = reinterpret_cast<CombatantRestorationView*>(combatant);
        actor->restoration->hp = combatant->baseStats_->primaryStats.maxHP;
        actor->restoration->mp = combatant->baseStats_->primaryStats.maxMP;
    }

    if (spellScript == 0) {
        if (LoadFileIntoMemory(data_020f102e, &g_fileLoadBuffer, &size) != 0) {
            spellScript = &g_fileLoadBuffer;
            spellScriptSize = size;
        }
    }

    if (arg7 != 0) {
        var3.ResetAllocatorPointer();
        var3.CreateTypeA(var2, 0x600);
        func_0209a804((int*)&var6);
        func_0209a8b4(&var6, &var3, (Struct_02013fb4*)arg7, arg8);
        unsigned int var11 = func_0209aa54(&var6, (unsigned char*)var7, var4, 0);
        func_02083b8c(reinterpret_cast<unsigned char*>(var9), var4, var11);
        var3.Destroy();
    }

    if (arg3 != 0) {
        func_ov017_021ce614(arg0, arg1, arg4);
    }

    BackgroundLoader::RemoveLockGlobal();
}
