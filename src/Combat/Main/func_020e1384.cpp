#include <globaldefs.h>

void CleanInvalidateCacheRange(const void* addr, unsigned int size);
void CleanCacheRange(const void* addr, unsigned int size);
extern "C" int func_020e12c0(void*);

typedef void (*Type_020e1384)(int, int, int);
extern Type_020e1384 data_020f2bb0[];

struct Struct_020e1384 {
    int field0;
    int field4;
    char pad8[4];
    int unknown_c_;
    char pad10[4];
    unsigned char unknown_14_;
};

// USA: func_020e1384
extern "C" ARM void func_020e1384(struct Struct_020e1384* obj) {
    int result = func_020e12c0(obj);
    if (result == 0) {
        return;
    }
    unsigned char idx = obj->unknown_14_;
    int base = obj->field0;
    Type_020e1384 fn = data_020f2bb0[idx];
    if (fn == NULL) {
        return;
    }
    int addr = result + base;
    CleanInvalidateCacheRange((const void*)(addr), obj->field4);
    fn(addr, obj->unknown_c_, obj->field4);
    CleanCacheRange((const void*)(addr), obj->field4);
}
