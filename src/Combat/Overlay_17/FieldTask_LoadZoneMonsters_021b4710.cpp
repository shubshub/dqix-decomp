#include <globaldefs.h>

typedef void (*Type_ov017_021a3544)(void*);

struct Struct_ov017_021d6bd8 {
    Type_ov017_021a3544 unknown_0_[9];
};
extern Struct_ov017_021d6bd8 data_ov017_021d6bd8;

struct Obj021b4710 {
    unsigned char pad[0x10];
    unsigned char index;
};

// Overlay 17, originally CallIndexedFunc_021b4710 (USA/EUR 0x021b4710, JPN 0x021b4e00)
extern "C" ARM void FieldTask_LoadZoneMonsters(Obj021b4710* p, void* context) {
    Struct_ov017_021d6bd8 local = data_ov017_021d6bd8;
    local.unknown_0_[p->index](p);
}
