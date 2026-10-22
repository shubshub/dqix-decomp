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

    signed char var1 = *(signed char*)(arg0 + 0x140);
    if (var1 >= 0) {
        Struct_020e6d5c_18* var2 = &var0.unknown_0_[var1];
        void* var3 = arg0 + ((int)var2->unknown_4_ >> 1);
        void* var4;
        if (var2->unknown_4_ & 1) {
            var4 = *(void**)((char*)*(void**)var3 + var2->unknown_0_);
        } else {
            var4 = (void*)var2->unknown_0_;
        }
        ((void (*)(void*))var4)(var3);
    }
    return *(unsigned char*)(arg0 + 0x143);
}
