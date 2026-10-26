#include <globaldefs.h>

extern "C" void GameObject_Initialize(void* obj);

struct Struct_02048120 {
    unsigned short flags;   // 0x0
    char pad[0x12e];        // 0x2..0x12f
    void* unknown_130_;         // 0x130
};

// USA: func_02048120
extern "C" ARM void func_02048120(struct Struct_02048120* obj) {
    GameObject_Initialize(obj);
    obj->flags |= 0x40;
    obj->unknown_130_ = 0;
}
