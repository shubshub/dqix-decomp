#include <globaldefs.h>

extern "C" signed char func_ov031_02237e9c(void);
extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_02237e58(void);
extern "C" void func_ov031_022274c0(int);
extern "C" void func_ov031_0222e0f8(void);

struct Struct_ov031_0222e09c { unsigned char pad[0x15]; unsigned char unknown_15_; };
extern Struct_ov031_0222e09c* data_ov031_02290c98;

// USA: func_ov031_0222e09c
extern "C" ARM void func_ov031_0222e09c(void) {
    data_ov031_02290c98->unknown_15_ = (unsigned char)func_ov031_02237e9c();
    switch (data_ov031_02290c98->unknown_15_) {
    case 0:
        func_ov031_02236878(7);
        break;
    case 1:
        func_ov031_02236878(0xe);
        break;
    default:
        return;
    }
    func_ov031_02237e58();
    func_ov031_022274c0((int)func_ov031_0222e0f8);
}
