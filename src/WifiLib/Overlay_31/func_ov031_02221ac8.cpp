#include <globaldefs.h>

extern "C" const unsigned int data_ov031_02248110[256];   // Td0
extern "C" const unsigned int data_ov031_02248510[256];   // Td1
extern "C" const unsigned int data_ov031_02246110[256];   // Td2
extern "C" const unsigned int data_ov031_02246510[256];   // Td3
extern "C" const unsigned int data_ov031_02246910[256];   // Td4

#define Td0 data_ov031_02248110
#define Td1 data_ov031_02248510
#define Td2 data_ov031_02246110
#define Td3 data_ov031_02246510
#define Td4 data_ov031_02246910

#define GETU32(p) \
    (((unsigned int)(p)[0] << 24) ^ ((unsigned int)(p)[1] << 16) ^ \
     ((unsigned int)(p)[2] << 8) ^ ((unsigned int)(p)[3]))

#define PUTU32(ct, st) { \
    (ct)[0] = (unsigned char)((st) >> 24); \
    (ct)[1] = (unsigned char)((st) >> 16); \
    (ct)[2] = (unsigned char)((st) >> 8);  \
    (ct)[3] = (unsigned char)(st); }

// USA: func_ov031_02221ac8
extern "C" THUMB void func_ov031_02221ac8(const unsigned int *arg0, int arg1,
                                           const unsigned char *arg2, unsigned char *pt) {
    unsigned int s0, s1, s2, s3, var4, var5, t2, var7;
    int r;

    s0 = GETU32(arg2     ) ^ arg0[0];
    s1 = GETU32(arg2 +  4) ^ arg0[1];
    s2 = GETU32(arg2 +  8) ^ arg0[2];
    s3 = GETU32(arg2 + 12) ^ arg0[3];

    r = arg1 >> 1;
    for (;;) {
        var4 =
            Td0[(s0 >> 24)       ] ^
            Td1[(s3 >> 16) & 0xff] ^
            Td2[(s2 >>  8) & 0xff] ^
            Td3[(s1      ) & 0xff] ^
            arg0[4];
        var5 =
            Td0[(s1 >> 24)       ] ^
            Td1[(s0 >> 16) & 0xff] ^
            Td2[(s3 >>  8) & 0xff] ^
            Td3[(s2      ) & 0xff] ^
            arg0[5];
        t2 =
            Td0[(s2 >> 24)       ] ^
            Td1[(s1 >> 16) & 0xff] ^
            Td2[(s0 >>  8) & 0xff] ^
            Td3[(s3      ) & 0xff] ^
            arg0[6];
        var7 =
            Td0[(s3 >> 24)       ] ^
            Td1[(s2 >> 16) & 0xff] ^
            Td2[(s1 >>  8) & 0xff] ^
            Td3[(s0      ) & 0xff] ^
            arg0[7];

        arg0 += 8;
        if (--r == 0) {
            break;
        }

        s0 =
            Td0[(var4 >> 24)       ] ^
            Td1[(var7 >> 16) & 0xff] ^
            Td2[(t2 >>  8) & 0xff] ^
            Td3[(var5      ) & 0xff] ^
            arg0[0];
        s1 =
            Td0[(var5 >> 24)       ] ^
            Td1[(var4 >> 16) & 0xff] ^
            Td2[(var7 >>  8) & 0xff] ^
            Td3[(t2      ) & 0xff] ^
            arg0[1];
        s2 =
            Td0[(t2 >> 24)       ] ^
            Td1[(var5 >> 16) & 0xff] ^
            Td2[(var4 >>  8) & 0xff] ^
            Td3[(var7      ) & 0xff] ^
            arg0[2];
        s3 =
            Td0[(var7 >> 24)       ] ^
            Td1[(t2 >> 16) & 0xff] ^
            Td2[(var5 >>  8) & 0xff] ^
            Td3[(var4      ) & 0xff] ^
            arg0[3];
    }

    s0 =
        (Td4[(var4 >> 24)       ] & 0xff000000) ^
        (Td4[(var7 >> 16) & 0xff] & 0x00ff0000) ^
        (Td4[(t2 >>  8) & 0xff] & 0x0000ff00) ^
        (Td4[(var5      ) & 0xff] & 0x000000ff) ^
        arg0[0];
    PUTU32(pt, s0);

    s1 =
        (Td4[(var5 >> 24)       ] & 0xff000000) ^
        (Td4[(var4 >> 16) & 0xff] & 0x00ff0000) ^
        (Td4[(var7 >>  8) & 0xff] & 0x0000ff00) ^
        (Td4[(t2      ) & 0xff] & 0x000000ff) ^
        arg0[1];
    PUTU32(pt + 4, s1);

    s2 =
        (Td4[(t2 >> 24)       ] & 0xff000000) ^
        (Td4[(var5 >> 16) & 0xff] & 0x00ff0000) ^
        (Td4[(var4 >>  8) & 0xff] & 0x0000ff00) ^
        (Td4[(var7      ) & 0xff] & 0x000000ff) ^
        arg0[2];
    PUTU32(pt + 8, s2);

    s3 =
        (Td4[(var7 >> 24)       ] & 0xff000000) ^
        (Td4[(t2 >> 16) & 0xff] & 0x00ff0000) ^
        (Td4[(var5 >>  8) & 0xff] & 0x0000ff00) ^
        (Td4[(var4      ) & 0xff] & 0x000000ff) ^
        arg0[3];
    PUTU32(pt + 12, s3);
}
