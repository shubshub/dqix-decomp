#include <globaldefs.h>

struct Struct_020979c0 {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    unsigned char h;
    unsigned char id;
    unsigned char k;
};

extern "C" void func_020979c0(struct Struct_020979c0* p, unsigned char id);

// USA: func_020979f4
extern "C" ARM void func_020979f4(struct Struct_020979c0* p) {
    func_020979c0(p, 0);
}
