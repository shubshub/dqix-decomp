#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x218
#define REGION_OFFSET_1 0x7000
#define REGION_OFFSET_2 0x2c
#define REGION_OFFSET_3 0x30
#define REGION_OFFSET_4 0xb40
#define REGION_OFFSET_5 0x21c
#else
#define REGION_OFFSET_0 0x29c
#define REGION_OFFSET_1 0x6000
#define REGION_OFFSET_2 0xe3c
#define REGION_OFFSET_3 0xe40
#define REGION_OFFSET_4 0x950
#define REGION_OFFSET_5 0x2a0
#endif

#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Util/Random.h"



extern "C" void LinkSession_GetInstance(void);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" void func_ov000_0215faa4(struct Random* arg0, unsigned int arg1, unsigned int arg2);
extern "C" void func_ov000_02169850(void* obj);
extern "C" void ProcessCombatTurn(void* a, void* allocator);
extern "C" void func_ov000_0215e6e8(void* p);
extern "C" void func_ov000_02160fbc(void* work, int mask);
extern "C" void func_ov000_02160e48(void* obj);
extern "C" void* Scenario_GetInstance(void);
extern "C" void Scenario_SetFlag(void* unused, unsigned char* array, int bit, int value);
extern "C" void* GameState_GetParty(GameState* battleStruct);
extern "C" void func_ov017_021d0d58(void);

// USA: func_ov000_02169770
extern "C" ARM void func_ov000_02169770(unsigned char* obj) {
    GameState* battle = GameState::GetInstance();
    LinkSession_GetInstance();
    void* var1 = *(void**)(obj + REGION_OFFSET_0);
    GameState_GetProtagonistIndex(battle);
    func_ov000_0215faa4((struct Random*)var1,
        *(unsigned int*)(obj + REGION_OFFSET_1 + REGION_OFFSET_2),
        *(unsigned int*)(obj + REGION_OFFSET_1 + REGION_OFFSET_3));
    func_ov000_02169850(obj);
    ((class SafeAllocator*)(obj + 0x30))->Reset();

    if (*(unsigned char*)(obj + 0x5000 + REGION_OFFSET_4) != 2) {
        ProcessCombatTurn(var1, obj + 0x30);
        func_ov000_0215e6e8(var1);
    }

    ((class SafeAllocator*)(obj + 0x30))->Reset();
    *(unsigned char*)(obj + 0x5000 + REGION_OFFSET_4) = 1;
    func_ov000_02160fbc(obj, 0x800000);
    func_ov000_02160e48(obj);

    if (*(int*)((char*)*(int**)(obj + REGION_OFFSET_5) + 0xc) == 0x19 &&
        *(signed char*)((char*)*(void**)(obj + REGION_OFFSET_0) + 0x8e00 + 0x14) == 1) {
        void* ctx = Scenario_GetInstance();
        Scenario_SetFlag(ctx, (unsigned char*)ctx + 0x8c, 3, 1);
        *(int*)((char*)GameState_GetParty(battle) + 0x2000 + 0xc94) = 0x6d;
        func_ov017_021d0d58();
    }
}
