#include <globaldefs.h>
#if defined(jpn)
#define REGION_LAYOUT(j,u) j
#define func_ov003_0216da90 func_ov003_0216d478
#else
#define REGION_LAYOUT(j,u) u
#endif

#include "GameState/GameState.h"
#include "NitroSDK/ColorEffects.h"
#include "Input/Input.h"

struct Container0205a330;
struct Struct_0205c570;
struct Obj_0205da38;
struct SePlayer;
struct Entry_0205d6a0;

struct Global0216b968 {
    char unk_0[REGION_LAYOUT(0x230, 0x2e0)];
    struct Container0205a330* entries_;
    char unknown_2e4_[REGION_LAYOUT(0x63c, 0x6bc)];
    int mode_;
    char unknown_9a4_[REGION_LAYOUT(0xf6a, 0x100a)];
    unsigned char unknown_19ae_;
};

struct Struct_ov003_0216b968_2 {
    char unk_0[0x4];
    short unknown_4_;
    short step_;
    char unk_8[0x8];
    int field_0x10;
    char unk_14[REGION_LAYOUT(0x113c, 0x12ac)];
    void* list_;
    char unknown_12c4_[0x126];
    unsigned char unknown_13ea_;
    char unknown_13eb_;
    unsigned char flags_;
    char unknown_13ed_;
    unsigned char unknown_13ee_;
};

extern "C" Global0216b968* MessageSystem_GetInstance(void);
extern "C" void func_0205d7a0(void* list, int index);
extern "C" void func_ov003_0216da90(Struct_ov003_0216b968_2* self);
extern "C" void SpriteEntryList_AdvanceAnimations(struct Container0205a330* c, int arg);
extern "C" int Window_GetSelectedIndex(struct Struct_0205c570* list);
extern "C" void func_ov003_0216dc58(Struct_ov003_0216b968_2* self);
extern "C" int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
extern "C" int func_0205d97c(void* list);
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern "C" void Window_ClosePane(struct Entry_0205d6a0* list, int value);

extern struct SePlayer g_sePlayer;

// USA: func_ov003_0216b968
extern "C" ARM void func_ov003_0216b968(Struct_ov003_0216b968_2* self) {
    Global0216b968* global = MessageSystem_GetInstance();

    if (self->step_ == 0) {
        if (global->mode_ == 3) {
            self->unknown_13ea_ = 1;
            self->step_ = 1;
        }
    } else if (self->step_ == 1) {
        if (self->flags_ & 1) {
            return;
        }
        func_0205d7a0(self->list_, 0);
        func_ov003_0216da90(self);
        ColorEffect_ConfigureAlphaBlend(0x04000050, 4, 1, 10, 6);
        self->step_ = 2;
    } else if (self->step_ == 2) {
        GameState* gameState = GameState::GetInstance();
        struct Container0205a330* entries = global->entries_;
        SpriteEntryList_AdvanceAnimations(entries, gameState->GetTickCount());
        global->unknown_19ae_ = 0;
        self->unknown_13ee_ = 0;
        Window_GetSelectedIndex((struct Struct_0205c570*)self->list_);
        if (self->field_0x10 != 0) {
            func_ov003_0216dc58(self);
        }

        int selection = -1;
        if (Window_IsSelectionTouched((struct Obj_0205da38*)self->list_, 0x14) != 0) {
            selection = Window_GetSelectedIndex((struct Struct_0205c570*)self->list_);
        } else if (g_keyManager.TestKeysPressed(0x401) != 0) {
            selection = Window_GetSelectedIndex((struct Struct_0205c570*)self->list_);
        } else if (g_keyManager.TestKeysPressed(2) != 0 || func_0205d97c(self->list_) == 2) {
            selection = -2;
        }

#if defined(jpn)
        switch (selection) {
        case 0:
            self->unknown_4_ = 3;
            self->step_ = 0;
            SePlayer_Play(&g_sePlayer, 1, 0);
            Window_ClosePane((struct Entry_0205d6a0*)self->list_, 0);
            break;
        case 1:
            self->unknown_4_ = 5;
            self->step_ = 0;
            SePlayer_Play(&g_sePlayer, 1, 0);
            Window_ClosePane((struct Entry_0205d6a0*)self->list_, 0);
            break;
        case 2:
            self->unknown_4_ = 4;
            self->step_ = 0;
            SePlayer_Play(&g_sePlayer, 1, 0);
            Window_ClosePane((struct Entry_0205d6a0*)self->list_, 0);
            break;
        case 3:
            self->unknown_4_ = 6;
            self->step_ = 0;
            SePlayer_Play(&g_sePlayer, 1, 0);
            Window_ClosePane((struct Entry_0205d6a0*)self->list_, 0);
            break;
        case -2:
            self->unknown_4_ = 6;
            self->step_ = 0;
            Window_ClosePane((struct Entry_0205d6a0*)self->list_, 0);
            break;
        default:
            break;
        }
#else
        int result;
        int dispatch = 1;
        switch (selection) {
        case 0:
            result = 3;
            break;
        case 1:
            result = 5;
            break;
        case 2:
            result = 4;
            break;
        case 3:
            result = 6;
            break;
        case -2:
            result = 6;
            dispatch = 0;
            break;
        default:
            return;
        }

        self->unknown_4_ = result;
        self->step_ = 0;
        if (dispatch) {
            SePlayer_Play(&g_sePlayer, 1, 0);
        }
        Window_ClosePane((struct Entry_0205d6a0*)self->list_, 0);
#endif
    }
}
