#include <globaldefs.h>
extern "C" void func_0206da74(int*);
extern "C" void func_02064e20(int*);
#include "std_library_functions.h"

struct Struct_020401e4;
extern "C" void func_020401e4(struct Struct_020401e4* obj);

struct Struct_0203cfb4 {
    unsigned char pad[0x8c];
    int unknown_8c_;
    unsigned char pad2[0x8];
    int field98;
    unsigned char unknown_9c_;
};

// USA: func_0203cfb4
extern "C" ARM void func_0203cfb4(struct Struct_0203cfb4* obj) {
    func_020401e4((struct Struct_020401e4*)obj);
    func_02064e20((int*)((char*)obj + 0x90));
    func_0206da74((int*)((char*)obj + 0x94));
    memset((char*)obj + 0xc, 0, 0x80);
    obj->field98 = 0;
    obj->unknown_8c_ = 0;
    obj->unknown_9c_ = 0;
}
