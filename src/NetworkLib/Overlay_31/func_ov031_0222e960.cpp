#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int arg);
extern "C" int func_ov031_02222e54(void);
extern "C" void* func_ov031_0223c7c4(int idx);
extern "C" int func_ov031_02223440(void);
extern "C" void func_ov031_0223cbbc(int a, int b);
extern "C" void func_ov031_02227520(int* a, int* b);
extern "C" void func_ov031_022274d0(int a, int b);
extern "C" void func_ov031_022274c0(int v);
extern "C" void func_ov031_0222750c(int a, int b);
extern "C" void func_ov031_02230ef0(unsigned char val);
extern "C" int func_ov031_02232508(void);
extern "C" int func_ov031_0222ea24(void);

// USA: func_ov031_0222e960
extern "C" ARM void func_ov031_0222e960(void) {
    if (func_ov031_0223c054(1) != 0) return;
    if (func_ov031_0223c054(0) != 0) return;
    if (func_ov031_02222e54() == 0) return;

    func_ov031_0223c7c4(0);
    func_ov031_02223440();
    func_ov031_0223cbbc(1, 1);
    func_ov031_0223cbbc(0, 0x15);

    int buf;
    func_ov031_02227520(0, &buf);
    if (buf != 0) {
        func_ov031_022274d0(2, 1);
        func_ov031_022274c0((int)func_ov031_02232508);
    } else {
        func_ov031_022274d0(2, 0);
        func_ov031_0222750c(0, 0);
        func_ov031_02230ef0(0);
        func_ov031_022274c0((int)func_ov031_0222ea24);
    }
}
