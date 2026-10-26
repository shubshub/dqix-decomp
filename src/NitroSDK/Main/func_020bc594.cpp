#include <globaldefs.h>

extern "C" void func_020d1e50(int, int);

struct Struct_020bc594 {
    unsigned char pad[0x2e];
    unsigned char state;
    unsigned char pad2[0x3c - 0x2e - 1];
    unsigned char kind;
};

// USA: func_020bc594
extern "C" ARM void func_020bc594(Struct_020bc594* obj, int val) {
    if (obj != 0 && val != obj->state) {
        func_020d1e50(obj->kind, val);
        obj->state = (unsigned char)val;
    }
}
