#include <globaldefs.h>

struct Struct_ov031_022140b0 {
    unsigned char unknown_0_0_ : 2;
    unsigned char unknown_0_2_ : 2;
    unsigned char rest : 4;
};
struct Struct_ov031_02213dd8 { unsigned char pad[0xd0b]; struct Struct_ov031_022140b0 unknown_d0b_; };

// USA: func_ov031_022140b0
extern "C" ARM unsigned int func_ov031_022140b0(struct Struct_ov031_02213dd8* e) {
    return e->unknown_d0b_.unknown_0_0_ == 1 ? 0x30000 : 0x20000;
}
