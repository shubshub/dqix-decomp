#include <globaldefs.h>

struct Struct_ov024_021f8874_3 {
    char pad0[0x2];
    unsigned short field2;
    char pad1[0x14 - 0x4];
    int unknown_14_;
};
struct Struct_ov024_021f8874 {
    char pad0[0x4];
    short field4;
    char pad1[0x138 - 0x6];
    struct Struct_ov024_021f8874_3* inner;
};
struct Struct_ov024_021f8874_2 { char pad0[0x8]; struct Struct_ov024_021f8874* field8; };
struct Struct_ov024_021f8874_4 {
    char pad0[0x8];
    unsigned int field8 : 8;
    unsigned int unknown_9_0_ : 19;
    unsigned int unknown_b_3_ : 1;
    unsigned int unknown_b_4_ : 4;
    char pad1[0x10 - 0xc];
    unsigned int field10;
};

extern "C" int func_ov024_021f87dc(struct Struct_ov024_021f8874* a0, struct Struct_ov024_021f8874_4* a1, int* a2);

// USA: func_ov024_021f8874
extern "C" ARM int func_ov024_021f8874(struct Struct_ov024_021f8874_2* obj, struct Struct_ov024_021f8874_4* target, struct Struct_ov024_021f8874* combatant, int* extra) {
    if (!target) return 0;
    if (target->unknown_b_3_ == 0) return 0;
    int inRange = 0;
    short category = combatant->field4;
    if (category >= 0 && category <= 3) {
        inRange = 1;
    }
    int value;
    if (inRange) {
        value = func_ov024_021f87dc(combatant, target, extra);
    } else {
        value = target->field8;
    }
    unsigned short threshold = obj->field8->inner->field2;
    if (value > threshold) return 0;
    if (target->field10 & 1) {
        if (combatant->inner->unknown_14_ & 0x100) return 0;
    }
    if (target->field10 & 2) {
        if (combatant->inner->unknown_14_ & 0x80) return 0;
    }
    return 1;
}
