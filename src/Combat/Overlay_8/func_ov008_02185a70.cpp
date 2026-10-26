#include <globaldefs.h>
#include "Graphics/Background.h"
#include "Resource/FontBankLoader.h"
#if defined(jpn)
#define func_ov008_02188d74 func_ov008_02189a9c
#define func_ov008_0218712c func_ov008_02188008
#define func_ov008_02187f6c func_ov008_02188ccc
#endif

#include <Memory/SafeAllocator.h>
#include <World/Object3D.h>
#include <Resource/MessageSystem.h>
#include <Filesystem/BackgroundLoader.h>
#include "Input/Input.h"
#include "Resource/GameResources.h"

struct Struct_01ff8b48_26 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
};

struct TextTable {
    int unknown_0_[0x18 / 4];
};


struct TextWindow {
    int unknown_0_[0xbc / 4];
};

struct Canvas {
    char unknown_0_[0xc2];
    unsigned short unknown_c2_;
    char unknown_c4_[0xe0 - 0xc4];
};

struct WindowCursor {
    int unknown_0_[0x40 / 4];
};

struct Struct_ov008_02185a70 {
    char unknown_0_[0x438];
    unsigned short flags_;
    char unknown_43a_[0x44c - 0x43a];
};

struct Struct_ov008_021842a0_2 {
    SafeAllocator allocator_;
    SafeAllocator unknown_14_;
    SafeAllocator textAllocator_;
    SafeAllocator spriteAllocator_;
    SafeAllocator iconAllocator_;
    SafeAllocator modelAllocator_;
    SafeAllocator titleAllocator_;
    SafeAllocator unknown_8c_;
    TextTable texts_;
    char* text_;
    char unknown_bc_[0x14];
    BackgroundGraphics backgrounds_[3];
    TextWindow window_;
    Canvas canvases_[6];
    void* pixels_;
    void* renderer_;
    void* sprites_;
    void* animations_;
    void* iconRenderer_;
    void* iconSprite_;
    unsigned char items_[8];
    unsigned char unknown_74c_;
    WindowCursor cursor_;
    Object3D model_;
    char camera_[0x2c8];
    void* titles_;
    Struct_ov008_02185a70* unknown_b08_;
    void* page_;
    signed char state_;
    unsigned char step_;
    unsigned char unknown_b12_;
    unsigned char unknown_b13_;
    short unknown_b14_;
    short unknown_b16_;
    int flags_;
    int unknown_b1c_;
    int task_;
    int mode_;
    unsigned char kind_;
    unsigned char unknown_b29_;
    unsigned char unknown_b2a_;
    int titleX_;
    const void* unknown_b30_;
    void* unknown_b34_;
    void* unknown_b38_;
    void* guestTitles_;
    Struct_01ff8b48_26 unknown_b40_[2];

    int inline_ov008_02185a70(int flag)
    {
        return flags_ & flag ? 1 : 0;
    }
};

struct GameResources;
struct Entry_0205d6a0;
struct Struct_ov008_02184a4c_13;
struct Struct_0205d81c;

extern "C" MessageSystem* MessageSystem_GetInstance();
extern "C" void Window_ClosePane(Entry_0205d6a0* window, int value);
void SetMainBrightness(GameResources* resources, int screen, int brightness);
extern "C" void func_ov008_02187664(Struct_ov008_02184a4c_13* self, int records);
extern "C" Canvas* func_0205d81c(Struct_0205d81c* window, int canvas);
int IsBrightnessTransitionActive(GameResources* resources);

extern "C" {
void func_ov023_021eb138(Struct_ov008_02185a70* arg0, int value);
void func_ov023_021eb080(Struct_ov008_02185a70* arg0, SafeAllocator* allocator);
void func_ov023_021eb564(Struct_ov008_02185a70* arg0, void* pages, int count);
void func_ov023_021eb26c(Struct_ov008_02185a70* arg0);
void func_ov008_02186964(Struct_ov008_021842a0_2* self);
int func_ov008_02188d74(Struct_ov008_021842a0_2* self);
int func_ov008_02188a54(Struct_ov008_021842a0_2* self, int arg1);
void func_ov008_0218712c(Struct_ov008_021842a0_2* self, void* records);
void func_ov008_02187a70(Struct_ov008_021842a0_2* self, void* records);
void func_ov008_02187f6c(Struct_ov008_021842a0_2* self, void* records);
void func_ov008_02186cec(Struct_ov008_021842a0_2* self);
}

// USA: func_ov008_02185a70
extern "C" ARM void func_ov008_02185a70(Struct_ov008_021842a0_2* self, unsigned int ticks)
{
    MessageSystem* messages = MessageSystem_GetInstance();
    GameResources* resources = GetGameResources();
    BackgroundLoader::GetInstance();
    FontBankLoader* music = FontBankLoader_GetInstance();
    unsigned char step = self->step_;
    if (step >= 2)
        messages->unknown_19ae_ = 0;
    if (step == 0)
    {
        if (messages->mode != 3)
            return;
        self->step_++;
    }
    if (step == 1 && (g_keyManager.TestKeysPressed(0xff3) || g_touchInput.pressed_))
        self->step_++;
    if (step == 2)
    {
        self->unknown_b08_ = (Struct_ov008_02185a70*)self->titleAllocator_.Allocate(sizeof(Struct_ov008_02185a70));
        func_ov023_021eb138(self->unknown_b08_, 0);
        func_ov023_021eb080(self->unknown_b08_, &self->titleAllocator_);
        func_ov023_021eb564(self->unknown_b08_, self->page_, 1);
        {
            int set = self->inline_ov008_02185a70(0x8000);
            Struct_ov008_02185a70* var5 = self->unknown_b08_;
            if (set)
                var5->flags_ |= 0x400;
            else
                var5->flags_ &= ~0x400;
        }
        {
            int set = self->inline_ov008_02185a70(2);
            Struct_ov008_02185a70* var7 = self->unknown_b08_;
            if (set)
                var7->flags_ |= 0x800;
            else
                var7->flags_ &= ~0x800;
        }
        self->step_++;
    }
    if (step == 3 && (self->unknown_b08_->flags_ & 4))
        self->step_++;
    if (step == 4)
    {
        func_ov023_021eb26c(self->unknown_b08_);
        self->titleAllocator_.Reset();
        self->unknown_b08_ = NULL;
        self->page_ = NULL;
        self->flags_ &= ~0x200000;
        func_ov008_02186964(self);
        int flags = self->flags_;
        if ((flags & 0x8000) || (flags & 2))
            self->flags_ &= ~0x200;
        self->flags_ &= ~0x8000;
        self->step_++;
    }
    if (step == 5)
    {
        Window_ClosePane((Entry_0205d6a0*)&self->window_, 1);
        func_02094b40(music);
        func_02094b34(music, 0x6b, 0x1fc, 0, 0);
        self->step_++;
    }
    if (step == 6)
    {
        if (!func_02094b4c(music))
            return;
        if (func_ov008_02188d74(self))
        {
            self->step_++;
            step++;
        }
    }
    if (step == 7 && func_ov008_02188a54(self, 0))
    {
        SetMainBrightness(resources, 0, 0xf);
        func_ov008_0218712c(self, NULL);
        func_ov008_02187664((Struct_ov008_02184a4c_13*)self, 0);
        func_ov008_02187a70(self, NULL);
        func_ov008_02187f6c(self, NULL);
        for (int i = 0; i < 6; i++)
        {
            Canvas* canvas = func_0205d81c((Struct_0205d81c*)&self->window_, (unsigned char)i);
            if (canvas != NULL)
                canvas->unknown_c2_ = 0;
        }
        self->step_++;
    }
    if (step == 8 && !IsBrightnessTransitionActive(resources))
    {
        self->flags_ |= 0x2000;
        func_ov008_02186cec(self);
        self->state_ = 3;
        self->step_ = 0;
        self->flags_ |= 0x20000;
        if (self->flags_ & 2)
            self->kind_ = 7;
        func_ov008_02186964(self);
        self->step_ = 1;
    }
}
