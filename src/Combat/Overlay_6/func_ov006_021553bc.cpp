#include <globaldefs.h>
#include "Resource/AlchemyPot.h"

struct Struct_ov006_021553bc;
struct Container020e0310;

#if defined(jpn)
extern "C" int KeyTable_Get(Container020e0310*, int);
#else
extern "C" const char** func_020e5294(void* names, int item);
extern "C" void func_020e4864(const char*, char*, int, int, int, int);
#endif
extern "C" void func_ov023_021dceac(char*, int, int, unsigned char, unsigned char, unsigned char);
extern "C" void func_ov023_021dced4(Struct_02000c9c*, unsigned char);
extern "C" void func_ov006_021571cc(Struct_ov006_021553bc*);

// USA: func_ov006_021553bc
extern "C" ARM void func_ov006_021553bc(Struct_ov006_02154614* self, short* items, unsigned char* arg2) {
    const char* names[3] = {0};
    for (unsigned char i = 0; i < 3; i++) {
        if (self->itemNames_ != 0) {
#if defined(jpn)
            names[i] = (const char*)KeyTable_Get((Container020e0310*)self->itemNames_, items[i]);
#else
            const char** name = func_020e5294(self->itemNames_, items[i]);
            if (name != 0) {
                func_020e4864(*name, self->names_[i], 1, 0, 0, 0);
                names[i] = self->names_[i];
            }
#endif
            func_ov023_021dceac((char*)&self->window_, i, (int)names[i], arg2[i], arg2[i], 0);
        }
    }
    func_ov023_021dced4(&self->window_, 1);
    func_ov006_021571cc((Struct_ov006_021553bc*)self);
}
