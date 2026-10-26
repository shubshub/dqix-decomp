#include <globaldefs.h>


extern "C" ARM void HaltSystem(void);
extern "C" ARM void func_ov031_02239368(int val);
extern "C" int func_020d503c(int arg);
extern "C" void func_ov031_02239b98(short* p);

struct Struct_ov031_0223a47c { unsigned char pad[0x40]; int field40; };
struct Struct_ov031_02290d18_28 { unsigned char pad[4]; struct Struct_ov031_0223a47c* inner; };
extern struct Struct_ov031_02290d18_28 data_ov031_02290d18;

// USA: func_ov031_0223a47c
extern "C" ARM int func_ov031_0223a47c(void) {
    if (data_ov031_02290d18.inner->field40 != 1) {
        HaltSystem();
    }
    func_ov031_02239368(3);
    int r = func_020d503c((int)func_ov031_02239b98);
    if (r == 2) {
        return 1;
    }
    func_ov031_02239368(9);
    return 0;
}
