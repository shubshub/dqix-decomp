#include <globaldefs.h>

#if defined(jpn)
#define data_020f1f14 data_020f2080
#endif

struct Struct_020f1f14_5 {
    int a;
    int b;
    char pad[0x10];
};

extern struct Struct_020f1f14_5 data_020f1f14[];

// Main, originally RestorePairTableFromBuffer_020bb740 (USA 0x020bb740, EUR 0x020bb750, JPN 0x020bd20c)
extern "C" ARM void NNS_GfdSetFrmTexVramState(int* out) {
    int i = 0;
    int j = 0;
    struct Struct_020f1f14_5* dst = data_020f1f14;
    do {
        dst->a = out[j];
        dst->b = (out + j)[1];
        j = j + 2;
        dst = dst + 1;
        i = i + 1;
    } while (i < 5);
}
