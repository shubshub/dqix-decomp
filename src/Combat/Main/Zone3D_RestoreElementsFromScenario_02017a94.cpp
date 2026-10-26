#include <globaldefs.h>

#include <World/Zone3D.h>
#include <GameState/GameState.h>


extern "C" void* Scenario_GetInstance(void);
extern "C" void* GameState_GetZoneTransition(GameState* battleStruct);
extern "C" int func_0206eaec(unsigned char* base, int row, int col);
extern "C" void* ZoneFeatures_GetFirstOfType(unsigned char* obj, unsigned int index);
extern "C" int Scenario_RunTriggerCommandsById(void* a, int mode, unsigned short id, void* c);

struct Obj0201b600;
extern "C" BmdjSceneElement* func_0201b600(Obj0201b600*, int, unsigned short);

// The scenario keeps two bits per scene element of script nodes 0 and 1 (func_02017c58 writes them before a battle):
// bit elementId when it was shown, bit kHiddenBits + elementId when it was hidden
enum {
    kHiddenBits = 0x80,
    kLastShownBit = 0x7f,
    kLastHiddenBit = 0xff,
};

// ZoneFeatures::Opcode6aEntry::maybeType of a door
enum { kDoorFeatureType = 2 };

// BmdjSceneElement::flags bit Zone3D_MarkDoorElements sets on every door's element
enum { kElementFlag_Door = 0x8 };

// The scenario command that marks a closed door blocked (Scenario_RunCommand_02061c04 case 0x6c)
enum { kScenarioCommand_BlockDoor = 0x6c };

struct TriggerQuery02017a94 {
    unsigned char unknown0[0x0c];
    unsigned int zoneId;
    unsigned char unknown10[0x30 - 0x10];
    unsigned int unknown30;
};

// Main, originally func_02017a94 (USA 0x02017a94, EUR 0x02017aa4, JPN 0x02017834)
extern "C" ARM void Zone3D_RestoreElementsFromScenario(Zone3D* zone) {
    GameState* gameState = GameState::GetInstance();
    if (gameState == NULL) {
        return;
    }
    if (GameState_GetZoneTransition(gameState) == NULL) {
        return;
    }
#if defined(jpn)
    enum { RestoreElementsFlagOffset = 0x285d };
#else
    enum { RestoreElementsFlagOffset = 0x281d };
#endif
    unsigned char* scenario = (unsigned char*)Scenario_GetInstance();
    int nodeId;
    int shownBit;
    int hiddenBit;
    if (scenario != NULL && *(unsigned char*)((char*)zone + RestoreElementsFlagOffset) != 0) {
        for (nodeId = 0; nodeId < 2; nodeId++) {
            for (shownBit = 0; shownBit < kLastShownBit; shownBit++) {
                if (func_0206eaec(scenario, (unsigned char)nodeId, (short)shownBit)) {
                    BmdjSceneElement* element =
                        func_0201b600((struct Obj0201b600*)zone, nodeId, shownBit);
                    if (element != NULL) {
                        element->flags &= ~BmdjElementFlag_Hidden;
                    }
                }
            }
            for (hiddenBit = kHiddenBits; hiddenBit < kLastHiddenBit; hiddenBit++) {
                if (func_0206eaec(scenario, (unsigned char)nodeId, (short)hiddenBit)) {
                    BmdjSceneElement* element =
                        func_0201b600((struct Obj0201b600*)zone, nodeId, hiddenBit - kHiddenBits);
                    ZoneFeatures::Opcode6aEntry* door;
                    if (element != NULL) {
                        element->flags |= BmdjElementFlag_Hidden;
                        if ((element->flags & kElementFlag_Door) != 0) {
                            element->flags |= BmdjElementFlag_Open;
                            door = (ZoneFeatures::Opcode6aEntry*)
                                ZoneFeatures_GetFirstOfType((unsigned char*)&zone->substruct_6c_, kDoorFeatureType);
                            while (door != NULL) {
                                if (door->unk_2c.type2.elementId == element->id) {
                                    door->unk_2c.type2.flags = (unsigned short)(door->unk_2c.type2.flags | DoorFlag_Open);
                                    break;
                                }
                                door = door->pNext;
                            }
                        }
                    }
                }
            }
        }
        struct TriggerQuery02017a94 query;
        query.zoneId = zone->currentZoneID_;
        Scenario_RunTriggerCommandsById(scenario, 3, kScenarioCommand_BlockDoor, &query);
        Scenario_RunTriggerCommandsById(scenario, 0x14, kScenarioCommand_BlockDoor, &query);
        zone->unk_276c[RestoreElementsFlagOffset - offsetof(Zone3D, unk_276c)] = 0;
    }
}
