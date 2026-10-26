#include <globaldefs.h>

struct Struct_ov001_02165880_18 { char pad[0x24]; void* field24; };
extern Struct_ov001_02165880_18 data_ov001_02165880;
struct Struct_ov001_021658b8_6 { char pad[0xe4]; int unknown_e4_; };
extern Struct_ov001_021658b8_6 data_ov001_021658b8;
extern "C" void func_ov001_021588e4(void* p);

// USA: func_ov001_0215d134
extern "C" ARM int func_ov001_0215d134(void) {
    func_ov001_021588e4(data_ov001_02165880.field24);
    if (data_ov001_021658b8.unknown_e4_ == 0) data_ov001_021658b8.unknown_e4_ = 1;
    return 1;
}
