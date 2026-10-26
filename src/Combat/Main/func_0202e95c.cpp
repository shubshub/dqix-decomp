#include <globaldefs.h>

struct HalfwordTriple0202e98c;
extern "C" void Camera_ResetYaw(struct HalfwordTriple0202e98c* p);

struct Struct_0202e95c {
    char pad[0x212];
    unsigned short unknown_212_;
    unsigned short unknown_214_;
    unsigned short unknown_216_;
};

// USA: func_0202e95c
extern "C" ARM void func_0202e95c(Struct_0202e95c* obj, short a, unsigned short b) {
    if (b != 0) {
        obj->unknown_214_ = a;
        obj->unknown_216_ = b;
        return;
    }
    Camera_ResetYaw((struct HalfwordTriple0202e98c*)obj);
    obj->unknown_212_ = a;
}
