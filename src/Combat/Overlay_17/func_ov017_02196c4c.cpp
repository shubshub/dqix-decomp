#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Graphics/LightingManager.h"
#include "Util/Random.h"
#include "Resource/Brightness.h"


extern "C" void* LinkSession_GetInstance(void);
extern "C" unsigned char* Zone3D_GetInstance(void);
struct PointerField32c_ffc0;
void* GameState_GetShip(struct PointerField32c_ffc0* obj);
extern "C" unsigned char* Scenario_GetInstance(void);
int FieldTaskQueue_IsEmpty(void** obj);
struct HeadNode02046b24;
int FieldTaskQueue_GetCurrentKind(struct HeadNode02046b24** obj);
int IsField0x1b4Or0x1b8Positive_02053cdc(int* obj);
int GetIntField0x264_02039760(void* obj);
int Scenario_TestFlag(int unused, unsigned char* arr, int index);
int NextRandomBetween(struct Random* rng, int lo, int hi);
extern "C" void func_ov017_021b6f18(void* node);
void InitStruct_02196c08(unsigned char* obj);
int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" unsigned short func_ov017_021a1a20(void);
void* GameObject_GetFloorAttribute(void* obj);
struct ColorHolder;
unsigned short ConvertColorToDecimal_0204be3c(struct ColorHolder* obj);
extern "C" int func_ov017_021970a0(int mode);
extern "C" void func_ov017_021b6e70(void* evt, unsigned short tag);
extern "C" void func_ov017_021b7104(void* node, void* src);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

struct Struct_ov017_02196c4c {
#if defined(jpn)
    unsigned char unknown_0_[0x34e8];
#else
    unsigned char unknown1_0_[0x36f8];
#endif
    unsigned short* unknown_36f8_;
    void* unknown_36fc_;
    unsigned char unknown_3700_[0x3718 - 0x3700];
    void* unknown_3718_;
};

struct Struct_ov017_02196c4c_2 {
    unsigned char unknown_0_[3];
    unsigned char unknown_3_;
};

struct Struct_ov017_02196c4c_3 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned char unknown_6_[2];
    int unknown_8_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
    unsigned char unknown_f_;
    unsigned short unknown_10_;
    unsigned char unknown_12_;
    unsigned char unknown_13_;
    int unknown_14_;
};

// USA: func_ov017_02196c4c
extern "C" ARM int func_ov017_02196c4c(Struct_ov017_02196c4c* arg0) {
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
    Actor02196c4c* actor = (Actor02196c4c*)GetGameResources()->unknown_ptr_array_371c[6];
    unsigned char* flags = Scenario_GetInstance();
    lighting = LightingManager::GetInstance();

    if (FieldTaskQueue_IsEmpty((void**)self->list) == 0) {
        return FieldTaskQueue_GetCurrentKind((struct HeadNode02046b24**)self->list) == 0x45 ? 0 : 2;
    }
    if (var2 == NULL) {
        return 2;
    }
    if (func_02053cdc((int*)var3)) {
        return 2;
    }
    if (*(unsigned int*)((unsigned char*)var3 + Enum_ov017_02196c4c_396) & 1) {
        return 2;
    }
    if (TestFlags04((GameResources*)arg0, 0x10)) {
        return 2;
    }
    if (var6->unknown_3_ != 0) {
        return 2;
    }
    if (func_02039760(var3) != 0) {
        return 0;
    }
    if (*var2 != 10000) {
        return 0;
    }
    if (!Scenario_TestFlag((int)flags, flags + 0x8c, 0x2b)) {
        return 0;
    }

    int var8 = 0;
    if (*(int*)(var1 + Enum_ov017_02196c4c_10132) <= 0) {
        var8 = 1;
        *(int*)(var1 + Enum_ov017_02196c4c_10132) = NextRandomBetween(GetBTRandom(), 0x1e, 0x64);
    }
    if (var8 == 0) {
        return 0;
    }

    func_ov017_021b6f18(self->node);
    Event02196c4c evt;
    InitStruct_02196c08((unsigned char*)&evt);
    evt.kind = 1;
    evt.field_0x1 = GameState_GetProtagonistIndex(battle);
    evt.id = func_ov017_021a1a20();
    evt.tag = 0xffff;
    evt.field_0xe = 1;
    evt.color = ConvertColorToDecimal_0204be3c((struct ColorHolder*)GameObject_GetFloorAttribute(field32c));
    evt.field_0xf = func_ov017_021970a0(0);
    func_ov017_021b6e70(&evt, evt.tag);
    evt.timeOfDay = lighting->timeOfDayIndex_;
    func_ov017_021b7104(self->node, &evt);
    AppendNodeToTail((struct TailList020469b4*)self->list, (struct TailNode020469b4*)self->node);
    return 1;
}
