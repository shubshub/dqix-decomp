#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov017_021a4e70(unsigned char* base);
extern "C" unsigned char GameObject_IsClimbingLadder(char* obj);

struct Struct_ov017_0219b33c {
    unsigned char field0;
    unsigned char field1;
    unsigned short field2;
    unsigned char field4;
    char pad5[3];
    int field8;
    int fieldc;
    short field10;
    short field12;
};

extern const unsigned char data_ov017_021d64a0[15];

struct Struct_ov017_0219b33c_2 { unsigned int v[2]; };
struct Struct_ov017_0219b33c_3 { unsigned char v[15]; };

// USA: func_ov017_0219b33c
extern "C" ARM void func_ov017_0219b33c(char* self, struct Struct_ov017_0219b33c* src) {
#if defined(jpn)
 enum {regionalOffset0=0x180, regionalOffset1=0x34b4, regionalOffset2=0x3e60, regionalOffset3=0x34a4, regionalOffset4=0x34a5, regionalOffset5=0x34a6, regionalOffset6=0x34a8, Enum_ov017_0219b33c_14012=0x34ac, Enum_ov017_0219b33c_14022=0x34b6};
#else
 enum {regionalOffset0=0x18c, regionalOffset1=0x36c4, regionalOffset2=0x4080, regionalOffset3=0x36b4, regionalOffset4=0x36b5, regionalOffset5=0x36b6, regionalOffset6=0x36b8, Enum_ov017_0219b33c_14012=0x36bc, Enum_ov017_0219b33c_14022=0x36c6};
#endif
    GameObject* combatant = GameState::GetInstance()->GetLeader();

    if (!func_ov017_021a4e70((unsigned char*)self)) return;

    if (combatant) {
        if (*(int*)((char*)combatant + regionalOffset0) & 1) return;
        if (GameObject_IsClimbingLadder((char*)combatant) != 0) return;
    }

    if (*(short*)(self + regionalOffset1) < src->field10) return;
    if (*(int*)(self + regionalOffset2) != 0) return;

    *(unsigned char*)(self + regionalOffset3) = src->field0;
    *(unsigned char*)(self + regionalOffset4) = src->field1;
    *(unsigned short*)(self + regionalOffset5) = src->field2;
    *(unsigned char*)(self + regionalOffset6) = src->field4;
    *(struct Struct_ov017_0219b33c_2*)(self + Enum_ov017_0219b33c_14012) = *(struct Struct_ov017_0219b33c_2*)&src->field8;
    *(short*)(self + regionalOffset1) = src->field10;
    *(short*)(self + Enum_ov017_0219b33c_14022) = src->field12;

    if (src->field1 != 0x12) return;

    struct Struct_ov017_0219b33c_3 var1;
    unsigned char* buf = var1.v;
    var1 = *(struct Struct_ov017_0219b33c_3*)data_ov017_021d64a0;

    *(unsigned char*)(self + regionalOffset4) = buf[src->field0];
}
