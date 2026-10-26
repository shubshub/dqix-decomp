#include <globaldefs.h>
#include <GameState/GameState.h>
#include "Input/Input.h"

#if defined(jpn)
#define RG(u, j) (j)
#define func_ov002_0215bba8 func_ov002_0215cd18
#else
#define RG(u, j) (u)
#endif

struct Struct_ov002_02155960_2;
struct Struct_ov002_02155960_3;
struct Struct_0201079c;
struct Struct_0201079c_2;

struct Struct_ov002_02155960_4 {
    unsigned char unknown_0_[0xc5];
    unsigned char unknown_c5_;
};

struct Struct_ov002_02155960_5 {
    unsigned char unknown_0_[RG(0x998, 0x868)];
    int unknown_998_;
    int unknown_99c_;
    int unknown_9a0_;
};

struct Struct_ov002_02155960_6 {
    unsigned int unknown_0_;
    unsigned char unknown_4_[0xba4];
    unsigned char unknown_ba8_[RG(0x130, 0xa0)];
};

class Struct_ov002_02155960_7 {
public:
    unsigned int unknown_0_;
    union {
        Struct_0201079c* unknown_0_;
        Struct_0201079c_2* unknown1_0_;
    } unknown_4_;
    unsigned char unknown_8_[RG(0x48, 0x30)];
    unsigned char unknown_50_[RG(0x864, 0x7e0)];
    unsigned char unknown_8b4_[RG(0x614, 0x608)];
    Struct_ov002_02155960_6 unknown_ec8_;
    int unknown_1ba0_;
    unsigned char unknown_1ba4_[0x14];
    int unknown_1bb8_;
    int unknown_1bbc_;
    int unknown_1bc0_;
    int unknown_1bc4_;
    int unknown_1bc8_;
    int unknown_1bcc_;
    unsigned char unknown_1bd0_[0x44];
    unsigned short unknown_1c14_;
    unsigned char unknown_1c16_[0x1a];
    unsigned char unknown_1c30_;
    unsigned char unknown_1c31_[RG(0x92, 0x8e)];
    unsigned char unknown_1cc3_;
    unsigned char unknown_1cc4_;
    unsigned char unknown_1cc5_[RG(0x7a3, 0x70f)];
    void* unknown_2468_;
    unsigned char unknown_246c_[0x10];
    unsigned int unknown_247c_;
    unsigned char unknown_2480_[5];
    unsigned char unknown_2485_;
    unsigned char unknown_2486_;
    unsigned char unknown_2487_;
};

typedef void (Struct_ov002_02155960_7::*Type_ov002_02155960)();
struct Struct_ov002_02155960 {
    unsigned char unknown_0_[0x34];
};

extern "C" int func_ov017_021959b4();
void SetTag2aIfNotAlreadyFlagged_02155024(unsigned char*);
int MessageSystem_GetInstance();
extern "C" void func_ov023_021e7404(void*, int);
extern "C" void func_ov002_02156178(unsigned char*);
extern "C" void func_ov023_021eb43c(void*);
extern "C" int func_ov002_02154c30(void*);
void SyncElementFlags0215b648(unsigned char*);
extern "C" void func_ov002_02156bc8(BattleActor*);
extern "C" void func_ov002_02156c7c(BattleActor*);
extern "C" void func_ov002_021561b0(BattleActor*);
Elem_0205d81c* Window_GetActivePane(Struct_0205d81c*);
int WindowPane_IsReady(unsigned char*);
void TouchGrid_SetTouchedCell(void*, int);
int GetInnerFlagBit0020e28dc(Outer020e28dc*);
void UpdateEntryStateAndPosition(Ctx020e263c*, int);
extern "C" int Window_Update(Struct_0205d81c*, int);
int CheckFlagOrThreshold_02161b48(char*, int);
extern "C" void* Scenario_GetInstance();
int Scenario_RunTrigger(void*, int, void*);
extern "C" void EventQuery_RunQueuedCommands(void*);
extern "C" void func_ov023_021dca88(void*);
void CopyByteField0215aa14(char*);
int GameState_GetStoryChapter(char*);
void SetElementFlag0x20ByKey0205def8(Struct_0205def8*, int, int);
void Window_SetPanePalette(Struct_0205d81c*, int, int);
extern "C" void func_ov002_0215bba8(BattleActor*);
extern unsigned int data_ov002_0216d3a8;
extern BattleHandler __ptmf_null;
extern BattleHandler data_ov002_0216cd74[RG(44, 47)];

static inline Struct_ov002_02155960_6* inline_ov002_02155960(Struct_ov002_02155960_7* arg0) { SDK_NULL_ASSERT(arg0); return &arg0->unknown_ec8_; }

// USA: func_ov002_02155960
extern "C" ARM int func_ov002_02155960(Struct_ov002_02155960_7* arg0, int arg1) {
    if (func_ov017_021959b4() != 0)
        SetTag2aIfNotAlreadyFlagged_02155024((unsigned char*)actor);
    BattleManager* manager = (BattleManager*)MessageSystem_GetInstance();
    actor->delta = delta;
    if (actor->effectEnabled != 0)
        func_ov023_021e7404(actor->effect, actor->delta);
    ClearFlagBit1IfEnabled_02156178((unsigned char*)actor);
    if (actor->optional != 0)
        func_ov023_021eb43c(actor->optional);
    if (actor->state != 0) {
        actor->elementsUpdated = 0;
        actor->elementsUpdated = func_ov002_02154c30(actor->elements.current);
        SyncElementFlags0215b648((unsigned char*)actor);
        if ((actor->flags & 0x20) == 0) {
            func_ov002_02156bc8(actor);
            func_ov002_02156c7c(actor);
        }
        func_ov002_021561b0(actor);
        Elem_0205d81c* element = Window_GetActivePane((Struct_0205d81c*)&actor->elements);
        if (element != 0 && WindowPane_IsReady((unsigned char*)element) != 0 && (element->flags & 2) == 0)
            TouchGrid_SetTouchedCell(GetElements(actor)->entries, -1);
        if (actor->connection.owner != 0 && GetInnerFlagBit0020e28dc(actor->connection.owner) != 0) {
            UpdateEntryStateAndPosition(actor->connection.context, actor->delta);
        } else {
            actor->displayMode = Window_Update((Struct_0205d81c*)&actor->elements, actor->delta);
        }
    }
    if (arg0->unknown_2485_ != 0) {
        if ((arg0->unknown_1bb8_ == 4 && arg0->unknown_1bc0_ == 1 && func_ov002_02161b48((char*)arg0, 1) != 0) ||
                g_keyManager.TestKeysPressed(0x800) != 0) {
            if (var0->unknown_998_ == 0)
                arg0->unknown_2487_ = 1;
        }
        if (actor->pendingState == 1) {
            BattleTarget target;
            if (Scenario_RunTrigger(Scenario_GetInstance(), 0x16, &target) != 0)
                EventQuery_RunQueuedCommands(&target);
            if (actor->flags & 1)
                func_ov023_021dca88(actor->model);
            actor->state = RG(0x2b, 0x2e);
            actor->previousState = RG(0x2b, 0x2e);
            actor->pendingState = 2;
        }
    }
    arg0->unknown_1bcc_ = 0;
    if (arg0->unknown_1bb8_ == RG(0x26, 0x29) && var0->unknown_998_ != 0 && var0->unknown_9a0_ == 5)
        return 0;
    if ((data_ov002_0216d3a8 & 1) == 0) {
        BattleHandler empty = __ptmf_null;
#if defined(jpn)
        data_ov002_0216cd74[6] = var3;
        data_ov002_0216cd74[9] = var3;
        data_ov002_0216cd74[19] = var3;
        data_ov002_0216cd74[20] = var3;
        data_ov002_0216cd74[23] = var3;
        data_ov002_0216cd74[27] = var3;
        data_ov002_0216cd74[28] = var3;
        data_ov002_0216cd74[30] = var3;
        data_ov002_0216cd74[33] = var3;
        data_ov002_0216cd74[34] = var3;
        data_ov002_0216cd74[35] = var3;
        data_ov002_0216cd74[43] = var3;
        data_ov002_0216cd74[44] = var3;
        data_ov002_0216cd74[46] = var3;
#else
        data_ov002_0216cd74[8] = var3;
        data_ov002_0216cd74[18] = var3;
        data_ov002_0216cd74[19] = var3;
        data_ov002_0216cd74[22] = var3;
        data_ov002_0216cd74[26] = var3;
        data_ov002_0216cd74[27] = var3;
        data_ov002_0216cd74[29] = var3;
        data_ov002_0216cd74[32] = var3;
        data_ov002_0216cd74[40] = var3;
        data_ov002_0216cd74[41] = var3;
        data_ov002_0216cd74[43] = var3;
#endif
        data_ov002_0216d3a8 |= 1;
    }
    if (data_ov002_0216cd74[actor->state] == 0)
        return (actor->flags & 1) == 0;
    (actor->*data_ov002_0216cd74[actor->state])();
    if (actor->state != 0 && actor->state != RG(0x1e, 0x1f) && actor->state != RG(0x2a, 0x2d) && actor->busy == 0 && actor->mode == 1) {
        manager = (BattleManager*)MessageSystem_GetInstance();
        if (g_keyManager.TestKeysPressed(0x800) != 0 && manager->blocked == 0) {
            if (actor->state == RG(0x21, 0x24))
                CopyByteField0215aa14((char*)actor);
            if (actor->state == RG(0xf, 0x10)) {
                SetTag2aIfNotAlreadyFlagged_02155024((unsigned char*)actor);
            } else {
                if (arg0->unknown_247c_ & 1)
                    func_ov023_021dca88(arg0->unknown_50_);
                arg0->unknown_1bb8_ = RG(0x2b, 0x2e);
                arg0->unknown_1c14_ = 0;
            }
        }
    }
    if (GameState_GetStoryChapter((char*)GameState::GetInstance()) == 1 || actor->active != 0) {
        SetElementFlag0x20ByKey0205def8((Struct_0205def8*)&actor->elements, 0, RG(0x29, 0x2c));
    }
    Window_SetPanePalette((Struct_0205d81c*)&actor->elements, RG(0x29, 0x2c), 0);
    Window_SetPanePalette((Struct_0205d81c*)&actor->elements, RG(0x28, 0x2b), 0);
    func_ov002_0215bba8(actor);
    return 0;
}
