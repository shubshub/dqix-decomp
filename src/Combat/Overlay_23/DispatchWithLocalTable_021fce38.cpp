#include <globaldefs.h>

struct Pair021fce38 { unsigned int a; unsigned int b; };
extern struct Pair021fce38 __ptmf_null;

struct Block8Words_021fce38 { unsigned int w[8]; };
extern struct Block8Words_021fce38 data_ov023_021fda14;

struct DispatchEntry021fce38 { unsigned int fn; unsigned int locator; };

// USA: func_ov023_021fce38  (semantic: DispatchWithLocalTable_021fce38)
extern "C" ARM int func_ov023_021fce38(void* obj, void* param2) {
    struct Block8Words_021fce38 buf;
    buf = data_ov023_021fda14;
    unsigned int tmp1 = __ptmf_null.b;
    unsigned int tmp0 = __ptmf_null.a;
    buf.w[7] = tmp1;
    buf.w[6] = tmp0;
    struct DispatchEntry021fce38* entries = (struct DispatchEntry021fce38*)&buf;

    int idx = *(int*)((char*)obj + 0x1c);
    struct DispatchEntry021fce38* d = &entries[idx];
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
