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

// USA: func_ov017_02191b70
extern "C" ARM void func_ov017_02191b70(void* resources) {
    Struct_ov017_02191b70* var0 = (Struct_ov017_02191b70*)resources;
    Struct_ov017_02191b70_2* entry = var0->entries;
    for (int index = 0; index < 4; ++index) {
        entry->pending = 0;
        entry->value = 0;
        ++entry;
    }
}
