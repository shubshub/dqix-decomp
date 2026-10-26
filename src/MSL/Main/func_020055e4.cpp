#include <globaldefs.h>

extern const unsigned short data_020e69ac[128];
extern const unsigned char data_020e692c[128];

static inline int inline_020055e4(int c) {
    return ((c < 0) || (c >= 128)) ? 0 : (int)(data_020e69ac[c] & 0x001);
}

static inline int inline_020055e4_2(int c) {
    return ((c < 0) || (c >= 128)) ? 0 : (int)(data_020e69ac[c] & 0x008);
}

static inline int inline_020055e4_3(int c) {
    return ((c < 0) || (c >= 128)) ? 0 : (int)(data_020e69ac[c] & 0x100);
}

static inline int inline_020055e4_4(int c) {
    return ((c < 0) || (c >= 128)) ? c : (int)(data_020e692c[c]);
}

enum Enum_020055e4 {
    Enum_020055e4_1 = 0x01,
    Enum_020055e4_2 = 0x02,
    Enum_020055e4_4 = 0x04,
    Enum_020055e4_8 = 0x08,
    Enum_020055e4_16 = 0x10,
    Enum_020055e4_32 = 0x20,
    Enum_020055e4_64 = 0x40
};

typedef int (*Type_020055e4)(void* arg, int c, int action);

// USA: func_020055e4
extern "C" ARM unsigned long func_020055e4(int base, int arg1, Type_020055e4 arg2, void* arg3,
                                           int* arg4, int* arg5, int* arg6) {
    int var0 = Enum_020055e4_1;
    int count = 0;
    int var2 = 0;
    unsigned long value = 0;
    unsigned long var4 = 0;
    int c;

    *arg5 = *arg6 = 0;

    if (base < 0 || base == 1 || base > 36 || arg1 < 1)
        var0 = Enum_020055e4_64;
    else
        c = (count++, arg2(arg3, 0, 0));

    if (base)
        var4 = 0xffffffff / base;

    while (count <= arg1 && c != -1 && !(var0 & (Enum_020055e4_32 | Enum_020055e4_64))) {
        switch (var0) {
            case Enum_020055e4_1:
                if (inline_020055e4_3(c)) {
                    c = (count++, arg2(arg3, 0, 0));
                    count--;
                    var2++;
                    break;
                }

                if (c == '+')
                    c = (count++, arg2(arg3, 0, 0));
                else if (c == '-') {
                    c = (count++, arg2(arg3, 0, 0));
                    *arg5 = 1;
                }

                var0 = Enum_020055e4_2;
                break;

            case Enum_020055e4_2:
                if (base == 0 || base == 16) {
                    if (c == '0') {
                        var0 = Enum_020055e4_4;
                        c = (count++, arg2(arg3, 0, 0));
                        break;
                    }
                }

                var0 = Enum_020055e4_8;
                break;

            case Enum_020055e4_4:
                if (c == 'X' || c == 'x') {
                    base = 16;
                    var0 = Enum_020055e4_8;
                    c = (count++, arg2(arg3, 0, 0));
                    break;
                }

                if (base == 0)
                    base = 8;

                var0 = Enum_020055e4_16;
                break;

            case Enum_020055e4_8:
            case Enum_020055e4_16:
                if (base == 0)
                    base = 10;

                if (!var4)
                    var4 = 0xffffffff / base;

                if (inline_020055e4_2(c)) {
                    if ((c -= '0') >= base) {
                        if (var0 == Enum_020055e4_16)
                            var0 = Enum_020055e4_32;
                        else
                            var0 = Enum_020055e4_64;

                        c += '0';
                        break;
                    }
                } else if (!inline_020055e4(c) || (inline_020055e4_4(c) - 'A' + 10) >= base) {
                    if (var0 == Enum_020055e4_16)
                        var0 = Enum_020055e4_32;
                    else
                        var0 = Enum_020055e4_64;

                    break;
                } else
                    c = inline_020055e4_4(c) - 'A' + 10;

                if (value > var4)
                    *arg6 = 1;

                value *= base;

                if (c > (0xffffffff - value))
                    *arg6 = 1;

                value += c;

                var0 = Enum_020055e4_16;

                c = (count++, arg2(arg3, 0, 0));
                break;
        }
    }

    if (!(var0 & (Enum_020055e4_4 | Enum_020055e4_16 | Enum_020055e4_32))) {
        count = 0;
        value = 0;
        *arg4 = 0;
    } else {
        count--;
        *arg4 = count + var2;
    }

    arg2(arg3, c, 1);

    return value;
}
