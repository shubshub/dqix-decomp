#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>
#include "Input/Input.h"

struct EquipmentMenu {
    char unk_0[LOW_REGION(0xee0, 0xee4)];
    char window_[LOW_REGION(0x3d33, 0x3dbb) - LOW_REGION(0xee0, 0xee4)];
    signed char slot_;
    char unknown_3dbc_[LOW_REGION(0x3d54, 0x3ddc) - LOW_REGION(0x3d34, 0x3dbc)];
    unsigned char unknown_3ddc_;
    unsigned char menuResult_;
    signed char menuChoice_;
    unsigned char unknown_3ddf_;
};

struct SePlayer;
struct Struct_0205c570;
struct Struct_0205cf1c;
struct Entry_0205d6a0;

extern "C" char g_sePlayer[];

extern "C" void func_ov005_02159904(EquipmentMenu* self);
extern "C" void func_0205cef8(void* window);
extern "C" void func_0205cf04(void* window);
extern "C" int Window_GetSelectedIndex(Struct_0205c570* window);
extern "C" int func_ov005_02157190(void* self);
struct Obj_0205da38;
extern "C" int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
extern "C" void SePlayer_Play(SePlayer* sound, int effect, int unk);
extern "C" void func_0205cf10(void* window);
extern "C" void func_0205cf1c(Struct_0205cf1c* window);
extern "C" void Window_ClosePane(Entry_0205d6a0* window, int unk);

// USA: func_ov005_02158f80
extern "C" ARM void func_ov005_02158f80(EquipmentMenu* self) {
    if (self->unknown_3ddc_ == 0) {
        func_ov005_02159904(self);
        func_0205cef8(self->window_);
        func_0205cf04(self->window_);
        self->unknown_3ddc_++;
    } else if (self->unknown_3ddc_ == 1) {
        self->menuChoice_ = Window_GetSelectedIndex((Struct_0205c570*)self->window_);
        if (func_ov005_02157190(self) | Window_IsSelectionTouched((struct Obj_0205da38*)self->window_, 0x14)) {
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            func_0205cf10(self->window_);
            func_0205cf1c((Struct_0205cf1c*)self->window_);
            Window_ClosePane((Entry_0205d6a0*)self->window_, 0);
            if (self->slot_ >= 0 && self->slot_ < 8) {
                switch (self->menuChoice_) {
                case 0:
                    self->unknown_3ddf_ = 1;
                    break;
                case 1:
                    self->unknown_3ddf_ = 3;
                    break;
                case 2:
                    self->unknown_3ddf_ = 4;
                    break;
                }
            } else {
                switch (self->menuChoice_) {
                case 0:
                    self->unknown_3ddf_ = 1;
                    break;
                case 1:
                    self->unknown_3ddf_ = 2;
                    break;
                case 2:
                    self->unknown_3ddf_ = 3;
                    break;
                case 3:
                    self->unknown_3ddf_ = 4;
                    break;
                }
            }
            self->unknown_3ddc_ = 0;
            return;
        }
        if (!g_keyManager.TestKeysPressed(2))
            return;
        func_0205cf10(self->window_);
        func_0205cf1c((Struct_0205cf1c*)self->window_);
        Window_ClosePane((Entry_0205d6a0*)self->window_, 0);
        self->unknown_3ddf_ = 4;
        self->unknown_3ddc_ = 0;
    }
}
