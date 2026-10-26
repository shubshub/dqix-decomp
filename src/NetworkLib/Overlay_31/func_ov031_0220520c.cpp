#include <globaldefs.h>

struct Struct_ov031_0224e204 {
    int a; int b; int c; int d;
    int e; int f; int g; int h;
};

extern "C" ARM void func_020c7de4(Struct_ov031_0224e204* s, int e, int f);
extern "C" ARM int func_020c7ea0(void* data, int* out, int count);
extern "C" ARM int func_ov031_022051a8(void* a, void* b);

struct Struct_ov031_0220520c {
    unsigned char pad0[8];
    void* field8;
    unsigned char pad1[1];
    signed char unknown_d_;
};

// USA: func_ov031_0220520c
extern "C" ARM int func_ov031_0220520c(void* arg0, Struct_ov031_0220520c* obj2) {
    int result;
    if (obj2->unknown_d_ == 1) {
        int var1;
        Struct_ov031_0224e204 var2;
        func_020c7de4(&var2, (int)&var1, 1);
        obj2->field8 = &var2;
        func_ov031_022051a8(arg0, obj2);
        func_020c7ea0(&var2, &result, 1);
    } else {
        obj2->field8 = NULL;
        result = func_ov031_022051a8(arg0, obj2);
    }
    return result;
}
