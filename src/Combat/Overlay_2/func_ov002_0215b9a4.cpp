#include <globaldefs.h>
#include "Combat/TryApplyElemFields.h"
#include "Resource/CharacterCreationUI.h"

#if defined(jpn)
enum { Enum_ov002_0215b9a4_3784 = 0xe20, Enum_ov002_0215b9a4_6808 = 0x1a98, Enum_ov002_0215b9a4_7116 = 0x1a94, Enum_ov002_0215b9a4_7096 = 0x1a80, Enum_ov002_0215b9a4_2400 = 0x800, Enum_ov002_0215b9a4_44 = 47 };
#define data_ov002_0216cfac data_ov002_0216d618
#define data_ov002_0216d3b0 data_ov002_0216db30
#define data_ov002_0216cae8 data_ov002_0216d0f0
#define data_ov002_0216caec data_ov002_0216d0f4
#else
enum { Enum_ov002_0215b9a4_3784 = 0xec8, Enum_ov002_0215b9a4_7120 = 0x1bd0, Enum_ov002_0215b9a4_7116 = 0x1bcc, Enum_ov002_0215b9a4_7096 = 0x1bb8, Enum_ov002_0215b9a4_2400 = 0x960, Enum_ov002_0215b9a4_44 = 44 };
#endif

class Struct_ov002_0215b9a4 {
public:
    unsigned char unknown_0_[Enum_ov002_0215b9a4_3784];
    Struct_ov023_021d9c7c unknown_ec8_;
    unsigned char unknown_f84_[Enum_ov002_0215b9a4_7096 - Enum_ov002_0215b9a4_3784 - sizeof(Struct_ov023_021d9c7c)];
    int unknown_1bb8_;
    unsigned char unknown_1bbc_[Enum_ov002_0215b9a4_7116 - Enum_ov002_0215b9a4_7096 - sizeof(int)];
    int unknown_1bcc_;
    void* unknown_1bd0_;
};

typedef void (Struct_ov002_0215b9a4::*Type_ov002_0215b9a4)(void *buf, int flag);

struct Struct_ov002_0216cae8 {
    int unknown_0_;
    int unknown_4_;
};

extern Type_ov002_0215b9a4 data_ov002_0216cfac[Enum_ov002_0215b9a4_44];
extern unsigned int data_ov002_0216d3b0[2];
extern PageFn0215b9a4 __ptmf_null;
extern ModePage0215b9a4 data_ov002_0216cae8[];
extern ModePage0215b9a4 data_ov002_0216caec[];

extern "C" void *memset(void *arg0, int arg1, unsigned int arg2);
struct Struct_0205d81c;
struct Struct_0205d0e0 {
    unsigned char unknown_0_[0xc4];
    unsigned char unknown_c4_;
    unsigned char unknown_c5_;
    unsigned char unknown_c6_[0xe0 - 0xc6];
};
extern "C" Struct_0205d0e0* func_0205d81c(Struct_0205d81c*, int);

// USA: func_ov002_0215b9a4
// JPN: func_ov002_0215cb1c
extern "C" ARM void func_ov002_0215b9a4(Struct_ov002_0215b9a4 *arg0, unsigned char arg1, int arg2) {
    Struct_0205d0e0* var0 = func_0205d81c(((Struct_0205d81c*)(&arg0->unknown_ec8_)), arg1);
    if (var0 == 0) {
        return;
    }
    if (arg2) {
        var0->unknown_c5_ |= 0x40;
    } else {
        var0->unknown_c5_ &= ~0x40;
    }
    int var1 = 0;
    if (var0->unknown_c5_ & 2) {
        var1 = 1;
    }
    memset(arg0->unknown_1bd0_, 0, Enum_ov002_0215b9a4_2400);
    if (!(data_ov002_0216d3b0[1] & 1)) {
        PageFn0215b9a4 nul      = __ptmf_null;
        data_ov002_0216cfac[0]  = nul;
#if defined(jpn)
        data_ov002_0216cfac[24] = var2;
        data_ov002_0216cfac[31] = var2;
        data_ov002_0216cfac[34] = var2;
        data_ov002_0216cfac[35] = var2;
        data_ov002_0216cfac[39] = var2;
        data_ov002_0216cfac[43] = var2;
        data_ov002_0216cfac[44] = var2;
        data_ov002_0216cfac[45] = var2;
        data_ov002_0216cfac[46] = var2;
#else
        data_ov002_0216cfac[23] = var2;
        data_ov002_0216cfac[30] = var2;
        data_ov002_0216cfac[36] = var2;
        data_ov002_0216cfac[40] = var2;
        data_ov002_0216cfac[41] = var2;
        data_ov002_0216cfac[42] = var2;
        data_ov002_0216cfac[43] = var2;
#endif
        data_ov002_0216d3b0[1] |= 1;
    }
    if (data_ov002_0216cfac[arg1] == 0) {
        return;
    }
    (self->*data_ov002_0216cfac[key])(self->text, hl);
    Window_SetPaneText(((StructA0205d5d0*)(&self->window)), key, ((int)(self->text)),
#if defined(jpn)
                             1);
#else
                             0, 0);
#endif
    if (arg0->unknown_1bcc_ == 0) {
        return;
    }
    for (int var3 = 0; data_ov002_0216cae8[var3].unknown_0_ >= 0; var3++) {
        if (arg0->unknown_1bb8_ == data_ov002_0216cae8[var3].unknown_0_) {
            int var4 = data_ov002_0216caec[var3].unknown_0_;
            memset(arg0->unknown_1bd0_, 0, Enum_ov002_0215b9a4_2400);
            if (data_ov002_0216cfac[var4] == 0) {
                break;
            }
            (self->*data_ov002_0216cfac[page])(self->text, hl);
            Window_SetPaneText(((StructA0205d5d0*)(&self->window)), static_cast<unsigned char>(page), ((int)(self->text)),
#if defined(jpn)
                                     1);
#else
                                     0, 0);
#endif
        }
    }
    arg0->unknown_1bcc_ = 0;
}

#if defined(jpn)
#undef data_ov002_0216cfac
#undef data_ov002_0216d3b0
#undef data_ov002_0216cae8
#undef data_ov002_0216caec
#endif
