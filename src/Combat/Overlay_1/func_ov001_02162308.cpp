#include <globaldefs.h>

struct Struct_ov001_02165880_49 {
    unsigned char pad0[0x28];
    int counter;
};
extern struct Struct_ov001_02165880_49 data_ov001_02165880;

// USA: func_ov001_02162308
extern "C" ARM void func_ov001_02162308(void) {
    data_ov001_02165880.counter += 2;
}
