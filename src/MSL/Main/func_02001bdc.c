#include <globaldefs.h>

enum Enum_02001bdc_C {
    Enum_02001bdc_C_0,
    Enum_02001bdc_C_1,
    Enum_02001bdc_C_2
};

enum Enum_02001bdc {
    Enum_02001bdc_0,
    Enum_02001bdc_1,
    Enum_02001bdc_2
};

enum Enum_02001bdc_B {
    Enum_02001bdc_B_0,
    Enum_02001bdc_B_1,
    Enum_02001bdc_B_2,
    Enum_02001bdc_B_3,
    Enum_02001bdc_B_4,
    Enum_02001bdc_B_5,
    Enum_02001bdc_B_6,
    Enum_02001bdc_B_7,
    Enum_02001bdc_B_8,
    Enum_02001bdc_B_9
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
#define bad_conversion 0xFF

typedef char* Type_02001bdc;
#define __fourbytealign(n) ((((unsigned int)(n)) + 3U) & ~3U)
#define va_arg(ap, type) (*(type*)((ap += __fourbytealign(sizeof(type))) - __fourbytealign(sizeof(type))))

extern const unsigned short data_020e69ac[128];

static inline int inline_02001bdc(int c) {
    return ((c < 0) || (c >= 128)) ? 0 : (int)(data_020e69ac[c] & 0x008);
}

// USA: func_02001bdc
ARM const char* func_02001bdc(const char* arg0, Type_02001bdc* arg, Struct_02001bdc* format) {
    Struct_02001bdc f;
    const char*  s = arg0;
    int          c;
    int          var3;

    f.unknown_0_ = Enum_02001bdc_C_1;
    f.unknown_1_          = Enum_02001bdc_0;
    f.unknown_2_   = 0;
    f.unknown_3_        = 0;
    f.unknown_4_      = Enum_02001bdc_B_0;
    f.unknown_8_           = 0;
    f.unknown_c_             = 0;

    if ((c = *++s) == '%') {
        f.unknown_5_ = c;
        *format           = f;
        return ((const char*)s + 1);
    }

    while (1) {
        var3 = 1;

        switch (c) {
            case '-':
                f.unknown_0_ = Enum_02001bdc_C_0;
                break;

            case '+':
                f.unknown_1_ = Enum_02001bdc_1;
                break;

            case ' ':
                if (f.unknown_1_ != Enum_02001bdc_1) {
                    f.unknown_1_ = Enum_02001bdc_2;
                }
                break;

            case '#':
                f.unknown_3_ = 1;
                break;

            case '0':
                if (f.unknown_0_ != Enum_02001bdc_C_0) {
                    f.unknown_0_ = Enum_02001bdc_C_2;
                }
                break;

            default:
                var3 = 0;
                break;
        }

        if (var3) {
            c = *++s;
        } else {
            break;
        }
    }

    if (c == '*') {
        if ((f.unknown_8_ = va_arg(*arg, int)) < 0) {
            f.unknown_0_ = Enum_02001bdc_C_0;
            f.unknown_8_           = -f.unknown_8_;
        }

        c = *++s;
    } else {
        while (inline_02001bdc(c)) {
            f.unknown_8_ = (f.unknown_8_ * 10) + (c - '0');
            c             = *++s;
        }
    }

    if (f.unknown_8_ > conversion_max) {
        f.unknown_5_ = bad_conversion;
        *format           = f;
        return ((const char*)s + 1);
    }

    if (c == '.') {
        f.unknown_2_ = 1;

        if ((c = *++s) == '*') {
            if ((f.unknown_c_ = va_arg(*arg, int)) < 0) {
                f.unknown_2_ = 0;
            }

            c = *++s;
        } else {
            while (inline_02001bdc(c)) {
                f.unknown_c_ = (f.unknown_c_ * 10) + (c - '0');
                c           = *++s;
            }
        }
    }

    var3 = 1;

    switch (c) {
        case 'h':
            f.unknown_4_ = Enum_02001bdc_B_2;
            if (s[1] == 'h') {
                f.unknown_4_ = Enum_02001bdc_B_1;
                c                  = *++s;
            }
            break;
        case 'l':
            f.unknown_4_ = Enum_02001bdc_B_3;
            if (s[1] == 'l') {
                f.unknown_4_ = Enum_02001bdc_B_4;
                c                  = *++s;
            }
            break;
        case 'L':
            f.unknown_4_ = Enum_02001bdc_B_9;
            break;
        case 'j':
            f.unknown_4_ = Enum_02001bdc_B_6;
            break;
        case 't':
            f.unknown_4_ = Enum_02001bdc_B_8;
            break;
        case 'z':
            f.unknown_4_ = Enum_02001bdc_B_7;
            break;
        default:
            var3 = 0;
            break;
    }

    if (var3) {
        c = *++s;
    }

    f.unknown_5_ = c;

    switch (c) {
        case 'd':
        case 'i':
        case 'u':
        case 'o':
        case 'x':
        case 'X':
            if (f.unknown_4_ == Enum_02001bdc_B_9) {
                f.unknown_5_ = bad_conversion;
                break;
            }

            if (!f.unknown_2_) {
                f.unknown_c_ = 1;
            } else if (f.unknown_0_ == Enum_02001bdc_C_2) {
                f.unknown_0_ = Enum_02001bdc_C_1;
            }
            break;

        case 'f':
        case 'F':
            if (f.unknown_4_ == Enum_02001bdc_B_2 || f.unknown_4_ == Enum_02001bdc_B_6 ||
                f.unknown_4_ == Enum_02001bdc_B_7 || f.unknown_4_ == Enum_02001bdc_B_8 ||
                f.unknown_4_ == Enum_02001bdc_B_4)
            {
                f.unknown_5_ = bad_conversion;
                break;
            }

            if (!f.unknown_2_) {
                f.unknown_c_ = 6;
            }
            break;

        case 'a':
        case 'A':
            if (!f.unknown_2_) {
                f.unknown_c_ = 0x0D;
            }
            if (f.unknown_4_ == Enum_02001bdc_B_2 || f.unknown_4_ == Enum_02001bdc_B_6 ||
                f.unknown_4_ == Enum_02001bdc_B_7 || f.unknown_4_ == Enum_02001bdc_B_8 ||
                f.unknown_4_ == Enum_02001bdc_B_4 || f.unknown_4_ == Enum_02001bdc_B_1)
            {
                f.unknown_5_ = bad_conversion;
            }
            break;

        case 'g':
        case 'G':
            if (!f.unknown_c_) {
                f.unknown_c_ = 1;
            }

        case 'e':
        case 'E':
            if (f.unknown_4_ == Enum_02001bdc_B_2 || f.unknown_4_ == Enum_02001bdc_B_6 ||
                f.unknown_4_ == Enum_02001bdc_B_7 || f.unknown_4_ == Enum_02001bdc_B_8 ||
                f.unknown_4_ == Enum_02001bdc_B_4 || f.unknown_4_ == Enum_02001bdc_B_1)
            {
                f.unknown_5_ = bad_conversion;
                break;
            }

            if (!f.unknown_2_) {
                f.unknown_c_ = 6;
            }
            break;

        case 'p':
            f.unknown_5_  = 'x';
            f.unknown_3_   = 1;
            f.unknown_4_ = Enum_02001bdc_B_3;
            f.unknown_c_        = 8;
            break;

        case 'c':
            if (f.unknown_4_ == Enum_02001bdc_B_3) {
                f.unknown_4_ = Enum_02001bdc_B_5;
            } else if (f.unknown_2_ || f.unknown_4_ != Enum_02001bdc_B_0) {
                f.unknown_5_ = bad_conversion;
            }
            break;

        case 's':
            if (f.unknown_4_ == Enum_02001bdc_B_3) {
                f.unknown_4_ = Enum_02001bdc_B_5;
            } else if (f.unknown_4_ != Enum_02001bdc_B_0) {
                f.unknown_5_ = bad_conversion;
            }
            break;

        case 'n':
            if (f.unknown_4_ == Enum_02001bdc_B_9) {
                f.unknown_5_ = bad_conversion;
            }
            break;

        default:
            f.unknown_5_ = bad_conversion;
            break;
    }

    *format = f;

    return ((const char*)s + 1);
}
