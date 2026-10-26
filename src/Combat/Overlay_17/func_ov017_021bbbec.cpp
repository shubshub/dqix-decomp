#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021bbbec_282 = 0x116 };
#else
enum { Enum_ov017_021bbbec_282 = 0x11a };
#endif

// USA: func_ov017_021bbbec
extern "C" ARM void func_ov017_021bbbec(void* obj, unsigned short v) {
    *(unsigned short*)((char*)obj + Enum_ov017_021bbbec_282) = v;
}
