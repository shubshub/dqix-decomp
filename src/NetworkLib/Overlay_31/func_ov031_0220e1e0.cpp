#include <globaldefs.h>

extern "C" void func_ov031_0220da1c(int);
extern "C" void func_ov031_0220db6c(void);
extern "C" void func_ov031_0220d984(int, int, int, int);

struct Struct_ov031_0220e1e0 { short f0; unsigned short type; };

// USA: func_ov031_0220e1e0
extern "C" ARM void func_ov031_0220e1e0(struct Struct_ov031_0220e1e0 *s) {
    switch (s->type) {
        case 0:
            func_ov031_0220da1c(3);
            func_ov031_0220d984(0, 0, 0, 0x783);
            break;
        case 1:
            func_ov031_0220db6c();
            break;
        case 2:
        case 3:
        case 4:
        default:
            func_ov031_0220da1c(0xb);
            func_ov031_0220d984(7, 0, 0, 0x793);
            break;
    }
}
