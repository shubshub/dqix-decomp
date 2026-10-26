#include <globaldefs.h>

struct Struct_020b2a58;
extern "C" unsigned short func_020b2a58(struct Struct_020b2a58*);
extern "C" void func_020b27c8(void*, void*);

struct Struct_020b0e48 {
    int field0;                                                // 0x0
    unsigned short (*handler)(struct Struct_020b2a58*);  // 0x4
};

// USA: func_020b0e48
extern "C" ARM void func_020b0e48(struct Struct_020b0e48* obj, void* arg) {
    func_020b27c8(arg, obj);
    obj->handler = func_020b2a58;
}
