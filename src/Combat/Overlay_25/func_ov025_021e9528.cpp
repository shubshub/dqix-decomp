#include <globaldefs.h>

extern "C" int func_ov025_021ed2f4(void* obj);

// USA: func_ov025_021e9528
extern "C" ARM int func_ov025_021e9528(char* obj) {
    if (*(int*)(obj + 4) != 0) {
        return 0;
    }
    return func_ov025_021ed2f4(obj + 0x1e8 + 0x400) != 0;
}
