#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

#if defined(jpn)
enum { Enum_ov003_02160ec4_1124 = 0x28c };
enum { Enum_ov003_02160ec4_1191 = 0x2cf };
#else
enum { Enum_ov003_02160ec4_1124 = 0x464 };
enum { Enum_ov003_02160ec4_1191 = 0x4a7 };
#endif

// USA: func_ov003_02160ec4
extern "C" ARM void func_ov003_02160ec4(void* p) {
    char* obj = (char*)p;
    if (!(*(int*)(obj + Enum_ov003_02160ec4_1124) & 0x1000)) return;
    unsigned char state = *(unsigned char*)(obj + Enum_ov003_02160ec4_1191);
    if (state == 0) {
        FontBankLoader* g = FontBankLoader_GetInstance();
        func_02094b34(g, 0x1f5, 0x66, 0, 0);
        *(unsigned char*)(obj + Enum_ov003_02160ec4_1191) = *(unsigned char*)(obj + Enum_ov003_02160ec4_1191) + 1;
    } else if (state == 1) {
        if (func_02094b4c(FontBankLoader_GetInstance()) != 0) {
            *(int*)(obj + Enum_ov003_02160ec4_1124) &= ~0x1000;
            *(unsigned char*)(obj + Enum_ov003_02160ec4_1191) = *(unsigned char*)(obj + Enum_ov003_02160ec4_1191) + 1;
        }
    }
}
