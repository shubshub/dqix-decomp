#include <globaldefs.h>
extern "C" int func_020de5b0(struct Struct_020de5b0*);

extern "C" void func_020de574(void);
extern "C" void func_020de714(void* a, void* b, unsigned char* out, void* fn);

// Main, originally CheckFlagOrFallback020de6c8 (USA 0x020de6c8, EUR 0x020de6d8, JPN 0x020e0044)
extern "C" ARM int ItemTable_LoadInPlace(void* obj, void* a, void* b) {
    unsigned char flag;
    if (a == NULL || b == NULL) return 0;
    func_020de714(obj, a, &flag, (void*)func_020de574);
    if (flag != 0) return 1;
    return func_020de5b0((struct Struct_020de5b0*)(obj));
}
