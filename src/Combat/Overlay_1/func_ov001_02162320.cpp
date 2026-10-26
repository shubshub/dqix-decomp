#include <globaldefs.h>

struct Struct_ov001_02165880_50 {
    unsigned char pad0[0x28];
    int counter;
};
extern struct Struct_ov001_02165880_50 data_ov001_02165880;

// USA: func_ov001_02162320
extern "C" ARM void func_ov001_02162320(void) {
    data_ov001_02165880.counter += 3;
}
