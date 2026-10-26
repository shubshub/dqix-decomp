#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
extern "C" void* func_ov004_02168f08(void* ctx, int value);
#else
extern "C" void* func_ov023_021f6524(void* ctx, int value);
#endif
extern "C" int func_ov023_021f9bc8(char* obj);
struct Struct_ov004_0216950c;
extern "C" void func_ov004_021695fc(struct Struct_ov004_0216950c* obj);
extern "C" void func_ov004_0216920c(void* obj);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" int func_ov004_02169adc(void* obj);

extern void* data_ov004_02171030;

struct Struct_ov004_0216950c_2 { char pad[0x5c]; short unknown_5c_; short unknown_5e_; };

// USA: func_ov004_0216950c
extern "C" ARM int func_ov004_0216950c(void* obj) {
#if defined(jpn)
    unsigned char* table = *(unsigned char**)((char*)data_ov004_02171030 + 0x10);
#else
    unsigned char* table = *(unsigned char**)((char*)data_ov004_02171030 + 0x190);
#endif
    if (!table) return 0;

#if defined(jpn)
    struct Struct_ov004_0216950c_2* node = (struct Struct_ov004_0216950c_2*)func_ov004_02168f08(obj, 0x64);
#else
    struct Struct_ov004_0216950c_2* node = (struct Struct_ov004_0216950c_2*)func_ov023_021f6524(obj, 0x64);
#endif
    short var2 = node->unknown_5c_;
    unsigned char *cur, *next;
    int idx = func_ov023_021f9bc8((char*)node) + var2 * 8;
    cur = table + 4 + idx * 0x2c;
    next = table + 4 + (idx + 1) * 0x2c;
    func_ov004_021695fc((struct Struct_ov004_0216950c*)cur);

    int n = 0x2c;
    for (; idx < table[0]; idx++) {
        memcpy(cur, next, n);
        cur += n;
        next += n;
    }

    unsigned char var7 = --table[0];
    unsigned char* last = table + 4 + var7 * 0x2c;
    func_ov004_021695fc((struct Struct_ov004_0216950c*)last);

    if (table[0] <= 8) {
        node->unknown_5c_ = 0;
        node->unknown_5e_ = 1;
    }
    func_ov004_0216920c(obj);

    if (table[0] == 0) {
        func_ov011_021848a0(obj, 0x66);
        return 0;
    }
    func_ov004_02169adc(obj);
    return 0;
}
