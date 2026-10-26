#include <globaldefs.h>

struct Struct_020ddfb4_2;
extern "C" void func_020ddffc(struct Struct_020ddfb4_2* obj);
struct Struct_020ddfb4;
extern "C" void func_020de0c8(struct Struct_020ddfb4* obj);
extern "C" void func_020de038(void* obj);

struct Struct_020ddea0_2 {
    unsigned char pad[4];
    unsigned char state;
};

// USA: func_020ddfb4
extern "C" ARM void func_020ddfb4(struct Struct_020ddea0_2* obj) {
    unsigned char state = obj->state;
    if (state == 2) {
        func_020ddffc((struct Struct_020ddfb4_2*)obj);
        return;
    }
    if (state == 1) return;
    if (state == 3) {
        func_020de038(obj);
        return;
    }
    if (state != 4) return;
    func_020de0c8((struct Struct_020ddfb4*)obj);
}
