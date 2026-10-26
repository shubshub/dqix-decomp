#include <globaldefs.h>

extern "C" void VCountIrq_PushDisable();

struct Struct_020db894;
extern "C" void func_020db964(Struct_020db894* obj);

struct Struct_020db3f4_3;
extern "C" void func_020db844(Struct_020db3f4_3* a, int b, int c, int d);

extern "C" void func_020db304(int obj, int b);

struct FlagWord020466f4;
extern "C" FlagWord020466f4* GlobalFlags_GetInstance();
extern "C" void FlagWord_ClearBits(FlagWord020466f4* word, unsigned int mask);

struct Struct_020dafd4;
extern "C" void func_020db0c4(Struct_020dafd4* p);

extern "C" void func_020db814(void* obj);

extern "C" void VCountIrq_PopDisable();

typedef void (*Type_0200f3a4_2)(int);
typedef int (*Type_01ff8b48_5)(void);
extern Type_0200f3a4_2 data_020f28dc[];
extern Type_01ff8b48_5 data_020f28fc[];
extern Type_0200f3a4_2 data_020f28f4[];

struct Struct_020db894_2 {
    char unknown_0_[0x3c];
    unsigned char unknown_3c_;
    char unknown_3d_[0x51 - 0x3d];
    unsigned char unknown_51_;
    unsigned char unknown_52_;
    unsigned char unknown_53_;
    char unknown_54_[0x5c - 0x54];
    int unknown_5c_;
    int field60;
    unsigned char unknown_64_;
    char unknown_65_[0x6a - 0x65];
    short unknown_6a_;
};

// USA: func_020db894
extern "C" ARM void func_020db894(Struct_020db894_2* obj) {
    if (!obj->unknown_51_) {
        return;
    }
    VCountIrq_PushDisable();
    func_020db964((Struct_020db894*)obj);
    if (obj->unknown_53_) {
        func_020db844((Struct_020db3f4_3*)obj, obj->unknown_3c_, obj->unknown_6a_, 0);
        data_020f28dc[6](obj->unknown_5c_);
        data_020f28dc[7](obj->field60);
    } else if (!obj->unknown_64_) {
        int result = data_020f28fc[obj->unknown_3c_]();
        result &= ~0x10;
        data_020f28f4[obj->unknown_3c_](result);
    }
    func_020db304((int)obj, obj->unknown_3c_);
    FlagWord_ClearBits(GlobalFlags_GetInstance(), 0x8000);
    func_020db0c4((Struct_020dafd4*)obj);
    func_020db814(obj);
    VCountIrq_PopDisable();
}
