#include <globaldefs.h>

extern "C" void func_020bbe64(int);

struct Struct_020bc9a8 {
    char pad[0x44];
    int mask;
    int count;
};

// USA: func_020bc9a8
extern "C" ARM void func_020bc9a8(struct Struct_020bc9a8* obj) {
    if (obj->mask != 0) {
        func_020bbe64(obj->mask);
        obj->mask = 0;
        obj->count = 0;
    }
}
