#include <globaldefs.h>
#include "World/ZoneChest.h"
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"


struct Entry_02028bd0;
struct Obj02028c64;
struct SePlayer;
struct Obj020397cc;
struct SoundTable { int values[5]; };
struct EventParameter {
    char pad_00[0xc];
    int ownerId;
    char pad_10[0xc];
    unsigned short nodeId;
    unsigned short entryKey;
    char pad_20[8];
    short angle;
    char pad_2a[0xa];
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
Obj02028c64* FindInlineEntryById(Entry_02028bd0*, int);
void ZoneRecord_SetDoorOpened(Obj02028c64*, int);
extern const SoundTable Zone3D_doorSounds;
extern SePlayer g_sePlayer;

// Main, originally func_02018300 (USA 0x02018300, EUR 0x02018310, JPN 0x020180a0)
extern "C" ARM void Zone3D_OpenDoor(Zone3D* self, ZoneFeatures::Opcode6aEntry* doorFeature, int sound, int forced, int notify) {
    BmdjSceneElement* door = Zone3D_FindDoorElement(self, doorFeature);
    if (!door) return;
    if (!forced && (doorFeature->unk_2c.type2.flags & 8)) return;
    if (!forced && (doorFeature->unk_2c.type2.flags & 4)) return;
    if (!forced) {
        void* gameProgress = Scenario_GetInstance();
        EventParameter event;
        event.angle = doorFeature->angle;
        event.entryKey = doorFeature->unk_2c.type2.elementId;
        event.nodeId = doorFeature->unk_2c.type2.nodeId;
        event.ownerId = self->currentZoneID_;
        Scenario_RunTriggerCommandsById(gameProgress, 17, 108, &event);
        Scenario_RunTriggerCommandsById(gameProgress, 3, 108, &event);
        if (doorFeature->unk_2c.type2.flags & 4) {
            doorFeature->unk_2c.type2.flags = (unsigned short)(doorFeature->unk_2c.type2.flags & ~4);
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
        door->movementSpeed = 0x266;
    } else {
        int turnAngle = (doorFeature->unk_2c.type2.flags & DoorFlag_QuarterTurn) ? FIX_2PI / 4 : FIX_2PI / 5;
        if (doorFeature->unk_2c.type2.flags & 256) {
            if (doorFeature->unk_2c.type2.flags & 128) {
                door->flags |= 16;
                if (doorFeature->unk_2c.type2.flags & DoorFlag_TurnBackward) {
                    door->destinationAngle = door->angle - turnAngle;
                    door->copiedAngle = door->destinationAngle;
                } else {
                    door->destinationAngle = door->angle + turnAngle;
                    door->copiedAngle = door->destinationAngle;
                }
            } else door->flags |= BmdjElementFlag_Hidden;
        } else {
            if (doorFeature->unk_2c.type2.flags & 128) door->flags |= 16;
            if (doorFeature->unk_2c.type2.flags & DoorFlag_TurnBackward) {
                door->destinationAngle = door->angle - turnAngle;
            } else {
                door->destinationAngle = door->angle + turnAngle;
            }
        }
        door->rotationSpeed = 0x199;
    }
    doorFeature->unk_2c.type2.flags = (unsigned short)(doorFeature->unk_2c.type2.flags | DoorFlag_Open);
    door->flags |= BmdjElementFlag_Open;
    for (int i = 0; i < self->terrainElementCount_; i++) {
        BmdjSceneElement* collisionElement = self->terrainElements_[i];
        if (collisionElement->parent == door) {
            collisionElement->flags |= BmdjElementFlag_Open;
            break;
        }
    }
    ZoneFeatures::Opcode6aEntry* feature = (ZoneFeatures::Opcode6aEntry*)ZoneFeatures_GetFirstOfType((unsigned char*)&self->substruct_6c_, 2);
    while (feature) {
        if (feature->unk_2c.type2.nodeId == doorFeature->unk_2c.type2.nodeId && feature->unk_2c.type2.elementId == doorFeature->unk_2c.type2.elementId)
            feature->unk_2c.type2.flags = (unsigned short)(feature->unk_2c.type2.flags | DoorFlag_Open);
        feature = feature->pNext;
    }
    if (sound) {
        SoundTable sounds = Zone3D_doorSounds;
        SePlayer_Play(&g_sePlayer, sounds.values[doorFeature->unk_2c.type2.soundIndex], 0);
    }
    if (forced && (doorFeature->unk_2c.type2.flags & 8)) {
        GameObject* protagonist = GameState::GetInstance()->GetProtagonist();
        protagonist->combatFields_.unknown_b2_ = 0;
        GameObject_DisableControl((Obj020397cc*)protagonist, 1);
        self->unk_830[0] = 8;
        return;
    }
    int doorIndex = Zone3D_GetDoorIndex(self, doorFeature);
    if (forced && notify) LinkMessageQueue_SendDoorOpened(self->currentZoneID_, (unsigned short)doorIndex, sound);
    Obj02028c64* zoneRecord = FindInlineEntryById(ZoneRecords_GetInstance(), self->currentZoneID_);
    if (zoneRecord && !(doorFeature->unk_2c.type2.flags & DoorFlag_NotSaved)) ZoneRecord_SetDoorOpened(zoneRecord, doorIndex);
}
