#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* func_0206a3c0(void* arg0, int arg1);
extern "C" int func_02005a94(char* arg0);

char* FindUnescapedAngleBracket_020424ac(char* str);
int IsPrefixMatch020d857c(signed char* a, signed char* b);
int StringStartsWithCI020d85dc(const char* str, const char* prefix);
int STD_GetStringLength(const char* s);

struct Struct_020e7f84 {
    const char* unknown_0_;
    int (*unknown_4_)(char**, char*);
};

extern struct Struct_020e7f84 data_020e7f84[];

struct Struct_020e7e74 {
    char* unknown_0_[6];
};
extern struct Struct_020e7e74 data_020e7e74;
extern char data_020f091b[];
extern char data_020f092a[];
extern char data_020f092f[];
struct Struct_020e7e04_2 {
    char unknown_0_[0x24];
    unsigned short unknown_24_[2];
};
extern struct Struct_020e7e04_2 data_020e7e04;

struct Struct_02069fec {
    char unknown_0_[0x94a];
    unsigned char unknown_94a_[4];
    char unknown_94e_[0x86];
    unsigned char unknown_9d4_;
};

struct Struct_02069fec_2 {
    char unknown_0_[0x1000];
    struct Struct_02069fec unknown_1000_;
};

// USA: func_02069fec
extern "C" ARM void func_02069fec(struct Struct_02069fec_2* arg0, int arg1, char* arg2) {
    unsigned short var0;
    char* var1;
    if (arg1 == 0 || arg2 == 0) return;
    char* var2 = arg2;
    var1 = (char*)func_0206a3c0(arg0, arg1);
    arg0->unknown_1000_.unknown_9d4_ = 1;
    unsigned short var3 = 0;

    for (;;) {
        signed char var4 = *var1;
        if (var4 == 0) break;

        if ((var4 == '\\' && var1[1] == 'n') || (var4 == '\r' && var1[1] == '\n')) {
            unsigned short var5 = 0xff18;
            memcpy(var2, &var5, 2);
            var1 += 2;
            var2 += 2;
            continue;
        }
        if (var4 == '\n') {
            unsigned short var6 = 0xff18;
            memcpy(var2, &var6, 2);
            var1 += 1;
            var2 += 2;
            continue;
        }
        if (c == '<') {
            char* close = FindUnescapedAngleBracket_020424ac(src);
            if (close != 0) {
                char* arg = src + 1;
                int matched = 0;
                struct TagEntry02069fec* e = data_020e7f84;
                while (e->name != 0 && e->fn != 0) {
                    if (StringStartsWithCI020d85dc(arg, e->name)) {
                        int len = STD_GetStringLength(e->name);
                        int n = e->fn(&out, arg + len);
                        out += n;
                        src = close + 1;
                        matched = 1;
                        break;
                    }
                    var10++;
                }
                if (var9) continue;

                {
                    struct Struct_020e7e74 var13 = data_020e7e74;
                    char** var14 = var13.unknown_0_;
                    while (*var14 != 0) {
                        if (func_020d857c((signed char*)var1, (signed char*)*var14)) {
                            while (*var1 != '>') { var1++; }
                            var1++;
                            break;
                        }
                        var14++;
                    }
                }

                if (func_020d857c((signed char*)var1, (signed char*)data_020f091b)) {
                    int var15 = 0xe;
                    int var16 = func_02005a94(var1 + 0xe);
                    while (var1[var15] != '>') {
                        if (var1[var15] == 0) return;
                        var15++;
                    }
                    arg0->unknown_1000_.unknown_94a_[var3] = (unsigned char)var16;
                    unsigned short var17 = var3 + 0x4d + 0xff00;
                    memcpy(var2, &var17, 2);
                    var1 += var15 + 1;
                    var2 += 2;
                    var3 = (unsigned short)(var3 + 1) & 3;
                    continue;
                }
                if (func_020d857c((signed char*)var1, (signed char*)data_020f092a)) {
                    int var18 = 4;
                    int var19 = func_02005a94(var1 + 4);
                    while (var1[var18] != '>') {
                        if (var1[var18] == 0) return;
                        var18++;
                    }
                    unsigned short var20 = var19 + 0x334 + 0xfc00;
                    memcpy(var2, &var20, 2);
                    var1 += var18 + 1;
                    var2 += 2;
                    continue;
                }
                if (func_020d857c((signed char*)var1, (signed char*)data_020f092f)) {
                    int var21 = 4;
                    int var22 = func_02005a94(var1 + 4);
                    while (var1[var21] != '>') {
                        if (var1[var21] == 0) return;
                        var21++;
                    }
                    short var23[2];
                    var23[0] = data_020e7e04.unknown_24_[0];
                    var23[1] = data_020e7e04.unknown_24_[1];
                    unsigned short var24 = 0xff4b;
                    unsigned short var25 = 0;
                    while (var23[var25] >= 0) {
                        if (var22 == var23[var25]) {
                            var24 += var25;
                            break;
                        }
                        var25++;
                    }
                    unsigned short var26 = var24;
                    memcpy(var2, &var26, 2);
                    var1 += var21 + 1;
                    var2 += 2;
                    continue;
                }
            }
        }
        *var2 = *var1;
        var1++;
        var2++;
    }
    var0 = 0xff01;
    memcpy(var2, &var0, 2);
    var2 += 2;
    *var2 = 0;
}
