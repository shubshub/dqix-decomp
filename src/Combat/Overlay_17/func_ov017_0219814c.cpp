#if defined(jpn)
enum { Enum_ov017_0219814c_108 = 0x8c };
#else
enum { Enum_ov017_0219814c_108 = 0x6c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"


struct Struct_ov017_0219814c {
    char unknown_0_[0x2c];
    unsigned char unknown_2c_;
    char unknown_2d_[0x70 - 0x2d];
    struct Struct_ov017_0219814c* unknown_70_;
};

struct Struct_ov017_0219814c_2 {
    unsigned int unknown_0_[3];
};

struct Struct_ov017_0219814c_3 {
    int unknown_0_;
    int unknown_4_;
    char unknown_8_[0x30 - 0x08];
    int unknown_30_;
};

extern "C" void* Zone3D_GetInstance(void);
extern "C" void* Scenario_GetInstance(void);
void* ZoneFeatures_GetFirstOfType(unsigned char* obj, unsigned int index);
extern "C" int func_02094b9c(struct AreaNode_0219814c* node, struct Anchor_0219814c* anchor);
struct AreaNode_0219814c* GetFieldAt0x188_02053ccc(unsigned char* obj);
void SetFieldAt0x188_02053cc4(unsigned char* obj, int value);
int Scenario_RunTrigger(void* a, int mode, void* c);
extern "C" void EventQuery_RunQueuedCommands(void* p);

// USA: func_ov017_0219814c
extern "C" ARM void func_ov017_0219814c(void) {
    GameState* battle = GameState::GetInstance();
    void* ctx = Zone3D_GetInstance();
    void* events = Scenario_GetInstance();
    GameObject* combatant = battle->GetLeader();
    struct Anchor_0219814c anchor = *(struct Anchor_0219814c*)((char*)combatant + 0x44);
    struct EventArgs_0219814c args;
    struct AreaNode_0219814c* node;
    struct AreaNode_0219814c* current;

    node = (struct AreaNode_0219814c*)ZoneFeatures_GetFirstOfType((unsigned char*)ctx + RegionOffset6c, 3);
    while (node != 0) {
        if (func_02094b9c(node, &anchor)) {
            break;
        }
        var6 = var6->unknown_70_;
    }

    current = GetFieldAt0x188_02053ccc((unsigned char*)combatant);
    if (current != 0) {
        if (node == 0) {
            args.areaId = current->areaId;
            if (Scenario_RunTrigger(events, 5, &args)) {
                EventQuery_RunQueuedCommands(&args);
            }
        } else if (node != current) {
            args.areaId = current->areaId;
            if (Scenario_RunTrigger(events, 5, &args)) {
                EventQuery_RunQueuedCommands(&args);
            }
            args.field_0x30 = 0;
            args.areaId = node->areaId;
            if (Scenario_RunTrigger(events, 2, &args)) {
                EventQuery_RunQueuedCommands(&args);
            }
        }
    } else if (node != 0) {
        args.areaId = node->areaId;
        if (Scenario_RunTrigger(events, 2, &args)) {
            EventQuery_RunQueuedCommands(&args);
        }
    }
    func_02053cc4((unsigned char*)var3, (int)var6);
}
