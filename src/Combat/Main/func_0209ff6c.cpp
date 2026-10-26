#include <globaldefs.h>

extern "C" int func_ov017_021d4df8(void*, int);
extern "C" void func_ov017_021d4ce4(void*, int);
extern "C" void func_ov017_021d4ccc(void*);

struct Struct_0209ff6c {
    char unknown_0_[0x48];
    int unknown_48_;
    char unknown_4c_[0x14];
    int unknown_60_;
    int unknown_64_;
};

// USA: func_0209ff6c
extern "C" ARM void func_0209ff6c(Struct_0209ff6c* obj) {
    if (obj->unknown_60_ >= 0) {
        if (func_ov017_021d4df8((char*)obj + 0xc, obj->unknown_60_) == 0) {
            obj->unknown_60_ = -1;
            return;
        }
        func_ov017_021d4ce4((char*)obj + 0xc, obj->unknown_60_);
        obj->unknown_64_ = obj->unknown_60_;
        obj->unknown_60_ = -1;
    } else {
        if (obj->unknown_64_ < 0) return;
        func_ov017_021d4ccc((char*)obj + 0xc);
        if (obj->unknown_48_ != 0) {
            obj->unknown_64_ = -1;
        }
    }
}
