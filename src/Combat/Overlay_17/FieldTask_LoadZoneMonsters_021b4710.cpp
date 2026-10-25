#include <globaldefs.h>

typedef void (*FuncPtr021b4710)(void*);

struct VTable021b4710 {
    FuncPtr021b4710 funcs[9];
};
extern VTable021b4710 data_ov017_021d6bd8;

struct Obj021b4710 {
    unsigned char pad[0x10];
    unsigned char index;
};

// Overlay 17, originally CallIndexedFunc_021b4710 (USA/EUR 0x021b4710, JPN 0x021b4e00)
ARM void FieldTask_LoadZoneMonsters(Obj021b4710* p, void* context) {
    VTable021b4710 local = data_ov017_021d6bd8;
    local.funcs[p->index](p);
}
