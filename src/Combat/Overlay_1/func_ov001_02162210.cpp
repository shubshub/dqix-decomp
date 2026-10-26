#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" unsigned short func_ov017_021bbc04(void* obj);
extern "C" void func_ov017_021bbbec(void* obj, unsigned short v);
extern "C" void func_ov017_021bbbf8(void* obj, unsigned short v);

// USA: func_ov001_02162210
extern "C" ARM int func_ov001_02162210(void) {
#if defined(jpn)
    enum { Enum_ov001_02162210_1844 = 0x524 };
#else
    enum { Enum_ov001_02162210_1844 = 0x734 };
#endif
    unsigned char* self = (unsigned char*)GetGameResources();
    void* work = *(void**)(self + 0x3000 + Enum_ov001_02162210_1844);
    unsigned short val = func_ov017_021bbc04(work);
    if (val != 0) {
        func_ov017_021bbbec(work, val);
        func_ov017_021bbbf8(work, 0);
    }
    return 1;
}
