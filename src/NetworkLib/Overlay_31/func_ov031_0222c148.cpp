#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern "C" ARM int func_ov031_02222ddc(void);
extern "C" ARM void func_ov031_02222e98(void);
extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" ARM void func_ov031_022274c0(int);
extern "C" void func_ov031_0222c1b8(void);

struct Struct_ov031_02290c8c_8 { unsigned char pad[4]; char* field4; };
extern Struct_ov031_02290c8c_8 data_ov031_02290c8c;

// USA: func_ov031_0222c148
extern "C" ARM void func_ov031_0222c148(void) {
    if (func_ov031_0223c054(1) != 0) return;
    if (*(unsigned char*)(data_ov031_02290c8c.field4 + 0x54) != 0) {
        func_ov031_02222ddc();
    } else {
        func_ov031_02222e98();
    }
    func_ov031_0223c078(3, 1, 1, 8);
    func_ov031_0223c078(3, 0, 0x1d, 8);
    func_ov031_022274c0((int)func_ov031_0222c1b8);
}
