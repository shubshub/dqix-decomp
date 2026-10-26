#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov000_02161318_1096 = 0x488 };
#else
enum { Enum_ov000_02161318_1096 = 0x448 };
#endif

// USA: func_ov000_02161318
extern "C" ARM void* func_ov000_02161318(void* obj, int id) {
    int var0 = (id >= 0 && id <= 3) ? 1 : 0;
    if (var0) {
        for (int i = 0; i < 4; i++) {
            int cur = *(int*)((char*)obj + i * Enum_ov000_02161318_1096 + 0x9a4);
            if (id == cur) {
                return (char*)obj + 0x958 + i * Enum_ov000_02161318_1096;
            }
        }
    }
    return 0;
}
