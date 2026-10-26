#include <globaldefs.h>

struct Struct_ov023_021e2bdc { short val; };
struct Struct_ov023_021e2bdc_2 { char pad2[2]; unsigned short flag; struct Struct_ov023_021e2bdc* ptr; };

extern "C" struct Struct_ov023_021e2bdc_2* func_ov023_021db4e4(void*);
extern "C" void func_ov023_021e2b5c(void*, int, short*, short*);

// USA: func_ov023_021e2bdc
extern "C" ARM void func_ov023_021e2bdc(void* a, int unused, short* out1, short* out2) {
    struct Struct_ov023_021e2bdc_2* r = func_ov023_021db4e4(a);
    if (r != 0 && r->flag != 0 && r->ptr != 0) {
        short v = r->ptr->val;
        short var2, var3;
        func_ov023_021e2b5c(a, v, &var2, &var3);
        *out1 = var2;
        *out2 = var3;
    }
}
