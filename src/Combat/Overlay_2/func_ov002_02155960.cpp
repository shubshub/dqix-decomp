#include <globaldefs.h>
#include <GameState/GameState.h>
#include "Input/Input.h"

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Struct_0205d81c;
struct Struct_0205def8;
struct Struct_0201079c;
struct Struct_0201079c_2;

struct Elem_0205d81c {
    unsigned char field_0x0[0xc5];
    unsigned char flags;
};

struct BattleManager {
    unsigned char field_0x0[RG(0x998, 0x868)];
    int blocked;
    int unknown_99c_;
    int state;
};

struct Struct_ov002_02155960_6 {
    unsigned int header;
    unsigned char entries[0xba4];
    unsigned char current[RG(0x130, 0xa0)];
};

class Struct_ov002_02155960_7 {
public:
    unsigned int field_0x0;
    union {
        Struct_0201079c* owner;
        Struct_0201079c_2* context;
    } unknown_4_;
    unsigned char unknown_8_[RG(0x48, 0x30)];
    unsigned char model[RG(0x864, 0x7e0)];
    unsigned char effect[RG(0x614, 0x608)];
    Struct_ov002_02155960_6 elements;
    int delta;
    unsigned char unknown_1ba4_[0x14];
    int state;
    int unknown_1bbc_;
    int mode;
    int unknown_1bc4_;
    int displayMode;
    int pending;
    unsigned char unknown_1bd0_[0x44];
    unsigned short unknown_1c14_;
    unsigned char unknown_1c16_[0x1a];
    unsigned char busy;
    unsigned char unknown_1c31_[RG(0x92, 0x8e)];
    unsigned char unknown_1cc3_;
    unsigned char unknown_1cc4_;
    unsigned char unknown_1cc5_[RG(0x7a3, 0x70f)];
    void* unknown_2468_;
    unsigned char unknown_246c_[0x10];
    unsigned int flags;
    unsigned char unknown_2480_[5];
    unsigned char active;
    unsigned char unknown_2486_;
    unsigned char unknown_2487_;
};

typedef void (Struct_ov002_02155960_7::*Type_ov002_02155960)();
struct Struct_ov002_02155960 {
    unsigned char data[0x34];
};

extern "C" int func_ov017_021959b4();
extern "C" void func_ov002_02155024(unsigned char*);
extern "C" int MessageSystem_GetInstance();
extern "C" void func_ov023_021e7404(void*, int);
extern "C" void func_ov002_02156178(unsigned char*);
extern "C" void func_ov023_021eb43c(void*);
extern "C" int func_ov002_02154c30(void*);
extern "C" void func_ov002_0215b648(unsigned char*);
extern "C" void func_ov002_02156bc8(Struct_ov002_02155960_7*);
extern "C" void func_ov002_02156c7c(Struct_ov002_02155960_7*);
extern "C" void func_ov002_021561b0(Struct_ov002_02155960_7*);
extern "C" Elem_0205d81c* Window_GetActivePane(Struct_0205d81c*);
extern "C" int WindowPane_IsReady(unsigned char*);
extern "C" void TouchGrid_SetTouchedCell(void*, int);
extern "C" int func_020e28dc(Struct_0201079c*);
extern "C" void func_020e263c(Struct_0201079c_2*, int);
extern "C" int Window_Update(Struct_0205d81c*, int);
extern "C" int func_ov002_02161b48(char*, int);
extern "C" void* Scenario_GetInstance();
extern "C" int Scenario_RunTrigger(void*, int, void*);
extern "C" void EventQuery_RunQueuedCommands(void*);
extern "C" void func_ov023_021dca88(void*);
extern "C" void func_ov002_0215aa14(char*);
extern "C" int GameState_GetStoryChapter(char*);
extern "C" void func_0205def8(Struct_0205def8*, int, int);
extern "C" void Window_SetPanePalette(Struct_0205d81c*, int, int);
extern "C" void func_ov002_0215bba8(Struct_ov002_02155960_7*);
extern unsigned int data_ov002_0216d3a8;
extern Type_ov002_02155960 __ptmf_null;
extern Type_ov002_02155960 data_ov002_0216cd74[RG(44, 47)];

static inline Struct_ov002_02155960_6* GetElements(Struct_ov002_02155960_7* actor) { SDK_NULL_ASSERT(actor); return &actor->elements; }

// USA: func_ov002_02155960
extern "C" ARM int func_ov002_02155960(Struct_ov002_02155960_7* actor, int delta) {
    if (func_ov017_021959b4() != 0)
        func_ov002_02155024((unsigned char*)actor);
    BattleManager* manager = (BattleManager*)MessageSystem_GetInstance();
    actor->delta = delta;
    if (actor->unknown_1cc3_ != 0)
        func_ov023_021e7404(actor->effect, actor->delta);
    func_ov002_02156178((unsigned char*)actor);
    if (actor->unknown_2468_ != 0)
        func_ov023_021eb43c(actor->unknown_2468_);
    if (actor->state != 0) {
        actor->unknown_1cc4_ = 0;
        actor->unknown_1cc4_ = func_ov002_02154c30(actor->elements.current);
        func_ov002_0215b648((unsigned char*)actor);
        if ((actor->flags & 0x20) == 0) {
            func_ov002_02156bc8(actor);
            func_ov002_02156c7c(actor);
        }
        func_ov002_021561b0(actor);
        Elem_0205d81c* element = Window_GetActivePane((Struct_0205d81c*)&actor->elements);
        if (element != 0 && WindowPane_IsReady((unsigned char*)element) != 0 && (element->flags & 2) == 0)
            TouchGrid_SetTouchedCell(GetElements(actor)->entries, -1);
        if (actor->unknown_4_.owner != 0 && func_020e28dc(actor->unknown_4_.owner) != 0) {
            func_020e263c(actor->unknown_4_.context, actor->delta);
        } else {
            actor->displayMode = Window_Update((Struct_0205d81c*)&actor->elements, actor->delta);
        }
    }
    if (actor->active != 0) {
        if ((actor->state == 4 && actor->mode == 1 && func_ov002_02161b48((char*)actor, 1) != 0) ||
                g_keyManager.TestKeysPressed(0x800) != 0) {
            if (manager->blocked == 0)
                actor->unknown_2487_ = 1;
        }
        if (actor->unknown_2487_ == 1) {
            Struct_ov002_02155960 target;
            if (Scenario_RunTrigger(Scenario_GetInstance(), 0x16, &target) != 0)
                EventQuery_RunQueuedCommands(&target);
            if (actor->flags & 1)
                func_ov023_021dca88(actor->model);
            actor->state = RG(0x2b, 0x2e);
            actor->unknown_1bbc_ = RG(0x2b, 0x2e);
            actor->unknown_2487_ = 2;
        }
    }
    actor->pending = 0;
    if (actor->state == RG(0x26, 0x29) && manager->blocked != 0 && manager->state == 5)
        return 0;
    if ((data_ov002_0216d3a8 & 1) == 0) {
        Type_ov002_02155960 empty = __ptmf_null;
#if defined(jpn)
        data_ov002_0216cd74[6] = empty;
        data_ov002_0216cd74[9] = empty;
        data_ov002_0216cd74[19] = empty;
        data_ov002_0216cd74[20] = empty;
        data_ov002_0216cd74[23] = empty;
        data_ov002_0216cd74[27] = empty;
        data_ov002_0216cd74[28] = empty;
        data_ov002_0216cd74[30] = empty;
        data_ov002_0216cd74[33] = empty;
        data_ov002_0216cd74[34] = empty;
        data_ov002_0216cd74[35] = empty;
        data_ov002_0216cd74[43] = empty;
        data_ov002_0216cd74[44] = empty;
        data_ov002_0216cd74[46] = empty;
#else
        data_ov002_0216cd74[8] = empty;
        data_ov002_0216cd74[18] = empty;
        data_ov002_0216cd74[19] = empty;
        data_ov002_0216cd74[22] = empty;
        data_ov002_0216cd74[26] = empty;
        data_ov002_0216cd74[27] = empty;
        data_ov002_0216cd74[29] = empty;
        data_ov002_0216cd74[32] = empty;
        data_ov002_0216cd74[40] = empty;
        data_ov002_0216cd74[41] = empty;
        data_ov002_0216cd74[43] = empty;
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
                func_ov002_0215aa14((char*)actor);
            if (actor->state == RG(0xf, 0x10)) {
                func_ov002_02155024((unsigned char*)actor);
            } else {
                if (actor->flags & 1)
                    func_ov023_021dca88(actor->model);
                actor->state = RG(0x2b, 0x2e);
                actor->unknown_1c14_ = 0;
            }
        }
    }
    if (GameState_GetStoryChapter((char*)GameState::GetInstance()) == 1 || actor->active != 0) {
        func_0205def8((Struct_0205def8*)&actor->elements, 0, RG(0x29, 0x2c));
    }
    Window_SetPanePalette((Struct_0205d81c*)&actor->elements, RG(0x29, 0x2c), 0);
    Window_SetPanePalette((Struct_0205d81c*)&actor->elements, RG(0x28, 0x2b), 0);
    func_ov002_0215bba8(actor);
    return 0;
}
