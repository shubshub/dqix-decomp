#include <globaldefs.h>
#if defined(jpn)
extern "C" int func_02069430(void*, unsigned short);
extern "C" int func_02069444(void*, unsigned short);
extern "C" int func_020694a0(void*, unsigned short);
extern "C" void func_0206cb14(void*, int, unsigned short);
#endif

extern "C" int func_02067ad8(int unused, void* src);
extern "C" bool func_02044494(void* obj, void* src);
extern "C" int func_02044420(void* obj, void* src);

struct Struct_0204500c_4;
extern "C" void func_0206b198(struct Struct_0204500c_4* obj, unsigned short idx);

struct Struct_02065990 {
    #if defined(jpn)
    unsigned char pad0[0x18];
#else
    unsigned char pad0[0x4c];
#endif
    unsigned short* buf;
    unsigned char pad1[0x74 - 0x50];
    int idx;
    int counter;
};

// USA: func_0206b61c
extern "C" ARM void func_0206b61c(struct Struct_02065990* obj) {
    int cont = 1;
    int var1 = 0;
    int var2 = var1;
    unsigned short* p = obj->buf + obj->idx;
    while (cont) {
        int extra;
        #if defined(jpn)
        if (func_020694a0(obj, *p)) {
#else
        if (func_02067ad8((int)obj, p)) {
#endif
            cont = var2;
        }
        #if defined(jpn)
        if (func_02069430(obj, *p)) {
#else
        if (func_02044494(obj, p)) {
#endif
            #if defined(jpn)
            extra = func_02069444(obj, *p);
#else
            extra = func_02044420(obj, p);
#endif
            p += extra;
            var1 += extra;
        } else {
#if defined(jpn)
            func_0206cb14(obj, *((unsigned char*)obj + 0x1788), *p);
            func_0206cb14(obj, 12, *p);
            func_0206cb14(obj, 6, *p);
#else
            func_0206b198((struct Struct_0204500c_4*)obj, *p);
#endif
        }
        p += 1;
        var1 += 1;
    }
    obj->idx += var1;
    obj->counter += 1;
}
