#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"

struct Struct_020bc2f0_2;
extern "C" void func_020bc6fc(struct Struct_020bc2f0_2*);

struct Struct_020bc180_2;
extern "C" void func_020c0204(struct Struct_020bc180_2*, int, int);

extern "C" void func_020bc870(SignedAllocatorHeader*, unsigned char);

struct Struct_020bc548 {
    char pad0[0x2c];
    unsigned char field2c;
};

// USA: func_020bc548
extern "C" ARM void func_020bc548(struct Struct_020bc548* obj, int flag) {
    if (obj == 0 || obj->field2c == 0) return;
    if (flag == 0) {
        func_020bc6fc((struct Struct_020bc2f0_2*)obj);
        return;
    }
    func_020c0204((struct Struct_020bc180_2*)((char*)obj + 0x1c), 0, flag);
    func_020bc870((SignedAllocatorHeader*)obj, 0);
    obj->field2c = 2;
}
