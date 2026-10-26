#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int flag);
extern "C" ARM int func_ov031_02237388(void);
extern "C" void* func_ov031_0223c7c4(int);
extern "C" void func_ov031_02223440(void);
extern "C" void func_ov031_0223cbbc(int, int);
extern "C" void func_ov031_022274d0(int, int);
extern "C" void func_ov031_02227520(int*, int*);
extern "C" void func_ov031_0222750c(int, int);
extern "C" void func_ov031_022274c0(int v);
extern "C" void func_ov031_0222ea24(void);
extern "C" void func_ov031_02228024(void);

// USA: func_ov031_02233fac
extern "C" ARM void func_ov031_02233fac(void) {
    if (func_ov031_0223c054(1) != 0) return;
    if (func_ov031_0223c054(0) != 0) return;
    if (func_ov031_02237388() == 0) return;
    func_ov031_0223c7c4(0);
    func_ov031_02223440();
    func_ov031_0223cbbc(1, 1);
    func_ov031_0223cbbc(0, 0x15);
    func_ov031_022274d0(2, 1);
    int local;
    func_ov031_02227520(0, &local);
    if (local == 0) {
        func_ov031_0222750c(0, 0);
        func_ov031_022274c0((int)func_ov031_0222ea24);
        return;
    }
    func_ov031_022274c0((int)func_ov031_02228024);
}
