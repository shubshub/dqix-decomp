#include <globaldefs.h>

struct Struct_ov027_021dd038 {
    char pad0[0xc];
    unsigned short fc;
};

struct Struct_ov027_021e33e0_17 {
    char pad0[0x8];
    Struct_ov027_021dd038* p8;
};

extern Struct_ov027_021e33e0_17 data_ov027_021e33e0;

// USA: func_ov027_021dd038
extern "C" ARM unsigned short func_ov027_021dd038(void) {
    return data_ov027_021e33e0.p8->fc;
}
