#include <globaldefs.h>

struct Struct_0203d028_16;
struct Struct_0203e2c4_2;
extern "C" void func_0203db34(unsigned char* obj, int a, int b, int c);
extern "C" void func_0204085c(struct Struct_0203d028_16* obj, int a, int b, int c);
extern "C" void func_02040b2c(struct Struct_0203e2c4_2* self, int value);

struct Struct_ov001_02164320 {
    int selector;
    char pad[8];
    unsigned char* target;
};

// USA: func_ov001_02164320
extern "C" ARM int func_ov001_02164320(struct Struct_ov001_02164320* arr, int index, int arg2, int arg3, int arg4) {
    struct Struct_ov001_02164320* e;
    unsigned char* t;

    if (index < 0 || index >= 0x20) {
        return 0;
    }
    e = &arr[index];
    switch (e->selector) {
    case 4:
    case 5:
        t = e->target;
        if (t == NULL) return 0;
        func_0203db34(t, arg2, arg3, arg4);
        return 1;
    case 0:
        t = e->target;
        if (t == NULL) return 0;
        func_0203db34(t, arg2, arg3, arg4);
        return 1;
    case 1:
        t = e->target;
        if (t == NULL) return 0;
        func_0203db34(t, arg2, arg3, arg4);
        return 1;
    case 2:
    case 6:
        t = e->target;
        if (t == NULL) return 0;
        func_0204085c((struct Struct_0203d028_16*)t, arg2, arg3, arg4);
        func_02040b2c((struct Struct_0203e2c4_2*)e->target, arg3);
        return 1;
    }
    return 0;
}
