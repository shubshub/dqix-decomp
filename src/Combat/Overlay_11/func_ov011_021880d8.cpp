#include <globaldefs.h>

extern "C" {
    void* func_ov017_021b2164(void);
    void MapVRAMBanksToMainBG(void* p);
}

struct Struct_ov011_021880d8 {
    char pad[0x1d4];
    void* unknown_1d4_;
};

// USA: func_ov011_021880d8
extern "C" ARM int func_ov011_021880d8(void) {
    Struct_ov011_021880d8* obj = (Struct_ov011_021880d8*)func_ov017_021b2164();
    MapVRAMBanksToMainBG(obj->unknown_1d4_);
    return 1;
}
