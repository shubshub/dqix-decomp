#include <globaldefs.h>

struct Struct_0209c2e0_2;
extern "C" void func_020bc180(Struct_0209c2e0_2*, int, int);
extern "C" void func_020bbf34(int, int);

extern float data_020e8ec4[];

struct Struct_0209c2e0 {
    char pad0[0xc8];
    unsigned char unknown_c8_0_ : 1;
    unsigned char unknown_c8_1_ : 1;
    unsigned char unknown_c8_2_ : 6;
    char unknown_c9_[3];
    unsigned char fcc;
    unsigned char unknown_cd_;
};

// USA: func_0209c2e0
extern "C" ARM void func_0209c2e0(Struct_0209c2e0* obj, int b, int arg2) {
    obj->unknown_cd_ = (unsigned char)b;
    int var0 = obj->fcc;
    float scale = ((float)var0 - 1.0f) / 4.0f;
    int v = (int)((float)obj->unknown_cd_ * scale);
    if (obj->unknown_c8_1_) {
        v = v / 2;
    }
    func_020bc180((Struct_0209c2e0_2*)((char*)obj + 0xbc), v, arg2);
    func_020bc180((Struct_0209c2e0_2*)((char*)obj + 0xc0), v, arg2);
    int result = (int)((float)obj->unknown_cd_ * data_020e8ec4[obj->fcc - 1]);
    func_020bbf34(5, result);
    func_020bbf34(7, result);
    func_020bbf34(6, result);
}
