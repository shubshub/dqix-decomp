#include <globaldefs.h>

extern "C" int func_020e51e4(int value);
extern "C" void* func_020e462c(void* a, int b, int c, void* d);

struct Struct_020e47bc {
    int field0;
    int field4;
    unsigned int unknown_8_0_ : 6;
    unsigned int unknown_8_6_ : 6;
};

// USA: func_020e47bc
extern "C" ARM void* func_020e47bc(void* arg0, struct Struct_020e47bc* p) {
    void* result = arg0;
    if (p->field4 != 0) {
        int entry = func_020e51e4((short)(p->unknown_8_6_ + 0x12c));
        result = func_020e462c(arg0, entry, p->field4, p);
    }
    return result;
}
