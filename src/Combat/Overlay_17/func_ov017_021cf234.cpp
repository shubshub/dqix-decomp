#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void PartyMember_RecalculateStats(void* a, int arg1);

struct Struct_ov017_021cf234 {
    unsigned int idx : 8;
    unsigned int rest : 24;
};

struct Struct_ov017_021cf234_2 {
    unsigned int fieldA : 10;
    unsigned int fieldB : 10;
    unsigned int fieldC : 10;
    unsigned int unknown_3_6_ : 2;
};

struct Struct_ov017_021cf234_3 {
    char pad[4];
    struct Struct_ov017_021cf234_2 field4;
    struct Struct_ov017_021cf234_2 field8;
    struct Struct_ov017_021cf234_2 fieldc;
    unsigned int field10;
};

#if defined(jpn)
enum { Enum_ov017_021cf234_2128 = 0x7b8 };
#else
enum { Enum_ov017_021cf234_2128 = 0x850 };
#endif

// USA: func_ov017_021cf234
extern "C" ARM void func_ov017_021cf234(int unused0, struct Struct_ov017_021cf234_3* src, GameState* battleStruct) {
    unsigned int id = (src->field10 << 21) >> 29;
    GameObject* c = func_0200ff1c(battleStruct, id);
    if (!c) return;
    unsigned char* p = (unsigned char*)func_02053c6c((unsigned char*)c);
    if (!p) return;

    unsigned int var3 = ((struct Struct_ov017_021cf234*)&src->field10)->idx;
    unsigned char idx = (unsigned char)var3;
    unsigned char* base = p + Enum_ov017_021cf234_2128 + idx * 0xc;
    ((struct Struct_ov017_021cf234_2*)(base + 0))->fieldA = src->field4.fieldA;
    ((struct Struct_ov017_021cf234_2*)(base + 0))->fieldB = src->field4.fieldB;
    ((struct Struct_ov017_021cf234_2*)(base + 0))->fieldC = src->field4.fieldC;
    ((struct Struct_ov017_021cf234_2*)(base + 4))->fieldA = src->field8.fieldA;
    ((struct Struct_ov017_021cf234_2*)(base + 4))->fieldB = src->field8.fieldB;
    ((struct Struct_ov017_021cf234_2*)(base + 4))->fieldC = src->field8.fieldC;
    ((struct Struct_ov017_021cf234_2*)(base + 8))->fieldA = src->fieldc.fieldA;
    ((struct Struct_ov017_021cf234_2*)(base + 8))->fieldB = src->fieldc.fieldB;
    ((struct Struct_ov017_021cf234_2*)(base + 8))->fieldC = src->fieldc.fieldC;

    unsigned int flag = (src->field10 << 20) >> 31;
    if (flag) {
        PartyMember_RecalculateStats(p, 0);
    }
}
