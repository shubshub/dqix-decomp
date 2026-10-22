#include <globaldefs.h>

struct Pair021fbab0 { unsigned int a; unsigned int b; };
extern struct Pair021fbab0 __ptmf_null;

struct Block8Words_021fbab0 { unsigned int w[8]; };
extern struct Block8Words_021fbab0 data_ov023_021fd984;

struct DispatchEntry021fbab0 { unsigned int fn; unsigned int locator; };

// USA: func_ov023_021fbab0  (semantic: DispatchWithLocalTable_021fbab0)
extern "C" ARM int func_ov023_021fbab0(void* obj, void* param2) {
    struct Block8Words_021fbab0 buf;
    buf = data_ov023_021fd984;
    unsigned int tmp1 = __ptmf_null.b;
    unsigned int tmp0 = __ptmf_null.a;
    buf.w[7] = tmp1;
    buf.w[6] = tmp0;
    struct DispatchEntry021fbab0* entries = (struct DispatchEntry021fbab0*)&buf;

    int idx = *(int*)((char*)obj + 0x1c);
    struct DispatchEntry021fbab0* d = &entries[idx];
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
