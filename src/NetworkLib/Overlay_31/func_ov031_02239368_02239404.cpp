#include <globaldefs.h>

struct Struct_0202db64;

extern "C" ARM void func_ov031_02239368(int val);
extern "C" void func_ov031_02239448(unsigned short* a);
extern "C" void func_ov031_022393e4(int v);
extern "C" int func_020d507c(int a, struct Struct_0202db64* b);

struct Struct_ov031_02290d18_5 { void* unk0; struct Struct_0202db64* inner; };
extern struct Struct_ov031_02290d18_5 data_ov031_02290d18;

// USA: func_ov031_02239404
extern "C" ARM int func_ov031_02239404(void) {
    func_ov031_02239368(3);
    int r = func_020d507c((int)func_ov031_02239448, data_ov031_02290d18.inner);
    if (r == 2) {
        return 1;
    }
    func_ov031_022393e4(r);
    func_ov031_02239368(9);
    return 0;
}
