#include <globaldefs.h>

struct Struct_02057334_2 {
    char pad0[0x4];
    unsigned int field4;
    unsigned int field8;
    unsigned char unknown_c_;
    char unknown_d_[0x34 - 0xd];
    struct Struct_02057334_2* unknown_34_;
    unsigned char unknown_38_;
    unsigned char unknown_39_;
    char unknown_3a_[0x148 - 0x3a];
    struct Struct_02057334_2* unknown_148_;
};

// USA: func_02057854
extern "C" ARM int func_02057854(struct Struct_02057334_2* node) {
    struct Struct_02057334_2* child;
    if (node->unknown_c_ != 0) return 0;
    if (node->unknown_39_ != 0) return 0;
    if (node->unknown_38_ == 0) {
        for (child = node->unknown_34_; child != 0; child = child->unknown_148_) {
            int ok;
            if (child->unknown_c_ != 0) {
                ok = 0;
            } else {
                ok = child->field8 <= child->field4;
            }
            if (!ok) return 0;
        }
    }
    return node->field8 < node->field4;
}
