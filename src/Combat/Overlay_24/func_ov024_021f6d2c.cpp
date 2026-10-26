#include <globaldefs.h>

extern "C" int func_020882f8(unsigned char* obj);

struct Struct_ov024_021de25c { char unk[0x14]; int flags; };
struct Struct_ov024_021de124 { char unk[0x138]; struct Struct_ov024_021de25c* inner; };
extern "C" int func_ov024_021de25c(struct Struct_ov024_021de124* obj);

struct Struct_ov024_021f6d2c {
    int pad0;
    struct Struct_ov024_021de124* combatant;
    int pad2[3];
    float x;
    float y;
    float unknown_1c_;
    float unknown_20_;
};

// USA: func_ov024_021f6d2c
extern "C" ARM int func_ov024_021f6d2c(struct Struct_ov024_021f6d2c* obj) {
    struct Struct_ov024_021de124* combatant = obj->combatant;
    if (func_020882f8((unsigned char*)combatant->inner) || func_ov024_021de25c(combatant)) {
        obj->unknown_1c_ = obj->x * 2.0f;
        obj->unknown_20_ = obj->y * 2.0f;
    }
    return 1;
}
