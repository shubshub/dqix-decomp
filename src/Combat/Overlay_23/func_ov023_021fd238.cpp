#include <globaldefs.h>

struct Struct_020e6d5c_9 { unsigned int a; unsigned int b; };
extern struct Struct_020e6d5c_9 __ptmf_null;

struct Struct_ov023_021fda34 { unsigned int w[8]; };
extern struct Struct_ov023_021fda34 data_ov023_021fda34;

struct Struct_ov023_021fd238 { unsigned int fn; unsigned int unknown_4_; };

// USA: func_ov023_021fd238
extern "C" ARM int func_ov023_021fd238(void* obj, void* param2) {
    struct Struct_ov023_021fda34 buf;
    buf = data_ov023_021fda34;
    unsigned int var1 = __ptmf_null.b;
    unsigned int var2 = __ptmf_null.a;
    buf.w[7] = var1;
    buf.w[6] = var2;
    struct Struct_ov023_021fd238* entries = (struct Struct_ov023_021fd238*)&buf;

    int idx = *(int*)((char*)obj + 0x1c);
    struct Struct_ov023_021fd238* d = &entries[idx];
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
