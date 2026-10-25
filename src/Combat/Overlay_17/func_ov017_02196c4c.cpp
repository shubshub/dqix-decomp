#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Graphics/LightingManager.h"
#include "Util/Random.h"
#include "Resource/Brightness.h"


extern "C" void* func_0202ae18(void);
extern "C" unsigned char* Zone3D_GetInstance(void);
struct PointerField32c_ffc0;
void* GetPointerAt0x32c_0200ffc0(struct PointerField32c_ffc0* obj);
extern "C" unsigned char* Scenario_GetInstance(void);
int IsField0Null_02046b08(void** obj);
struct HeadNode02046b24;
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);
int IsField0x1b4Or0x1b8Positive_02053cdc(int* obj);
int GetIntField0x264_02039760(void* obj);
int Scenario_TestFlag(int unused, unsigned char* arr, int index);
int NextRandomBetween(struct Random* rng, int lo, int hi);
extern "C" void func_ov017_021b6f18(void* node);
void InitStruct_02196c08(unsigned char* obj);
int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" unsigned short func_ov017_021a1a20(void);
extern "C" void* func_02033fa0(void* arg0);
struct Struct_0204be3c;
extern "C" unsigned short func_0204be3c(struct Struct_0204be3c* arg0);
extern "C" int func_ov017_021970a0(int arg0);
extern "C" void func_ov017_021b6e70(void* arg0, unsigned short arg1);
extern "C" void func_ov017_021b7104(void* arg0, void* arg1);
struct Struct_0201bdac_2;
struct Struct_0201bdac;
extern "C" void func_020469b4(struct Struct_0201bdac_2* arg0, struct Struct_0201bdac* arg1);

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
    GameState* var0 = GameState::GetInstance();
    func_0202ae18();
    unsigned char* work = Zone3D_GetInstance();
    unsigned short* entry = self->entry;
    GameObject* combatant = battle->GetUnknownGameObject();
    void* field32c = GetPointerAt0x32c_0200ffc0((struct PointerField32c_ffc0*)battle);
    LightingManager* lighting;
    Actor02196c4c* actor = (Actor02196c4c*)GetGameResources()->unknown_ptr_array_371c[6];
    unsigned char* flags = Scenario_GetInstance();
    lighting = LightingManager::GetInstance();

    if (func_02046b08((void**)arg0->unknown_36fc_) == 0) {
        return func_02046b24((struct Struct_02015438**)arg0->unknown_36fc_) == 0x45 ? 0 : 2;
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
    evt.color = ConvertColorToDecimal_0204be3c((struct ColorHolder*)GetPtrField0x114_02033fa0(field32c));
    evt.field_0xf = func_ov017_021970a0(0);
    func_ov017_021b6e70(&evt, evt.tag);
    evt.timeOfDay = lighting->timeOfDayIndex_;
    func_ov017_021b7104(self->node, &evt);
    AppendNodeToTail((struct TailList020469b4*)self->list, (struct TailNode020469b4*)self->node);
    return 1;
}
