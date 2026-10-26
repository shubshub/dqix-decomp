#include <globaldefs.h>

extern "C" void func_ov023_021db2e4(volatile int* p);

#if defined(jpn)
enum { Enum_ov023_021dca88_1844 = 0x6b0, Enum_ov023_021dca88_1848 = 0x6b4, Enum_ov023_021dca88_1910 = 0x6f2, Enum_ov023_021dca88_1779 = 0x6f3 };
#else
enum { Enum_ov023_021dca88_1844 = 0x734, Enum_ov023_021dca88_1848 = 0x738, Enum_ov023_021dca88_1910 = 0x776, Enum_ov023_021dca88_1911 = 0x777 };
#endif

struct Struct_ov023_021dca88 {
    unsigned char unknown0[Enum_ov023_021dca88_1844];
    int unknown_734_;
    int unknown_738_[7];
    unsigned char unknown_754_[Enum_ov023_021dca88_1910 - Enum_ov023_021dca88_1848 - 7 * sizeof(int)];
    unsigned char state;
    unsigned char flag;
};

// USA: func_ov023_021dca88
extern "C" ARM void func_ov023_021dca88(void* obj) {
    Struct_ov023_021dca88* var0 = (Struct_ov023_021dca88*)obj;
    if (var0->state == 2) return;
    func_ov023_021db2e4(&var0->unknown_734_);
    for (int i = 0; i < 7; i++) {
        func_ov023_021db2e4(&var0->unknown_738_[i]);
    }
    var0->state = 2;
    var0->flag = 0;
}
