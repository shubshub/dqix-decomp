#include <globaldefs.h>

struct Struct_ov031_022247ec { unsigned char pad[0x11d]; unsigned char unknown_11d_; };
extern Struct_ov031_022247ec* data_ov031_02250bfc;
extern "C" void func_ov031_02224f20(int);
extern "C" void func_ov031_02236878(int);

// USA: func_ov031_022247ec
extern "C" ARM void func_ov031_022247ec(void) {
    func_ov031_02224f20(data_ov031_02250bfc->unknown_11d_ == 1 ? 0 : 1);
    func_ov031_02236878(1);
}
