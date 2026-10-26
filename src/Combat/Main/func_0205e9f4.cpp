#include <globaldefs.h>

extern "C" void func_0205e944(void*, int);

struct Obj0205e9f4 {
    char unknown_0_[0xc8];
    int unknown_c8_;
    unsigned char field_cc;
};

// USA: func_0205e9f4
extern "C" ARM void func_0205e9f4(struct Obj0205e9f4* obj, int state) {
    if (state < 1) return;
    if (state > 5) return;
    obj->field_cc = (unsigned char)state;
    func_0205e944(obj, obj->unknown_c8_);
}
