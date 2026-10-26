#include <globaldefs.h>
#include "Graphics/Background.h"
#if defined(jpn)
#define REGION_LAYOUT(j,u) j
#define REGION_FLAG(obj,flag) ((obj)->flags_ & (flag))
#define data_ov008_0218b400 data_ov008_0218c080
#define func_ov008_0218712c func_ov008_02188008
#define func_ov008_02187f6c func_ov008_02188ccc
#else
#define REGION_LAYOUT(j,u) u
#define REGION_FLAG(obj,flag) ((obj)->inline_ov008_02185a70(flag))
#endif
#include <Memory/SafeAllocator.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Resource/MessageSystem.h>
#include "Input/Input.h"

struct Struct_01ff8b48_26 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
};

struct Struct_ov008_021843f8_2 {
    Struct_01ff8b48_26 unknown_0_[2];
    unsigned int unknown_8_0_ : 17;
    unsigned int unknown_a_1_ : 7;
    unsigned int unknown_b_0_ : 7;
    unsigned int unknown_b_7_ : 1;
    unsigned int unknown_c_0_ : 17;
    unsigned int unknown_e_1_ : 7;
    unsigned int unknown_f_0_ : 7;
    unsigned int unknown_f_7_ : 1;
    unsigned int unknown_10_0_ : 9;
    unsigned int unknown_11_1_ : 14;
    unsigned int unknown_12_7_ : 9;
    unsigned int unk_14;
};

struct Struct_ov008_021843f8_3 {
    Struct_01ff8b48_26 unknown_0_;
    Struct_01ff8b48_26 unk_4;
    unsigned int unk_8;
    unsigned int unk_c;
    unsigned int unknown_10_0_ : 9;
    unsigned int unknown_11_1_ : 14;
    unsigned int unknown_12_7_ : 9;
    char unknown_14_[0x90 - 0x14];
    Struct_ov008_021843f8_2 unknown_90_[1];
    unsigned int unknown_a8_;
    unsigned int unk_ac;
};

struct Struct_ov000_021735d0 {
    unsigned int flags_[15];
};

struct Struct_ov008_021843f8 {
    Struct_ov000_021735d0 flags_;
    Struct_ov008_021843f8_3 unknown_3c_;
};

struct TextTable {
    int unknown_0_[0x18 / 4];
};

struct Struct_ov008_02185dc0 {
    int unknown_0_[2];
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
    void* unknown_b08_;
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

struct Struct_ov000_02171ffc_2 {
    char unknown_0_[0x49c];
    unsigned char female_ : 1;
};

struct PartyMember : GameObject {
    char unknown_13c_[REGION_LAYOUT(0x144, 0x150) - 0x13c];
    Struct_ov000_02171ffc_2* unknown_150_;
};

struct GameResources;
struct Struct_020727d8;
struct StreamHeader;
struct Container020e0310;
struct Struct_0205d81c;
struct SePlayer;

extern char data_ov008_0218b400[] __attribute__((aligned(4)));
extern unsigned char g_fileLoadBuffer[];
extern SePlayer g_sePlayer;

extern "C" MessageSystem* MessageSystem_GetInstance();
void SetSubBrightness(GameResources* resources, int brightness, int frames);
int IsBrightnessTransitionActive(GameResources* resources);
void* LoadFileIntoMemory(const char* path, void* archive, unsigned int* size);
extern "C" void func_020727d8(Struct_020727d8* list);
extern "C" void func_02072928(void* list, StreamHeader* file, int size, int id, void* output, unsigned char female);
extern "C" int GameState_GetProtagonistIndex(GameState* gameState);
extern "C" const char* KeyTable_Get(Container020e0310* texts, int id);
extern "C" void Text_Append(char* text, const char* append);
extern "C" Canvas* func_0205d81c(Struct_0205d81c* window, int canvas);
struct Struct_ov008_02184a4c_13;
extern "C" void func_ov008_02187664(Struct_ov008_02184a4c_13*, int);
extern "C" void SePlayer_Play(SePlayer* sound, int effect, int value);
#if defined(jpn)
extern "C" void func_020727f8(void* list, const char* path, int id, void* out, unsigned char mode);
#endif

extern "C" {
void* ExtractFileFromGP2(char* path, char* inner, unsigned int* size);
void GridCursor_SetSelectedIndex(WindowCursor* cursor, int index);
int func_ov008_02188a54(Struct_ov008_021842a0_2* self, int arg1);
void func_ov008_0218712c(Struct_ov008_021842a0_2* self, Struct_ov008_021843f8_2* records);
void func_ov008_02187a70(Struct_ov008_021842a0_2* self, Struct_ov008_021843f8_2* records);
void func_ov008_02187f6c(Struct_ov008_021842a0_2* self, Struct_ov008_021843f8_2* records);
void func_ov008_02186964(Struct_ov008_021842a0_2* self);
int func_ov008_02186b18(Struct_ov008_021842a0_2* self, int x, int y);
}

static inline Struct_ov008_021843f8* inline_ov008_021843f8(GameState* gameState)
{
    return (Struct_ov008_021843f8*)((char*)gameState + REGION_LAYOUT(0x2c4, 0x104) + REGION_LAYOUT(0x7000, 0x7400));
}

static inline Struct_ov008_021843f8_2* inline_ov008_02186388(Struct_ov008_021843f8* saved, int i)
{
    return &saved->unknown_3c_.unknown_90_[i];
}

// USA: func_ov008_02186388
extern "C" ARM void func_ov008_02186388(Struct_ov008_021842a0_2* self)
{
#if defined(jpn)
    Struct_ov008_021843f8* saved;
#endif
    GameState* gameState = GameState::GetInstance();
    GameResources* resources = gameState->GetResources();
    BackgroundLoader::GetInstance();
    MessageSystem* messages = MessageSystem_GetInstance();
#if defined(jpn)
    saved = inline_ov008_021843f8(gameState);
#define CLEAR_RECORDS inline_ov008_02186388(saved, 0)
#define CLEAR_TITLE saved->unknown_3c_.unknown_90_[0].unknown_12_7_
#else
    Struct_ov008_021843f8_2* clear = inline_ov008_02186388(inline_ov008_021843f8(gameState), 0);
#define CLEAR_RECORDS clear
#define CLEAR_TITLE clear->unknown_12_7_
#endif
    messages->unknown_19ae_ = 0;
    unsigned char step = self->step_;
    if (step == 0)
    {
        SetSubBrightness(resources, -16, 15);
        self->step_++;
        step++;
    }
    if (step == 1 && func_ov008_02188a54(self, 1))
    {
        func_ov008_0218712c(self, CLEAR_RECORDS);
        func_ov008_02187664((Struct_ov008_02184a4c_13*)self, (int)CLEAR_RECORDS);
        func_ov008_02187a70(self, CLEAR_RECORDS);
        func_ov008_02187f6c(self, CLEAR_RECORDS);
        for (int i = 0; i < 5; i++)
        {
            Canvas* canvas = func_0205d81c((Struct_0205d81c*)&self->window_, (unsigned char)i);
            if (canvas != NULL)
                canvas->unknown_c2_ = 0;
        }
        self->flags_ |= 0x10000;
        self->step_++;
    }
    if (step == 2)
    {
        SetSubBrightness(resources, 0, 15);
        self->step_++;
    }
    if (step == 3)
    {
        if (IsBrightnessTransitionActive(resources))
            return;
        if (self->unknown_b14_ != CLEAR_TITLE)
        {
            memset(self->text_, 0, REGION_LAYOUT(0x800, 0x960));
#if defined(jpn)
            char* path = self->text_;
            char* comment = path + 0x80;
            Struct_ov008_02185dc0 list;
            func_020727d8((Struct_020727d8*)&list);
            func_020727f8(&list, data_ov008_0218b400, 1001, path, 0);
            PartyMember* member = (PartyMember*)func_0200ff1c(gameState, GameState_GetProtagonistIndex(gameState));
            func_020727d8((Struct_020727d8*)&list);
            unsigned char female = member->unknown_150_->female_;
            func_020727f8(&list, path, CLEAR_TITLE, comment, female);
#else
            char* path = self->text_;
            char* inner = path + 0x80;
            char* comment = path + 0x100;
            BackgroundLoader::AddLockGlobal();
            Struct_ov008_02185dc0 list;
            unsigned int size;
            void* file = LoadFileIntoMemory(data_ov008_0218b400, g_fileLoadBuffer, &size);
            if (file != NULL)
            {
                func_020727d8((Struct_020727d8*)&list);
                func_02072928(&list, (StreamHeader*)file, size, 1001, path, 0);
                func_020727d8((Struct_020727d8*)&list);
                func_02072928(&list, (StreamHeader*)file, size, 1001, inner, 1);
            }
            file = ExtractFileFromGP2(path, inner, &size);
            if (file != NULL)
            {
                PartyMember* member = (PartyMember*)func_0200ff1c(gameState, GameState_GetProtagonistIndex(gameState));
                func_020727d8((Struct_020727d8*)&list);
                unsigned char female = member->unknown_150_->female_;
                func_02072928(&list, (StreamHeader*)file, size, CLEAR_TITLE, comment, female);
            }
            BackgroundLoader::RemoveLockGlobal();
#endif
            Text_Append(comment, KeyTable_Get((Container020e0310*)&self->texts_, 1000));
#if defined(jpn)
            func_0204500c(messages, comment, 0);
#else
            func_0204500c(messages, comment, 0, 0xe3);
#endif
            messages->unknown_19b2_ = 1;
            messages->unknown_19c8_ = 1;
            messages->state = 2;
            if (REGION_FLAG(self, 0x40000))
            {
                messages->unknown_19c5_ = 1;
                messages->unknown_19b2_ = 0;
            }
            else
            {
                messages->unknown_19c5_ = 0;
            }
            self->flags_ |= 0x40000;
        }
        self->step_++;
        step++;
    }
    if (step == 4)
    {
        if (messages->mode != 3)
            return;
        int x;
        int y;
        int ok = 0;
        if (g_keyManager.TestKeysPressed(0x403))
            ok = 1;
        g_touchInput.GetTouchPoint(&x, &y);
        if (g_touchInput.pressed_)
        {
            int index = func_ov008_02186b18(self, x, y);
            if (index == -2)
                ok = 1;
            if (self->items_[index] == 7)
                ok = 1;
        }
        if (ok)
        {
            SePlayer_Play(&g_sePlayer, 1, 0);
            self->step_++;
        }
    }
    if (step == 5)
    {
        SetSubBrightness(resources, -16, 15);
        self->step_++;
    }
    if (step == 6 && func_ov008_02188a54(self, 0))
    {
        func_ov008_0218712c(self, NULL);
        func_ov008_02187664((Struct_ov008_02184a4c_13*)self, (int)NULL);
        func_ov008_02187a70(self, NULL);
        func_ov008_02187f6c(self, NULL);
        for (int i = 0; i < 6; i++)
        {
            Canvas* canvas = func_0205d81c((Struct_0205d81c*)&self->window_, (unsigned char)i);
            if (canvas != NULL)
                canvas->unknown_c2_ = 0;
        }
        self->flags_ &= ~0x10000;
        self->step_++;
    }
    if (step == 7)
    {
        SetSubBrightness(resources, 0, 15);
        self->step_++;
    }
    if (step == 8 && !IsBrightnessTransitionActive(resources))
    {
        if (self->unknown_b14_ == CLEAR_TITLE)
        {
            self->flags_ |= 0x200;
        }
        else
        {
            self->flags_ |= 0x20000;
            self->flags_ &= ~0x200;
        }
        self->state_ = 3;
        self->step_ = 2;
        func_ov008_02186964(self);
        for (int i = 0; i < self->unknown_74c_; i++)
        {
            if (self->items_[i] == 7)
            {
                GridCursor_SetSelectedIndex(&self->cursor_, i);
#if defined(jpn)
                int limit = 5;
                int first = self->unknown_b29_;
                limit += first;
                if (i > limit)
                    self->unknown_b29_ = i - 5;
                else if (i < first)
                    self->unknown_b29_ = i;
#else
                if (i > self->unknown_b29_ + 5)
                    self->unknown_b29_ = i - 5;
                else if (i < self->unknown_b29_)
                    self->unknown_b29_ = i;
#endif
                return;
            }
        }
    }
}
