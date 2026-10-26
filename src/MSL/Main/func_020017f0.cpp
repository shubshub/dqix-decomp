#include <globaldefs.h>

extern "C" void func_020017bc(int a, int* b);
extern "C" void func_020017c0(void* obj);

struct Struct_020017f0 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 1;
};

struct Struct_020017f0_2 {
    int f0;
    int flags;
    char pad1[0x10];
    int f18;
    int f1c;
    char pad2[0x4];
    int f24;
    int f28;
    char pad3[0x14];
    void* f40;
    char pad4[0x4];
    int unknown_48_;
};

typedef int (*Type_020017f0)(int, int, int*, int);

// USA: func_020017f0
extern "C" ARM int func_020017f0(Struct_020017f0_2* obj, int* arg1) {
    int delta = obj->f24 - obj->f1c;
    if (delta != 0) {
        obj->f28 = delta;
        if (!((Struct_020017f0*)&obj->flags)->unknown_1_4_) {
            func_020017bc(obj->f1c, &obj->f28);
        }
        Type_020017f0 fn = (Type_020017f0)obj->f40;
        int result = fn(obj->f0, obj->f1c, &obj->f28, obj->unknown_48_);
        if (arg1 != 0) *arg1 = obj->f28;
        if (result != 0) return result;
        obj->f18 += obj->f28;
    }
    func_020017c0(obj);
    return 0;
}
