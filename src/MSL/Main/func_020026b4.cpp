#include <globaldefs.h>
#include <string.h>

#define TARGET_FLOAT_BITS 64
#define TARGET_FLOAT_BYTES (TARGET_FLOAT_BITS / 8)
#define TARGET_FLOAT_MAX_EXP 128
#define TARGET_FLOAT_MANT_DIG 53
#define TARGET_FLOAT_IMPLICIT_J_BIT 1
#define TARGET_FLOAT_MANT_BITS (TARGET_FLOAT_MANT_DIG - TARGET_FLOAT_IMPLICIT_J_BIT)
#define TARGET_FLOAT_EXP_BITS (TARGET_FLOAT_BITS - TARGET_FLOAT_MANT_BITS - 1)

enum Enum_02001bdc_C {
    Enum_02001bdc_C_0_4,
    Enum_02001bdc_C_1_4,
    Enum_02001bdc_C_2_4
};

enum Enum_02001bdc {
    Enum_02001bdc_0_4,
    Enum_02001bdc_1_4,
    Enum_02001bdc_2_4
};

enum Enum_02001bdc_B {
    Enum_02001bdc_B_0_2,
    Enum_02001bdc_B_1_2,
    Enum_02001bdc_B_2_2,
    Enum_02001bdc_B_3_2,
    Enum_02001bdc_B_4_2,
    Enum_02001bdc_B_5_2,
    Enum_02001bdc_B_6_2,
    Enum_02001bdc_B_7_2,
    Enum_02001bdc_B_8_2,
    Enum_02001bdc_B_9_2
};

typedef struct {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned char unknown_4_;
    unsigned char unknown_5_;
    int unknown_8_;
    int unknown_c_;
} Struct_02001bdc;

#define conversion_max 509

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

typedef struct Struct_020026b4_2 {
    char style;
    char unused;
    short digits;
} Struct_020026b4_2;

extern "C" void func_0200a300(const Struct_020026b4_2* f, double x, Struct_020026b4* d);
extern "C" double func_02008f3c(double x);
extern "C" char* func_0200216c(long num, char* arg1, Struct_02001bdc format);

static inline long double inline_020026b4(long double x) {
    return (long double)func_02008f3c((double)x);
}

extern const unsigned short data_020e69ac[128];

static inline int inline_02002cb4(int c) {
    return ((c < 0) || (c >= 128)) ? 0 : (int)(data_020e69ac[c] & 0x200);
}

static inline int inline_02001bdc(int c) {
    return ((c < 0) || (c >= 128)) ? 0 : (int)(data_020e69ac[c] & 0x008);
}

// USA: func_020026b4
extern "C" ARM char* func_020026b4(long double num, char* arg1, Struct_02001bdc format) {
    char*          p;
    unsigned char* q;
    unsigned char  var2;
    long double    var3;
    int            var4, var5;
    unsigned       var6;
    long           var7;
    Struct_02001bdc   var8;
    int            var9;
    int            var10;
    Struct_020026b4_2        form;
    Struct_020026b4        var12;
    int            var13;

    var13 = '.';
    p            = arg1;
    var3           = num;

    if (format.unknown_c_ > conversion_max) {
        return 0;
    }

    form.style  = (char)0;
    form.digits = 0x20;
    func_0200a300(&form, num, &var12);

    if (inline_020026b4(num) == 0.0) {
        p = arg1 - 6;
        strcpy(p, "0x0p0");
        return p;
    }

    if (*var12.sig.text == 'I') {
        if (var12.unknown_0_) {
            p = arg1 - 5;
            if (format.unknown_5_ == 'A') {
                strcpy(p, "-INF");
            } else {
                strcpy(p, "-inf");
            }
        } else {
            p = arg1 - 4;
            if (format.unknown_5_ == 'A') {
                strcpy(p, "INF");
            } else {
                strcpy(p, "inf");
            }
        }
        return p;
    } else if (*var12.sig.text == 'N') {
        if (var12.unknown_0_) {
            p = arg1 - 5;
            if (format.unknown_5_ == 'A') {
                strcpy(p, "-NAN");
            } else {
                strcpy(p, "-nan");
            }
        } else {
            p = arg1 - 4;
            if (format.unknown_5_ == 'A') {
                strcpy(p, "NAN");
            } else {
                strcpy(p, "nan");
            }
        }
        return p;
    }

    var8.unknown_0_ = Enum_02001bdc_C_1_4;
    var8.unknown_1_          = Enum_02001bdc_1_4;
    var8.unknown_2_   = 0;
    var8.unknown_3_        = 0;
    var8.unknown_4_      = Enum_02001bdc_B_0_2;
    var8.unknown_8_           = 0;
    var8.unknown_c_             = 1;
    var8.unknown_5_       = 'd';

    int   i;
    char* var15 = (char*)&num;
    for (i = 0; i < TARGET_FLOAT_BYTES / 2; i++) {
        char x                           = var15[i];
        var15[i]                          = var15[TARGET_FLOAT_BYTES - i - 1];
        var15[TARGET_FLOAT_BYTES - i - 1] = x;
    }

    var4 = TARGET_FLOAT_EXP_BITS;
    var5 = 0x7FF;

    var6 = ((unsigned char*)&num)[0] << 25;
    if (TARGET_FLOAT_EXP_BITS > 7) {
        var6 |= ((unsigned char*)&num)[1] << 17;
    }
    if (TARGET_FLOAT_EXP_BITS > 15) {
        var6 |= ((unsigned char*)&num)[2] << 9;
    }
    if (TARGET_FLOAT_EXP_BITS > 23) {
        var6 |= ((unsigned char*)&num)[3] << 1;
    }

    var6 = (var6 >> (32 - var4)) & var5;
    var7  = var6 - 0x3FF;

    p = func_0200216c(var7, arg1, var8);
    if (format.unknown_5_ == 'a') {
        *--p = 'p';
    } else {
        *--p = 'P';
    }
    q = (unsigned char*)&num;

    if (TARGET_FLOAT_IMPLICIT_J_BIT) {
        var10 = (1 + var4 + format.unknown_c_ * 4) - 1;
    } else {
        var10 = (1 + var4 + format.unknown_c_ * 4) - 4;
    }

    for (var9 = format.unknown_c_; var9 >= 1; var9--) {
        if (var10 < 64) {
            int var17;

            var17 = var10 >> 3;
            var2  = (*(q + var17)) >> (7 - (var10 & 7));

            if ((var10 & ~7) != ((var10 - 4) & ~7)) {
                var2 |= ((*(q + (var17 - 1))) << 8) >> (7 - ((var10) & 7));
            }

            if (!TARGET_FLOAT_IMPLICIT_J_BIT) {
                if (var10 == 1 + var4) {
                    *--p = var13;
                    var2 &= 0x1;
                }
            }

            if ((var2 &= 0xF) < 10) {
                var2 += '0';
            } else if (format.unknown_5_ == 'a') {
                var2 += 'a' - 10;
            } else {
                var2 += 'A' - 10;
            }
        } else {
            var2 = '0';
        }

        *--p = var2;
        var10 -= 4;
    }

    if (TARGET_FLOAT_IMPLICIT_J_BIT) {
        if (format.unknown_c_ || format.unknown_3_) {
            *--p = var13;
        }
        *--p = '1';
    }

    if (format.unknown_5_ == 'a') {
        *--p = 'x';
    } else {
        *--p = 'X';
    }

    *--p = '0';

    if (var12.unknown_0_) {
        *--p = '-';
    } else if (format.unknown_1_ == Enum_02001bdc_1_4) {
        *--p = '+';
    } else if (format.unknown_1_ == Enum_02001bdc_2_4) {
        *--p = ' ';
    }

    return p;
}

// USA: func_02002b90
extern "C" ARM void func_02002b90(Struct_020026b4* arg0, int arg1) {
    char  c;
    char* p;
    int   var2;

    if (arg1 < 0) {
    return_zero:
        arg0->unknown_2_        = 0;
        arg0->sig.length = 1;
        *arg0->sig.text  = '0';
        return;
    }

    if (arg1 >= arg0->sig.length) {
        return;
    }

    p = (char*)arg0->sig.text + arg1 + 1;
    c = *--p - '0';

    if (c == 5) {
        char* q = &((char*)arg0->sig.text)[arg0->sig.length];

        while (--q > p && *q == '0')
            ;
        var2 = (q == p) ? p[-1] & 1 : 1;
    } else {
        var2 = (c > 5);
    }

    while (arg1 != 0) {
        c = *--p - '0' + var2;

        if ((var2 = (c > 9)) != 0 || c == 0) {
            --arg1;
        } else {
            *p = c + '0';
            break;
        }
    }

    if (var2 != 0) {
        arg0->unknown_2_ += 1;
        arg0->sig.length = 1;
        *arg0->sig.text  = '1';
        return;
    } else if (arg1 == 0) {
        goto return_zero;
    }

    arg0->sig.length = arg1;
}

// USA: func_02002cb4
extern "C" ARM char* func_02002cb4(long double num, char* arg1, Struct_02001bdc format) {
    Struct_020026b4 var0;
    Struct_020026b4_2 form;
    char*   p;
    char* q;
    int   n, digits, var6;
    int   var7, var8;
    int   var9;

    var9 = '.';

    if (format.unknown_c_ > conversion_max) {
        return 0;
    }

    form.style  = 0;
    form.digits = 0x20;
    func_0200a300(&form, num, &var0);
    p = (char*)var0.sig.text + var0.sig.length;

    while (var0.sig.length > 1 && *--p == '0') {
        --var0.sig.length;
        ++var0.unknown_2_;
    }

    switch (*var0.sig.text) {
        case '0':
            var0.unknown_2_ = 0;
            break;
        case 'I':
            if (num < 0) {
                p = arg1 - 5;

                if (inline_02002cb4(format.unknown_5_)) {
                    strcpy(p, "-INF");
                } else {
                    strcpy(p, "-inf");
                }
            } else {
                p = arg1 - 4;
                if (inline_02002cb4(format.unknown_5_)) {
                    strcpy(p, "INF");
                } else {
                    strcpy(p, "inf");
                }
            }

            return p;

        case 'N':
            if (var0.unknown_0_) {
                p = arg1 - 5;
                if (inline_02002cb4(format.unknown_5_)) {
                    strcpy(p, "-NAN");
                } else {
                    strcpy(p, "-nan");
                }
            } else {
                p = arg1 - 4;
                if (inline_02002cb4(format.unknown_5_)) {
                    strcpy(p, "NAN");
                } else {
                    strcpy(p, "nan");
                }
            }

            return p;
    }

    var0.unknown_2_ += var0.sig.length - 1;
    p    = arg1;
    *--p = 0;

    switch (format.unknown_5_) {
        case 'g':
        case 'G':

            if (var0.sig.length > format.unknown_c_) {
                func_02002b90(&var0, format.unknown_c_);
            }

            if (var0.unknown_2_ < -4 || var0.unknown_2_ >= format.unknown_c_) {
                if (format.unknown_3_) {
                    --format.unknown_c_;
                } else {
                    format.unknown_c_ = var0.sig.length - 1;
                }

                if (format.unknown_5_ == 'g') {
                    format.unknown_5_ = 'e';
                } else {
                    format.unknown_5_ = 'E';
                }

                goto e_format;
            }

            if (format.unknown_3_) {
                format.unknown_c_ -= var0.unknown_2_ + 1;
            } else {
                if ((format.unknown_c_ = var0.sig.length - (var0.unknown_2_ + 1)) < 0) {
                    format.unknown_c_ = 0;
                }
            }

            goto f_format;

        case 'e':
        case 'E':
        e_format:

            if (var0.sig.length > format.unknown_c_ + 1) {
                func_02002b90(&var0, format.unknown_c_ + 1);
            }

            n    = var0.unknown_2_;
            var6 = '+';

            if (n < 0) {
                n    = -n;
                var6 = '-';
            }

            for (digits = 0; n || digits < 2; ++digits) {
                *--p = n % 10 + '0';
                n /= 10;
            }

            *--p = var6;
            *--p = format.unknown_5_;

            if (arg1 - p + format.unknown_c_ > conversion_max) {
                return 0;
            }

            if (var0.sig.length < format.unknown_c_ + 1) {
                for (n = format.unknown_c_ + 1 - var0.sig.length + 1; --n;) {
                    *--p = '0';
                }
            }

            for (n = var0.sig.length, q = (char*)var0.sig.text + var0.sig.length; --n;) {
                *--p = *--q;
            }

            if (format.unknown_c_ || format.unknown_3_) {
                *--p = var9;
            }

            *--p = *var0.sig.text;

            if (var0.unknown_0_) {
                *--p = '-';
            } else if (format.unknown_1_ == Enum_02001bdc_1_4) {
                *--p = '+';
            } else if (format.unknown_1_ == Enum_02001bdc_2_4) {
                *--p = ' ';
            }

            break;

        case 'f':
        case 'F':
        f_format:

            if ((var8 = -var0.unknown_2_ + var0.sig.length - 1) < 0) {
                var8 = 0;
            }

            if (var8 > format.unknown_c_) {
                func_02002b90(&var0, var0.sig.length - (var8 - format.unknown_c_));

                if ((var8 = -var0.unknown_2_ + var0.sig.length - 1) < 0) {
                    var8 = 0;
                }
            }

            if ((var7 = var0.unknown_2_ + 1) < 0) {
                var7 = 0;
            }

            if (var7 + var8 > conversion_max) {
                return 0;
            }

            q = (char*)var0.sig.text + var0.sig.length;

            for (digits = 0; digits < (format.unknown_c_ - var8); ++digits) {
                *--p = '0';
            }

            for (digits = 0; digits < var8 && digits < var0.sig.length; ++digits) {
                *--p = *--q;
            }

            for (; digits < var8; ++digits) {
                *--p = '0';
            }

            if (format.unknown_c_ || format.unknown_3_) {
                *--p = var9;
            }

            if (var7) {
                for (digits = 0; digits < var7 - var0.sig.length; ++digits) {
                    *--p = '0';
                }

                for (; digits < var7; ++digits) {
                    *--p = *--q;
                }
            } else {
                *--p = '0';
            }

            if (var0.unknown_0_) {
                *--p = '-';
            } else if (format.unknown_1_ == Enum_02001bdc_1_4) {
                *--p = '+';
            } else if (format.unknown_1_ == Enum_02001bdc_2_4) {
                *--p = ' ';
            }

            break;
    }

    return p;
}
