#include <globaldefs.h>

union Struct_020026b4 {
    struct {
        unsigned char unknown1_0_;
        char unused;
        short unknown_2_;
        unsigned char length;
        unsigned char text[32];
    };
    unsigned short halfwords[19];
};

extern "C" void func_020098fc(Struct_020026b4* d, const char* str, short arg2);
extern "C" void func_02009778(Struct_020026b4* result, const Struct_020026b4* x, const Struct_020026b4* y);

extern const char data_020eef74[];
extern const char data_020eefa4[];
extern const char data_020eefcc[];
extern const char data_020eefe4[];
extern const char data_020eeff4[];
extern const char data_020eeffc[];
extern const char data_020ef004[];
extern const char data_020ef00c[];
extern const char data_020ef014[];
extern const char data_020ef018[];
extern const char data_020ef01c[];
extern const char data_020ef020[];
extern const char data_020ef024[];
extern const char data_020ef028[];
extern const char data_020ef02c[];
extern const char data_020ef030[];
extern const char data_020ef034[];
extern const char data_020ef038[];
extern const char data_020ef03c[];
extern const char data_020ef040[];
extern const char data_020ef044[];

// USA: func_02009998
extern "C" ARM void func_02009998(Struct_020026b4* result, long arg1) {
    switch (arg1) {
        case -64:
            func_020098fc(result, data_020eef74, -20);
            return;
        case -53:
            func_020098fc(result, data_020eefa4, -16);
            return;
        case -32:
            func_020098fc(result, data_020eefcc, -10);
            return;
        case -16:
            func_020098fc(result, data_020eefe4, -5);
            return;
        case -8:
            func_020098fc(result, data_020eeff4, -3);
            return;
        case -7:
            func_020098fc(result, data_020eeffc, -3);
            return;
        case -6:
            func_020098fc(result, data_020ef004, -2);
            return;
        case -5:
            func_020098fc(result, data_020ef00c, -2);
            return;
        case -4:
            func_020098fc(result, data_020ef014, -2);
            return;
        case -3:
            func_020098fc(result, data_020ef018, -1);
            return;
        case -2:
            func_020098fc(result, data_020ef01c, -1);
            return;
        case -1:
            func_020098fc(result, data_020ef020, -1);
            return;
        case 0:
            func_020098fc(result, data_020ef024, 0);
            return;
        case 1:
            func_020098fc(result, data_020ef028, 0);
            return;
        case 2:
            func_020098fc(result, data_020ef02c, 0);
            return;
        case 3:
            func_020098fc(result, data_020ef030, 0);
            return;
        case 4:
            func_020098fc(result, data_020ef034, 1);
            return;
        case 5:
            func_020098fc(result, data_020ef038, 1);
            return;
        case 6:
            func_020098fc(result, data_020ef03c, 1);
            return;
        case 7:
            func_020098fc(result, data_020ef040, 2);
            return;
        case 8:
            func_020098fc(result, data_020ef044, 2);
            return;
    }

    {
        Struct_020026b4 x2, var1;

        func_02009998(&x2, ((long)((0x80000000UL & arg1) >> 31) + arg1) >> 1);
        func_02009778(result, &x2, &x2);

        if (arg1 & 1) {
            var1 = *result;

            if (arg1 > 0) {
                func_020098fc(&x2, data_020ef028, 0);
            } else {
                func_020098fc(&x2, data_020ef020, -1);
            }

            func_02009778(result, &var1, &x2);
        }
    }
}
