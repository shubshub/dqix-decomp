#include <globaldefs.h>

struct Struct_ov001_02165880_48 {
    unsigned char pad0[0x28];
    int counter;
};
extern struct Struct_ov001_02165880_48 data_ov001_02165880;

// USA: func_ov001_021622f0
extern "C" ARM void func_ov001_021622f0(void) {
    data_ov001_02165880.counter += 1;
}
