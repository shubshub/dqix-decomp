#include <globaldefs.h>

struct Struct_020e6d5c_18 { unsigned int fn; unsigned int unknown_4_; };
struct Struct_ov003_0217fb98 { Struct_020e6d5c_18 e[6]; };
extern Struct_ov003_0217fb98 data_ov003_0217fb98;
extern Struct_020e6d5c_18 __ptmf_null;

// USA: func_ov003_0217bdb8
extern "C" ARM unsigned char func_ov003_0217bdb8(char* obj) {
    Struct_ov003_0217fb98 t = data_ov003_0217fb98;
    t.e[5].unknown_4_ = __ptmf_null.unknown_4_;
    t.e[5].fn = __ptmf_null.fn;

    signed char idx = *(signed char*)(obj + 0x140);
    if (idx >= 0) {
        Struct_020e6d5c_18* e = &t.e[idx];
        void* base = obj + ((int)e->unknown_4_ >> 1);
        void* callback;
        if (e->unknown_4_ & 1) {
            callback = *(void**)((char*)*(void**)base + e->fn);
        } else {
            callback = (void*)e->fn;
        }
        ((void (*)(void*))callback)(base);
    }
    return *(unsigned char*)(obj + 0x143);
}
