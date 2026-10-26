#include <globaldefs.h>

struct Struct_020dbdc0;
extern "C" void func_020dbf70(struct Struct_020dbdc0* o);
extern "C" int func_02057924(void);
extern "C" void func_02057f00(int a, int b);

struct Struct_020dbebc {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
};

// USA: func_020dbedc
extern "C" ARM void func_020dbedc(struct Struct_020dbebc* a) {
    int s = a->f10;
    if (s == 1) {
        func_020dbf70((struct Struct_020dbdc0*)a);
        return;
    }
    if (s != 2) return;
    func_02057f00(func_02057924(), a->f8);
    a->f10 = 0;
}
