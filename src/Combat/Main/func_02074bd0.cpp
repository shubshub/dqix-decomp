#include <globaldefs.h>

struct Struct_02074bd0 {
    char pad[0x10];
    unsigned char unknown_10_;
};

extern "C" void func_02074c18(struct Struct_02074bd0*);

// USA: func_02074bd0
extern "C" ARM void func_02074bd0(struct Struct_02074bd0* obj) {
    if (obj->unknown_10_) {
        func_02074c18(obj);
        obj->unknown_10_ = 0;
    }
}
