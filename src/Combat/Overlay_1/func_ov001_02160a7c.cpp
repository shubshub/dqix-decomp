#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" void func_ov017_021d6134(void* p, int flag);

struct Struct_ov001_02160a7c { 
#if defined(jpn)
    char pad[0xc8];
#else
    char pad[0xcc];
#endif
 unsigned char unknown_cc_, unknown_cd_, unknown_ce_, unknown_cf_; };

// USA: func_ov001_02160a7c
extern "C" ARM int func_ov001_02160a7c(char* obj, int count) {
#if defined(jpn)
    enum { Enum_ov001_02160a7c_14132 = 0x3524 };
#else
    enum { Enum_ov001_02160a7c_14132 = 0x3734 };
#endif
    int flag;
    void* ov17 = GetGameResources();
    struct Struct_ov001_02160a7c* s = *(struct Struct_ov001_02160a7c**)((char*)ov17 + Enum_ov001_02160a7c_14132);
    func_ov017_021d6134(obj, s->unknown_cd_);
    obj += 8;
    if (count >= 2) {
        func_ov017_021d6134(obj, s->unknown_cf_);
        obj += 8;
    }
    if (count >= 3) {
        func_ov017_021d6134(obj, s->unknown_ce_);
        obj += 8;
    }
    if (count >= 4) {
        unsigned char v = s->unknown_cc_;
        if (v == 2) {
            flag = 0;
        } else if (v == 1) {
            flag = 1;
        }
        func_ov017_021d6134(obj, flag);
    }
    return 1;
}
