#include <globaldefs.h>
#include "Resource/GameResources.h"

struct Struct_ov000_02161e30;

struct Struct_ov000_0217e870_2 {
    char unknown_0_[0x2a];
    unsigned char unknown_2a_;
};

struct Struct_ov000_02160da0 {
#if defined(jpn)
    char unknown_0_[0x218];
#else
    char unknown1_0_[0x29c];
#endif
    Struct_ov000_02161e30* unknown_29c_;
    Struct_ov000_0217e870_2* unknown_2a0_;
    char unknown_2a4_[0x974];
    char unknown_c18_[0x220];
    char unknown_e38_[0x60];
    char unknown_e98_[0x8];
    char unknown_ea0_[0x8];
    char unknown_ea8_[0x20];
#if defined(jpn)
    char unknown_ec8_[0x28d8];
    char unknown_3760_[0x21fc];
#else
    char unknown_ec8_[0x2898];
    char unknown_3760_[0x1fc8];
#endif
    char unknown_5728_[0x1e8];
    char unknown_5910_[0x32c];
    char unknown_5c3c_[0x1200];
};

extern "C" int func_ov026_021d8a40();
int FieldTaskQueue_IsEmpty(void**);
int TestBitAt0x34_020a35e0(unsigned char*, unsigned char);
extern "C" void func_ov026_021dce34(int, BattleWork*, BattleState*, PartyState*, void*, void*, void*, void*, void*, void*, void*, void*);

// USA: func_ov026_021dbe44
extern "C" ARM void func_ov026_021dbe44(BattleWork* self) {
    void** field3704 = (void**)GetGameResources()->unknown_ptr_array_3700[1];
    if (func_ov026_021d8a40() && FieldTaskQueue_IsEmpty(field3704) && TestBitAt0x34_020a35e0((unsigned char*)self->party, self->party->myIndex)) {
        func_ov026_021dce34(-1, self, self->battle, self->party, self->list, self->ctxEc8, self->ctx5c3c, self->ctx5728, self->scriptA, self->scriptB, self->ctx5910, self->view);
    }
}
