#include <globaldefs.h>

struct Pair021f6f90 { unsigned int a; unsigned int b; };
extern struct Pair021f6f90 __ptmf_null;

struct Block8Words_021f6f90 { unsigned int w[8]; };
extern struct Block8Words_021f6f90 data_ov023_021fd8d8;

struct DispatchEntry021f6f90 { unsigned int fn; unsigned int locator; };

// USA: func_ov023_021f6f90
ARM int DispatchByTableEntry_021f6f90(void* obj, void* param2) {
    struct Block8Words_021f6f90 buf;
    buf = data_ov023_021fd8d8;
    unsigned int tmp1 = __ptmf_null.b;
    unsigned int tmp0 = __ptmf_null.a;
    buf.w[7] = tmp1;
    buf.w[6] = tmp0;
    struct DispatchEntry021f6f90* entries = (struct DispatchEntry021f6f90*)&buf;

    int idx = *(int*)((char*)obj + 0x1c);
    struct DispatchEntry021f6f90* d = &entries[idx];
    void* base = (char*)obj + ((int)d->locator >> 1);
    void* callback;
    if (d->locator & 1) {
        callback = *(void**)((char*)*(void**)base + d->fn);
    } else {
        callback = (void*)d->fn;
    }
    int result = ((int(*)(void*, void*))callback)(base, param2);
    *(int*)((char*)obj + 0x1c) = result;
    return result;
}
