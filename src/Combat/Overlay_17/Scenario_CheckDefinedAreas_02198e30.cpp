#include <globaldefs.h>

#if defined(jpn)
enum { kRegionalFieldOffset = 0x4196 };
#else
enum { kRegionalFieldOffset = 0x4446 };
#endif
#include "GameState/GameState.h"


struct Struct_ov017_02198e30 {
    unsigned short id;
    short param;
    char area[0x10 - 4];
    unsigned int flags;
    char pos[0x2c - 0x14];
    struct Struct_ov017_02198e30* next;
};

struct ZoneMgr02198e30 {
    char pad0[0x491];
    signed char activeId;
    char pad1[0x494 - 0x492];
    struct Struct_ov017_02198e30* head;
};

struct Struct_ov017_02198e30_3 {
    char pad0[4];
    int id;
    char pad1[0x30 - 8];
    int unknown_30_;
};

extern "C" struct ZoneMgr02198e30* Scenario_GetInstance(void);
extern "C" int Bounds3D_ContainsPointRotated(Vector3fix* pos, void* nodePos, int param, void* area, unsigned int flags);
extern "C" int Scenario_RunTrigger(void* a, int mode, void* c);
extern "C" void EventQuery_RunQueuedCommands(void* p);

// Overlay 17, originally func_ov017_02198e30 (USA/EUR 0x02198e30, JPN 0x021999e0)
extern "C" ARM void Scenario_CheckDefinedAreas(unsigned char* self) {
    GameState* gs = GameState::GetInstance();
    struct ZoneMgr02198e30* mgr = Scenario_GetInstance();
    struct Struct_ov017_02198e30* node = mgr->head;
    GameObject* obj = gs->GetLeader();

    for (; node != 0; node = node->next) {
        if (Bounds3D_ContainsPointRotated(&obj->obj3D_.position_, node->pos, node->param, node->area, node->flags)) {
            break;
        }
    }

    signed char cur = mgr->activeId;

    if (node == 0) {
        if (cur > -1) {
            struct Struct_ov017_02198e30_3 c1;
            c1.id = cur;
            if (Scenario_RunTrigger(mgr, 5, &c1)) {
                EventQuery_RunQueuedCommands(&c1);
            }
            mgr->activeId = -1;
        }
        return;
    }

    if (node->id == cur) return;

    struct Struct_ov017_02198e30_3 c2;
    if (cur > -1) {
        c2.id = cur;
        if (Scenario_RunTrigger(mgr, 5, &c2)) {
            EventQuery_RunQueuedCommands(&c2);
        }
        c2.id = -1;
        c2.unknown_30_ = 0;
    }

    self[kRegionalFieldOffset] = node->id;
    c2.id = node->id;
    if (Scenario_RunTrigger(mgr, 2, &c2)) {
        EventQuery_RunQueuedCommands(&c2);
    }

    unsigned short id = node->id;
    Scenario_GetInstance()->activeId = id;
}
