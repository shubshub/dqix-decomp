#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" void func_ov017_0218d4b8(unsigned char* base, int bit);
extern "C" void func_ov017_0218d4d0(void* obj, int bit);

struct Struct_ov017_021d2774 { unsigned char pad0[4]; unsigned char unknown_4_; unsigned char enable; };

// USA: func_ov017_021d2774
extern "C" ARM void func_ov017_021d2774(void* a, Struct_ov017_021d2774* p) {
    void* obj = GetGameResources();
    if (p->enable != 0)
        func_ov017_0218d4b8((unsigned char*)obj, p->unknown_4_);
    else
        func_ov017_0218d4d0(obj, p->unknown_4_);
}
