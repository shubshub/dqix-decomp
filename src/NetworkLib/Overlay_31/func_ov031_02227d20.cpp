#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int flag);
extern "C" void func_ov031_0223e330(int idx, unsigned char val);
extern "C" void func_ov031_0223bd88(int idx);
extern "C" int func_ov031_02223984(void);
extern "C" int func_ov031_02223708(void);
extern "C" void func_ov031_02227688(void* a);
extern "C" void func_ov031_0222761c(void);
extern "C" int func_ov031_02235c5c(void);
extern "C" void func_ov031_0222758c(void);
extern void* data_ov031_02290c4c;

// USA: func_ov031_02227d20
extern "C" ARM void func_ov031_02227d20(void) {
    if (func_ov031_0223c054(1)) return;
    if (func_ov031_0223c054(0)) return;
    func_ov031_0223e330(0, 0);
    func_ov031_0223e330(1, 0);
    func_ov031_0223bd88(1);
    func_ov031_0223bd88(0);
    func_ov031_02223984();
    func_ov031_02223708();
    func_ov031_02227688(data_ov031_02290c4c);
    func_ov031_0222761c();
    func_ov031_02235c5c();
    func_ov031_0222758c();
}
