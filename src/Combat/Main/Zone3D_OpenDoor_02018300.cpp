#include <globaldefs.h>
#include "World/ZoneChest.h"
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"


struct Entry_02028bd0;
struct Obj02028c64;
struct SePlayer;
struct Obj020397cc;
struct SoundTable { int values[5]; };
struct TriggerQuery02018300 {
    char unknown0[0xc];
    int zoneId;
    char unknown10[0xc];
    unsigned short nodeId;
    unsigned short elementId;
    char unknown20[8];
    short angle;
    char unknown2a[0xa];
};

// ZoneFeatures::Opcode6aEntry::maybeType of a door
enum { kDoorFeatureType = 2 };

// ZoneFeatures::Opcode6aEntry type2 flags (DoorFlag) the header doesn't name yet
enum {
    kDoorFlag_Blocked = 0x4,            // set on a closed door by kScenarioCommand_BlockDoor; the next try clears it
    kDoorFlag_Exit = 0x8,               // leads to another zone (func_ov017_02198f84 starts the zone transition)
    kDoorFlag_StaysVisible = 0x80,      // its element gets kElementFlag_StaysVisible
    kDoorFlag_OpenInstantly = 0x100,    // no turn: shown already open, or hidden at once
};

// BmdjSceneElement::flags bit: BmdjSceneElement_Update stops a door that has finished turning instead of fading it out
enum { kElementFlag_StaysVisible = 0x10 };

// The scenario command that marks a closed door blocked (Scenario_RunCommand_02061c04 case 0x6c)
enum { kScenarioCommand_BlockDoor = 0x6c };

// How fast a door slides and turns, and how many frames the player stays stopped after opening an exit door
// (Zone3D_Update counts unk_830[0] down and gives control back at 0)
enum {
    kDoorSlideSpeed = 0x266,
    kDoorTurnSpeed = 0x199,
    kExitDoorControlLockFrames = 8,
};
extern "C" void* Scenario_GetInstance();
int Scenario_RunTriggerCommandsById(void*, int, unsigned short, void*);
int fix32ReduceAngle0To2Pi(int);
int fix32cos(int);
int fix32sin(int);
void Vector3fixMultiplyScalar(const Vector3i*, int, Vector3i*);
void* ZoneFeatures_GetFirstOfType(unsigned char*, unsigned int);
void SePlayer_Play(SePlayer*, int, int);
void GameObject_DisableControl(Obj020397cc*, int);
void LinkMessageQueue_SendDoorOpened(unsigned short, unsigned short, int);
Entry_02028bd0* ZoneRecords_GetInstance();
Obj02028c64* ZoneRecords_Find(Entry_02028bd0*, int);
void ZoneRecord_SetDoorOpened(Obj02028c64*, int);
extern const SoundTable Zone3D_doorSounds;
extern SePlayer g_sePlayer;

// Main, originally func_02018300 (USA 0x02018300, EUR 0x02018310, JPN 0x020180a0)
extern "C" ARM void Zone3D_OpenDoor(Zone3D* zone, ZoneFeatures::Opcode6aEntry* doorFeature, int sound, int forced, int notify) {
    BmdjSceneElement* door = Zone3D_FindDoorElement(zone, doorFeature);
    if (!door) return;
    if (!forced && (doorFeature->unk_2c.type2.flags & kDoorFlag_Exit)) return;
    if (!forced && (doorFeature->unk_2c.type2.flags & kDoorFlag_Blocked)) return;
    if (!forced) {
        void* scenario = Scenario_GetInstance();
        TriggerQuery02018300 query;
        query.angle = doorFeature->angle;
        query.elementId = doorFeature->unk_2c.type2.elementId;
        query.nodeId = doorFeature->unk_2c.type2.nodeId;
        query.zoneId = zone->currentZoneID_;
        Scenario_RunTriggerCommandsById(scenario, 17, kScenarioCommand_BlockDoor, &query);
        Scenario_RunTriggerCommandsById(scenario, 3, kScenarioCommand_BlockDoor, &query);
        if (doorFeature->unk_2c.type2.flags & kDoorFlag_Blocked) {
            doorFeature->unk_2c.type2.flags = (unsigned short)(doorFeature->unk_2c.type2.flags & ~kDoorFlag_Blocked);
            doorFeature->unk_2c.type2.flags = (unsigned short)(doorFeature->unk_2c.type2.flags & ~DoorFlag_Open);
            return;
        }
    }
    if (doorFeature->unk_2c.type2.flags & DoorFlag_Slides) {
        short angle = fix32ReduceAngle0To2Pi((short)(doorFeature->angle + FIX_2PI / 4));
        int cosine = fix32cos(angle);
        Vector3i direction;
        direction.x = fix32sin(angle);
        direction.y = 0;
        direction.z = cosine;
        Vector3fix_Normalize(&direction, &direction);
        Vector3fixMultiplyScalar(&direction, doorFeature->unk_2c.type2.slideDistance, &direction);
        Vector3i unit;
        Vector3fix_Normalize(&direction, &unit);
        door->direction = unit;
        Vector3i destination;
        Vector3fix_Add(&door->position, &direction, &destination);
        door->destination = destination;
        door->movementSpeed = kDoorSlideSpeed;
    } else {
        int turnAngle = (doorFeature->unk_2c.type2.flags & DoorFlag_QuarterTurn) ? FIX_2PI / 4 : FIX_2PI / 5;
        if (doorFeature->unk_2c.type2.flags & kDoorFlag_OpenInstantly) {
            if (doorFeature->unk_2c.type2.flags & kDoorFlag_StaysVisible) {
                door->flags |= kElementFlag_StaysVisible;
                if (doorFeature->unk_2c.type2.flags & DoorFlag_TurnBackward) {
                    door->destinationAngle = door->angle - turnAngle;
                    door->copiedAngle = door->destinationAngle;
                } else {
                    door->destinationAngle = door->angle + turnAngle;
                    door->copiedAngle = door->destinationAngle;
                }
            } else door->flags |= BmdjElementFlag_Hidden;
        } else {
            if (doorFeature->unk_2c.type2.flags & kDoorFlag_StaysVisible) door->flags |= kElementFlag_StaysVisible;
            if (doorFeature->unk_2c.type2.flags & DoorFlag_TurnBackward) {
                door->destinationAngle = door->angle - turnAngle;
            } else {
                door->destinationAngle = door->angle + turnAngle;
            }
        }
        door->rotationSpeed = kDoorTurnSpeed;
    }
    doorFeature->unk_2c.type2.flags = (unsigned short)(doorFeature->unk_2c.type2.flags | DoorFlag_Open);
    door->flags |= BmdjElementFlag_Open;
    for (int i = 0; i < zone->terrainElementCount_; i++) {
        BmdjSceneElement* collisionElement = zone->terrainElements_[i];
        if (collisionElement->parent == door) {
            collisionElement->flags |= BmdjElementFlag_Open;
            break;
        }
    }
    ZoneFeatures::Opcode6aEntry* feature = (ZoneFeatures::Opcode6aEntry*)ZoneFeatures_GetFirstOfType((unsigned char*)&zone->substruct_6c_, kDoorFeatureType);
    while (feature) {
        if (feature->unk_2c.type2.nodeId == doorFeature->unk_2c.type2.nodeId && feature->unk_2c.type2.elementId == doorFeature->unk_2c.type2.elementId)
            feature->unk_2c.type2.flags = (unsigned short)(feature->unk_2c.type2.flags | DoorFlag_Open);
        feature = feature->pNext;
    }
    if (sound) {
        SoundTable sounds = Zone3D_doorSounds;
        SePlayer_Play(&g_sePlayer, sounds.values[doorFeature->unk_2c.type2.soundIndex], 0);
    }
    if (forced && (doorFeature->unk_2c.type2.flags & kDoorFlag_Exit)) {
        GameObject* protagonist = GameState::GetInstance()->GetProtagonist();
        protagonist->combatFields_.unknown_b2_ = 0;
        GameObject_DisableControl((Obj020397cc*)protagonist, 1);
        zone->unk_830[0] = kExitDoorControlLockFrames;
        return;
    }
    int doorIndex = Zone3D_GetDoorIndex(zone, doorFeature);
    if (forced && notify) LinkMessageQueue_SendDoorOpened(zone->currentZoneID_, (unsigned short)doorIndex, sound);
    Obj02028c64* zoneRecord = ZoneRecords_Find(ZoneRecords_GetInstance(), zone->currentZoneID_);
    if (zoneRecord && !(doorFeature->unk_2c.type2.flags & DoorFlag_NotSaved)) ZoneRecord_SetDoorOpened(zoneRecord, doorIndex);
}
