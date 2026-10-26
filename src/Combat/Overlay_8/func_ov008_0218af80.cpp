#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Resource/Brightness.h"
#include "NitroSDK/OverlayId.h"
#include "Resource/GameResources.h"

extern "C" void Overlay_Load(unsigned int id);
extern "C" void func_ov008_021843f8(void* obj);
extern "C" void func_ov008_021842a0(void* obj, void* arg);
extern "C" void func_ov008_02184a3c(char* obj, unsigned char value);
extern "C" void func_020dc2bc();

struct Struct_ov008_0218af80 {
    char pad0[0x228];
    char unknown_228_[0x288 - 0x228];
    char unknown_288_[0x2a8 - 0x288];
    char unknown_2a8_[0xdcc - 0x2a8];
    int unknown_dcc_;
    char pad1[R(0xdd4 - 0xdd0, 0xdd8 - 0xdd0)];
    char* unknown_dd8_;
    char* unknown_ddc_;
    char pad2[0xde4 - 0xde0];
    char* unknown_de4_;
    char pad3[0xdf6 - 0xde8];
    char unknown_df6_[0xe04 - 0xdf6];
    char unknown_e04_[0xe9b - 0xe04];
    unsigned char unknown_e9b_;
    signed char unknown_e9c_;
    char pad4[R(0xeb4 - 0xe99, 0xebc - 0xe9d)];
    char* ebc;
    unsigned char bit0 : 1;
    unsigned char unknown_ec0_1_ : 1;
    unsigned char bit2 : 1;
    unsigned char rest : 5;
};

// USA: func_ov008_0218af80
extern "C" ARM void func_ov008_0218af80(Struct_ov008_0218af80* self) {
    GameResources* res = GetGameResources();
    if (self->unknown_e9c_ == 0 && self->unknown_ec0_1_ && !IsBrightnessTransitionActive(res)) {
        Overlay_Load(OVERLAY_ID(8));
        func_ov008_021843f8(self->unknown_2a8_);
        self->unknown_dcc_ = 1;
        func_ov008_021842a0(self->unknown_2a8_, self->unknown_228_);
        func_ov008_02184a3c(self->unknown_2a8_, 1);
        self->unknown_de4_ = self->unknown_288_;
        char* first = self->ebc;
        char* second;
        if (first == NULL) {
            first = self->unknown_df6_;
            second = self->unknown_e04_;
        } else {
            second = first + 0x38;
        }
        self->unknown_dd8_ = first;
        self->unknown_ddc_ = second;
        self->unknown_e9c_ = self->unknown_e9c_ + 1;
        return;
    }
    if (self->unknown_e9c_ == 1 && self->unknown_ec0_1_ && self->bit2) {
        func_020dc2bc();
        SetSubBrightness(res, -16, 15);
        self->unknown_e9b_ = 1;
        self->unknown_e9c_ = 0;
    }
}
