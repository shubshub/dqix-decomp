#include <globaldefs.h>

struct Struct_020e6d5c_7 { unsigned int a; unsigned int b; };
extern struct Struct_020e6d5c_7 __ptmf_null;

struct Struct_ov023_021fd9c4 { unsigned int w[8]; };
extern struct Struct_ov023_021fd9c4 data_ov023_021fd9c4;

struct Struct_ov023_021fc238 { unsigned int fn; unsigned int unknown_4_; };

// USA: func_ov023_021fc238
extern "C" ARM int func_ov023_021fc238(void* obj, void* param2) {
    struct Struct_ov023_021fd9c4 buf;
    buf = data_ov023_021fd9c4;
    unsigned int var1 = __ptmf_null.b;
    unsigned int var2 = __ptmf_null.a;
    buf.w[7] = var1;
    buf.w[6] = var2;
    struct Struct_ov023_021fc238* entries = (struct Struct_ov023_021fc238*)&buf;

    int idx = *(int*)((char*)obj + 0x1c);
    struct Struct_ov023_021fc238* d = &entries[idx];
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
