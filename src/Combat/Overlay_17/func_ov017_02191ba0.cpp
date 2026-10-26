#include <globaldefs.h>

struct Struct_ov017_02191b70_2 {
    unsigned char pending;
    unsigned char unknown_1_;
    unsigned short value;
};

struct Struct_ov017_02191b70 {
#if defined(jpn)
    unsigned char unknown_0_[0x41ec];
#else
    unsigned char unknown1_0_[0x449c];
#endif
    Struct_ov017_02191b70_2 entries[4];
};

// USA: func_ov017_02191ba0
extern "C" ARM void func_ov017_02191ba0(char* resources, int index, int value) {
    int var0 = index >= 0 && index <= 3;
    if (!var0) return;
    Struct_ov017_02191b70* var1 = (Struct_ov017_02191b70*)resources;
    var1->entries[index].value = value;
    var1->entries[index].pending = 1;
}
