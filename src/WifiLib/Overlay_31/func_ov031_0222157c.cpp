#include <globaldefs.h>

extern "C" const unsigned int data_ov031_02247d10[256];
extern "C" const unsigned int data_ov031_02248110[256];
extern "C" const unsigned int data_ov031_02248510[256];
extern "C" const unsigned int data_ov031_02246110[256];
extern "C" const unsigned int data_ov031_02246510[256];

#define Te4 data_ov031_02247d10
#define Td0 data_ov031_02248110
#define Td1 data_ov031_02248510
#define Td2 data_ov031_02246110
#define Td3 data_ov031_02246510

extern "C" int func_ov031_022212c4(unsigned int *arg0, const unsigned char *arg1, int arg2);

// USA: func_ov031_0222157c (rijndaelKeySetupDec)
extern "C" THUMB int func_ov031_0222157c(unsigned int *arg0, const unsigned char *arg1, int arg2) {
    int var0, i, j;
    unsigned int var3;

    var0 = func_ov031_022212c4(arg0, arg1, arg2);
    for (i = 0, j = 4*var0; i < j; i += 4, j -= 4) {
        var3 = arg0[i    ]; arg0[i    ] = arg0[j    ]; arg0[j    ] = var3;
        var3 = arg0[i + 1]; arg0[i + 1] = arg0[j + 1]; arg0[j + 1] = var3;
        var3 = arg0[i + 2]; arg0[i + 2] = arg0[j + 2]; arg0[j + 2] = var3;
        var3 = arg0[i + 3]; arg0[i + 3] = arg0[j + 3]; arg0[j + 3] = var3;
    }
    for (i = 1; i < var0; i++) {
        arg0 += 4;
        arg0[0] =
            Td0[Te4[(arg0[0] >> 24)       ] & 0xff] ^
            Td1[Te4[(arg0[0] >> 16) & 0xff] & 0xff] ^
            Td2[Te4[(arg0[0] >>  8) & 0xff] & 0xff] ^
            Td3[Te4[(arg0[0]      ) & 0xff] & 0xff];
        arg0[1] =
            Td0[Te4[(arg0[1] >> 24)       ] & 0xff] ^
            Td1[Te4[(arg0[1] >> 16) & 0xff] & 0xff] ^
            Td2[Te4[(arg0[1] >>  8) & 0xff] & 0xff] ^
            Td3[Te4[(arg0[1]      ) & 0xff] & 0xff];
        arg0[2] =
            Td0[Te4[(arg0[2] >> 24)       ] & 0xff] ^
            Td1[Te4[(arg0[2] >> 16) & 0xff] & 0xff] ^
            Td2[Te4[(arg0[2] >>  8) & 0xff] & 0xff] ^
            Td3[Te4[(arg0[2]      ) & 0xff] & 0xff];
        arg0[3] =
            Td0[Te4[(arg0[3] >> 24)       ] & 0xff] ^
            Td1[Te4[(arg0[3] >> 16) & 0xff] & 0xff] ^
            Td2[Te4[(arg0[3] >>  8) & 0xff] & 0xff] ^
            Td3[Te4[(arg0[3]      ) & 0xff] & 0xff];
    }
    return var0;
}
