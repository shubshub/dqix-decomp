#include <globaldefs.h>

class Struct_ov028_021d8a74;
extern "C" void func_ov028_021d8a74(Struct_ov028_021d8a74* obj, float angle);
extern "C" void func_ov028_021d8ad4(void* obj, char* buf);

struct Struct_ov028_021d942c {
    float field0;
    char pad4[0x40 - 4];
    void* field40;
    char unknown_44_[0x60 - 0x44];
    int f60;
    int f64;
    char pad68[0x80 - 0x68];
    unsigned char unknown_80_;
    unsigned char unknown_81_;
};

// USA: func_ov028_021d942c
extern "C" ARM void func_ov028_021d942c(Struct_ov028_021d942c* obj, int val) {
    float f0 = obj->field0;
    float angle = (float)val * f0 * 0.5f;
    func_ov028_021d8a74((Struct_ov028_021d8a74*)((char*)obj + 0x60), angle);
    func_ov028_021d8ad4((char*)obj + 0x60, (char*)obj->field40);
    if ((unsigned int)((obj->f64 >> 12) + 16) <= (unsigned int)(obj->f60 >> 12)) {
        obj->unknown_80_ = 3;
        obj->unknown_81_ = 0;
    }
}
