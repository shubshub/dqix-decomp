#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Graphics/LightingManager.h"
#include "Util/Random.h"
#include "Resource/Brightness.h"


extern "C" void* LinkSession_GetInstance(void);
extern "C" unsigned char* Zone3D_GetInstance(void);
struct PointerField32c_ffc0;
extern "C" void* GameState_GetShip(struct PointerField32c_ffc0* obj);
extern "C" unsigned char* Scenario_GetInstance(void);
extern "C" int FieldTaskQueue_IsEmpty(void** obj);
struct HeadNode02046b24;
extern "C" int FieldTaskQueue_GetCurrentKind(struct HeadNode02046b24** obj);
extern "C" int func_02053cdc(int* obj);
extern "C" int func_02039760(void* obj);
extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);
int NextRandomBetween(struct Random* rng, int lo, int hi);
extern "C" void func_ov017_021b6f18(void* node);
extern "C" void func_ov017_02196c08(unsigned char* obj);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" unsigned short func_ov017_021a1a20(void);
extern "C" void* GameObject_GetFloorAttribute(void* obj);
struct ColorHolder;
extern "C" unsigned short func_0204be3c(struct ColorHolder* obj);
extern "C" int func_ov017_021970a0(int mode);
extern "C" void func_ov017_021b6e70(void* evt, unsigned short tag);
extern "C" void func_ov017_021b7104(void* node, void* src);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);

struct Struct_ov017_02196c4c {
#if defined(jpn)
    unsigned char pad0[0x34e8];
#else
    unsigned char pad0[0x36f8];
#endif
    unsigned short* entry;
    void* list;
    unsigned char unknown_3700_[0x3718 - 0x3700];
    void* node;
};

struct Struct_ov017_02196c4c_2 {
    unsigned char pad0[3];
    unsigned char active;
};

struct Struct_ov017_02196c4c_3 {
    unsigned char kind;
    unsigned char field_0x1;
    unsigned short tag;
    unsigned short id;
    unsigned char pad6[2];
    int unknown_8_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
    unsigned char unknown_f_;
    unsigned short color;
    unsigned char timeOfDay;
    unsigned char unknown_13_;
    int unknown_14_;
};

// USA: func_ov017_02196c4c
extern "C" ARM int func_ov017_02196c4c(Struct_ov017_02196c4c* self) {
#if defined(jpn)
 enum {Enum_ov017_02196c4c_396=0x180, Enum_ov017_02196c4c_10132=0x27d4};
#else
 enum {Enum_ov017_02196c4c_396=0x18c, Enum_ov017_02196c4c_10132=0x2794};
#endif
    GameState* battle = GameState::GetInstance();
    LinkSession_GetInstance();
    unsigned char* work = Zone3D_GetInstance();
    unsigned short* entry = self->entry;
    GameObject* combatant = battle->GetLeader();
    void* field32c = GameState_GetShip((struct PointerField32c_ffc0*)battle);
    LightingManager* lighting;
    Struct_ov017_02196c4c_2* actor = (Struct_ov017_02196c4c_2*)GetGameResources()->unknown_ptr_array_371c[6];
    unsigned char* flags = Scenario_GetInstance();
    lighting = LightingManager::GetInstance();

    if (FieldTaskQueue_IsEmpty((void**)self->list) == 0) {
        return FieldTaskQueue_GetCurrentKind((struct HeadNode02046b24**)self->list) == 0x45 ? 0 : 2;
    }
    if (entry == NULL) {
        return 2;
    }
    if (func_02053cdc((int*)combatant)) {
        return 2;
    }
    if (*(unsigned int*)((unsigned char*)combatant + Enum_ov017_02196c4c_396) & 1) {
        return 2;
    }
    if (TestFlags04((GameResources*)self, 0x10)) {
        return 2;
    }
    if (actor->active != 0) {
        return 2;
    }
    if (func_02039760(combatant) != 0) {
        return 0;
    }
    if (*entry != 10000) {
        return 0;
    }
    if (!Scenario_TestFlag((int)flags, flags + 0x8c, 0x2b)) {
        return 0;
    }

    int var8 = 0;
    if (*(int*)(work + Enum_ov017_02196c4c_10132) <= 0) {
        var8 = 1;
        *(int*)(work + Enum_ov017_02196c4c_10132) = NextRandomBetween(GetBTRandom(), 0x1e, 0x64);
    }
    if (var8 == 0) {
        return 0;
    }

    func_ov017_021b6f18(self->node);
    Struct_ov017_02196c4c_3 evt;
    func_ov017_02196c08((unsigned char*)&evt);
    evt.kind = 1;
    evt.field_0x1 = GameState_GetProtagonistIndex(battle);
    evt.id = func_ov017_021a1a20();
    evt.tag = 0xffff;
    evt.unknown_e_ = 1;
    evt.color = func_0204be3c((struct ColorHolder*)GameObject_GetFloorAttribute(field32c));
    evt.unknown_f_ = func_ov017_021970a0(0);
    func_ov017_021b6e70(&evt, evt.tag);
    evt.timeOfDay = lighting->timeOfDayIndex_;
    func_ov017_021b7104(self->node, &evt);
    func_020469b4((struct TailList020469b4*)self->list, (struct TailNode020469b4*)self->node);
    return 1;
}
