#include <globaldefs.h>
#include "std_library_functions.h"
#include "NitroSDK/Cache.h"

extern "C" void* func_020a6084(void);
extern "C" int LoadToMainObjStandardPalette(int arg0, int arg1, unsigned int arg2);

// USA: func_ov002_0215af64
extern "C" ARM void func_ov002_0215af64(char* p) {
#if defined(jpn)
    enum { Enum_ov002_0215af64_7168 = 0x1a00, Enum_ov002_0215af64_6 = 0xce, Enum_ov002_0215af64_3032 = 0xaa0 };
#else
    enum { Enum_ov002_0215af64_7168 = 0x1c00, Enum_ov002_0215af64_6 = 0x6, Enum_ov002_0215af64_3032 = 0xbd8 };
#endif
    short idx = *(short*)(p + Enum_ov002_0215af64_7168 + Enum_ov002_0215af64_6);
    void* buf = *(void**)(p + 0x1000 + Enum_ov002_0215af64_3032);
    unsigned char var2 = (unsigned char)idx;
    int base = (int)func_020a6084();
    memcpy(buf, (void*)(base + (var2 << 5) + 0x1e), 2);
    CleanInvalidateCacheRange(buf, 2);
    LoadToMainObjStandardPalette((int)buf, 0x11e, 2);
}
