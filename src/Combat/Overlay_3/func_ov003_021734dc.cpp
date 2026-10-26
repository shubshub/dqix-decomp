#include <globaldefs.h>

// USA: func_ov003_021734dc
extern "C" ARM int func_ov003_021734dc(int unused, int a, int b) {
#if defined(jpn)
    enum { Enum_ov003_021734dc_67 = 0x4f, Enum_ov003_021734dc_189 = 0xb1 };
#else
    enum { Enum_ov003_021734dc_67 = 0x43, Enum_ov003_021734dc_189 = 0xbd };
#endif
    if (a >= Enum_ov003_021734dc_67 && a <= Enum_ov003_021734dc_189 && b >= 0x5f && b <= 0x6f) return 1;
    return 0;
}
