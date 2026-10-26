#include <globaldefs.h>

union Struct_020026b4 {
    struct {
        char unknown1_0_;
        char unused;
        short unknown_2_;
        unsigned char length;
        unsigned char text[32];
    };
    unsigned short halfwords[19];
};

extern "C" double func_02008da4(double x, double y);
extern "C" double func_020091d8(double x, int n);
extern "C" double func_020095a4(double x, double y);
extern "C" void func_020098fc(Struct_020026b4* d, const char* str, short arg2);
extern "C" int func_02009d1c(const Struct_020026b4* x, const Struct_020026b4* y);
extern "C" int func_02009dfc(const Struct_020026b4* x, const Struct_020026b4* y);
extern "C" void func_02009edc(Struct_020026b4* z, const Struct_020026b4* x, const Struct_020026b4* y);
extern "C" void func_0200a180(Struct_020026b4* d, double x);
extern "C" int func_0200aa74(double x);

extern float data_020eecc4;
extern double data_020eef34[];
extern const char data_020ef048[];

// USA: func_0200a3a8
extern "C" ARM double func_0200a3a8(const Struct_020026b4* d) {
    if (d->length <= 0) {
        return func_02008da4(0.0, d->unknown1_0_ == 0 ? 1.0 : -1.0);
    }

    switch (d->text[0]) {
        case '0':
            return func_02008da4(0.0, d->unknown1_0_ == 0 ? 1.0 : -1.0);
        case 'I':
            return func_02008da4(data_020eecc4, d->unknown1_0_ == 0 ? 1.0 : -1.0);
        case 'N': {
            double result;
            unsigned long long* var1 = (unsigned long long*)&result;

            *var1 = 0x7FF0000000000000ULL;
            if (d->unknown1_0_) {
                *var1 |= 0x8000000000000000ULL;
            }
            *var1 |= 0x0008000000000000ULL;
            return result;
        }
    }

    {
        Struct_020026b4 var2 = *d;
        unsigned char* i = var2.text;
        unsigned char* e = i + var2.length;
        double var5;
        int var6;

        for (; i < e; ++i) {
            *i -= '0';
        }

        var2.unknown_2_ += var2.length - 1;
        var6 = var2.unknown_2_;

        {
            Struct_020026b4 max;
            func_020098fc(&max, data_020ef048, 308);
            if (func_02009dfc(&max, &var2)) {
                return func_02008da4(data_020eecc4, d->unknown1_0_ == 0 ? 1.0 : -1.0);
            }
        }

        i = var2.text;
        var5 = *i++;

        while (i < e) {
            unsigned long var8 = 0;
            int j;
            double var10, temp2;
            int var12 = (e - i) % 8;

            if (var12 == 0) {
                var12 = 8;
            }

            for (j = 0; j < var12; ++j, ++i) {
                var8 = var8 * 10 + *i;
            }

            var10 = var5 * data_020eef34[var12 - 1];
            temp2 = var10 + var8;
            if (var8 != 0 && var10 == temp2) {
                break;
            }
            var5 = temp2;
            var6 -= var12;
        }

        if (var6 < 0) {
            var5 /= func_020095a4(5.0, -var6);
        } else {
            var5 *= func_020095a4(5.0, var6);
        }

        var5 = func_020091d8(var5, var6);

        if (func_0200aa74(var5) == 2) {
            var5 = 1.7976931348623157e+308;
        }

        {
            Struct_020026b4 var13, var14, var15, var16;
            double var17;
            unsigned long long* var18 = (unsigned long long*)&var17;
            int var19 = 0;

            func_0200a180(&var13, var5);

            if (func_02009d1c(&var13, &var2)) {
                goto done;
            }

            if (func_02009dfc(&var13, &var2)) {
                var19 = 1;
            }

            var17 = var5;

            while (1) {
                if (var19) {
                    ++*var18;
                    if (func_0200aa74(var17) == 2) {
                        goto done;
                    }
                } else {
                    --*var18;
                }

                func_0200a180(&var14, var17);

                if (var19 && !func_02009dfc(&var14, &var2)) {
                    break;
                } else if (!var19 && !func_02009dfc(&var2, &var14)) {
                    var15 = var13;
                    var13 = var14;
                    var14 = var15;
                    {
                        double var20 = var5;
                        var5 = var17;
                        var17 = var20;
                    }
                    break;
                }

                var13 = var14;
                var5 = var17;
            }

            func_02009edc(&var15, &var2, &var13);
            func_02009edc(&var16, &var14, &var2);

            if (func_02009d1c(&var15, &var16)) {
                if (*(unsigned long long*)&var5 & 1) {
                    var5 = var17;
                }
            } else if (!func_02009dfc(&var15, &var16)) {
                var5 = var17;
            }
        }

    done:
        if (var2.unknown1_0_) {
            var5 = -var5;
        }

        return var5;
    }
}
