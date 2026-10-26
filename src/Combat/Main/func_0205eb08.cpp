#include <globaldefs.h>

extern "C" void SoundPlayer_RestoreHeapState(void* obj, int arg1);

struct Obj0205eb08 {
    char unknown_0_[0xb8];
    int field_b8;
    char unknown_bc_[4];
    int unknown_c0_;
};

// USA: func_0205eb08
extern "C" ARM void func_0205eb08(struct Obj0205eb08* obj) {
    SoundPlayer_RestoreHeapState(obj, obj->field_b8);
    obj->unknown_c0_ = obj->field_b8;
}
