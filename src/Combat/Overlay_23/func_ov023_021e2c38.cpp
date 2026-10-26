#include <globaldefs.h>

struct Struct_ov023_021e2c38 {
    char pad0[0xc];
    short f0xc;
    char pad1[0x10 - 0xe];
    short unknown_10_;
    char pad2[0x16 - 0x12];
    unsigned char unknown_16_;
};

extern "C" struct Struct_ov023_021e2c38* func_ov023_021db4e4(void*);

// USA: func_ov023_021e2c38
extern "C" ARM int func_ov023_021e2c38(void* obj) {
    int result = 1;
    struct Struct_ov023_021e2c38* entry = func_ov023_021db4e4(obj);
    int var2 = 0;
    int var3 = result;
    while (entry != 0) {
        result = (entry->unknown_16_ & 1) ? var3 : var2;
        if (result == 0) break;
        while (entry->unknown_10_ > 0) {
            entry = func_ov023_021db4e4(obj);
        }
        if (entry->f0xc >= 0) {
            entry = func_ov023_021db4e4(obj);
        }
    }
    return result;
}
