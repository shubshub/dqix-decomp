#include <globaldefs.h>

typedef struct Struct_020026b4 {
    char unknown_0_;
    char unused;
    short unknown_2_;
    struct {
        unsigned char length;
        unsigned char text[32];
        unsigned char unused;
    } sig;
} Struct_020026b4;

extern "C" double func_0200a3a8(const Struct_020026b4* d);
extern "C" double func_02001710(const char* arg);

extern int data_020eecc4[];
extern int data_020eeccc[];

#define INFINITY (*(float*)data_020eecc4)
#define HUGE_VAL (*(double*)data_020eeccc)
#define LDBL_MIN 0x1.0000000000000P-1022L
#define LDBL_MAX 0x1.fffffffffffffP1023L

extern const unsigned short data_020e69ac[128];
extern const unsigned char data_020e692c[128];

static inline int inline_020042a8_3(int c) {
    return ((c < 0) || (c >= 128)) ? 0 : (int)(data_020e69ac[c] & 0x001);
}

static inline int inline_02001bdc(int c) {
    return ((c < 0) || (c >= 128)) ? 0 : (int)(data_020e69ac[c] & 0x008);
}

static inline int inline_020042a8_4(int c) {
    return ((c < 0) || (c >= 128)) ? 0 : (int)(data_020e69ac[c] & 0x100);
}

static inline int inline_020042a8(int c) {
    return ((c < 0) || (c >= 128)) ? 0 : (int)(data_020e69ac[c] & 0x400);
}

static inline int inline_020042a8_2(int c) {
    return ((c < 0) || (c >= 128)) ? c : (int)(data_020e692c[c]);
}

enum Enum_020042a8 {
    Enum_020042a8_0,
    Enum_020042a8_1,
    Enum_020042a8_2
};

#define TARGET_FLOAT_BITS  64
#define TARGET_FLOAT_BYTES (TARGET_FLOAT_BITS / 8)

#define TARGET_FLOAT_MAX_EXP        1024
#define TARGET_FLOAT_MANT_DIG       53
#define TARGET_FLOAT_IMPLICIT_J_BIT 1

#define TARGET_FLOAT_MANT_BITS (TARGET_FLOAT_MANT_DIG - TARGET_FLOAT_IMPLICIT_J_BIT)
#define TARGET_FLOAT_EXP_BITS  (TARGET_FLOAT_BITS - TARGET_FLOAT_MANT_BITS - 1)

enum Enum_020042a8_B {
    start              = 0x0001,
    Enum_020042a8_B_2          = 0x0002,
    Enum_020042a8_B_4 = 0x0004,
    Enum_020042a8_B_8     = 0x0008,
    Enum_020042a8_B_16         = 0x0010,
    Enum_020042a8_B_32    = 0x0020,
    Enum_020042a8_B_64            = 0x0040,
    Enum_020042a8_B_128          = 0x0080,
    Enum_020042a8_B_256  = 0x0100,
    Enum_020042a8_B_512 = 0x0200,
    Enum_020042a8_B_1024     = 0x0400,
    Enum_020042a8_B_2048           = 0x0800,
    Enum_020042a8_B_4096            = 0x1000,
    Enum_020042a8_B_8192          = 0x2000,
    Enum_020042a8_B_16384        = 0x4000,
    Enum_020042a8_B_32768          = 0x8000
};

enum Enum_020042a8_C {
    Enum_020042a8_C_0                = 0x0000,
    Enum_020042a8_C_1              = 0x0001,
    Enum_020042a8_C_2 = 0x0002,
    Enum_020042a8_C_4     = 0x0004,
    Enum_020042a8_C_8    = 0x0008,
    Enum_020042a8_C_16            = 0x0010,
    Enum_020042a8_C_32          = 0x0020,
    Enum_020042a8_C_64  = 0x0040,
    Enum_020042a8_C_128 = 0x0080,
    Enum_020042a8_C_256     = 0x0100
};

#define MAX_SIG_DIG 20

#define final_state(scan_state) (scan_state & (Enum_020042a8_B_2048 | Enum_020042a8_B_4096))

#define success(scan_state)                                                                                                 \
    (scan_state & (Enum_020042a8_B_4 | Enum_020042a8_B_8 | Enum_020042a8_B_32 | Enum_020042a8_B_512 | Enum_020042a8_B_1024 | Enum_020042a8_B_2048))

#define hex_success(count, scan_state)                                                                  \
    (count - 1 > 2 && scan_state & (Enum_020042a8_C_2 | Enum_020042a8_C_4 | Enum_020042a8_C_8 | \
                                    Enum_020042a8_C_128 | Enum_020042a8_C_256))

#define fetch()    (count++, (*arg1)(arg2, 0, Enum_020042a8_0))
#define unfetch(c) (*arg1)(arg2, c, Enum_020042a8_1)

// USA: func_020042a8
extern "C" ARM long double func_020042a8(int arg0, int (*arg1)(void*, int, int), void* arg2, int* arg3, int* arg4) {
    int     var0     = start;
    int     var1 = Enum_020042a8_C_0;
    int     count          = 0;
    int     var3         = 0;
    int     c;
    Struct_020026b4 d = {
        0, 0, 0, {0, ""}
    };
    int         var6  = 0;
    int         var7  = 0;
    long        var8     = 0;
    int         var9    = 0;
    long double result        = 0.0;
    int         var11 = 0;

    int var12 = '.';

    unsigned char* var13;
    unsigned char  var14[TARGET_FLOAT_BYTES];
    unsigned       var15;
    unsigned long  var16 = 0;

    int           var17;
    unsigned char var18, var19;
    int           var20;
    int           var21   = 0;
    unsigned      var22 = 0;

    *arg4 = 0;
    c         = fetch();

    while (count <= arg0 && c != -1 && !final_state(var0)) {

        switch (var0) {
            case start:
                if (inline_020042a8_4(c)) {
                    c = fetch();
                    count--;
                    var3++;
                    break;
                }

                switch (inline_020042a8_2(c)) {
                    case '-':
                        var6 = 1;

                    case '+':
                        c             = fetch();
                        var11 = 1;
                        break;

                    case 'I':
                        c          = fetch();
                        var0 = Enum_020042a8_B_16384;
                        break;

                    case 'N':
                        c          = fetch();
                        var0 = Enum_020042a8_B_8192;
                        break;

                    default:
                        var0 = Enum_020042a8_B_2;
                        break;
                }
                break;
            case Enum_020042a8_B_16384: {
                int  i       = 1;
                char model[] = "INFINITY";
                while ((i < 8) && (inline_020042a8_2(c) == model[i])) {
                    i++;
                    c = fetch();
                }
                if ((i == 3) || (i == 8)) {
                    if (var6)
                        result = -INFINITY;
                    else
                        result = INFINITY;
                    *arg3 = var3 + i + var11;
                    return (result);
                } else
                    var0 = Enum_020042a8_B_4096;
                break;
            }

            case Enum_020042a8_B_8192: {
                int  i = 1, j = 0;
                char model[]     = "NAN(";
                char var28[32] = "";
                while ((i < 4) && (inline_020042a8_2(c) == model[i])) {
                    i++;
                    c = fetch();
                }
                if ((i == 3) || (i == 4)) {
                    if (i == 4) {
                        while ((j < 32) && (inline_02001bdc(c) || inline_020042a8_3(c) || (c == var12))) {
                            var28[j++] = (char)c;
                            c            = fetch();
                        }
                        if (c != ')') {
                            var0 = Enum_020042a8_B_4096;
                            break;
                        } else
                            j++;
                    }
                    var28[j] = '\0';

                    if (var6)
                        result = -func_02001710(var28);
                    else
                        result = func_02001710(var28);
                    *arg3 = var3 + i + j + var11;
                    return (result);
                } else
                    var0 = Enum_020042a8_B_4096;
                break;
            }

            case Enum_020042a8_B_2:
                if (c == var12) {
                    var0 = Enum_020042a8_B_16;
                    c          = fetch();
                    break;
                }
                if (!inline_02001bdc(c)) {
                    var0 = Enum_020042a8_B_4096;
                    break;
                }
                if (c == '0') {
                    c = fetch();
                    if (inline_020042a8_2(c) == 'X') {
                        var0     = Enum_020042a8_B_32768;
                        var1 = Enum_020042a8_C_1;
                    } else
                        var0 = Enum_020042a8_B_4;
                    break;
                }
                var0 = Enum_020042a8_B_8;
                break;

            case Enum_020042a8_B_4:

                if (c == '0') {
                    c = fetch();

                    break;
                }
                var0 = Enum_020042a8_B_8;
                break;

            case Enum_020042a8_B_8:
                if (!inline_02001bdc(c)) {
                    if (c == var12) {
                        var0 = Enum_020042a8_B_32;
                        c          = fetch();
                    } else
                        var0 = Enum_020042a8_B_64;
                    break;
                }
                if (d.sig.length < MAX_SIG_DIG)
                    d.sig.text[d.sig.length++] = (unsigned char)c;
                else
                    var9++;
                c = fetch();
                break;

            case Enum_020042a8_B_16:
                if (!inline_02001bdc(c)) {
                    var0 = Enum_020042a8_B_4096;
                    break;
                }
                var0 = Enum_020042a8_B_32;
                break;

            case Enum_020042a8_B_32:
                if (!inline_02001bdc(c)) {
                    var0 = Enum_020042a8_B_64;
                    break;
                }
                if (d.sig.length < MAX_SIG_DIG) {
                    if (c != '0' || d.sig.length)
                        d.sig.text[d.sig.length++] = (unsigned char)c;
                    var9--;
                }
                c = fetch();
                break;

            case Enum_020042a8_B_64:
                if (inline_020042a8_2(c) == 'E') {
                    var0 = Enum_020042a8_B_128;
                    c          = fetch();
                    break;
                }
                var0 = Enum_020042a8_B_2048;
                break;

            case Enum_020042a8_B_128:
                if (c == '+')
                    c = fetch();
                else if (c == '-') {
                    c            = fetch();
                    var7 = 1;
                }
                var0 = Enum_020042a8_B_256;
                break;

            case Enum_020042a8_B_256:
                if (!inline_02001bdc(c)) {
                    var0 = Enum_020042a8_B_4096;
                    break;
                }
                if (c == '0') {
                    var0 = Enum_020042a8_B_512;
                    c          = fetch();
                    break;
                }
                var0 = Enum_020042a8_B_1024;
                break;

            case Enum_020042a8_B_512:
                if (c == '0') {
                    c = fetch();
                    break;
                }
                var0 = Enum_020042a8_B_1024;
                break;

            case Enum_020042a8_B_1024:
                if (!inline_02001bdc(c)) {
                    var0 = Enum_020042a8_B_2048;
                    break;
                }
                var8 = var8 * 10 + (c - '0');
                if (var8 > 0x7fff)
                    *arg4 = 1;
                c = fetch();
                break;

            case Enum_020042a8_B_32768: {
                switch (var1) {
                    case Enum_020042a8_C_1:
                        var13 = var14;

                        __builtin__clear(var14, sizeof(var14));
                        var15 = (TARGET_FLOAT_MANT_DIG + 3) / 4;

                        var22      = 0;
                        var20    = 0;
                        var1 = Enum_020042a8_C_2;
                        c              = fetch();
                        break;

                    case Enum_020042a8_C_2:
                        if (c == '0') {
                            c = fetch();
                            break;
                        }
                        var1 = Enum_020042a8_C_4;

                        break;

                    case Enum_020042a8_C_4:
                        if (!inline_020042a8(c)) {
                            if (c == var12) {
                                var1 = Enum_020042a8_C_8;
                                c              = fetch();
                            } else
                                var1 = Enum_020042a8_C_16;
                            break;
                        }

                        if (var22 < var15) {
                            var22++;
                            var18 = *(var13 + var20 / 2);
                            var17  = inline_020042a8_2(c);
                            if (var17 >= 'A')
                                var17 = var17 - 'A' + 10;
                            else
                                var17 -= '0';
                            var19 = (unsigned char)var17;
                            if ((var20 % 2) != 0)
                                var18 |= var19;
                            else
                                var18 |= (unsigned char)(var19 << 4);
                            *(var13 + var20++ / 2) = var18;
                            c                            = fetch();
                        } else
                            c = fetch();
                        break;

                    case Enum_020042a8_C_8:
                        if (!inline_020042a8(c)) {
                            var1 = Enum_020042a8_C_16;
                            break;
                        }
                        if (var22 < var15) {
                            var18 = *(var13 + var20 / 2);
                            var17  = inline_020042a8_2(c);
                            if (var17 >= 'A')
                                var17 = var17 - 'A' + 10;
                            else
                                var17 -= '0';
                            var19 = (unsigned char)var17;
                            if ((var20 % 2) != 0)
                                var18 |= var19;
                            else
                                var18 |= (unsigned char)(var19 << 4);
                            *(var13 + var20++ / 2) = var18;
                            c                            = fetch();
                        } else
                            c = fetch();
                        break;

                    case Enum_020042a8_C_16:
                        if (inline_020042a8_2(c) == 'P') {
                            var1 = Enum_020042a8_C_32;
                            c              = fetch();
                        } else
                            var0 = Enum_020042a8_B_2048;
                        break;

                    case Enum_020042a8_C_32:
                        if (c == '-')
                            var21 = 1;
                        else if (c != '+') {
                            c = unfetch(c);
                            count--;
                        }
                        var1 = Enum_020042a8_C_64;
                        c              = fetch();
                        break;

                    case Enum_020042a8_C_64:

                        if (!inline_02001bdc(c)) {
                            var0 = Enum_020042a8_B_4096;
                            break;
                        }
                        if (c == '0') {
                            var1 = Enum_020042a8_C_128;
                            c              = fetch();
                            break;
                        }
                        var1 = Enum_020042a8_C_256;
                        break;

                    case Enum_020042a8_C_128:
                        if (c == '0') {
                            c = fetch();
                            break;
                        }
                        var1 = Enum_020042a8_C_256;
                        break;

                    case Enum_020042a8_C_256:
                        if (!inline_02001bdc(c)) {
                            var0 = Enum_020042a8_B_2048;
                            break;
                        }
                        var16 = var16 * 10 + (c - '0');
                        if (var8 > 0x7fff)
                            *arg4 = 1;
                        c = fetch();

                        break;
                }
            } break;
        }
    }

    if (var0 != Enum_020042a8_B_32768 ? !success(var0) : !hex_success(count, var1)) {
        count          = 0;
        *arg3 = 0;
    } else {
        count--;
        *arg3 = count + var3;
    }

    unfetch(c);
    if (var1 == Enum_020042a8_C_0) {
        if (var7)
            var8 = -var8;

        {
            int            n = d.sig.length;
            unsigned char* p = &d.sig.text[n];

            while (n-- && *--p == '0')
                var9++;

            d.sig.length = (unsigned char)(n + 1);

            if (d.sig.length == 0)
                d.sig.text[d.sig.length++] = '0';
        }

        var8 += var9;

        if (var8 < ~0x7fff || var8 > 0x7fff)
            *arg4 = 1;

        if (*arg4)
            if (var7)
                return (0.0);
            else
                return (var6 ? -HUGE_VAL : HUGE_VAL);

        d.unknown_2_ = (short)var8;

        result = func_0200a3a8(&d);

        if (result != 0.0 && result < LDBL_MIN) {
            *arg4 = 1;
        } else if (result > LDBL_MAX) {
            *arg4 = 1;
            result    = HUGE_VAL;
        }

        if (var6 && success(var0))
            result = -result;

        return (result);
    } else {
        unsigned       var31, var32;
        unsigned       var33;
        long double    var34;
        unsigned char* var35 = (unsigned char*)&var34;

        if (var21)
            var16 = -var16;

        var16 += var22 * 4;

        var33 = 0;
        while (var33 < 4 && !(var14[0] & (0x80 >> var33))) {
            var33++;
            var16--;
        }
        var16--;

        if (TARGET_FLOAT_IMPLICIT_J_BIT) {
            var33++;
        }

        if (var33) {
            unsigned char var36 = 0;
            for (var13 = var14 + sizeof(var14) - 1; var13 >= var14; var13--) {
                unsigned char a = *var13;
                *var13          = (unsigned char)((a << var33) | var36);
                var36           = (unsigned char)(a >> (8 - var33));
            }
        }

        var35[0] = 0;
        var35[1] = 0;
        var35[2] = 0;
        var35[3] = 0;
        var35[4] = 0;
        var35[5] = 0;
        var35[6] = 0;
        var35[7] = 0;

        var32 = (TARGET_FLOAT_BITS - TARGET_FLOAT_MANT_BITS);

        for (var31 = 0; var31 < TARGET_FLOAT_MANT_BITS; var31 += 8) {
            unsigned char var38 = var14[var31 >> 3];
            int           var39;

            if (var31 + 8 > TARGET_FLOAT_MANT_BITS)
                var38 &= 0xff << (TARGET_FLOAT_MANT_BITS - var31);

            var39 = (var32 & 7);
            var35[var32 >> 3] |= (unsigned char)(var38 >> var39);

            var32 += 8;
            var35[var32 >> 3] |= (unsigned char)(var38 << (8 - var39));
        }

        var16 += TARGET_FLOAT_MAX_EXP - 1;

        if ((var16 & ~(TARGET_FLOAT_MAX_EXP * 2 - 1))) {
            *arg4 = 1;
            return 0.0;
        }

        var16 <<= 32 - TARGET_FLOAT_EXP_BITS;

        var35[0] |= var16 >> 25;
        if (TARGET_FLOAT_EXP_BITS > 7)
            var35[1] |= var16 >> 17;
        if (TARGET_FLOAT_EXP_BITS > 15)
            var35[2] |= var16 >> 9;
        if (TARGET_FLOAT_EXP_BITS > 23)
            var35[3] |= var16 >> 1;

        if (var6)
            var35[0] |= 0x80;

        int            i;
        unsigned char* c = var35;
        unsigned char  var42;
        for (i = 0; i < TARGET_FLOAT_BYTES / 2; i++) {
            var42                          = c[i];
            c[i]                          = c[TARGET_FLOAT_BYTES - 1 - i];
            c[TARGET_FLOAT_BYTES - 1 - i] = var42;
        }

        result = *(long double*)var35;

        return result;
    }
}
