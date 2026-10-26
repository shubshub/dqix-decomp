#include <globaldefs.h>

extern "C" int func_020e51e4(int value);
extern "C" void* func_020e462c(void* a, int b, int c, void* d);

struct Struct_020e46fc {
    int field0;
    int field4;
    unsigned int field8 : 6;
};

// USA: func_020e46fc
extern "C" ARM void* func_020e46fc(void* arg0, struct Struct_020e46fc* p) {
    void* result = arg0;
    if (p->field0 != 0) {
        int entry = func_020e51e4((short)(p->field8 + 0x64));
        result = func_020e462c(arg0, entry, p->field0, 0);
    }
    return result;
}
