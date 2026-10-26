#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void* Zone3D_GetInstance(void);
extern "C" int func_020981e4(int a, int id);
extern "C" void* func_ov011_021845f8(void* a, int b);

struct Struct_ov004_021707e8_10 {
    char pad0[0xc];
    void* unknown_c_;
    char pad10[8];
    void* unknown_18_;
    char unknown_1c_[0xc];
    void* unknown_28_;
};

extern Struct_ov004_021707e8_10 data_ov004_021707e8;

static inline int GetZoneId(char* zone) { SDK_NULL_ASSERT(zone); return *(unsigned short*)zone; }

// USA: func_ov004_02163304
extern "C" ARM int func_ov004_02163304(void* self) {
    int kind = 3;
    char* zone = (char*)Zone3D_GetInstance();
    char* grotto = zone + 0x840;
    if (grotto != NULL && func_020981e4((int)grotto, GetZoneId(zone))) {
        kind = 7;
    }
    char* node = (char*)func_ov011_021845f8(self, kind);
    SafeAllocator* alloc = (SafeAllocator*)(node + 4);

    data_ov004_021707e8.unknown_18_ = alloc->Allocate(0x1000);
    memset(data_ov004_021707e8.unknown_18_, 0, 0x1000);
    data_ov004_021707e8.unknown_c_ = alloc->Allocate(0x800);
    memset(data_ov004_021707e8.unknown_c_, 0, 0x800);
    data_ov004_021707e8.unknown_28_ = alloc->Allocate(0x80);
    memset(data_ov004_021707e8.unknown_28_, 0, 0x80);
    return 0;
}
