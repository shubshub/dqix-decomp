#include <globaldefs.h>

struct Struct_ov028_021d9494 {
    char pad0[0x84];
    long long f84;
    long long unknown_90_;
    int unknown_98_;
    int unknown_9c_;
    unsigned char f9c;
    char unknown_a1_[3];
    long long unknown_a8_;
    long long unknown_b0_;
};

extern "C" void func_ov028_021d8b90(void* obj);

// USA: func_ov028_021d9494
extern "C" ARM void func_ov028_021d9494(void* p) {
    struct Struct_ov028_021d9494* obj = (struct Struct_ov028_021d9494*)p;
    func_ov028_021d8b90(p);
    obj->unknown_90_ = 0;
    obj->f84 = obj->unknown_90_;
    obj->unknown_98_ = obj->unknown_9c_ = 0;
    obj->unknown_b0_ = 0;
    obj->unknown_a8_ = obj->unknown_b0_;
    obj->f9c = 0;
}
