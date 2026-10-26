#include <globaldefs.h>

extern "C" void __clear(void*, int);
extern "C" void func_0206831c(void*, int, void*);
extern "C" void func_02068418(void*, void*, int, int);
extern "C" void func_02068f40(void*, int, void*, int);
extern "C" void func_02069234(void*, void*, int, int);
extern "C" void func_020695f4(void*, int, void*, int);
extern "C" void func_0206b974(void*, int, void*, int, int, int, int, int);

// Main, originally func_02046608 (USA 0x02046608, EUR 0x02046618; JPN not identified)
extern "C" ARM void MessageSystem_FormatText(void* a, int unused1, int b, int c, int d, int e, int f) {
    char buf[0x960];
    if (b != 0 && c != 0) {
        __clear(buf, 0x960);
        func_0206831c(a, b, buf);
        func_02068418(a, buf, c, f);
        func_02068f40(a, c, buf, f);
        func_02069234(a, buf, c, f);
        func_020695f4(a, c, buf, f);
        func_0206b974(a, 0, buf, c, d, e, 0, f);
    }
}
