#include <globaldefs.h>

extern "C" unsigned int func_020937f0(int a);
extern "C" int func_0209378c(int a);
extern "C" void OamManager_GetInstance(int a);

extern "C" int func_020db2dc(int a, int b);

struct Struct_020db264;
extern "C" void func_020db360(struct Struct_020db264* obj, int b);

extern "C" void func_020db6e4(void* obj, int val);

struct Struct_020db5ec;
extern "C" void func_020db768(struct Struct_020db5ec* s, void* other);

void DMAMemsetSynchronous(int, unsigned int, unsigned int, unsigned int);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
void CleanCacheRange(const void* addr, unsigned int size);

struct Struct_020db3f4_3;
extern "C" void func_020db844(struct Struct_020db3f4_3* a, int b, int c, int d);

typedef void (*Type_01ff8b48_8)(int, int, int);
extern Type_01ff8b48_8 data_020f2904[];
typedef void (*Type_01ff8b48_9)(int);
extern Type_01ff8b48_9 data_020f28f4[];

struct Struct_020db5ec_2 {
    unsigned char pad0[0x3c];
    unsigned char field3c;
    unsigned char pad1[0x51 - 0x3c - 1];
    unsigned char unknown_51_;
    unsigned char pad2[0x53 - 0x51 - 1];
    unsigned char unknown_53_;
    unsigned char pad3[0x58 - 0x53 - 1];
    unsigned int unknown_58_;
};

// USA: func_020db5ec
extern "C" ARM void func_020db5ec(struct Struct_020db5ec_2* obj) {
    if (obj->unknown_51_ == 0) return;
    unsigned int base = func_020937f0(obj->field3c);
    int shift = func_0209378c(obj->field3c);
    int var2 = (base - 0xb80) >> shift;
    int var3 = (base - 0x800) >> shift;
    OamManager_GetInstance(shift);
    int handle = func_020db2dc((int)obj, obj->field3c);
    func_020db360((struct Struct_020db264*)obj, 0);
    if (obj->unknown_53_ != 0) {
        func_020db6e4(obj, var3);
    }
    func_020db768((struct Struct_020db5ec*)obj, (void*)var2);
    CleanInvalidateCacheRange((const void*)handle, 0xe0);
    data_020f2904[obj->field3c](handle, 0, 0xe0);
    CleanCacheRange((const void*)handle, 0xe0);
    DMAMemsetSynchronous(3, handle + 0x20, 0xc0, 0x60);
    func_020db844((struct Struct_020db3f4_3*)obj, obj->field3c, 0, 0);
    data_020f28f4[obj->field3c](obj->unknown_58_);
}
