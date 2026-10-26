#include <globaldefs.h>

struct Struct_ov005_02154d18 {
    char pad0[8];
    int unknown_8_;
    char pad2[4];
    int unknown_10_;
    char pad3[4];
    int f18;
    int f1c;
};

// USA: func_ov005_02154d18
extern "C" ARM void func_ov005_02154d18(Struct_ov005_02154d18* obj, int a, int b) {
    obj->f18 = a + obj->unknown_8_;
    obj->f1c = b + obj->unknown_10_;
}
