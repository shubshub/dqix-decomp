#include <globaldefs.h>

struct Struct_020e1cb8;

extern "C" void func_020e1cb8(struct Struct_020e1cb8* obj);
extern "C" void func_020e25cc(signed char* p);

struct Struct_020e25e8 {
    char pad[0x10];
    struct Struct_020e1cb8* owner;
};

// USA: func_020e25e8
extern "C" ARM void func_020e25e8(struct Struct_020e25e8* obj) {
    func_020e1cb8(obj->owner);
    func_020e25cc((signed char*)obj);
}
