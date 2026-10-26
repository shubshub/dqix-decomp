#include <globaldefs.h>

extern "C" unsigned short GetSubBGVRAMBanks(void);

struct Struct_ov011_02184c14 {
    char pad[0x1d8];
    unsigned int unknown_1d8_;
};

// USA: func_ov011_02184c14
extern "C" ARM void func_ov011_02184c14(Struct_ov011_02184c14* obj) {
    obj->unknown_1d8_ = GetSubBGVRAMBanks();
}
