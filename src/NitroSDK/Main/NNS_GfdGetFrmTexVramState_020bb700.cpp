#include <globaldefs.h>

#if defined(jpn)
#define data_020f1f14 data_020f2080
#endif

struct Struct_020f1f14_4 {
    int a;
    int b;
    char pad[0x10];
};

extern struct Struct_020f1f14_4 data_020f1f14[];

// Main, originally BackupPairTableToBuffer_020bb700 (USA 0x020bb700, EUR 0x020bb710, JPN 0x020bd1cc)
extern "C" ARM void NNS_GfdGetFrmTexVramState(int* out) {
    int i = 0;
    struct Struct_020f1f14_4* src = data_020f1f14;
    int j = 0;
    do {
        out[j] = src->a;
        (out + j)[1] = src->b;
        src = src + 1;
        j = j + 2;
        i = i + 1;
    } while (i < 5);
}
