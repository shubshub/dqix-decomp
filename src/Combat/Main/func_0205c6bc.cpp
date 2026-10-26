#include <globaldefs.h>

extern "C" int func_0205bea0(void* p);

struct Struct_0205c5b0_2 {
    char pad0[0x94];
    unsigned char unknown_94_;
};

// USA: func_0205c6bc
extern "C" ARM int func_0205c6bc(Struct_0205c5b0_2* obj) {
    int result = 0;
    if (obj->unknown_94_) {
        result = func_0205bea0((char*)obj + 4);
    }
    return result;
}
