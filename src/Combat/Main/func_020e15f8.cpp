#include <globaldefs.h>

struct Struct_020e12a8;
extern "C" void func_020e12a8(struct Struct_020e12a8* dst, short a, short b, short c, short d);

struct Struct_020e2bd8;
extern "C" void func_020e2bd8(struct Struct_020e2bd8* obj, int arg1, int arg2);

// USA: func_020e15f8
extern "C" ARM void func_020e15f8(char* obj, int arg1, int arg2) {
    *(int*)(obj + 0) = 0;
    *(int*)(obj + 4) = 0;
    *(unsigned char*)(obj + 8) = 0;
    int i;
    for (i = 0; i < 3; i++) {
        func_020e12a8((struct Struct_020e12a8*)(obj + 0xa + i * 8), 0, 0, 0, 0);
    }
    *(short*)(obj + 0x22) = 0x7fff;
    *(short*)(obj + 0x24) = 0xf0a;
    func_020e2bd8((struct Struct_020e2bd8*)(obj + 0x28), arg1, arg2);
}
