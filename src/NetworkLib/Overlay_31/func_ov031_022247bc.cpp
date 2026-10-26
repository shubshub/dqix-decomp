#include <globaldefs.h>

struct Struct_ov031_022247bc { unsigned char pad[0x11d]; unsigned char unknown_11d_; };
extern Struct_ov031_022247bc* data_ov031_02250bfc;
extern "C" void func_ov031_02224f20(int);
extern "C" void func_ov031_02236878(int);

// USA: func_ov031_022247bc
extern "C" ARM void func_ov031_022247bc(void) {
    func_ov031_02224f20(data_ov031_02250bfc->unknown_11d_ == 2 ? 0 : 2);
    func_ov031_02236878(1);
}
