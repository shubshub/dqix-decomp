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

struct Struct_0205a330;
struct Struct_0205c570;
struct Obj_0205da38;
struct SePlayer;
struct Entry_0205d6a0;

struct Struct_ov003_0216b968 {
    char unknown_0_[REGION_LAYOUT(0x230, 0x2e0)];
    struct Struct_0205a330* unknown_2e0_;
    char unknown_2e4_[REGION_LAYOUT(0x63c, 0x6bc)];
    int unknown_9a0_;
    char unknown_9a4_[REGION_LAYOUT(0xf6a, 0x100a)];
    unsigned char unknown_19ae_;
};

struct Struct_ov003_0216b968_2 {
    char unknown_0_[0x4];
    short unknown_4_;
    short unknown_6_;
    char unknown_8_[0x8];
    int unknown_10_;
    char unknown_14_[REGION_LAYOUT(0x113c, 0x12ac)];
    void* unknown_12c0_;
    char unknown_12c4_[0x126];
    unsigned char unknown_13ea_;
    char unknown_13eb_;
    unsigned char unknown_13ec_;
    char unknown_13ed_;
    unsigned char unknown_13ee_;
};

Global0216b968* GetGlobalField0x1c020421a0(void);
extern "C" void func_0205d7a0(void* list, int index);
extern "C" void func_ov003_0216da90(Self0216b968* self);
void IterateEntries0205a330(struct Container0205a330* c, int arg);
int Window_GetSelectedIndex(struct Struct_0205c570* list);
extern "C" void func_ov003_0216dc58(Self0216b968* self);
int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
extern "C" int func_0205d97c(void* list);
void SePlayer_Play(struct SePlayer* obj, int a, int b);
void ResetEntryList0205d6a0(struct Entry_0205d6a0* list, int value);

extern struct SePlayer g_sePlayer;

// USA: func_ov003_0216b968
extern "C" ARM void func_ov003_0216b968(Struct_ov003_0216b968_2* arg0) {
    Struct_ov003_0216b968* var0 = func_020421a0();

    if (arg0->unknown_6_ == 0) {
        if (var0->unknown_9a0_ == 3) {
            arg0->unknown_13ea_ = 1;
            arg0->unknown_6_ = 1;
        }
    } else if (arg0->unknown_6_ == 1) {
        if (arg0->unknown_13ec_ & 1) {
            return;
        }
        func_0205d7a0(arg0->unknown_12c0_, 0);
        func_ov003_0216da90(arg0);
        ColorEffect_ConfigureAlphaBlend(0x04000050, 4, 1, 10, 6);
        self->step_ = 2;
    } else if (self->step_ == 2) {
        GameState* gameState = GameState::GetInstance();
        struct Container0205a330* entries = global->entries_;
        IterateEntries0205a330(entries, gameState->GetTickCount());
        global->field_0x19ae = 0;
        self->field_0x13ee = 0;
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
        switch (var3) {
        case 0:
            self->result_ = 3;
            self->step_ = 0;
            SePlayer_Play(&g_sePlayer, 1, 0);
            ResetEntryList0205d6a0((struct Entry_0205d6a0*)self->list_, 0);
            break;
        case 1:
            self->result_ = 5;
            self->step_ = 0;
            SePlayer_Play(&g_sePlayer, 1, 0);
            ResetEntryList0205d6a0((struct Entry_0205d6a0*)self->list_, 0);
            break;
        case 2:
            self->result_ = 4;
            self->step_ = 0;
            SePlayer_Play(&g_sePlayer, 1, 0);
            ResetEntryList0205d6a0((struct Entry_0205d6a0*)self->list_, 0);
            break;
        case 3:
            self->result_ = 6;
            self->step_ = 0;
            SePlayer_Play(&g_sePlayer, 1, 0);
            ResetEntryList0205d6a0((struct Entry_0205d6a0*)self->list_, 0);
            break;
        case -2:
            arg0->unknown_4_ = 6;
            arg0->unknown_6_ = 0;
            func_0205d6a0((struct Struct_0205d6a0*)arg0->unknown_12c0_, 0);
            break;
        default:
            break;
        }
#else
        int var4;
        int var5 = 1;
        switch (var3) {
        case 0:
            var4 = 3;
            break;
        case 1:
            var4 = 5;
            break;
        case 2:
            var4 = 4;
            break;
        case 3:
            var4 = 6;
            break;
        case -2:
            var4 = 6;
            var5 = 0;
            break;
        default:
            return;
        }

        self->result_ = result;
        self->step_ = 0;
        if (dispatch) {
            SePlayer_Play(&g_sePlayer, 1, 0);
        }
        func_0205d6a0((struct Struct_0205d6a0*)arg0->unknown_12c0_, 0);
#endif
    }
}
