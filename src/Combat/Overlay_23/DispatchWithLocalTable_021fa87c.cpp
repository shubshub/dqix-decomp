#include <globaldefs.h>

struct Pair021fa87c { unsigned int a; unsigned int b; };
extern struct Pair021fa87c __ptmf_null;

struct Block8Words_021fa87c { unsigned int w[8]; };
extern struct Block8Words_021fa87c data_ov023_021fd944;

struct DispatchEntry021fa87c { unsigned int fn; unsigned int locator; };

// USA: func_ov023_021fa87c
ARM int DispatchWithLocalTable_021fa87c(void* obj, void* param2) {
    struct Block8Words_021fa87c buf;
    buf = data_ov023_021fd944;
    unsigned int tmp1 = __ptmf_null.b;
    unsigned int tmp0 = __ptmf_null.a;
    buf.w[7] = tmp1;
    buf.w[6] = tmp0;
    struct DispatchEntry021fa87c* entries = (struct DispatchEntry021fa87c*)&buf;

    int idx = *(int*)((char*)obj + 0x1c);
    struct DispatchEntry021fa87c* d = &entries[idx];
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
