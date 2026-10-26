#include <globaldefs.h>

struct Struct_ov006_02159f94 {
    unsigned char pad0[0x3a4];
    int unknown_3a4_;
    int unknown_3a8_;
    int unknown_3ac_;
};

// USA: func_ov006_02159f94
extern "C" ARM void func_ov006_02159f94(struct Struct_ov006_02159f94* obj) {
    if (obj->unknown_3ac_ != 0 && obj->unknown_3a4_ != 0) {
        obj->unknown_3ac_ = 0;
    }
}
