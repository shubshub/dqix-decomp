#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/TreasureMapMetadata.h"
#include "Grotto/Main/DetailedTreasureMapData.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"


#if defined(jpn)
enum { Enum_ov004_02164738_2292 = 0x9f4, flagOffset = 0x9fb, Enum_ov004_02164738_2320 = 0xa10, Enum_ov004_02164738_6399 = 0x19ff, Enum_ov004_02164738_452 = 0x1e4, Enum_ov004_02164738_1246 = 0x29e, resetOffset = 0x790 };
#else
enum { Enum_ov004_02164738_2292 = 0x8f4, flagOffset = 0x8fb, Enum_ov004_02164738_2320 = 0x910, Enum_ov004_02164738_6399 = 0x18ff, Enum_ov004_02164738_452 = 0x1c4, Enum_ov004_02164738_1246 = 0x4de, resetOffset = 0x962 };
#endif

struct Struct_020263e4;
struct Struct_02011930;

extern "C" int func_020ac734(void* arg);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_020263e4(Struct_020263e4* buf);
extern "C" void func_02026418(unsigned char* buf, unsigned char val);
extern "C" void func_020dc2d0(int mode);
extern "C" void* func_ov011_021845f8(void* obj, int idx);
extern "C" void func_020a39d8(SafeAllocator* alloc);
extern "C" unsigned char func_02011930(void* obj, struct Struct_02011930* info, void* name1, void* name2);
extern "C" void* Scenario_GetInstance(void);
extern "C" int Scenario_RunTrigger(void* a, int mode, void* c);
extern "C" void EventQuery_RunQueuedCommands(void* p);
extern "C" int ZoneId_IsGrottoBossFloor(int x);
extern "C" void func_020e1154(void* obj);
extern "C" void func_020118fc(void* obj);
extern "C" void func_020119e8(void* obj);
extern "C" void func_02011ad4(char* obj);
extern "C" int MessageSystem_GetInstance(void);

extern char* data_ov004_02171010;

struct Struct_ov004_02164738 {
    unsigned char unknown_0_;
    TreasureMapMetadata unknown_2_[99];
};

// USA: func_ov004_02164738
extern "C" ARM int func_ov004_02164738(void* a) {
    char request[0x34];
    Struct_ov004_02164738 save;
    int i;

    save.unknown_0_ = *(unsigned char*)(data_ov004_02171010 + 0x1000 + Enum_ov004_02164738_2292);
    for (i = 0; i < 99; i++) {
        VectorizedInvertedMemcpy(data_ov004_02171010 + i * sizeof(TreasureMapMetadata), &save.unknown_2_[i], sizeof(TreasureMapMetadata));
    }
    func_020ac734(&save);

    GameState* state = GameState::GetInstance();
    char* zone = (char*)Zone3D_GetInstance();
    GameResources* res = GetGameResources();
    unsigned char* buf = (unsigned char*)res->unknown_ptr_36d0;
    res->unknown_41c8[0x42e0 - 0x41c8] = *(unsigned char*)(data_ov004_02171010 + 0x1000 + flagOffset);
    func_020263e4((Struct_020263e4*)buf);
    func_02026418(buf, 0);
    *(int*)(buf + 0x14) = *(int*)(data_ov004_02171010 + 0x1000 + Enum_ov004_02164738_2320);
    strcpy(zone + 0x26, data_ov004_02171010 + Enum_ov004_02164738_6399);
    res->allocator_array_38[12].Reset();
    func_020dc2d0(0);

    for (i = 0; i < 8; i++) {
        ((DetailedTreasureMapData*)(data_ov004_02171010 + 0xad4 + i * Enum_ov004_02164738_452))->BlankFunction();
    }

    char* owner = (char*)func_ov011_021845f8(a, 0);
    if (owner != NULL && data_ov004_02171010 != NULL) {
        ((SafeAllocator*)(owner + 4))->Free(data_ov004_02171010);
        data_ov004_02171010 = NULL;
        func_020a39d8((SafeAllocator*)(owner + 4));
    }

    if (func_02011930(state, NULL, NULL, NULL) != 0) {
        if (*((unsigned char*)state + 0x6000 + Enum_ov004_02164738_1246) != 0) {
            if (Scenario_RunTrigger(Scenario_GetInstance(), 0x1b, request)) {
                EventQuery_RunQueuedCommands(request);
            }
        }
        if (ZoneId_IsGrottoBossFloor(*(unsigned short*)zone)) {
            func_020e1154((void*)0x7d0);
        }
    }

    func_020118fc(state);
    func_020119e8(state);
    func_02011ad4((char*)state);
    *(unsigned char*)(MessageSystem_GetInstance() + 0x1000 + resetOffset) = 0;
    return 0;
}
