#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov000_02170c7c(void* obj);
extern "C" void func_0204bc08(void* a, int b, int size, void* src, int extra);
extern short data_ov000_021833a0[];

// USA: func_ov000_021750e4
extern "C" ARM void func_ov000_021750e4(char* obj) {
    char* elem;
    int i;
    for (i = 0; i < 4; i++) {
        int kind;
        signed char idx = *(signed char*)(obj + i + 0x6c);
#if defined(jpn)
        enum { Enum_ov000_021750e4_1096 = 0x488 };
#else
        enum { Enum_ov000_021750e4_1096 = 0x448 };
#endif
        elem = obj + 0x958 + idx * Enum_ov000_021750e4_1096;
        int cid = *(int*)(elem + 0x4c);
        int var5 = (cid >= 0 && cid <= 3) ? 1 : 0;
        if (!var5) continue;
        kind = 0;
        int code = func_ov000_02170c7c(elem);
        switch (code) {
        case 4: kind = 1; break;
        case 5: kind = 2; break;
        case 6: kind = 3; break;
        }
        memcpy(*(void**)(obj + 0x178), &data_ov000_021833a0[kind], 2);
        func_0204bc08(obj + 0x8c4, cid + 2, 0xa, *(void**)(obj + 0x178), 2);
    }
}
