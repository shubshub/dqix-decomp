#include <globaldefs.h>
#include "GameState/GameState.h"

struct Entry_02028bd0 {
    unsigned short id;
    unsigned short slotGroup : 2;
    unsigned short active : 1;
    unsigned short flags : 13;
};
struct Element0x318_02028bac;
struct Struct_02076a8c_2;
struct FieldMonster021a1ad0 {
    Object3D object;
    char unknown_ac_[0x130 - 0xac];
    int phase;
    char unknown_134_[0x17d - 0x134];
    unsigned char flags;
};
struct MonsterBounds021a1ad0 {
    Vector3fix maximum;
    Vector3fix minimum;
};
union Struct_ov017_021a1ad0_3 {
    Vector3fix vector;
    unsigned int words[3];
};
struct Struct_ov017_021a1ad0_4 {
    Vector3fix origin;
    Struct_ov017_021a1ad0_3 position;
    MonsterBounds021a1ad0 bounds;
    Struct_ov017_021a1ad0_3 unknown_30_;

    Struct_ov017_021a1ad0_4(const Vector3fix& position) : origin(position) {}
};
extern "C" Entry_02028bd0* ZoneRecords_GetInstance();
extern "C" Entry_02028bd0* ZoneRecords_GetAt(Element0x318_02028bac*, int);
extern "C" Entry_02028bd0* ZoneRecords_Find(Entry_02028bd0*, int);
extern "C" void func_02076b58(Struct_02076a8c_2*);
extern "C" int ZoneId_IsGrottoBossFloor(int);
extern "C" int LinkSession_IsActive(int*);
extern "C" void func_ov017_021c9544(int, int, int, int);
extern "C" int* LinkSession_GetInstance();
extern "C" unsigned short* Zone3D_GetInstance();
extern "C" int LinkSession_IsHostOrSolo(int*);
extern "C" void func_02034104(Vector3fix*, GameObject*);
extern "C" int Bounds3D_ContainsPoint(Vector3fix*, MonsterBounds021a1ad0*);
extern "C" void FieldMonsterState_Init(FieldMonster021a1ad0*);

// USA: func_ov017_021a1ad0
extern "C" ARM void func_ov017_021a1ad0() {
    GameState* state = GameState::GetInstance();
    Entry_02028bd0* table = ZoneRecords_GetInstance();
    int* manager = LinkSession_GetInstance();
    unsigned short* currentArea = Zone3D_GetInstance();
    if (LinkSession_IsHostOrSolo(manager)) {
        int base;
        int group;
        Entry_02028bd0* entry;
        for (group = 0; group < 4; group++) {
            entry = ZoneRecords_GetAt((Element0x318_02028bac*)table, group);
            if (!entry->active) continue;
            base = group * 12 + 0x70;
            int tag = -1;
            for (int slot = 0; slot < 12; slot++) {
                FieldMonster021a1ad0* monster = (FieldMonster021a1ad0*)state->GetFieldMonsterByIndex(slot + base);
                if (!monster || !monster->object.IsVisible()) continue;
                func_02076b58((Struct_02076a8c_2*)monster);
                int removable = 1;
                if ((monster->flags & 2) || (monster->flags & 4) || ZoneId_IsGrottoBossFloor(*currentArea)) removable = 0;
                if (monster->flags & 8) removable = 0;
                if (!removable) continue;
                int clear;
                {
                    GameObject* fieldMonster;
                    GameState* collisionState = GameState::GetInstance();
                    fieldMonster = collisionState->GetFieldMonsterByIndex(slot + base);
                    if (!fieldMonster) clear = 0;
                    else {
                        Struct_ov017_021a1ad0_4 frame(fieldMonster->obj3D_.position_);
                        for (int i = 0; i < 4; i++) {
                            GameObject* wanderingMonster = collisionState->GetWanderingMonsterByIndex(i);
                            if (!wanderingMonster) continue;
                            int area = wanderingMonster->obj3D_.GetField06();
                            if (area != fieldMonster->obj3D_.GetField06()) continue;
                            func_02034104(&frame.unknown_30_.vector, wanderingMonster);
                            frame.position = frame.unknown_30_;
                            frame.bounds.maximum = frame.position.vector;
                            frame.bounds.maximum.x += 0x19000;
                            frame.bounds.maximum.y += 0x19000;
                            frame.bounds.maximum.z += 0x19000;
                            frame.bounds.minimum = frame.position.vector;
                            frame.bounds.minimum.x -= 0x19000;
                            frame.bounds.minimum.y -= 0x19000;
                            frame.bounds.minimum.z -= 0x19000;
                            if (Bounds3D_ContainsPoint(&frame.origin, &frame.bounds)) {
                                clear = 0;
                                goto collisionComplete;
                            }
                        }
                        clear = 1;
                    }
                }
collisionComplete:
                if (clear && monster->phase != 8 && monster->phase != 9) {
                    FieldMonsterState_Init(monster);
                    monster->object.MakeHidden();
                    if (LinkSession_IsActive(manager) && entry) {
                        func_ov017_021c9544(entry->id, slot, monster->object.unknown_2_, tag);
                    }
                }
            }
        }
    } else {
        Entry_02028bd0* entry = ZoneRecords_Find(table, *currentArea);
        if (!entry) return;
        for (int slot = 0; slot < 12; slot++) {
            FieldMonster021a1ad0* monster = (FieldMonster021a1ad0*)state->GetFieldMonsterByIndex(entry->slotGroup * 12 + 0x70 + slot);
            if (monster && monster->object.IsVisible()) func_02076b58((Struct_02076a8c_2*)monster);
        }
    }
}
