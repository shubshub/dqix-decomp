#include <globaldefs.h>

struct Struct_02074bf4 {
    char pad[0x11];
    unsigned char flag11;
};

extern "C" void func_02074e54(struct Struct_02074bf4*);

// USA: func_02074bf4
extern "C" ARM void func_02074bf4(struct Struct_02074bf4* obj) {
    if (obj->flag11) {
        func_02074e54(obj);
        obj->flag11 = 0;
    }
}
