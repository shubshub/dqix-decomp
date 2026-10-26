#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/TreasureMapMetadata.h"
#include "Grotto/Main/DetailedTreasureMapData.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"


#if defined(jpn)
enum { Enum_ov004_02164738_2292 = 0x9f4, Enum_ov004_02164738_2299 = 0x9fb, Enum_ov004_02164738_2320 = 0xa10, Enum_ov004_02164738_6399 = 0x19ff, Enum_ov004_02164738_452 = 0x1e4, Enum_ov004_02164738_1246 = 0x29e, Enum_ov004_02164738_2402 = 0x790 };
#else
enum { Enum_ov004_02164738_2292 = 0x8f4, Enum_ov004_02164738_2299 = 0x8fb, Enum_ov004_02164738_2320 = 0x910, Enum_ov004_02164738_6399 = 0x18ff, Enum_ov004_02164738_452 = 0x1c4, Enum_ov004_02164738_1246 = 0x4de, Enum_ov004_02164738_2402 = 0x962 };
#endif

struct Struct_020263e4;
struct Struct_02011930;

int CopyToBattleRegion0x64f4_020ac734(void* arg);
extern "C" void* Zone3D_GetInstance(void);
void FreeBuffer020263e4(Struct020263e4* buf);
void SetByteFieldAt0x764_02026418(unsigned char* buf, unsigned char val);
void SetCombatModeFromCase020dc2d0(int mode);
extern "C" void* func_ov011_021845f8(void* obj, int idx);
void ReleaseBattleBuffers020a39d8(SafeAllocator* alloc);
unsigned char GetAndConsumeNameEntries02011930(void* obj, struct Info02011930* info, void* name1, void* name2);
extern "C" void* Scenario_GetInstance(void);
int Scenario_RunTrigger(void* a, int mode, void* c);
extern "C" void EventQuery_RunQueuedCommands(void* p);
int ZoneId_IsGrottoBossFloor(int x);
void InitContext020e1154(void* obj);
void ResetState_020118fc(void* obj);
void ClearByte0x6480_020119e8(void* obj);
void ClearRegion0x649e02011ad4(char* obj);
int MessageSystem_GetInstance(void);

extern char* data_ov004_02171010;

struct Struct_ov004_02164738 {
    unsigned char unknown_0_;
    TreasureMapMetadata unknown_2_[99];
};

// USA: func_ov004_02164738
extern "C" ARM int func_ov004_02164738(void* arg0) {
    char var0[0x34];
    Struct_ov004_02164738 var1;
    int var2;

    var1.unknown_0_ = *(unsigned char*)(data_ov004_02171010 + 0x1000 + Enum_ov004_02164738_2292);
    for (var2 = 0; var2 < 99; var2++) {
        VectorizedInvertedMemcpy(data_ov004_02171010 + var2 * sizeof(TreasureMapMetadata), &var1.unknown_2_[var2], sizeof(TreasureMapMetadata));
    }
    func_020ac734(&var1);

    GameState* state = GameState::GetInstance();
    char* zone = (char*)Zone3D_GetInstance();
    GameResources* res = GetGameResources();
    unsigned char* buf = (unsigned char*)res->unknown_ptr_36d0;
    res->unknown_41c8[0x42e0 - 0x41c8] = *(unsigned char*)(data_ov004_02171010 + 0x1000 + flagOffset);
    FreeBuffer020263e4((Struct020263e4*)buf);
    SetByteFieldAt0x764_02026418(buf, 0);
    *(int*)(buf + 0x14) = *(int*)(data_ov004_02171010 + 0x1000 + valueOffset);
    strcpy(zone + 0x26, data_ov004_02171010 + nameOffset);
    res->allocator_array_38[12].Reset();
    SetCombatModeFromCase020dc2d0(0);

    for (var2 = 0; var2 < 8; var2++) {
        ((DetailedTreasureMapData*)(data_ov004_02171010 + 0xad4 + var2 * Enum_ov004_02164738_452))->BlankFunction();
    }

    char* var7 = (char*)func_ov011_021845f8(arg0, 0);
    if (var7 != NULL && data_ov004_02171010 != NULL) {
        ((SafeAllocator*)(var7 + 4))->Free(data_ov004_02171010);
        data_ov004_02171010 = NULL;
        func_020a39d8((SafeAllocator*)(var7 + 4));
    }

    if (GetAndConsumeNameEntries02011930(state, NULL, NULL, NULL) != 0) {
        if (*((unsigned char*)state + 0x6000 + stateFlag) != 0) {
            if (Scenario_RunTrigger(Scenario_GetInstance(), 0x1b, request)) {
                EventQuery_RunQueuedCommands(request);
            }
        }
        if (ZoneId_IsGrottoBossFloor(*(unsigned short*)zone)) {
            InitContext020e1154((void*)0x7d0);
        }
    }

    ResetState_020118fc(state);
    ClearByte0x6480_020119e8(state);
    ClearRegion0x649e02011ad4((char*)state);
    *(unsigned char*)(MessageSystem_GetInstance() + 0x1000 + resetOffset) = 0;
    return 0;
}
