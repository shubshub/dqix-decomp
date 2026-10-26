#include <globaldefs.h>

struct Struct_ov031_0224f670_8 {
    int pad[11];
    int field2c;
};

extern Struct_ov031_0224f670_8 data_ov031_0224f670;

// USA: func_ov031_0221f994
extern "C" THUMB int func_ov031_0221f994(void) {
    return data_ov031_0224f670.field2c;
}
