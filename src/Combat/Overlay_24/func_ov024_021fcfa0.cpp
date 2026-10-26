#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" int func_ov024_021fe698(void* obj, int arg);
extern "C" void func_ov024_021f9874(void* obj, void* buf, int unused, int val);

struct Struct_ov024_021fcfa0 {
    char pad0[4];
    short field4;
    unsigned char field6;
    GameObject* field8;
    int fieldC;
};

struct Struct_ov024_021fcfa0_2 {
    signed int unknown_0_0_ : 3;
    signed int unknown_0_3_ : 3;
    signed int unknown_0_6_ : 3;
    signed int unknown_1_1_ : 3;
    signed int unknown_1_4_ : 3;
    signed int unknown_1_7_ : 3;
    signed int unknown_2_2_ : 3;
    signed int unknown_2_5_ : 3;
};

// USA: func_ov024_021fcfa0
extern "C" ARM void func_ov024_021fcfa0(struct Struct_ov024_021fcfa0* obj) {
    int count;
    int flag = 0;
    if (obj->field6 == 2) flag = 1;
    if (obj->field6 == 0) return;
    if (obj->fieldC >= 3) flag = 1;
    if (!flag) return;
    if (!func_ov024_021fe698(obj, 0x12)) return;
    count = 0;
    if (((struct Struct_ov024_021fcfa0_2*)((char*)obj->field8->currentStats_ + 0x58))->unknown_0_3_ >= 2) count++;
    if (((struct Struct_ov024_021fcfa0_2*)((char*)obj->field8->currentStats_ + 0x58))->unknown_2_5_ >= 2) count++;
    if (((struct Struct_ov024_021fcfa0_2*)((char*)obj->field8->currentStats_ + 0x58))->unknown_0_0_ >= 2) count++;
    if (count >= 2) return;
    char buf[0xc8];
    memset(buf, 0, 0xc8);
    *(float*)(buf + 0xc4) = 1000.0f;
    func_ov024_021f9874(obj, buf, 0, obj->field4 & 0xff);
}
