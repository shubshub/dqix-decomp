#include <globaldefs.h>

struct Struct_0207f0ac;

struct Struct_020807c4 {
    char pad[0xa];
    short field_a;
    short unknown_c_;
};

extern "C" struct Struct_020807c4* func_0207f0ac(struct Struct_0207f0ac* list, int id);

// USA: func_020807c4
extern "C" ARM void func_020807c4(void* obj, int id, short* outX, short* outY) {
    struct Struct_020807c4* e = func_0207f0ac((struct Struct_0207f0ac*)((char*)obj + 0xc), id);
    if (e != NULL) {
        *outX = e->field_a << 3;
        *outY = e->unknown_c_ << 3;
    }
}
