#include <globaldefs.h>

struct Struct_020bc180_2 { int f0; int f4; int f8; int fc; };
struct Struct_020bc2f0 { char unk0[8]; int field8; int fieldC; };

extern "C" ARM void func_020c0260(struct Struct_020bc180_2* t);
extern "C" ARM int func_020c0278(struct Struct_020bc2f0* state);
extern "C" ARM int func_020c022c(struct Struct_020bc180_2* t);
extern "C" int func_020d1ff0(int a, int b, int c);

extern "C" void func_020bcf3c(void);

extern char data_0210fd74;
extern char data_0210fdbc;

// USA: func_020bceb4
extern "C" ARM void func_020bceb4(void) {
    char* base = &data_0210fdbc;
    if (*(int*)(&data_0210fd74 + 0x48) == 0) {
        return;
    }
    if (*(int*)(base + 0x4) != 0) {
        return;
    }
    func_020c0260((struct Struct_020bc180_2*)(base + 0x3c));
    if (*(int*)(base + 0x4c) != 0) {
        if (func_020c0278((struct Struct_020bc2f0*)(base + 0x3c)) != 0) {
            func_020bcf3c();
            return;
        }
    }
    int v = func_020c022c((struct Struct_020bc180_2*)(base + 0x3c)) >> 8;
    if (v == *(int*)(base + 0x50)) {
        return;
    }
    func_020d1ff0(*(int*)(base + 0x24), v, 0);
    *(int*)(base + 0x50) = v;
}
