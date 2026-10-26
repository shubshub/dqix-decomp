#include <globaldefs.h>

struct Struct_ov001_02155d54;

struct Struct_ov028_021d9574 {
    char pad0[0x80];
    unsigned char unknown_80_;
    char unknown_81_[3];
    long long f84;
    long long unknown_90_;
    int unknown_98_;
    int unknown_9c_;
    unsigned char f9c;
    char unknown_a1_[3];
    long long unknown_a8_;
    long long unknown_b0_;
};

long long GetCurrentTimestamp(void);
extern "C" void func_ov028_021d8d40(
    struct Struct_ov001_02155d54* obj, int delta);

// USA: func_ov028_021d9574
extern "C" ARM void func_ov028_021d9574(struct Struct_ov028_021d9574* obj) {
    if (obj->unknown_80_ == 0) {
        return;
    }
    obj->unknown_98_ = obj->unknown_9c_;
    obj->unknown_90_ = GetCurrentTimestamp();
    obj->unknown_9c_ = (int)((unsigned long long)(obj->unknown_90_ - obj->f84) * 0x3c / 0x7fd88);
    if (obj->unknown_9c_ == obj->unknown_98_) {
        return;
    }
    func_ov028_021d8d40(
        (struct Struct_ov001_02155d54*)obj, obj->unknown_9c_ - obj->unknown_98_);
    obj->f9c = (obj->f9c == 0);
    obj->unknown_b0_ = obj->unknown_90_ - obj->unknown_a8_;
}
