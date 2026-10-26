#include <globaldefs.h>
#include "Util/Random.h"

extern "C" int func_ov000_0215eb1c(struct Random* arg0, short* buf, int count, int flag);
extern "C" int func_ov024_021edcc8(void* obj, int id);
extern "C" int func_ov024_021ed890(struct Random** arg0, int* arg1, short* table);

struct Struct_ov024_021f2f78 { int field0; };
struct Struct_ov024_021fed5c { short v[8]; };
extern struct Struct_ov024_021fed5c data_ov024_021fed5c;

// USA: func_ov024_021f2f78
extern "C" ARM int func_ov024_021f2f78(struct Struct_ov024_021f2f78* obj, int unused1, int arg2, int* outCount, short* arg4) {
    struct Struct_ov024_021fed5c buf = data_ov024_021fed5c;
    int count = func_ov000_0215eb1c((struct Random*)obj->field0, buf.v, 8, 1);
    if (count <= 0) return 0;
    *outCount = 0;
    for (int i = 0; i < count; i++) {
        if (!func_ov024_021edcc8(obj, buf.v[i])) continue;
        int n = *outCount;
        *outCount = n + 1;
        arg4[n] = buf.v[i];
    }
    if (*outCount <= 0) return 0;
    func_ov024_021ed890((struct Random**)obj, outCount, arg4);
    return 1;
}
