#include <globaldefs.h>

struct Struct_02081058 {
    char unk0[0x2a];
    unsigned char unknown_2a_;
    unsigned char unknown_2b_;
    unsigned char field2c;
    char unknown_2d_[0x30 - 0x2d];
};

struct Struct_0207f524;

extern "C" struct Struct_02081058* func_0207f6ac(struct Struct_0207f524*, int);

// USA: func_02081058
extern "C" ARM void func_02081058(void* obj, int id, int value) {
    struct Struct_02081058* e = func_0207f6ac((struct Struct_0207f524*)((char*)obj + 4), id);
    if (e == NULL) {
        return;
    }
    e->unknown_2b_ = (unsigned char)value;
    e->field2c = 8;
    e->unknown_2a_ |= 0x20;
}
