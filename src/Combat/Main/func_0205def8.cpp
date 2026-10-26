#include <globaldefs.h>

struct Struct_0205d81c;
struct Elem_0205d81c;
extern "C" struct Elem_0205d81c* func_0205d81c(struct Struct_0205d81c*, int);
struct Struct_0205d5b8;
extern "C" void func_0205d5b8(struct Struct_0205d5b8*, int);

struct Struct_0205def8 {
    char pad0[0x98];
    int field98;
    int unknown_9c_;
};

// USA: func_0205def8
extern "C" ARM void func_0205def8(struct Struct_0205def8* s, int clear, int key) {
    struct Elem_0205d81c* elem;
    if (s->field98 == 0 || s->unknown_9c_ == 0) return;
    elem = func_0205d81c((struct Struct_0205d81c*)s, key);
    if (elem == 0) return;
    func_0205d5b8((struct Struct_0205d5b8*)elem, clear == 0);
}
