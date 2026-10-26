#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e62c8_12 = 0x4 };
#else
enum { Enum_ov025_021e62c8_12 = 0xc };
#endif

extern "C" void* func_ov000_02160130(void);
extern "C" int func_ov000_02162954(void* self);
extern "C" int func_ov025_021ed0fc(void* obj);
extern int data_ov025_021ef988;

// USA: func_ov025_021e62c8
extern "C" ARM int func_ov025_021e62c8(void) {
    void* p = *(void**)((char*)&data_ov025_021ef988 + Enum_ov025_021e62c8_12);
    if (!func_ov025_021ed0fc((char*)p + 0x22c)) return 0;
    void* w = func_ov000_02160130();
    int v = func_ov000_02162954(w);
    return v == 0;
}
