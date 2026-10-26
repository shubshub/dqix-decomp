#include <globaldefs.h>

struct Struct_ov031_0224e5dc_3 { int pad0; int pad4; int tag; };
extern Struct_ov031_0224e5dc_3 data_ov031_0224e5dc;

// USA: func_ov031_02216698
extern "C" ARM void func_ov031_02216698(void) {
    if (data_ov031_0224e5dc.tag == 4)
        data_ov031_0224e5dc.tag = 5;
}
