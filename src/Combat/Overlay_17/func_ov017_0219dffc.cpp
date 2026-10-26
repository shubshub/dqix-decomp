#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_0219dffc_2824 = 0x8f8 };
#else
enum { Enum_ov017_0219dffc_2824 = 0xb08 };
#endif

// USA: func_ov017_0219dffc
extern "C" ARM void func_ov017_0219dffc(void* obj, int val) {
    *(int*)((char*)obj + 0x2000 + Enum_ov017_0219dffc_2824) = val;
}
