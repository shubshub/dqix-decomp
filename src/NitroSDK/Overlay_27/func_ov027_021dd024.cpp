#include <globaldefs.h>

struct Struct_ov027_021dd024 {
    unsigned char pad0[8];
    unsigned int f8;
};

struct Struct_ov027_021e33e0_16 {
    unsigned char pad0[8];
    Struct_ov027_021dd024* ptr;
};

extern Struct_ov027_021e33e0_16 data_ov027_021e33e0;

// USA: func_ov027_021dd024
extern "C" ARM unsigned int func_ov027_021dd024(void) {
    return data_ov027_021e33e0.ptr->f8;
}
