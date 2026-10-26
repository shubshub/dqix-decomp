#include <globaldefs.h>

extern "C" int func_020095b0(void* obj, int value);
extern "C" void func_0200961c(unsigned char* base, int startOffset);

struct Struct_0200966c { char pad[0x4]; unsigned char unknown_4_; };

// USA: func_0200966c
extern "C" ARM void func_0200966c(struct Struct_0200966c* obj, int value) {
    if (value <= 0) {
        return;
    }
    if (value >= obj->unknown_4_) {
        return;
    }
    int ret = func_020095b0(obj, value);
    obj->unknown_4_ = value;
    if (ret < 0) {
        return;
    }
    func_0200961c((unsigned char*)obj, value);
}
