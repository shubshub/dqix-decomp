#include <globaldefs.h>

struct Struct_ov023_021e2acc {
    short f0;
    char pad1[6];
    short f8;
    short fa;
    short fc;
    char pad2[2];
    short f10;
};

extern "C" Struct_ov023_021e2acc* func_ov023_021db4e4(void* obj);
extern "C" Struct_ov023_021e2acc* func_ov023_021e2acc(void* obj, int val, short* out1, short* out2);

// USA: func_ov023_021e2acc
extern "C" ARM Struct_ov023_021e2acc* func_ov023_021e2acc(void* obj, int val, short* out1, short* out2) {
    Struct_ov023_021e2acc* result = func_ov023_021db4e4(obj);
    *out1 = *out1 + result->f8;
    *out2 = *out2 + result->fa;
    while (result != NULL) {
        if (result->f10 > 0) {
            result = func_ov023_021db4e4(obj);
            continue;
        }
        if (result->fc < 0) {
            return result;
        }
        result = func_ov023_021db4e4(obj);
        if (result == NULL) return result;
        return func_ov023_021e2acc(obj, result->f0, out1, out2);
    }
    return result;
}
