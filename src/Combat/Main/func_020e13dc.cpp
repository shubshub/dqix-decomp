#include <globaldefs.h>

void CleanInvalidateCacheRange(const void* addr, unsigned int size);
void CleanCacheRange(const void* addr, unsigned int size);
extern "C" int func_020e12c0(void* p);

typedef void (*Type_020e13dc)(int, int, int);
extern Type_020e13dc data_020f2bb0[];

struct Struct_020e13dc {
    int field_0;
    int unknown_4_;
    unsigned char field_8;
    int unknown_c_;
    int unknown_10_;
    unsigned char unknown_14_;
};

// USA: func_020e13dc
extern "C" ARM void func_020e13dc(Struct_020e13dc* obj) {
    int base = func_020e12c0(&obj->unknown_c_);
    if (base) {
        Type_020e13dc cb = data_020f2bb0[obj->field_8];
        int var2 = obj->unknown_c_;
        if (cb) {
            CleanInvalidateCacheRange((const void*)(base + var2), obj->unknown_4_);
            cb(base + var2, obj->field_0, obj->unknown_10_);
            CleanCacheRange((const void*)(base + var2), obj->unknown_4_);
        }
    }
}
