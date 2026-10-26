#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021bd38c_288 = 0x11c, Enum_ov017_021bd38c_312 = 0x134 };
#else
enum { Enum_ov017_021bd38c_288 = 0x120, Enum_ov017_021bd38c_312 = 0x138 };
#endif

// USA: func_ov017_021bd38c
extern "C" ARM void func_ov017_021bd38c(void* obj, int a, int b) {
    *(int*)((char*)obj + Enum_ov017_021bd38c_288) = a;
    *(int*)((char*)obj + Enum_ov017_021bd38c_312) = b;
}
