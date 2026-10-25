#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_02198e30_17478 = 0x4196 };
#else
enum { Enum_ov017_02198e30_17478 = 0x4446 };
#endif
#include "GameState/GameState.h"


struct Struct_ov017_02198e30 {
    unsigned short unknown_0_;
    short unknown_2_;
    char unknown_4_[0x10 - 4];
    unsigned int unknown_10_;
    char unknown_14_[0x2c - 0x14];
    struct Struct_ov017_02198e30* unknown_2c_;
};

struct Struct_ov017_02198e30_2 {
    char unknown_0_[0x491];
    signed char unknown_491_;
    char unknown_492_[0x494 - 0x492];
    struct Struct_ov017_02198e30* unknown_494_;
};

struct Struct_ov017_02198e30_3 {
    char unknown_0_[4];
    int unknown_4_;
    char unknown_8_[0x30 - 8];
    int unknown_30_;
};

extern "C" struct ZoneMgr02198e30* Scenario_GetInstance(void);
extern "C" int func_020321e0(Vector3fix* pos, void* nodePos, int param, void* area, unsigned int flags);
int Scenario_RunTrigger(void* a, int mode, void* c);
extern "C" void EventQuery_RunQueuedCommands(void* p);

// Overlay 17, originally func_ov017_02198e30 (USA/EUR 0x02198e30, JPN 0x021999e0)
extern "C" ARM void Scenario_CheckDefinedAreas(unsigned char* self) {
    GameState* gs = GameState::GetInstance();
    struct ZoneMgr02198e30* mgr = Scenario_GetInstance();
    struct ZoneNode02198e30* node = mgr->head;
    GameObject* obj = gs->GetUnknownGameObject();

    for (; var2 != 0; var2 = var2->unknown_2c_) {
        if (func_020321e0(&var3->obj3D_.position_, var2->unknown_14_, var2->unknown_2_, var2->unknown_4_, var2->unknown_10_)) {
            break;
        }
    }

    signed char var4 = var1->unknown_491_;

    if (node == 0) {
        if (cur > -1) {
            struct LookupBuf02198e30 c1;
            c1.id = cur;
            if (Scenario_RunTrigger(mgr, 5, &c1)) {
                EventQuery_RunQueuedCommands(&c1);
            }
            var1->unknown_491_ = -1;
        }
        return;
    }

    if (var2->unknown_0_ == var4) return;

    struct LookupBuf02198e30 c2;
    if (cur > -1) {
        c2.id = cur;
        if (Scenario_RunTrigger(mgr, 5, &c2)) {
            EventQuery_RunQueuedCommands(&c2);
        }
        var6.unknown_4_ = -1;
        var6.unknown_30_ = 0;
    }

    self[kRegionalFieldOffset] = node->id;
    c2.id = node->id;
    if (Scenario_RunTrigger(mgr, 2, &c2)) {
        EventQuery_RunQueuedCommands(&c2);
    }

    unsigned short id = node->id;
    Scenario_GetInstance()->activeId = id;
}
