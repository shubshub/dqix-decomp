#include <globaldefs.h>

extern "C" void func_ov031_02239368(int);
extern "C" int func_020d68d0(void *p);
extern "C" void func_ov031_022393e4(int v);

struct Struct_ov031_02290d18_15 { unsigned char pad[4]; char *inner; };
extern struct Struct_ov031_02290d18_15 data_ov031_02290d18;

// USA: func_ov031_02239a24
extern "C" ARM int func_ov031_02239a24(void) {
    if (*(int *)(data_ov031_02290d18.inner + 0x40) != 6) {
        return 0;
    }
    func_ov031_02239368(3);
    void *p = data_ov031_02290d18.inner + 0x1e00;
    int r = func_020d68d0(p);
    if (r == 2) {
        return 1;
    }
    func_ov031_022393e4(r);
    return 0;
}
