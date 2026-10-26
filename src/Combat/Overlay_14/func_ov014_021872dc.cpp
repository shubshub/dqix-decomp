#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_ov014_02186bc8_3;
extern "C" short func_ov014_021874f8(struct Struct_ov014_02186bc8_3* obj);
struct Struct_ov014_021872dc;
extern "C" short func_ov014_02187520(struct Struct_ov014_021872dc* obj);
struct Struct_ov014_021872dc_2;
extern "C" struct Struct_ov014_021872dc_2* func_ov014_02187340(void* obj, int target);

// USA: func_ov014_021872dc
extern "C" ARM struct Struct_ov014_021872dc_2* func_ov014_021872dc(unsigned char* obj, int param1) {
    short count = func_ov014_021874f8((struct Struct_ov014_02186bc8_3*)obj);
    int var1 = count + 15;
    int var2 = var1 >> 3;
    int rounded = var1 + ((unsigned int)var2 >> 28);
    int r5 = (rounded << 12) >> 16;

    short idx = func_ov014_02187520((struct Struct_ov014_021872dc*)obj);
    short s = (short)(idx + param1);
    if (s < 0) {
        s = (short)(r5 + s);
    }
    if (r5 <= s) {
        s = (short)(s - r5);
    }

    struct Struct_ov014_021872dc_2* ret = func_ov014_02187340(obj, s);
    *(struct Struct_ov014_021872dc_2**)(obj + 0xbc) = ret;
    return ret;
}
