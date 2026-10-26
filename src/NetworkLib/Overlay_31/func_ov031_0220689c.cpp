#include <globaldefs.h>

extern "C" void func_ov031_022033e8(void);

struct Struct_ov031_0220689c { char pad[0x73]; signed char unknown_73_; };

// USA: func_ov031_0220689c
extern "C" ARM int func_ov031_0220689c(void* obj) {
    struct Struct_ov031_0220689c* p = *(struct Struct_ov031_0220689c**)((char*)obj + 4);
    int var1 = 1;
    signed char v = p->unknown_73_;
    if (v != 0 && v != 4) {
        var1 = 0;
    }
    if (var1) {
        func_ov031_022033e8();
    }
    return 0;
}
