#if defined(jpn)
enum { targetRecordOffset = 0x4ac, targetBase = 0x3400, targetIndexOffset = 0xa6, targetAngleOffset = 0xb6, openChestTaskOffset = 0x904, taskQueueOffset = 0x4ec };
#else
enum { targetRecordOffset = 0x6bc, targetBase = 0x3600, targetIndexOffset = 0xb6, targetAngleOffset = 0xc6, openChestTaskOffset = 0xb24, taskQueueOffset = 0x6fc };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/FieldTask.h"
#include "World/Zone3D.h"


extern "C" void* Scenario_GetInstance(void);
extern "C" int Scenario_RunTrigger(void* a, int mode, void* c);
extern "C" void EventQuery_RunQueuedCommands(void* p);
extern "C" void FieldTask_InitOpenChest(OpenChestTask* self);
extern "C" unsigned char GameState_GetLeaderIndex(GameState* battleStruct);
int fix32ReduceAngle0To2Pi(int angle);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);

// The query Scenario_RunTrigger and EventQuery_RunQueuedCommands take.
struct EventQuery {
    char pad0[0x20];
    int chestId;        // trigger kind 0x12 (a chest already open): the chest's container id
    char pad24[0xc];
    void* commands;     // the deferred commands: Scenario_RunTrigger clears it, EventQuery_RunQueuedCommands runs them
};

// Overlay 17, originally func_ov017_0219922c (USA/EUR 0x0219922c, JPN 0x02199ddc)
extern "C" ARM void GameResources_StartOpenChest(unsigned char* self) {
    GameState* gs = GameState::GetInstance();
    ZoneChestRenderRecord* chest = *(ZoneChestRenderRecord**)(self + 0x3000 + targetRecordOffset);
    int closed = (chest->state == ZoneChestState_Closed);
    unsigned short chestIndex = *(unsigned short*)(self + targetBase + targetIndexOffset);
    signed short angleFromChest = *(signed short*)(self + targetBase + targetAngleOffset);   // chest to player

    if (!closed) {
        void* progress = Scenario_GetInstance();
        struct EventQuery query;
        query.chestId = chest->uniqueID;
        if (Scenario_RunTrigger(progress, 0x12, &query)) {
            EventQuery_RunQueuedCommands(&query);
        }
        return;
    }

    // the task this queues: GameResources keeps one for it (re-read each time, as the original does)
#define OPEN_CHEST_TASK (*(OpenChestTask**)(self + 0x3000 + openChestTaskOffset))
    FieldTask_InitOpenChest(OPEN_CHEST_TASK);
    OPEN_CHEST_TASK->chestIndex = (unsigned char)chestIndex;
    int opener = GameState_GetLeaderIndex(gs);
    OPEN_CHEST_TASK->opener = (unsigned char)opener;
    int facing = fix32ReduceAngle0To2Pi(angleFromChest + 0x3244);   // + 180 degrees: towards the chest
    OPEN_CHEST_TASK->facing = (unsigned short)facing;
    OPEN_CHEST_TASK->position = chest->position;
    if (chest->kind == 2) {
        OPEN_CHEST_TASK->fromZoneList = 1;
    }
#undef OPEN_CHEST_TASK

    unsigned char* base3000 = self + 0x3000;
    struct TailList020469b4* taskQueue = *(struct TailList020469b4**)(base3000 + taskQueueOffset);
    struct TailNode020469b4* task = *(struct TailNode020469b4**)(base3000 + openChestTaskOffset);
    func_020469b4(taskQueue, task);
}
