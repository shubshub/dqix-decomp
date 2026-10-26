#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_02199480_14012 = 0x34ac };
#else
enum { Enum_ov017_02199480_14012 = 0x36bc };
#endif

extern "C" void func_020a87cc(void);

// USA: func_ov017_02199480
extern "C" ARM void func_ov017_02199480(void* obj) {
    if (*(int*)((char*)obj + Enum_ov017_02199480_14012)) func_020a87cc();
}
