#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/GameResources.h"

// USA: func_ov003_02160344
#if defined(jpn)
extern "C" ARM void func_ov003_02160344(char* obj) {
    char* base = (char*)GetGameResources() + 0x13c;
    int i = 0;
    base = base + 0x4000;
    for (; i < 4; i++) {
        int* arr = *(int**)(obj + 0x27c);
        if (arr == 0) return;
        int val = arr[i];
        if (val == 0) continue;
        char* dest = base + i * 0xc;
        if (dest != 0) {
            memcpy(dest, (const void*)val, 0xc);
        }
    }
}
#else
extern "C" ARM void func_ov003_02160344(char* obj) {
    char* base = (char*)GetGameResources() + 0x35c;
    int i = 0;
    base = base + 0x4000;
    for (; i < 4; i++) {
        int* arr = *(int**)(obj + 0x394);
        if (arr == 0) return;
        int val = arr[i];
        if (val == 0) continue;
        char* dest = base + i * 0x30;
        if (dest != 0) {
            sprintf(dest, (const char*)val);
        }
    }
}
#endif
