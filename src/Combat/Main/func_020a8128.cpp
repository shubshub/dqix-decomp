#include <globaldefs.h>

struct Struct_020a7f88;
extern "C" void func_020a810c(struct Struct_020a7f88*);

// USA: func_020a8128
extern "C" ARM void func_020a8128(unsigned char* obj) {
    obj[0] = 0;
    obj[1] = 0xff;
    obj[2] = 0;
    *(int*)(obj + 4) = 0;
    *(short*)(obj + 0x18) = 0;
    func_020a810c((struct Struct_020a7f88*)(obj + 8));
    *(short*)(obj + 0x1a) = 0;
    *(short*)(obj + 0x1c) = 0;
    *(int*)(obj + 0x20) = 0;
    *(int*)(obj + 0x24) = 0;
    *(int*)(obj + 0x28) = 0;
}
