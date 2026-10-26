#include <globaldefs.h>

struct Struct_02081130 {
    char unk0[0x15];
    unsigned char unknown_15_;
    char unknown_16_[0x18 - 0x16];
};

struct Struct_0207f0ac;

extern "C" struct Struct_02081130* func_0207f0ac(struct Struct_0207f0ac*, int);

// USA: func_02081130
extern "C" ARM void func_02081130(void* obj, int id, int flag) {
    struct Struct_02081130* e = func_0207f0ac((struct Struct_0207f0ac*)((char*)obj + 0xc), id);
    if (e == NULL) {
        return;
    }
    if (flag != 0) {
        e->unknown_15_ |= 1;
    } else {
        e->unknown_15_ &= ~1;
    }
}
