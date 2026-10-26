#include <globaldefs.h>

struct Struct_020e6d5c_4 { unsigned int a; unsigned int b; };
extern struct Struct_020e6d5c_4 __ptmf_null;

struct Struct_ov023_021fd944 { unsigned int w[8]; };
extern struct Struct_ov023_021fd944 data_ov023_021fd944;

struct Struct_ov023_021fa87c { unsigned int fn; unsigned int unknown_4_; };

// USA: func_ov023_021fa87c
extern "C" ARM int func_ov023_021fa87c(void* obj, void* param2) {
    struct Struct_ov023_021fd944 buf;
    buf = data_ov023_021fd944;
    unsigned int var1 = __ptmf_null.b;
    unsigned int var2 = __ptmf_null.a;
    buf.w[7] = var1;
    buf.w[6] = var2;
    struct Struct_ov023_021fa87c* entries = (struct Struct_ov023_021fa87c*)&buf;

    int idx = *(int*)((char*)obj + 0x1c);
    struct Struct_ov023_021fa87c* d = &entries[idx];
    void* base = (char*)obj + ((int)d->unknown_4_ >> 1);
    void* callback;
    if (d->unknown_4_ & 1) {
        callback = *(void**)((char*)*(void**)base + d->fn);
    } else {
        callback = (void*)d->fn;
    }
    int result = ((int(*)(void*, void*))callback)(base, param2);
    *(int*)((char*)obj + 0x1c) = result;
    return result;
}
