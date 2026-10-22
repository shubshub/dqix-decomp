#include <globaldefs.h>

struct Pair021fc238 { unsigned int a; unsigned int b; };
extern struct Pair021fc238 __ptmf_null;

struct Block8Words_021fc238 { unsigned int w[8]; };
extern struct Block8Words_021fc238 data_ov023_021fd9c4;

struct DispatchEntry021fc238 { unsigned int fn; unsigned int locator; };

// USA: func_ov023_021fc238  (semantic: DispatchWithLocalTable_021fc238)
extern "C" ARM int func_ov023_021fc238(void* obj, void* param2) {
    struct Block8Words_021fc238 buf;
    buf = data_ov023_021fd9c4;
    unsigned int tmp1 = __ptmf_null.b;
    unsigned int tmp0 = __ptmf_null.a;
    buf.w[7] = tmp1;
    buf.w[6] = tmp0;
    struct DispatchEntry021fc238* entries = (struct DispatchEntry021fc238*)&buf;

    int idx = *(int*)((char*)obj + 0x1c);
    struct DispatchEntry021fc238* d = &entries[idx];
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
