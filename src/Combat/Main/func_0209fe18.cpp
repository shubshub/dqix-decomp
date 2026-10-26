#include <globaldefs.h>

extern "C" int func_ov017_021d4df8(void*, int);
extern "C" void func_ov017_021d4ce4(void*, int);
extern "C" void func_ov017_021d4ccc(void*);

struct Struct_0209fe18 {
    char unknown_0_[0x4c];
    int unknown_4c_;
    char unk_50[0x14];
    int unknown_64_;
    int unknown_68_;
};

// USA: func_0209fe18
extern "C" ARM void func_0209fe18(Struct_0209fe18* obj) {
    if (obj->unknown_64_ >= 0) {
        if (func_ov017_021d4df8((char*)obj + 0x10, obj->unknown_64_) == 0) {
            obj->unknown_64_ = -1;
            return;
        }
        func_ov017_021d4ce4((char*)obj + 0x10, obj->unknown_64_);
        obj->unknown_68_ = obj->unknown_64_;
        obj->unknown_64_ = -1;
    } else {
        if (obj->unknown_68_ < 0) return;
        func_ov017_021d4ccc((char*)obj + 0x10);
        if (obj->unknown_4c_ != 0) {
            obj->unknown_68_ = -1;
        }
    }
}
