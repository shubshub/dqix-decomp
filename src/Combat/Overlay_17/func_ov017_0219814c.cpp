#if defined(jpn)
enum { RegionOffset6c = 0x8c };
#else
enum { RegionOffset6c = 0x6c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"


struct AreaNode_0219814c {
    char unknown_0_[0x2c];
    unsigned char areaId;
    char unknown_2d_[0x70 - 0x2d];
    struct AreaNode_0219814c* next;
};

struct Struct_ov017_0219814c_2 {
    unsigned int w[3];
};

struct Struct_ov017_0219814c_3 {
    int field_0x0;
    int areaId;
    char pad08[0x30 - 0x08];
    int unknown_30_;
};

extern "C" void* Zone3D_GetInstance(void);
extern "C" void* Scenario_GetInstance(void);
extern "C" void* ZoneFeatures_GetFirstOfType(unsigned char* obj, unsigned int index);
extern "C" int func_02094b9c(struct AreaNode_0219814c* node, struct Struct_ov017_0219814c_2* anchor);
extern "C" struct AreaNode_0219814c* func_02053ccc(unsigned char* obj);
extern "C" void func_02053cc4(unsigned char* obj, int value);
extern "C" int Scenario_RunTrigger(void* a, int mode, void* c);
extern "C" void EventQuery_RunQueuedCommands(void* p);

// USA: func_ov017_0219814c
extern "C" ARM void func_ov017_0219814c(void) {
    GameState* battle = GameState::GetInstance();
    void* ctx = Zone3D_GetInstance();
    void* events = Scenario_GetInstance();
    GameObject* combatant = battle->GetLeader();
    struct Struct_ov017_0219814c_2 anchor = *(struct Struct_ov017_0219814c_2*)((char*)combatant + 0x44);
    struct Struct_ov017_0219814c_3 args;
    struct AreaNode_0219814c* node;
    struct AreaNode_0219814c* current;

    node = (struct AreaNode_0219814c*)ZoneFeatures_GetFirstOfType((unsigned char*)ctx + RegionOffset6c, 3);
    while (node != 0) {
        if (func_02094b9c(node, &anchor)) {
            break;
        }
        node = node->next;
    }

    current = func_02053ccc((unsigned char*)combatant);
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
            args.unknown_30_ = 0;
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
    func_02053cc4((unsigned char*)combatant, (int)node);
}
