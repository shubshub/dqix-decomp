#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_ov005_02153954 {
    char unknown_0_[LOW_REGION(0xee0, 0xee4)];
    char unknown_ee4_[LOW_REGION(0x3d33, 0x3dbb) - LOW_REGION(0xee0, 0xee4)];
    signed char unknown_3dbb_;
    char unknown_3dbc_[LOW_REGION(0x3d54, 0x3ddc) - LOW_REGION(0x3d34, 0x3dbc)];
    unsigned char unknown_3ddc_;
    unsigned char unknown_3ddd_;
    signed char unknown_3dde_;
    unsigned char unknown_3ddf_;
};

struct SePlayer;
struct Struct_0205c570;
struct Struct_0205cf1c;
struct Struct_0205d6a0;

extern "C" char g_sePlayer[];

extern "C" void func_ov005_02159904(EquipmentMenu* self);
void SetChannelAFlag0205cef8(void* window);
void SetChannelBFlag0205cf04(void* window);
int Window_GetSelectedIndex(Struct_0205c570* window);
int CheckFlag30Or401_02157190(void* self);
struct Obj_0205da38;
int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
void SePlayer_Play(SePlayer* sound, int effect, int unk);
void ClearChannelAFlag0205cf10(void* window);
void ClearFlagByte0205cf1c(Struct0205cf1c* window);
void Window_ClosePane(Entry_0205d6a0* window, int unk);

// USA: func_ov005_02158f80
extern "C" ARM void func_ov005_02158f80(EquipmentMenu* self) {
    if (self->menuStep_ == 0) {
        func_ov005_02159904(self);
        SetChannelAFlag0205cef8(self->window_);
        SetChannelBFlag0205cf04(self->window_);
        self->menuStep_++;
    } else if (self->menuStep_ == 1) {
        self->menuChoice_ = Window_GetSelectedIndex((Struct_0205c570*)self->window_);
        if (CheckFlag30Or401_02157190(self) | Window_IsSelectionTouched((struct Obj_0205da38*)self->window_, 0x14)) {
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            ClearChannelAFlag0205cf10(self->window_);
            ClearFlagByte0205cf1c((Struct0205cf1c*)self->window_);
            Window_ClosePane((Entry_0205d6a0*)self->window_, 0);
            if (self->slot_ >= 0 && self->slot_ < 8) {
                switch (self->menuChoice_) {
                case 0:
                    arg0->unknown_3ddf_ = 1;
                    break;
                case 1:
                    arg0->unknown_3ddf_ = 3;
                    break;
                case 2:
                    arg0->unknown_3ddf_ = 4;
                    break;
                }
            } else {
                switch (arg0->unknown_3dde_) {
                case 0:
                    arg0->unknown_3ddf_ = 1;
                    break;
                case 1:
                    arg0->unknown_3ddf_ = 2;
                    break;
                case 2:
                    arg0->unknown_3ddf_ = 3;
                    break;
                case 3:
                    arg0->unknown_3ddf_ = 4;
                    break;
                }
            }
            arg0->unknown_3ddc_ = 0;
            return;
        }
        if (!g_keyManager.TestKeysPressed(2))
            return;
        ClearChannelAFlag0205cf10(self->window_);
        ClearFlagByte0205cf1c((Struct0205cf1c*)self->window_);
        Window_ClosePane((Entry_0205d6a0*)self->window_, 0);
        self->menuState_ = 4;
        self->menuStep_ = 0;
    }
}
