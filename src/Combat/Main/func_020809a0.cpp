#include <globaldefs.h>

struct Struct_020809a0_2 {
    char pad[0xa];
    short unknown_a_;
    short unknown_c_;
    char pad2[0x30 - 0xe];
};

struct Struct_0207f524 {
    struct Struct_020809a0_2* entries;
    short count;
};

extern "C" struct Struct_020809a0_2* func_0207f6ac(struct Struct_0207f524* list, int id);

struct Struct_020809a0 {
    char pad[4];
    struct Struct_0207f524 list;
};

// USA: func_020809a0
extern "C" ARM void func_020809a0(struct Struct_020809a0* obj, int id, short x, short y) {
    struct Struct_020809a0_2* e = func_0207f6ac(&obj->list, id);
    if (e != NULL) {
        e->unknown_a_ = x;
        e->unknown_c_ = y;
    }
}
