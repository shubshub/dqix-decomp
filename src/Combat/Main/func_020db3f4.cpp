#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_020db3f4_3;
extern "C" void func_020db844(struct Struct_020db3f4_3* arg0, int arg1, int arg2, int arg3);

void* GlobalFlags_GetInstance(void);

void FlagWord_SetBits(unsigned int* word, unsigned int mask);

extern "C" int func_020937f0(int arg0);

struct Struct_020db3a8;
extern "C" int func_020db3a8(struct Struct_020db3a8* arg0);

void CleanInvalidateCacheRange(const void* addr, unsigned int size);
void CleanCacheRange(const void* addr, unsigned int size);

extern "C" void func_020db304(int arg0, int arg1);

struct Struct_020db3f4_2;
extern "C" void func_020dde64(struct Struct_020db3f4_2* arg0);

struct Struct_020de0ec;
extern "C" void func_020de0ec(struct Struct_020de0ec* arg0);

typedef void* (*Type_01ff8b48_4)(void);
extern Type_01ff8b48_4 data_020f28e4[];

typedef void (*Type_ov031_02220af0_2)(void*, int, unsigned int);
extern Type_ov031_02220af0_2 data_020f28ec[];
extern Type_ov031_02220af0_2 data_020f28dc[];

typedef int (*Type_01ff8b48_5)(void);
extern Type_01ff8b48_5 data_020f28fc[];

struct Struct_020db3f4 {
    unsigned char unknown_0_[0x3c];
    unsigned char unknown_3c_;
    unsigned char unknown_3d_[0x40 - 0x3d];
    void* unknown_40_;
    unsigned int unknown_44_;
    void* unknown_48_;
    unsigned int unknown_4c_;
    unsigned char unknown_50_[0x51 - 0x50];
    unsigned char unknown_51_;
    unsigned char unknown_52_[0x53 - 0x52];
    unsigned char unknown_53_;
    unsigned char unknown_54_[0x58 - 0x54];
    unsigned int unknown_58_;
    unsigned char unknown_5c_[0x64 - 0x5c];
    unsigned char unknown_64_;
    unsigned char unknown_65_[0x6a - 0x65];
    short unknown_6a_;
    unsigned char unknown_6c_[0x6e - 0x6c];
    unsigned short unknown_6e_;
    unsigned char unknown_70_[3][0x28];
};

// USA: func_020db3f4
extern "C" ARM void func_020db3f4(struct Struct_020db3f4* arg0) {
    if (arg0->unknown_51_ != 0) {
        return;
    }

    func_020db844((struct Struct_020db3f4_3*)arg0, arg0->unknown_3c_, arg0->unknown_6a_, 0);
    arg0->unknown_51_ = 1;

    FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0x8000);

    int var0 = func_020937f0(arg0->unknown_3c_);
    int var1 = var0 - 0xb80;
    int var2 = 0x1e0;
    int var3 = var0 - 0x800;

    if (func_020db3a8((struct Struct_020db3a8*)arg0) != 0) {
        var2 = 0x1c0;
    }

    void* var4 = data_020f28e4[arg0->unknown_3c_]();

    CleanInvalidateCacheRange(arg0->unknown_40_, arg0->unknown_44_);
    data_020f28ec[arg0->unknown_3c_](arg0->unknown_40_, var1, arg0->unknown_44_);
    CleanCacheRange(arg0->unknown_40_, arg0->unknown_44_);

    char* var5 = (char*)var4 + var3;
    if (arg0->unknown_53_ == 0 || arg0->unknown_6a_ == 0) {
        memset(var5, 0, 0x800);
    } else if (arg0->unknown_6a_ == -16) {
        memset(var5, -16 + 15, 0x800);
    } else if (arg0->unknown_6a_ == 0x10) {
        memset(var5, 0xeeeeeeee, 0x800);
    }

    CleanInvalidateCacheRange(var5, 0x800);
    data_020f28ec[arg0->unknown_3c_](var5, var3, 0x800);
    CleanCacheRange(var5, 0x800);

    CleanInvalidateCacheRange(arg0->unknown_48_, arg0->unknown_4c_);
    data_020f28dc[arg0->unknown_3c_](arg0->unknown_48_, var2, arg0->unknown_4c_);
    CleanCacheRange(arg0->unknown_48_, arg0->unknown_4c_);

    func_020db304((int)arg0, arg0->unknown_3c_);

    arg0->unknown_6e_ = 0;
    for (int var6 = 0; var6 < 3; var6++) {
        unsigned char* var7 = arg0->unknown_70_[0];
        unsigned char* var8 = var7 + var6 * 0x28;
        func_020dde64((struct Struct_020db3f4_2*)var8);
        func_020de0ec((struct Struct_020de0ec*)var8);
    }

    if (arg0->unknown_53_ != 0) {
        arg0->unknown_58_ = 0x10;
        return;
    }

    int var9 = data_020f28fc[arg0->unknown_3c_]();
    arg0->unknown_64_ = var9 & 0x10;
    arg0->unknown_58_ = var9 | 0x10;
}
