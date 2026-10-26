#include <globaldefs.h>

#if defined(jpn)
enum { kPendingFieldTasksOffset = 0x784, kTreasureMapTypeOffset = 0x785, kTreasureMapQualityOffset = 0x786, kTreasureMapSeedOffset = 0x88 };
#else
enum { kPendingFieldTasksOffset = 0x744, kTreasureMapTypeOffset = 0x745, kTreasureMapQualityOffset = 0x746, kTreasureMapSeedOffset = 0x48 };
#endif

#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"
#include "Resource/Brightness.h"

extern "C" void FieldTask_InitAcquireTreasureMap(void* node, int flag);
extern "C" void AcquireTreasureMapTask_CreateMap(void* node, int b1, int b2, int h3, int extra);
extern "C" void func_ov017_021aa4cc(void* overlay, int flag);
extern "C" void* LinkSession_GetInstance(void);
extern "C" void func_020ae53c(int arg);

extern "C" void* GameState_GetParty(GameState* battleStruct);
extern "C" int FieldTaskQueue_IsEmpty(void** obj);

struct TailNode020469b4 { char unk0[2]; unsigned char inList; char unknown_3_; TailNode020469b4* next; };
struct TailList020469b4 { TailNode020469b4* head; TailNode020469b4* tail; };
extern "C" void func_020469b4(TailList020469b4* list, TailNode020469b4* node);

struct Struct020d9850 { unsigned char byte0; unsigned char pad1[7]; unsigned char byte8; };
extern "C" void func_020d9850(Struct020d9850* p);

extern "C" int LinkSession_IsActive(int* obj);

struct Obj02086b98;
extern "C" int func_02086b98(Obj02086b98* o);

// The field tasks a battle can leave pending in Zone3D +0x2744 (func_0201bf38 sets the treasure map with
// its type, quality and seed at +0x2745, +0x2746 and +0x2748; func_0201bf70 the evac prompt); the wipeout
// prompt starts only while linked. 4 runs func_020ae53c.
enum {
    kPendingFieldTask_AcquireTreasureMap = 0x1,
    kPendingFieldTask_ConfirmEvac = 0x2,
    kPendingFieldTask_WipeoutPrompt = 0x8,
};

// GameResources::fieldTasks_ slots: the AcquireTreasureMap task (FieldTask_InitAcquireTreasureMap) and the
// ConfirmEvac one (func_020d9850 gives it kind FieldTaskKind_ConfirmEvac)
enum {
    kAcquireTreasureMapTaskSlot = 0x1b,
    kConfirmEvacTaskSlot = 0x2f,
};

// Main, originally DispatchField0x744FlagsAndNotify_0201bdac (USA 0x0201bdac, EUR 0x0201bdbc, JPN 0x0201bb24)
extern "C" ARM void Zone3D_StartPendingFieldTask(unsigned char* zone) {
    GameState* gameState = GameState::GetInstance();
    GameResources* resources = GetGameResources();
    TailList020469b4* taskQueue = (TailList020469b4*)resources->fieldTaskQueue_;
    void* linkState = LinkSession_GetInstance();
    void* party = GameState_GetParty(gameState);

    if (!FieldTaskQueue_IsEmpty((void**)taskQueue)) return;
    if (!IsBrightnessZero(resources, false)) return;
    if (!IsBrightnessZero(resources, true)) return;

    unsigned char pending = *(zone + 0x2000 + kPendingFieldTasksOffset);
    if (pending & kPendingFieldTask_AcquireTreasureMap) {
        struct GrottoStruct* grotto = gameState->GetGrottoStruct();
        grotto->unknown_9 = 2;
        TailNode020469b4* task = (TailNode020469b4*)resources->fieldTasks_[kAcquireTreasureMapTaskSlot];
        FieldTask_InitAcquireTreasureMap(task, 0);
        int extra = 0;
        int type = *(zone + 0x2000 + kTreasureMapTypeOffset);
        int quality = *(zone + 0x2000 + kTreasureMapQualityOffset);
        int seed = *(unsigned short*)(zone + 0x2700 + kTreasureMapSeedOffset);
        AcquireTreasureMapTask_CreateMap(task, type, quality, seed, extra);
        func_020469b4(taskQueue, task);
        *(zone + 0x2000 + kPendingFieldTasksOffset) &= ~kPendingFieldTask_AcquireTreasureMap;
        return;
    }
    if (pending & kPendingFieldTask_ConfirmEvac) {
        Struct020d9850* task = (Struct020d9850*)resources->fieldTasks_[kConfirmEvacTaskSlot];
        func_020d9850(task);
        func_020469b4(taskQueue, (TailNode020469b4*)task);
        *(zone + 0x2000 + kPendingFieldTasksOffset) &= ~kPendingFieldTask_ConfirmEvac;
        return;
    }
    if (pending & 4) {
        func_020ae53c(0);
        *(zone + 0x2000 + kPendingFieldTasksOffset) &= ~4;
        return;
    }

    if (LinkSession_IsActive((int*)linkState)) {
        if (func_02086b98((Obj02086b98*)party) != 0 || (*(zone + 0x2000 + kPendingFieldTasksOffset) & kPendingFieldTask_WipeoutPrompt)) {
            func_ov017_021aa4cc(resources, 1);
        }
    }
    *(zone + 0x2000 + kPendingFieldTasksOffset) = 0;
}
