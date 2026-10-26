#include <globaldefs.h>
#include "Graphics/Background.h"
#if defined(jpn)
#define REGION_LAYOUT(j,u) j
#define REGION_FLAG(obj,flag) ((obj)->flags_ & (flag))
#define REGION_MESSAGE(obj,shown) (!((obj)->flags_ & 0x200))
#define data_ov008_0218b400 data_ov008_0218c080
#else
#define REGION_LAYOUT(j,u) u
#define REGION_FLAG(obj,flag) ((obj)->inline_ov008_02185a70(flag))
#define REGION_MESSAGE(obj,shown) (!(shown))
#endif

#include <Memory/SafeAllocator.h>
#include "World/Object3D.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/MessageSystem.h"
#include "Input/Input.h"

struct Struct_01ff8b48_26 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
};

struct Struct_ov008_021843f8_3 {
    int unknown_0_[0xb0 / 4];
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
    int unknown_0_[0xe0 / 4];
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
#if defined(jpn)
        return flags_ & flag ? 1 : 0;
#else
        return *(int*)&flags_ & flag ? 1 : 0;
#endif
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

struct Struct_020a05d8;
struct Struct_020727d8;
struct StreamHeader;
struct Container020e0310;
struct GridCursor;
struct SePlayer;

extern char data_ov008_0218b400[] __attribute__((aligned(4)));
extern unsigned char g_fileLoadBuffer[];
extern SePlayer g_sePlayer;

extern "C" MessageSystem* MessageSystem_GetInstance();
void SetBrightness(GameResources* resources, int screen, int brightness);
int IsBrightnessTransitionActive(GameResources* resources);
extern "C" void func_020ac4c0(void* records);
extern "C" void func_020a05d8(Struct_020a05d8* records, unsigned int value);
extern "C" void func_020ac494(void* records);
void* LoadFileIntoMemory(const char* path, void* archive, unsigned int* size);
extern "C" void func_020727d8(Struct_020727d8* list);
extern "C" void func_02072928(void* list, StreamHeader* file, int size, int id, void* output, int female);
extern "C" int GameState_GetProtagonistIndex(GameState* gameState);
extern "C" const char* KeyTable_Get(Container020e0310* texts, int id);
extern "C" void Text_Append(char* text, const char* append);
extern "C" int GridCursor_GetSelectedIndex(GridCursor* cursor);
extern "C" void SePlayer_Play(SePlayer* sound, int effect, int value);

extern "C" {
void* ExtractFileFromGP2(char* path, char* inner, unsigned int* size);
void func_ov008_02186964(Struct_ov008_021842a0_2* self);
int func_ov008_02186a30(Struct_ov008_021842a0_2* self, int ticks);
void* LinkSession_GetInstance();
int LinkSession_IsGuest(void* value);
}

#if defined(jpn)
extern "C" void func_020727f8(void*, const char*, int, void*, int);
#endif

// USA: func_ov008_02185dc0
extern "C" ARM void func_ov008_02185dc0(Struct_ov008_021842a0_2* self, unsigned int ticks)
{
    GameState* gameState = GameState::GetInstance();
    GameResources* resources = gameState->GetResources();
    MessageSystem* messages = MessageSystem_GetInstance();
    if (messages->active != NULL)
        messages->unknown_19ae_ = 0;
    signed char step = self->step_;
    if (step == 0)
    {
        func_ov008_02186964(self);
        self->step_++;
    }
    if (step == 1)
    {
        if (REGION_FLAG(self, 0x20000) && REGION_FLAG(self, 0x200))
        {
            if (messages->mode != 3)
                return;
            self->flags_ &= ~0x20000;
        }
        if (REGION_FLAG(self, 0x20000))
            step++;
        else
            SetBrightness(resources, 0, 0xf);
        self->step_++;
    }
    if (step == 2)
    {
        if (IsBrightnessTransitionActive(resources))
            return;
        if (!REGION_FLAG(self, 0x80))
        {
#if !defined(jpn)
            int shown = 1;
#endif
            messages->active = 1;
            if (self->unknown_b14_ > 0)
            {
#if !defined(jpn)
                if (!(self->flags_ & 0x200))
                    shown = 0;
#endif
                if (REGION_MESSAGE(self, shown))
                {
                    if (REGION_FLAG(self, 1) && !REGION_FLAG(self, 0x8000))
                    {
                        Struct_ov008_021843f8_3 records;
                        func_020ac4c0(&records);
                        func_020a05d8((Struct_020a05d8*)&records, 1);
                        func_020ac494(&records);
                    }
                    memset(self->text_, 0, REGION_LAYOUT(0x800, 0x960));
#if defined(jpn)
                    char* path = self->text_;
                    char* comment = path + 0x80;
                    Struct_ov008_02185dc0 list;
                    func_020727d8((Struct_020727d8*)&list);
                    func_020727f8(&list, data_ov008_0218b400, self->unknown_b16_, path, 0);
                    PartyMember* member = (PartyMember*)func_0200ff1c(gameState, GameState_GetProtagonistIndex(gameState));
                    func_020727d8((Struct_020727d8*)&list);
                    int female = member->unknown_150_->female_;
                    func_020727f8(&list, path, self->unknown_b14_, comment, female);
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
                        func_02072928(&list, (StreamHeader*)file, size, self->unknown_b16_, path, 0);
                        func_020727d8((Struct_020727d8*)&list);
                        func_02072928(&list, (StreamHeader*)file, size, self->unknown_b16_, inner, 1);
                    }
                    file = ExtractFileFromGP2(path, inner, &size);
                    if (file != NULL)
                    {
                        PartyMember* member = (PartyMember*)func_0200ff1c(gameState, GameState_GetProtagonistIndex(gameState));
                        func_020727d8((Struct_020727d8*)&list);
                        int female = member->unknown_150_->female_;
                        func_02072928(&list, (StreamHeader*)file, size, self->unknown_b14_, comment, female);
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
                    if (self->page_ != NULL)
                    {
                        self->flags_ |= 0x200;
                        self->state_ = 2;
                        self->step_ = 0;
                        return;
                    }
                }
            }
            else
            {
#if !defined(jpn)
                if (!(self->flags_ & 0x200))
                    shown = 0;
#endif
                if (REGION_MESSAGE(self, shown))
                {
#if defined(jpn)
                    func_0204500c(messages, KeyTable_Get((Container020e0310*)&self->texts_, 10000), 0);
#else
                    func_0204500c(messages, KeyTable_Get((Container020e0310*)&self->texts_, 10000), 0, 0xe3);
#endif
                    messages->unknown_19b2_ = 1;
                    messages->unknown_19c8_ = 1;
                    messages->state = 2;
                }
            }
            if (REGION_FLAG(self, 0x20000))
            {
                messages->unknown_19c5_ = 1;
                messages->unknown_19b2_ = 0;
                self->flags_ |= 0x200;
                self->step_ = 1;
                return;
            }
            self->flags_ |= 0x20;
        }
        self->flags_ |= 8;
        self->step_++;
    }
    if (step == 3)
    {
        int result = func_ov008_02186a30(self, ticks);
        int selected = GridCursor_GetSelectedIndex((GridCursor*)&self->cursor_);
#if defined(jpn)
        int limit = 5;
        int first = self->unknown_b29_;
        limit += first;
        if (selected > limit)
            self->unknown_b29_ = selected - 5;
        else if (selected < first)
            self->unknown_b29_ = selected;
#else
        if (selected > self->unknown_b29_ + 5)
            self->unknown_b29_ = selected - 5;
        else if (selected < self->unknown_b29_)
            self->unknown_b29_ = selected;
#endif
        unsigned char kind = self->items_[selected];
        if (g_keyManager.TestKeysPressed(0x401) || result == 1)
        {
            if (!LinkSession_IsGuest(LinkSession_GetInstance()) || kind != 5)
            {
                SePlayer_Play(&g_sePlayer, 1, 0);
                self->state_ = kind + 5;
                self->step_ = 0;
                self->flags_ &= ~8;
                self->flags_ &= ~0x20;
                return;
            }
        }
        else if (g_keyManager.TestKeysPressed(0x806) || result == -2)
        {
            self->state_ = 13;
            self->step_ = 0;
            self->flags_ &= ~8;
            self->flags_ &= ~0x20;
        }
    }
}
