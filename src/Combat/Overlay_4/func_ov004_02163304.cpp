#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void* Zone3D_GetInstance(void);
int IsIdInRange020981e4(int a, int id);
extern "C" void* func_ov011_021845f8(void* a, int b);

struct Struct_ov004_021707e8_10 {
    char unknown_0_[0xc];
    void* unknown_c_;
    char unknown_10_[8];
    void* unknown_18_;
    char unknown_1c_[0xc];
    void* unknown_28_;
};

extern Struct_ov004_021707e8_10 data_ov004_021707e8;

static inline int inline_ov004_02163304(char* arg0) { SDK_NULL_ASSERT(arg0); return *(unsigned short*)arg0; }

// USA: func_ov004_02163304
extern "C" ARM int func_ov004_02163304(void* self) {
    int kind = 3;
    char* zone = (char*)Zone3D_GetInstance();
    char* grotto = zone + 0x840;
    if (grotto != NULL && IsIdInRange020981e4((int)grotto, GetZoneId(zone))) {
        kind = 7;
    }
    char* var3 = (char*)func_ov011_021845f8(arg0, var0);
    SafeAllocator* var4 = (SafeAllocator*)(var3 + 4);

    data_ov004_021707e8.unknown_18_ = var4->Allocate(0x1000);
    memset(data_ov004_021707e8.unknown_18_, 0, 0x1000);
    data_ov004_021707e8.unknown_c_ = var4->Allocate(0x800);
    memset(data_ov004_021707e8.unknown_c_, 0, 0x800);
    data_ov004_021707e8.unknown_28_ = var4->Allocate(0x80);
    memset(data_ov004_021707e8.unknown_28_, 0, 0x80);
    return 0;
}
