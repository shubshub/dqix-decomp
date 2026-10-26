#include <globaldefs.h>

enum Enum_02001bdc_C {
    Enum_02001bdc_C_0_2,
    Enum_02001bdc_C_1_2,
    Enum_02001bdc_C_2_2
};

enum Enum_02001bdc {
    Enum_02001bdc_0_2,
    Enum_02001bdc_1_2,
    Enum_02001bdc_2_2
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

// USA: func_0200216c
extern "C" ARM char*func_0200216c(long num, char* arg1, Struct_02001bdc format) {
    unsigned long var0, base;
    char*         p;
    int           n, digits;
    int           var5 = 0;
    var0        = num;
    var5               = 0;

    p      = arg1;
    *--p   = 0;
    digits = 0;

    if (!num && !format.unknown_c_ && !(format.unknown_3_ && format.unknown_5_ == 'o')) {
        return p;
    }

    switch (format.unknown_5_) {
        case 'd':
        case 'i':
            base = 10;

            if (num < 0) {
                if (num != 0x80000000) {
                    var0 = -num;
                }

                var5 = 1;
            }
            break;

        case 'o':
            base                = 8;
            format.unknown_1_ = Enum_02001bdc_0_2;
            break;

        case 'u':
            base                = 10;
            format.unknown_1_ = Enum_02001bdc_0_2;
            break;

        case 'x':
        case 'X':
            base                = 16;
            format.unknown_1_ = Enum_02001bdc_0_2;
            break;
    }

    do {
        n = var0 % base;
        var0 /= base;

        if (n < 10) {
            n += '0';
        } else {
            n -= 10;

            if (format.unknown_5_ == 'x') {
                n += 'a';
            } else {
                n += 'A';
            }
        }

        *--p = n;
        ++digits;
    } while (var0 != 0);

    if (base == 8 && format.unknown_3_ && *p != '0') {
        *--p = '0';
        ++digits;
    }

    if (format.unknown_0_ == Enum_02001bdc_C_2_2) {
        format.unknown_c_ = format.unknown_8_;

        if (var5 || format.unknown_1_ != Enum_02001bdc_0_2) {
            --format.unknown_c_;
        }

        if (base == 16 && format.unknown_3_) {
            format.unknown_c_ -= 2;
        }
    }

    if (arg1 - p + format.unknown_c_ > conversion_max) {
        return 0;
    }

    while (digits < format.unknown_c_) {
        *--p = '0';
        ++digits;
    }

    if (base == 16 && format.unknown_3_) {
        *--p = format.unknown_5_;
        *--p = '0';
    }

    if (var5) {
        *--p = '-';
    } else if (format.unknown_1_ == Enum_02001bdc_1_2) {
        *--p = '+';
    } else if (format.unknown_1_ == Enum_02001bdc_2_2) {
        *--p = ' ';
    }

    return p;
}
