#include <globaldefs.h>

extern "C" signed char func_ov031_02237e9c(void);
extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_02237e58(void);
extern "C" void func_ov031_022274c0(int);
extern "C" void func_ov031_0222d474(void);

struct Struct_ov031_0222d418 { unsigned char pad[0x2a]; unsigned char field2a; };
extern Struct_ov031_0222d418* data_ov031_02290c94;

// USA: func_ov031_0222d418
extern "C" ARM void func_ov031_0222d418(void) {
    data_ov031_02290c94->field2a = (unsigned char)func_ov031_02237e9c();
    switch (data_ov031_02290c94->field2a) {
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
    func_ov031_022274c0((int)func_ov031_0222d474);
}
