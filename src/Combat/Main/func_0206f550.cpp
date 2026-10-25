#include <globaldefs.h>

int STD_GetStringLength(const char* s);
extern "C" int memcmp(void* a, void* b, int n);
extern "C" int func_02005a94(void* p);

extern char* data_020f0afc[];

struct Struct_0206f550 {
    unsigned char unknown_0_[4];
    int unknown_4_;
    short unknown_8_[4];
};

// USA: func_0206f550
extern "C" ARM int func_0206f550(struct Struct_0206f550* arg0, char* arg1, char* arg2) {
    unsigned char* var0 = (unsigned char*)arg1;
    int var1;
    char* var2;
    int var3;
    unsigned char var4;
    unsigned char var5;
    char** var6;

    if (in == 0) return 0;
    if (out == 0) return 0;
    s->count = 0;
    while ((c = *p) != 0) {
        if (c == '<') {
            found = 0;
            if (s->count < 4) {
                i = 1;
                tab = data_020f0afc;
                while (i < 13) {
                    tag = tab[i];
                    len = STD_GetStringLength(tag);
                    if (memcmp(p, tag, len) == 0) {
                        if (i == 4 || (unsigned char)(i + 0xff) <= 1) {
                            p += len;
                            s->vals[s->count] = (short)func_02005a94(p);
                        }
                        var1 = 1;
                        arg0->unknown_0_[arg0->unknown_4_] = var4;
                        arg0->unknown_4_++;
                        break;
                    }
                    var4++;
                }
            }
            if (var1) {
                while ((var5 = *var0) != '>') {
                    if (var5 == 0) return arg0->unknown_4_;
                    var0++;
                }
                var0++;
            } else {
                while ((var5 = *var0) != '>') {
                    *arg2 = var5;
                    var5 = *var0;
                    if (var5 == 0) return arg0->unknown_4_;
                    var0++;
                    arg2++;
                }
                *arg2++ = var5;
                var0++;
            }
        } else {
            if ((var5 >= 0x81 && var5 <= 0x9f) || (var5 >= 0xe0 && var5 <= 0xea)) {
                *arg2++ = var5;
                var0++;
            }
            *arg2++ = *var0++;
        }
    }
    return arg0->unknown_4_;
}
