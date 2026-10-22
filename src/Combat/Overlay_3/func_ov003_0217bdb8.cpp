#include <globaldefs.h>

struct DispatchEntry0217bdb8 { unsigned int fn; unsigned int locator; };
struct Table0217bdb8 { DispatchEntry0217bdb8 e[6]; };
extern Table0217bdb8 data_ov003_0217fb98;
extern DispatchEntry0217bdb8 __ptmf_null;

// USA: func_ov003_0217bdb8
extern "C" ARM unsigned char func_ov003_0217bdb8(char* obj) {
    Table0217bdb8 t = data_ov003_0217fb98;
    t.e[5].locator = __ptmf_null.locator;
    t.e[5].fn = __ptmf_null.fn;

    signed char idx = *(signed char*)(obj + 0x140);
    if (idx >= 0) {
        DispatchEntry0217bdb8* e = &t.e[idx];
        void* base = obj + ((int)e->locator >> 1);
        void* callback;
        if (e->locator & 1) {
            callback = *(void**)((char*)*(void**)base + e->fn);
        } else {
            callback = (void*)e->fn;
        }
        ((void (*)(void*))callback)(base);
    }
    return *(unsigned char*)(obj + 0x143);
}
