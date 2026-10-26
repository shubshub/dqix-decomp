#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02160cc0_1124 = 0x28c };
#else
enum { Enum_ov003_02160cc0_1124 = 0x464 };
#endif

extern "C" int func_ov003_02160cf8(void* obj);
extern "C" int func_ov003_02160e34(void* obj);

// USA: func_ov003_02160cc0
extern "C" ARM int func_ov003_02160cc0(char* obj) {
    int flags = *(int*)(obj + Enum_ov003_02160cc0_1124);
    int result = 1;
    if (flags & 0x400) {
        result = func_ov003_02160cf8(obj);
    } else if (flags & 0x800) {
        result = func_ov003_02160e34(obj);
    }
    return result;
}
