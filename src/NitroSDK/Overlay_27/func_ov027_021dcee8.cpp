#include <globaldefs.h>

struct Struct_ov027_021e33e0_14 {
    char pad0[0x26];
    unsigned short unknown_26_;
};

extern Struct_ov027_021e33e0_14 data_ov027_021e33e0;

// USA: func_ov027_021dcee8
extern "C" ARM void func_ov027_021dcee8(unsigned short value) {
    data_ov027_021e33e0.unknown_26_ = value;
}
