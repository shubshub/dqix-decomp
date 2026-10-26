#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern "C" void func_ov031_02223c08(void);
extern "C" void func_ov031_02236878(int);
extern void* data_ov031_02290c94;
extern "C" void func_ov031_02223fb4(int v);
extern "C" void func_ov031_02223fc8(int v);
extern "C" void func_ov031_022274c0(int v);
extern "C" void func_ov031_0222cea0(void);

// USA: func_ov031_0222ce24
extern "C" ARM void func_ov031_0222ce24(void) {
    if (func_ov031_0223c054(1) != 0) return;
    if (func_ov031_0223c054(0) != 0) return;

    func_ov031_02223c08();
    func_ov031_02236878(0x14);

    unsigned char v = *((unsigned char*)data_ov031_02290c94 + 0x29);
    if (v == 0) {
        func_ov031_02223fb4(0);
    }
    v = *((unsigned char*)data_ov031_02290c94 + 0x29);
    if (v == 0x20) {
        func_ov031_02223fc8(0);
    }
    func_ov031_022274c0((int)func_ov031_0222cea0);
}
