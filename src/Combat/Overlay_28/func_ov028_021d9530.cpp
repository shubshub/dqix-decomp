#include <globaldefs.h>

extern "C" void func_ov028_021d8b44(void* obj, void* alloc);
unsigned long long GetCurrentTimestamp(void);

struct Struct_ov028_021d9530 {
    char pad84[0x84];
    unsigned long long unknown_88_;
    unsigned long long unknown_90_;
    int unknown_98_;
    int unknown_9c_;
    unsigned char f9c;
    char unknown_a1_[3];
    unsigned int unknown_a4_;
    unsigned int unknown_a8_;
};

// USA: func_ov028_021d9530
extern "C" ARM void func_ov028_021d9530(Struct_ov028_021d9530* obj, void* alloc) {
    func_ov028_021d8b44(obj, alloc);
    obj->unknown_90_ = 0;
    obj->unknown_88_ = obj->unknown_90_;
    obj->unknown_9c_ = 0;
    obj->unknown_98_ = 0;
    obj->f9c = 0;
    unsigned long long var0 = GetCurrentTimestamp();
    obj->unknown_a4_ = (unsigned int)var0;
    obj->unknown_a8_ = (unsigned int)(var0 >> 32);
}
