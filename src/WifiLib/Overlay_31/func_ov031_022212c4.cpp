#include <globaldefs.h>

extern "C" const unsigned int data_ov031_02247d10[256];
extern "C" const unsigned int data_ov031_022460e8[10];

#define Te4 data_ov031_02247d10
#define rcon data_ov031_022460e8

#define GETU32(p) \
    (((unsigned int)(p)[0] << 24) ^ ((unsigned int)(p)[1] << 16) ^ \
     ((unsigned int)(p)[2] << 8) ^ ((unsigned int)(p)[3]))

// USA: func_ov031_022212c4
extern "C" THUMB int func_ov031_022212c4(unsigned int *arg0, const unsigned char *arg1,
                                          int arg2) {
    int i = 0;
    unsigned int var1;

    arg0[0] = GETU32(arg1     );
    arg0[1] = GETU32(arg1 +  4);
    arg0[2] = GETU32(arg1 +  8);
    arg0[3] = GETU32(arg1 + 12);
    if (arg2 == 128) {
        for (;;) {
            var1  = arg0[3];
            arg0[4] = arg0[0] ^
                (Te4[(var1 >> 16) & 0xff] & 0xff000000) ^
                (Te4[(var1 >>  8) & 0xff] & 0x00ff0000) ^
                (Te4[(var1      ) & 0xff] & 0x0000ff00) ^
                (Te4[(var1 >> 24)       ] & 0x000000ff) ^
                rcon[i];
            arg0[5] = arg0[1] ^ arg0[4];
            arg0[6] = arg0[2] ^ arg0[5];
            arg0[7] = arg0[3] ^ arg0[6];
            if (++i >= 10) {
                return 10;
            }
            arg0 += 4;
        }
    }
    arg0[4] = GETU32(arg1 + 16);
    arg0[5] = GETU32(arg1 + 20);
    if (arg2 == 192) {
        for (;;) {
            var1 = arg0[ 5];
            arg0[ 6] = arg0[ 0] ^
                (Te4[(var1 >> 16) & 0xff] & 0xff000000) ^
                (Te4[(var1 >>  8) & 0xff] & 0x00ff0000) ^
                (Te4[(var1      ) & 0xff] & 0x0000ff00) ^
                (Te4[(var1 >> 24)       ] & 0x000000ff) ^
                rcon[i];
            arg0[ 7] = arg0[ 1] ^ arg0[ 6];
            arg0[ 8] = arg0[ 2] ^ arg0[ 7];
            arg0[ 9] = arg0[ 3] ^ arg0[ 8];
            if (++i >= 8) {
                return 12;
            }
            arg0[10] = arg0[ 4] ^ arg0[ 9];
            arg0[11] = arg0[ 5] ^ arg0[10];
            arg0 += 6;
        }
    }
    arg0[6] = GETU32(arg1 + 24);
    arg0[7] = GETU32(arg1 + 28);
    if (arg2 == 256) {
        for (;;) {
            var1 = arg0[ 7];
            arg0[ 8] = arg0[ 0] ^
                (Te4[(var1 >> 16) & 0xff] & 0xff000000) ^
                (Te4[(var1 >>  8) & 0xff] & 0x00ff0000) ^
                (Te4[(var1      ) & 0xff] & 0x0000ff00) ^
                (Te4[(var1 >> 24)       ] & 0x000000ff) ^
                rcon[i];
            arg0[ 9] = arg0[ 1] ^ arg0[ 8];
            arg0[10] = arg0[ 2] ^ arg0[ 9];
            arg0[11] = arg0[ 3] ^ arg0[10];
            if (++i >= 7) {
                return 14;
            }
            var1 = arg0[11];
            arg0[12] = arg0[ 4] ^
                (Te4[(var1 >> 24)       ] & 0xff000000) ^
                (Te4[(var1 >> 16) & 0xff] & 0x00ff0000) ^
                (Te4[(var1 >>  8) & 0xff] & 0x0000ff00) ^
                (Te4[(var1      ) & 0xff] & 0x000000ff);
            arg0[13] = arg0[ 5] ^ arg0[12];
            arg0[14] = arg0[ 6] ^ arg0[13];
            arg0[15] = arg0[ 7] ^ arg0[14];
            arg0 += 8;
        }
    }
    return 0;
}
