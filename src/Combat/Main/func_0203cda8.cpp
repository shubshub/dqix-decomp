#include <globaldefs.h>

struct Struct_0203cda8 {
    char unk0[0x60];
    int unknown_60_;
    int unknown_64_;
};

// USA: func_0203cda8
extern "C" ARM void func_0203cda8(struct Struct_0203cda8* obj, int value) {
    obj->unknown_60_ = value;
    if ((unsigned int)(value & 0xff) >= (unsigned int)-128) {
        obj->unknown_60_ = (value & ~0xff) + 0x100;
    } else {
        obj->unknown_60_ = value & ~0xff;
    }
    obj->unknown_64_ = obj->unknown_60_;
}
