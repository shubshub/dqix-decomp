#include <globaldefs.h>

struct Struct_020d3084;
struct Struct_020d30b4;
struct Struct_020d3108;
extern "C" void func_020d3084(Struct_020d3084* sink, int c);
extern "C" void func_020d30b4(Struct_020d30b4* sink, char value, int count);
extern "C" void func_020d3108(Struct_020d3108* sink, char* src, int count);

struct Struct_020d3160 {
    unsigned long len;
    char* cur;
    char* base;
};

static inline void inline_020d3160(Struct_020d3160* p, char c) {
    func_020d3084((Struct_020d3084*)p, c);
}

static inline void inline_020d3160_2(Struct_020d3160* p, char c, int n) {
    func_020d30b4((Struct_020d30b4*)p, c, n);
}

static inline void inline_020d3160_3(Struct_020d3160* p, const char* s, int n) {
    func_020d3108((Struct_020d3108*)p, (char*)s, n);
}

#define va_arg(list, ty) (*(ty*)((list += 4) - 4))
#define va_arg_64(list, ty) (*(ty*)((list += 8) - 8))

typedef unsigned long long Type_020b11c8_2;
typedef unsigned int u32;

// USA: func_020d3160
extern "C" ARM int func_020d3160(char* dst, unsigned long len, const char* fmt, char* arg3) {
    char buf[24];
    int var1;
    char prefix[2];
    int var3;

    const char* s = fmt;

    struct Struct_020d3160 str;
    str.len = len, str.cur = str.base = dst;

    while (*s) {
        if ((unsigned int)(((unsigned char)*s ^ 0x20) - 0xA1) < 0x3C) {
            inline_020d3160(&str, *s++);
            if (*s)
                inline_020d3160(&str, *s++);
        } else if (*s != '%') {
            inline_020d3160(&str, *s++);
        } else {
            enum {
                Enum_020d3160_1 = 000001,
                Enum_020d3160_2 = 000002,
                Enum_020d3160_4 = 000004,
                Enum_020d3160_8 = 000010,
                Enum_020d3160_16 = 000020,
                Enum_020d3160_32 = 000040,
                Enum_020d3160_64 = 000100,
                Enum_020d3160_128 = 000200,
                Enum_020d3160_256 = 000400,
                Enum_020d3160_4096 = 010000,
                Enum_020d3160_4097
            };

            int flag = 0, width = 0, var8 = -1, var9 = 10;
            char var10 = 'a' - 10;
            const char* var11 = s;

            for (;;) {
                switch (*++s) {
                case '+':
                    if (s[-1] != ' ')
                        break;
                    flag |= Enum_020d3160_2;
                    continue;
                case ' ':
                    flag |= Enum_020d3160_1;
                    continue;
                case '-':
                    flag |= Enum_020d3160_8;
                    continue;
                case '0':
                    flag |= Enum_020d3160_16;
                    continue;
                }
                break;
            }

            if (*s == '*') {
                ++s, width = va_arg(arg3, int);
                if (width < 0)
                    width = -width, flag |= Enum_020d3160_8;
            } else {
                while ((*s >= '0') && (*s <= '9'))
                    width = (width * 10) + *s++ - '0';
            }

            if (*s == '.') {
                ++s, var8 = 0;
                if (*s == '*') {
                    ++s, var8 = va_arg(arg3, int);
                    if (var8 < 0)
                        var8 = -1;
                } else {
                    while ((*s >= '0') && (*s <= '9'))
                        var8 = (var8 * 10) + *s++ - '0';
                }
            }

            switch (*s) {
            case 'h':
                if (*++s != 'h')
                    flag |= Enum_020d3160_64;
                else
                    ++s, flag |= Enum_020d3160_256;
                break;
            case 'l':
                if (*++s != 'l')
                    flag |= Enum_020d3160_32;
                else
                    ++s, flag |= Enum_020d3160_128;
                break;
            }

            switch (*s) {
            case 'd':
            case 'i':
                goto put_integer;
            case 'o':
                var9 = 8;
                flag |= Enum_020d3160_4096;
                goto put_integer;
            case 'u':
                flag |= Enum_020d3160_4096;
                goto put_integer;
            case 'X':
                var10 = 'A' - 10;
                goto put_hexadecimal;
            case 'x':
                goto put_hexadecimal;
            case 'p':
                flag |= Enum_020d3160_4;
                var8 = 8;
                goto put_hexadecimal;
            case 'c':
                if (var8 >= 0)
                    goto put_invalid;
                {
                    int c = va_arg(arg3, int);
                    width -= 1;
                    if (flag & Enum_020d3160_8) {
                        inline_020d3160(&str, (char)c);
                        inline_020d3160_2(&str, ' ', width);
                    } else {
                        int pad = (flag & Enum_020d3160_16) ? '0' : ' ';
                        inline_020d3160_2(&str, pad, width);
                        inline_020d3160(&str, (char)c);
                    }
                    ++s;
                }
                break;
            case 's': {
                int var14 = 0;
                const char* var15 = va_arg(arg3, const char*);
                if (var8 < 0) {
                    while (var15[var14])
                        ++var14;
                } else {
                    while ((var14 < var8) && var15[var14])
                        ++var14;
                }
                width -= var14;
                if (flag & Enum_020d3160_8) {
                    inline_020d3160_3(&str, var15, var14);
                    inline_020d3160_2(&str, ' ', width);
                } else {
                    int pad = (flag & Enum_020d3160_16) ? '0' : ' ';
                    inline_020d3160_2(&str, pad, width);
                    inline_020d3160_3(&str, var15, var14);
                }
                ++s;
            } break;
            case 'n': {
                int pos = str.cur - str.base;
                if (flag & Enum_020d3160_256)
                    ;
                else if (flag & Enum_020d3160_64)
                    *va_arg(arg3, signed short*) = (signed short)pos;
                else if (flag & Enum_020d3160_128)
                    *va_arg(arg3, Type_020b11c8_2*) = (Type_020b11c8_2)pos;
                else
                    *va_arg(arg3, signed int*) = (signed int)pos;
            }
                ++s;
                break;
            case '%':
                if (var11 + 1 != s)
                    goto put_invalid;
                inline_020d3160(&str, *s++);
                break;
            default:
                goto put_invalid;
            put_invalid:
                inline_020d3160_3(&str, var11, s - var11);
                break;
            put_hexadecimal:
                var9 = 16;
                flag |= Enum_020d3160_4096;
            put_integer: {
                Type_020b11c8_2 val = 0;
                var3 = 0;

                if (flag & Enum_020d3160_8)
                    flag &= ~Enum_020d3160_16;
                if (var8 < 0)
                    var8 = 1;
                else
                    flag &= ~Enum_020d3160_16;

                if (flag & Enum_020d3160_4096) {
                    if (flag & Enum_020d3160_256)
                        val = va_arg(arg3, unsigned char);
                    else if (flag & Enum_020d3160_64)
                        val = va_arg(arg3, unsigned short);
                    else if (flag & Enum_020d3160_128)
                        val = va_arg_64(arg3, Type_020b11c8_2);
                    else
                        val = va_arg(arg3, unsigned long);
                    flag &= ~(Enum_020d3160_2 | Enum_020d3160_1);
                    if (flag & Enum_020d3160_4) {
                        if (var9 == 16) {
                            if (val != 0) {
                                prefix[0] = (char)(var10 + (10 + 'x' - 'a'));
                                prefix[1] = '0';
                                var3 = 2;
                            }
                        } else if (var9 == 8) {
                            prefix[0] = '0';
                            var3 = 1;
                        }
                    }
                } else {
                    if (flag & Enum_020d3160_256)
                        val = va_arg(arg3, char);
                    else if (flag & Enum_020d3160_64)
                        val = va_arg(arg3, short);
                    else if (flag & Enum_020d3160_128)
                        val = va_arg_64(arg3, Type_020b11c8_2);
                    else
                        val = va_arg(arg3, long);
                    if ((val >> 32) & 0x80000000) {
                        val = ~val + 1;
                        prefix[0] = '-';
                        var3 = 1;
                    } else {
                        if (val || var8) {
                            if (flag & Enum_020d3160_2) {
                                prefix[0] = '+';
                                var3 = 1;
                            } else if (flag & Enum_020d3160_1) {
                                prefix[0] = ' ';
                                var3 = 1;
                            }
                        }
                    }
                }

                var1 = 0;
                switch (var9) {
                case 8:
                    while (val != 0) {
                        int d = (int)(val & 0x07);
                        val >>= 3;
                        buf[var1++] = (char)(d + '0');
                    }
                    break;
                case 10:
                    if ((val >> 32) == 0) {
                        u32 v = (u32)val;
                        while (v != 0) {
                            u32 r = v / 10;
                            int d = (int)(v - (r * 10));
                            v = r;
                            buf[var1++] = (char)(d + '0');
                        }
                    } else {
                        while (val != 0) {
                            Type_020b11c8_2 r = val / 10;
                            int d = (int)(val - (r * 10));
                            val = r;
                            buf[var1++] = (char)(d + '0');
                        }
                    }
                    break;
                case 16:
                    while (val != 0) {
                        int d = (int)(val & 0x0f);
                        val >>= 4;
                        buf[var1++] = (char)((d < 10) ? (d + '0') : (d + var10));
                    }
                    break;
                }

                if ((var3 > 0) && (prefix[0] == '0')) {
                    var3 = 0;
                    buf[var1++] = '0';
                }
            }
                goto put_to_stream;

            put_to_stream: {
                int var26 = var8 - var1;
                if (flag & Enum_020d3160_16) {
                    if (var26 < width - var1 - var3)
                        var26 = width - var1 - var3;
                }

                if (var26 > 0)
                    width -= var26;
                width -= var3 + var1;

                if (!(flag & Enum_020d3160_8))
                    inline_020d3160_2(&str, ' ', width);

                while (var3 > 0)
                    inline_020d3160(&str, prefix[--var3]);
                inline_020d3160_2(&str, '0', var26);

                while (var1 > 0)
                    inline_020d3160(&str, buf[--var1]);

                if (flag & Enum_020d3160_8)
                    inline_020d3160_2(&str, ' ', width);
                ++s;
            } break;
            }
        }
    }

    if (str.len > 0) {
        *str.cur = '\0';
    } else if (len > 0) {
        str.base[len - 1] = '\0';
    }

    return str.cur - str.base;
}
