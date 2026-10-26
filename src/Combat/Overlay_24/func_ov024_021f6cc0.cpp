#include <globaldefs.h>

struct Struct_020885b4;
extern "C" int func_020885b4(struct Struct_020885b4* obj);
struct Struct_02088514;
extern "C" int func_02088514(struct Struct_02088514* obj);

struct Struct_ov024_021da9b0 { char unk[0x14]; int flags; };
struct Struct_ov024_021da670_7 { char unk[0x138]; struct Struct_ov024_021da9b0* inner; };
extern "C" int func_ov024_021da9b0(struct Struct_ov024_021da670_7* obj);

struct Struct_ov024_021f6cc0 {
    int pad0;
    struct Struct_ov024_021da670_7* combatant;
    int pad2[3];
    float x;
    float y;
    float unknown_1c_;
    float unknown_20_;
};

// USA: func_ov024_021f6cc0
extern "C" ARM int func_ov024_021f6cc0(struct Struct_ov024_021f6cc0* obj) {
    struct Struct_ov024_021da670_7* combatant = obj->combatant;
    if (func_020885b4((struct Struct_020885b4*)combatant->inner) ||
        func_02088514((struct Struct_02088514*)combatant->inner) ||
        func_ov024_021da9b0(combatant)) {
        obj->unknown_1c_ = obj->x * 1.5f;
        obj->unknown_20_ = obj->y * 1.5f;
    }
    return 1;
}
