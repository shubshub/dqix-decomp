#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_020db3f4_3;
extern "C" void func_020db844(struct Struct_020db3f4_3* a, int b, int c, int d);

extern "C" void* GlobalFlags_GetInstance(void);

extern "C" void FlagWord_SetBits(unsigned int* word, unsigned int mask);

extern "C" int func_020937f0(int a);

struct Struct_020db3a8;
extern "C" int func_020db3a8(struct Struct_020db3a8* s);

void CleanInvalidateCacheRange(const void* addr, unsigned int size);
void CleanCacheRange(const void* addr, unsigned int size);

extern "C" void func_020db304(int param0, int param1);

struct Struct_020db3f4_2;
extern "C" void func_020dde64(struct Struct_020db3f4_2* obj);

struct Struct_020de0ec;
extern "C" void func_020de0ec(struct Struct_020de0ec* obj);

typedef void* (*Type_01ff8b48_4)(void);
extern Type_01ff8b48_4 data_020f28e4[];

typedef void (*Type_ov031_02220af0_2)(void*, int, unsigned int);
extern Type_ov031_02220af0_2 data_020f28ec[];
extern Type_ov031_02220af0_2 data_020f28dc[];

typedef int (*Type_01ff8b48_5)(void);
extern Type_01ff8b48_5 data_020f28fc[];

struct Struct_020db3f4 {
    unsigned char unknown_0_[0x3c];
    unsigned char field3c;
    unsigned char unknown_3d_[0x40 - 0x3d];
    void* field40;
    unsigned int field44;
    void* field48;
    unsigned int field4c;
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
    unsigned char pad6c[0x6e - 0x6c];
    unsigned short unknown_6e_;
    unsigned char slots[3][0x28];
};

// USA: func_020db3f4
extern "C" ARM void func_020db3f4(struct Struct_020db3f4* obj) {
    if (obj->unknown_51_ != 0) {
        return;
    }

    func_020db844((struct Struct_020db3f4_3*)obj, obj->field3c, obj->unknown_6a_, 0);
    obj->unknown_51_ = 1;

    FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0x8000);

    int x = func_020937f0(obj->field3c);
    int var1 = x - 0xb80;
    int mode = 0x1e0;
    int var3 = x - 0x800;

    if (func_020db3a8((struct Struct_020db3a8*)obj) != 0) {
        mode = 0x1c0;
    }

    void* base = data_020f28e4[obj->field3c]();

    CleanInvalidateCacheRange(obj->field40, obj->field44);
    data_020f28ec[obj->field3c](obj->field40, var1, obj->field44);
    CleanCacheRange(obj->field40, obj->field44);

    char* addr = (char*)base + var3;
    if (obj->unknown_53_ == 0 || obj->unknown_6a_ == 0) {
        memset(addr, 0, 0x800);
    } else if (obj->unknown_6a_ == -16) {
        memset(addr, -16 + 15, 0x800);
    } else if (obj->unknown_6a_ == 0x10) {
        memset(addr, 0xeeeeeeee, 0x800);
    }

    CleanInvalidateCacheRange(addr, 0x800);
    data_020f28ec[obj->field3c](addr, var3, 0x800);
    CleanCacheRange(addr, 0x800);

    CleanInvalidateCacheRange(obj->field48, obj->field4c);
    data_020f28dc[obj->field3c](obj->field48, mode, obj->field4c);
    CleanCacheRange(obj->field48, obj->field4c);

    func_020db304((int)obj, obj->field3c);

    obj->unknown_6e_ = 0;
    for (int i = 0; i < 3; i++) {
        unsigned char* arr = obj->slots[0];
        unsigned char* p = arr + i * 0x28;
        func_020dde64((struct Struct_020db3f4_2*)p);
        func_020de0ec((struct Struct_020de0ec*)p);
    }

    if (obj->unknown_53_ != 0) {
        obj->unknown_58_ = 0x10;
        return;
    }

    int result = data_020f28fc[obj->field3c]();
    obj->unknown_64_ = result & 0x10;
    obj->unknown_58_ = result | 0x10;
}
