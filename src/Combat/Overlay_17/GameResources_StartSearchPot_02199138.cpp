#include <globaldefs.h>
#include "GameState/GameState.h"


extern "C" void* Zone3D_GetInstance(void);
extern "C" void* Scenario_GetInstance(void);
extern "C" int Scenario_RunTrigger(void* a, int mode, void* c);
extern "C" void EventQuery_RunQueuedCommands(void* p);
extern "C" void FieldTask_InitSearchPot(void* obj);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);

// The query Scenario_RunTrigger and EventQuery_RunQueuedCommands take (+0x30: the queued commands).
struct EventQuery02199138 {
    char pad0[0xc];
    int zoneId;
    char pad1[0x24 - 0x10];
    int lootableId;
    char pad2[0x34 - 0x28];
};

// Overlay 17, originally func_ov017_02199138 (USA/EUR 0x02199138, JPN 0x02199ce8)
extern "C" ARM void GameResources_StartSearchPot(char* self) {
#if defined(jpn)
 enum {searchPotTaskOffset=0x8dc, targetRecordOffset=0x4ac, targetIndexBase=0x3400, targetIndexOffset=0xa6, taskQueueOffset=0x4ec};
#else
 enum {searchPotTaskOffset=0xafc, targetRecordOffset=0x6bc, targetIndexBase=0x3600, targetIndexOffset=0xb6, taskQueueOffset=0x6fc};
#endif
    GameState* gameState = GameState::GetInstance();
    GameObject* leader = gameState->GetLeader();
    unsigned short* zone = (unsigned short*)Zone3D_GetInstance();   // its first field is the zone id
    // the task GameResources keeps for it (searchPotTaskOffset); an earlier one still queued: nothing to do
    if (*((unsigned char*)(*(void**)(self + 0x3000 + searchPotTaskOffset)) + 2) != 0) {
        return;
    }
    void* progress = Scenario_GetInstance();
    struct EventQuery02199138 query;
    query.zoneId = *zone;
    query.lootableId = *(unsigned short*)(*(void**)(self + 0x3000 + targetRecordOffset));   // the targeted pot's id
    if (Scenario_RunTrigger(progress, 0x17, &query)) {
        EventQuery_RunQueuedCommands(&query);
        return;
    }
    FieldTask_InitSearchPot(*(void**)(self + 0x3000 + searchPotTaskOffset));
    *(int*)((char*)(*(void**)(self + 0x3000 + searchPotTaskOffset)) + 0x1c) = (int)leader;              // leader
    *(unsigned short*)((char*)(*(void**)(self + 0x3000 + searchPotTaskOffset)) + 0x10) =           // lootableIndex
        *(unsigned short*)(self + targetIndexBase + targetIndexOffset);
    func_020469b4((struct TailList020469b4*)(*(void**)(self + 0x3000 + taskQueueOffset)),
                      (struct TailNode020469b4*)(*(void**)(self + 0x3000 + searchPotTaskOffset)));
}
