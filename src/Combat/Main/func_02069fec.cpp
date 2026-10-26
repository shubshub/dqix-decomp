#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* func_0206a3c0(void* ctx, int msgId);
extern "C" int func_02005a94(char* str);

extern "C" char* func_020424ac(char* str);
extern "C" int func_020d857c(signed char* a, signed char* b);
extern "C" int func_020d85dc(const char* str, const char* prefix);
extern "C" int STD_GetStringLength(const char* s);

struct Struct_020e7f84 {
    const char* name;
    int (*fn)(char**, char*);
};

extern struct Struct_020e7f84 data_020e7f84[];

struct Struct_020e7e74 {
    char* p[6];
};
extern struct Struct_020e7e74 data_020e7e74;
extern char data_020f091b[];
extern char data_020f092a[];
extern char data_020f092f[];
struct Struct_020e7e04_2 {
    char pad0[0x24];
    unsigned short ids[2];
};
extern struct Struct_020e7e04_2 data_020e7e04;

struct Struct_02069fec {
    char pad0[0x94a];
    unsigned char unknown_94a_[4];
    char pad1[0x86];
    unsigned char unknown_9d4_;
};

struct Struct_02069fec_2 {
    char pad0[0x1000];
    struct Struct_02069fec sub;
};

// USA: func_02069fec
extern "C" ARM void func_02069fec(struct Struct_02069fec_2* ctx, int msgId, char* arg2) {
    unsigned short var0;
    char* src;
    if (msgId == 0 || arg2 == 0) return;
    char* out = arg2;
    src = (char*)func_0206a3c0(ctx, msgId);
    ctx->sub.unknown_9d4_ = 1;
    unsigned short depth = 0;

    for (;;) {
        signed char c = *src;
        if (c == 0) break;

        if ((c == '\\' && src[1] == 'n') || (c == '\r' && src[1] == '\n')) {
            unsigned short code = 0xff18;
            memcpy(out, &code, 2);
            src += 2;
            out += 2;
            continue;
        }
        if (c == '\n') {
            unsigned short code = 0xff18;
            memcpy(out, &code, 2);
            src += 1;
            out += 2;
            continue;
        }
        if (c == '<') {
            char* close = func_020424ac(src);
            if (close != 0) {
                char* arg = src + 1;
                int matched = 0;
                struct Struct_020e7f84* e = data_020e7f84;
                while (e->name != 0 && e->fn != 0) {
                    if (func_020d85dc(arg, e->name)) {
                        int len = STD_GetStringLength(e->name);
                        int n = e->fn(&out, arg + len);
                        out += n;
                        src = close + 1;
                        matched = 1;
                        break;
                    }
                    e++;
                }
                if (matched) continue;

                {
                    struct Struct_020e7e74 names = data_020e7e74;
                    char** var14 = names.p;
                    while (*var14 != 0) {
                        if (func_020d857c((signed char*)src, (signed char*)*var14)) {
                            while (*src != '>') { src++; }
                            src++;
                            break;
                        }
                        var14++;
                    }
                }

                if (func_020d857c((signed char*)src, (signed char*)data_020f091b)) {
                    int r7 = 0xe;
                    int id = func_02005a94(src + 0xe);
                    while (src[r7] != '>') {
                        if (src[r7] == 0) return;
                        r7++;
                    }
                    ctx->sub.unknown_94a_[depth] = (unsigned char)id;
                    unsigned short code = depth + 0x4d + 0xff00;
                    memcpy(out, &code, 2);
                    src += r7 + 1;
                    out += 2;
                    depth = (unsigned short)(depth + 1) & 3;
                    continue;
                }
                if (func_020d857c((signed char*)src, (signed char*)data_020f092a)) {
                    int r7 = 4;
                    int val = func_02005a94(src + 4);
                    while (src[r7] != '>') {
                        if (src[r7] == 0) return;
                        r7++;
                    }
                    unsigned short code = val + 0x334 + 0xfc00;
                    memcpy(out, &code, 2);
                    src += r7 + 1;
                    out += 2;
                    continue;
                }
                if (func_020d857c((signed char*)src, (signed char*)data_020f092f)) {
                    int r7 = 4;
                    int val = func_02005a94(src + 4);
                    while (src[r7] != '>') {
                        if (src[r7] == 0) return;
                        r7++;
                    }
                    short ids[2];
                    ids[0] = data_020e7e04.ids[0];
                    ids[1] = data_020e7e04.ids[1];
                    unsigned short result = 0xff4b;
                    unsigned short k = 0;
                    while (ids[k] >= 0) {
                        if (val == ids[k]) {
                            result += k;
                            break;
                        }
                        k++;
                    }
                    unsigned short code = result;
                    memcpy(out, &code, 2);
                    src += r7 + 1;
                    out += 2;
                    continue;
                }
            }
        }
        *out = *src;
        src++;
        out++;
    }
    var0 = 0xff01;
    memcpy(out, &var0, 2);
    out += 2;
    *out = 0;
}
