#include <globaldefs.h>

extern "C" void func_ov001_0215a134(void* p);
extern "C" void func_ov001_02158ae4(void);

struct Struct_ov001_02165880_5 { char pad0[0x1c]; char* field1c; char pad1[4]; int field24; };
extern Struct_ov001_02165880_5 data_ov001_02165880;

struct Struct_ov001_021658b8_3 { char pad0[0xe4]; int unknown_e4_; };
extern Struct_ov001_021658b8_3 data_ov001_021658b8;

// USA: func_ov001_0215a9b4
extern "C" ARM int func_ov001_0215a9b4(void) {
    int i;
    for (i = 0; i < 0x18; i++) {
        func_ov001_0215a134(data_ov001_02165880.field1c + i * 0x588);
    }
    if (data_ov001_021658b8.unknown_e4_ != 0 && data_ov001_02165880.field24 != 0) {
        func_ov001_02158ae4();
    }
    return 1;
}
