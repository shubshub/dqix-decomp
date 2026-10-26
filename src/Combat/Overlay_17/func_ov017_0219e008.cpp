#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_0219e008_2824 = 0x8f8 };
#else
enum { Enum_ov017_0219e008_2824 = 0xb08 };
#endif

// USA: func_ov017_0219e008
extern "C" ARM int func_ov017_0219e008(void* obj) {
    return *(int*)((char*)obj + 0x2000 + Enum_ov017_0219e008_2824);
}
