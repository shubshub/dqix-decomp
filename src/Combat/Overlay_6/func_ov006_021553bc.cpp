#include <globaldefs.h>
#include "Resource/AlchemyPot.h"

struct Struct_ov006_021553bc;
struct Struct_0201099c_3;

#if defined(jpn)
int KeyTable_Get(Container020e0310*, int);
#else
extern "C" const char** func_020e5294(void* arg0, int arg1);
extern "C" void func_020e4864(const char*, char*, int, int, int, int);
#endif
extern "C" void func_ov023_021dceac(char*, int, int, unsigned char, unsigned char, unsigned char);
extern "C" void func_ov023_021dced4(Struct_02000c9c*, unsigned char);
extern "C" void func_ov006_021571cc(Struct_ov006_021553bc*);

// USA: func_ov006_021553bc
extern "C" ARM void func_ov006_021553bc(Struct_ov006_02154614* arg0, short* arg1, unsigned char* arg2) {
    const char* var0[3] = {0};
    for (unsigned char var1 = 0; var1 < 3; var1++) {
        if (arg0->unknown_1ac_ != 0) {
#if defined(jpn)
            names[i] = (const char*)KeyTable_Get((Container020e0310*)self->itemNames_, items[i]);
#else
            const char** var2 = func_020e5294(arg0->unknown_1ac_, arg1[var1]);
            if (var2 != 0) {
                func_020e4864(*var2, arg0->unknown_0_[var1], 1, 0, 0, 0);
                var0[var1] = arg0->unknown_0_[var1];
            }
#endif
            func_ov023_021dceac((char*)&arg0->unknown_ae4_, var1, (int)var0[var1], arg2[var1], arg2[var1], 0);
        }
    }
    func_ov023_021dced4(&arg0->unknown_ae4_, 1);
    func_ov006_021571cc((Struct_ov006_021553bc*)arg0);
}
