#include <globaldefs.h>
#include "Resource/GameResources.h"

struct Struct_ov000_02161e30;

struct PartyState {
    char pad0[0x2a];
    unsigned char myIndex;
};

struct Struct_ov000_02160da0 {
#if defined(jpn)
    char pad0[0x218];
#else
    char pad0[0x29c];
#endif
    Struct_ov000_02161e30* battle;
    PartyState* party;
    char unknown_2a4_[0x974];
    char view[0x220];
    char unknown_e38_[0x60];
    char unknown_e98_[0x8];
    char unknown_ea0_[0x8];
    char unknown_ea8_[0x20];
#if defined(jpn)
    char unknown_ec8_[0x28d8];
    char list[0x21fc];
#else
    char unknown_ec8_[0x2898];
    char list[0x1fc8];
#endif
    char unknown_5728_[0x1e8];
    char unknown_5910_[0x32c];
    char unknown_5c3c_[0x1200];
};

extern "C" int func_ov026_021d8a40();
extern "C" int FieldTaskQueue_IsEmpty(void**);
extern "C" int func_020a35e0(unsigned char*, unsigned char);
extern "C" void func_ov026_021dce34(int, Struct_ov000_02160da0*, Struct_ov000_02161e30*, PartyState*, void*, void*, void*, void*, void*, void*, void*, void*);

// USA: func_ov026_021dbe44
extern "C" ARM void func_ov026_021dbe44(Struct_ov000_02160da0* self) {
    void** field3704 = (void**)GetGameResources()->unknown_ptr_array_3700[1];
    if (func_ov026_021d8a40() && FieldTaskQueue_IsEmpty(field3704) && func_020a35e0((unsigned char*)self->party, self->party->myIndex)) {
        func_ov026_021dce34(-1, self, self->battle, self->party, self->list, self->unknown_ec8_, self->unknown_5c3c_, self->unknown_5728_, self->unknown_e98_, self->unknown_ea0_, self->unknown_5910_, self->view);
    }
}
