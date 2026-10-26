#include <globaldefs.h>

struct Struct_0207f0ac;
struct Struct_0207fdcc_2;

struct Struct_02080c68_2 {
    char pad[0x8];
    short unknown_8_;
    char pad2[0x12 - 0xa];
    union {
        unsigned char raw;
        struct { unsigned char lo : 4; unsigned char hi : 4; } unknown1_0_;
    } state;
};

struct Struct_02080c68 {
    char pad[0xc2];
    short unknown_c2_;
};

extern "C" struct Struct_02080c68_2* func_0207f0ac(struct Struct_0207f0ac* list, int id);
extern "C" struct Struct_02080c68* func_02081da8(struct Struct_0207fdcc_2* obj, int key);

// USA: func_02080c68
extern "C" ARM void func_02080c68(void* obj, int id, int value) {
    struct Struct_02080c68_2* e = func_0207f0ac((struct Struct_0207f0ac*)((char*)obj + 0xc), id);
    struct Struct_02080c68* elem;
    if (e == NULL) {
        return;
    }
    e->state.raw = (e->state.raw & ~0xf) | (value & 0xf);
    elem = func_02081da8((struct Struct_0207fdcc_2*)obj, e->unknown_8_);
    if (elem != NULL) {
        elem->unknown_c2_ = e->state.unknown1_0_.lo & 0xf;
    }
}
