#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_0218b628_1744 = 0x4c0 };
#else
enum { Enum_ov017_0218b628_1744 = 0x6d0 };
#endif

extern "C" int func_02020084(unsigned char* base, int bit);

struct Struct_ov017_021d82e0_6 { int a; int b; };
extern Struct_ov017_021d82e0_6 data_ov017_021d82e0;

// USA: func_ov017_0218b628
extern "C" ARM int func_ov017_0218b628(signed char bit) {
    int b = data_ov017_021d82e0.b;
    if (b == 0) return 0;
    int val = *(int*)((char*)b + 0x3000 + Enum_ov017_0218b628_1744);
    if (val == 0) return 0;
    return func_02020084((unsigned char*)val, bit);
}
