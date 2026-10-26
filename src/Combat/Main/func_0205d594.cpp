#include <globaldefs.h>

struct Struct_0205d304_2 {
    char unk[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
};

// USA: func_0205d594
extern "C" ARM void func_0205d594(struct Struct_0205d304_2* obj, unsigned char* arg1, unsigned char* arg2) {
    *arg1 = obj->unknown_1c_0_;
    *arg2 = obj->unknown_1c_4_;
}
