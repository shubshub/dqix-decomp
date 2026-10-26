#include <globaldefs.h>

extern "C" int func_020e51e4(int value);
extern "C" void* func_020e462c(void* a, int b, int c, void* d);

struct Struct_020e4810 {
    int field0;
    int field4;
    unsigned int unknown_8_0_ : 18;
    unsigned int unknown_a_2_ : 6;
};

// USA: func_020e4810
extern "C" ARM void* func_020e4810(void* arg0, struct Struct_020e4810* p) {
    void* result = arg0;
    if (p->field4 != 0) {
        int entry = func_020e51e4((short)(p->unknown_a_2_ + 0xc8));
        result = func_020e462c(arg0, entry, p->field4, p);
    }
    return result;
}
