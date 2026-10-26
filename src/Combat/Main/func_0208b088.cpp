#include <globaldefs.h>

struct Struct_0208b088_2;
extern "C" int func_0208b4d4(struct Struct_0208b088_2* obj);

extern "C" void func_0208b0f8(void* obj);
extern "C" int func_0208ab34(void* ptr, int val);

struct Obj0208b088 {
    char pad0[0x20];
    int unknown_20_;
    char pad1[0x9c - 0x24];
    unsigned char unknown_9c_;
};

// USA: func_0208b088
extern "C" ARM int func_0208b088(struct Obj0208b088* obj) {
    int captured;
    func_0208b0f8(obj);
    obj->unknown_20_ = (obj->unknown_9c_ == 0) ? 1 : 0;
    captured = func_0208b4d4((struct Struct_0208b088_2*)obj);
    func_0208ab34((char*)obj + 0x4, captured);
    func_0208ab34((char*)obj + 0x24, captured);
    func_0208ab34((char*)obj + 0x40, captured);
    func_0208ab34((char*)obj + 0x5c, captured);
    func_0208ab34((char*)obj + 0x78, captured);
    return 1;
}
