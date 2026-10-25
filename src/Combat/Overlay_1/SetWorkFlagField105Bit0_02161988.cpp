#include <globaldefs.h>

extern "C" void* Zone3D_GetInstance(void);
extern "C" int func_ov017_021d60f4(void* obj);

// USA: func_ov001_02161988  (semantic: SetWorkFlagField105Bit0_02161988)
extern "C" ARM int func_ov001_02161988(void* obj) {
#if defined(jpn)
    enum { fieldOffset = 0x125 };
#else
    enum { fieldOffset = 0x105 };
#endif
    unsigned char* work = (unsigned char*)Zone3D_GetInstance();
    int cond = func_ov017_021d60f4(obj);
    if (cond != 0)
        work[fieldOffset] &= ~1;
    else
        work[fieldOffset] |= 1;
    return 1;
}
