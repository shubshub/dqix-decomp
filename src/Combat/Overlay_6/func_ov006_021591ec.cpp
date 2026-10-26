#if defined(jpn)
#define R(j,u) (j)
#define func_ov006_02154e58 func_ov006_021565b0
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_ov006_021591ec {
    unsigned char pad0[R(0x48, 0x50)];
    unsigned short* arr;
    unsigned char pad1[0x362 - R(0x4c, 0x54)];
    short unknown_362_;
};

// USA: func_ov006_021591ec
extern "C" ARM unsigned short func_ov006_021591ec(struct Struct_ov006_021591ec* s) {
    unsigned short result = 0;
    short idx = s->unknown_362_ - 0x5b;
    if (idx >= 0) {
        result = s->arr[idx];
    }
    return result;
}
