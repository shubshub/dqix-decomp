#include <globaldefs.h>

enum Enum_02001bdc_C {
    Enum_02001bdc_C_0_3,
    Enum_02001bdc_C_1_3,
    Enum_02001bdc_C_2_3
};

enum Enum_02001bdc {
    Enum_02001bdc_0_3,
    Enum_02001bdc_1_3,
    Enum_02001bdc_2_3
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

// USA: func_020023b8
extern "C" ARM char*func_020023b8(long long num, char* arg1, Struct_02001bdc fmt) {
    unsigned long long var0, base;
    char*              p;
    int                n, digits;
    int                var5 = 0;
    var0             = num;
    var5                    = 0;
    p                        = arg1;
    *--p                     = 0;
    digits                   = 0;

    if (!num && !fmt.unknown_c_ && !(fmt.unknown_3_ && fmt.unknown_5_ == 'o')) {
        return p;
    }

    switch (fmt.unknown_5_) {
        case 'd':
        case 'i':
            base = 10;

            if (num < 0) {
                if (num != 0x8000000000000000) {
                    var0 = -num;
                }

                var5 = 1;
            }
            break;
        case 'o':
            base             = 8;
            fmt.unknown_1_ = Enum_02001bdc_0_3;
            break;
        case 'u':
            base             = 10;
            fmt.unknown_1_ = Enum_02001bdc_0_3;
            break;
        case 'x':
        case 'X':
            base             = 16;
            fmt.unknown_1_ = Enum_02001bdc_0_3;
            break;
    }

    do {
        n = var0 % base;
        var0 /= base;

        if (n < 10) {
            n += '0';
        } else {
            n -= 10;
            if (fmt.unknown_5_ == 'x') {
                n += 'a';
            } else {
                n += 'A';
            }
        }

        *--p = n;
        ++digits;
    } while (var0 != 0);

    if (base == 8 && fmt.unknown_3_ && *p != '0') {
        *--p = '0';
        ++digits;
    }

    if (fmt.unknown_0_ == Enum_02001bdc_C_2_3) {
        fmt.unknown_c_ = fmt.unknown_8_;

        if (var5 || fmt.unknown_1_ != Enum_02001bdc_0_3) {
            --fmt.unknown_c_;
        }

        if (base == 16 && fmt.unknown_3_) {
            fmt.unknown_c_ -= 2;
        }
    }

    if (arg1 - p + fmt.unknown_c_ > conversion_max) {
        return 0;
    }

    while (digits < fmt.unknown_c_) {
        *--p = '0';
        ++digits;
    }

    if (base == 16 && fmt.unknown_3_) {
        *--p = fmt.unknown_5_;
        *--p = '0';
    }

    if (var5) {
        *--p = '-';
    } else if (fmt.unknown_1_ == Enum_02001bdc_1_3) {
        *--p = '+';
    } else if (fmt.unknown_1_ == Enum_02001bdc_2_3) {
        *--p = ' ';
    }

    return p;
}
