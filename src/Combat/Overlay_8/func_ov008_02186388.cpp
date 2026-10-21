#include <globaldefs.h>
#if defined(jpn)
#define REGION_LAYOUT(j,u) j
#define REGION_FLAG(obj,flag) ((obj)->flags_ & (flag))
#define data_ov008_0218b400 data_ov008_0218c080
#define func_ov008_0218712c func_ov008_02188008
#define func_ov008_02187f6c func_ov008_02188ccc
#else
#define REGION_LAYOUT(j,u) u
#define REGION_FLAG(obj,flag) ((obj)->IsFlagSet(flag))
#endif
#include <Memory/SafeAllocator.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Resource/MessageSystem.h>
#include "Input/Input.h"

struct PlayTime {
    unsigned short hours_;
    unsigned char minutes_;
    unsigned char seconds_;
};

struct ClearRecords {
    PlayTime times_[2];
    unsigned int unk_8_0 : 17;
    unsigned int unk_8_17 : 7;
    unsigned int unk_8_24 : 7;
    unsigned int unk_8_31 : 1;
    unsigned int unk_c_0 : 17;
    unsigned int unk_c_17 : 7;
    unsigned int unk_c_24 : 7;
    unsigned int unk_c_31 : 1;
    unsigned int unk_10_0 : 9;
    unsigned int unk_10_9 : 14;
    unsigned int title_ : 9;
    unsigned int unk_14;
};

struct PlayRecords {
    PlayTime playTime_;
    PlayTime unk_4;
    unsigned int unk_8;
    unsigned int unk_c;
    unsigned int unk_10_0 : 9;
    unsigned int unk_10_9 : 14;
    unsigned int unk_10_23 : 9;
    char pad_14[0x90 - 0x14];
    ClearRecords clears_[1];
    unsigned int unk_a8;
    unsigned int unk_ac;
};

struct GameFlags {
    unsigned int flags_[15];
};

struct SavedRecords {
    GameFlags flags_;
    PlayRecords records_;
};

struct TextTable {
    int pad_0[0x18 / 4];
};

struct TextList {
    int pad_0[2];
};

struct BackgroundGraphics {
    int pad_0[0x20 / 4];
};

struct TextWindow {
    int pad_0[0xbc / 4];
};

struct Canvas {
    char pad_0[0xc2];
    unsigned short unk_c2;
    char pad_c4[0xe0 - 0xc4];
};

struct WindowCursor {
    int pad_0[0x40 / 4];
};

struct BattleRecords {
    SafeAllocator allocator_;
    SafeAllocator backgroundAllocator_;
    SafeAllocator textAllocator_;
    SafeAllocator spriteAllocator_;
    SafeAllocator iconAllocator_;
    SafeAllocator modelAllocator_;
    SafeAllocator titleAllocator_;
    SafeAllocator guideAllocator_;
    TextTable texts_;
    char* text_;
    char titleTable_[0x14];
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
    unsigned char itemCount_;
    WindowCursor cursor_;
    Object3D model_;
    char camera_[0x2c8];
    void* titles_;
    void* guide_;
    void* page_;
    signed char state_;
    unsigned char step_;
    unsigned char loadStep_;
    unsigned char exit_;
    short title_;
    short comment_;
    int flags_;
    int unk_b1c;
    int task_;
    int mode_;
    unsigned char kind_;
    unsigned char top_;
    unsigned char closed_;
    int titleX_;
    const void* guest_;
    void* guestRecords_;
    void* guestTexts_;
    void* guestTitles_;
    PlayTime times_[2];

    int IsFlagSet(int flag)
    {
        return flags_ & flag ? 1 : 0;
    }
};

struct CombatantData {
    char pad_0[0x49c];
    unsigned char female_ : 1;
};

struct PartyMember : GameObject {
    char pad_13c[REGION_LAYOUT(0x144, 0x150) - 0x13c];
    CombatantData* data_;
};

struct GameResources;
struct List020727d8;
struct StreamHeader;
struct Container020e0310;
struct Struct_0205d81c;
struct Obj0205eaa0;

extern char data_ov008_0218b400[] __attribute__((aligned(4)));
extern unsigned char data_0211e33c[];
extern Obj0205eaa0 data_02108760;

MessageSystem* GetGlobalField0x1c020421a0();
void SetSubBrightness(GameResources* resources, int brightness, int frames);
int IsBrightnessTransitionActive(GameResources* resources);
void* LoadFileIntoMemory(const char* path, void* archive, unsigned int* size);
void ResetListHeader020727d8(List020727d8* list);
void SubmitAndRunScript02072928(void* list, StreamHeader* file, int size, int id, void* output, unsigned char female);
int GetField0x3acValue_020100a8(GameState* gameState);
const char* GetFieldByKey020e0434(Container020e0310* texts, int id);
void AppendString02042058(char* text, const char* append);
Canvas* FindElementByC40205d81c(Struct_0205d81c* window, int canvas);
struct Manager02187664;
void InitConfig02187664(Manager02187664*, int);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0* sound, int effect, int value);
#if defined(jpn)
void SubmitScriptFromFile020727f8(void* list, const char* path, int id, void* out, unsigned char mode);
#endif

extern "C" {
void* ExtractFileFromGP2(char* path, char* inner, unsigned int* size);
void func_0205bb04(WindowCursor* cursor, int index);
int func_ov008_02188a54(BattleRecords* self, int lastClear);
void func_ov008_0218712c(BattleRecords* self, ClearRecords* records);
void func_ov008_02187a70(BattleRecords* self, ClearRecords* records);
void func_ov008_02187f6c(BattleRecords* self, ClearRecords* records);
void func_ov008_02186964(BattleRecords* self);
int func_ov008_02186b18(BattleRecords* self, int x, int y);
}

static inline SavedRecords* GetSavedRecords(GameState* gameState)
{
    return (SavedRecords*)((char*)gameState + REGION_LAYOUT(0x2c4, 0x104) + REGION_LAYOUT(0x7000, 0x7400));
}

static inline ClearRecords* GetClearRecords(SavedRecords* saved, int i)
{
    return &saved->records_.clears_[i];
}

// USA: func_ov008_02186388
extern "C" ARM void func_ov008_02186388(BattleRecords* self)
{
#if defined(jpn)
    SavedRecords* saved;
#endif
    GameState* gameState = GameState::GetInstance();
    GameResources* resources = gameState->GetResources();
    BackgroundLoader::GetInstance();
    MessageSystem* messages = GetGlobalField0x1c020421a0();
#if defined(jpn)
    saved = GetSavedRecords(gameState);
#define CLEAR_RECORDS GetClearRecords(saved, 0)
#define CLEAR_TITLE saved->records_.clears_[0].title_
#else
    ClearRecords* clear = GetClearRecords(GetSavedRecords(gameState), 0);
#define CLEAR_RECORDS clear
#define CLEAR_TITLE clear->title_
#endif
    messages->b19ae = 0;
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
        InitConfig02187664((Manager02187664*)self, (int)CLEAR_RECORDS);
        func_ov008_02187a70(self, CLEAR_RECORDS);
        func_ov008_02187f6c(self, CLEAR_RECORDS);
        for (int i = 0; i < 5; i++)
        {
            Canvas* canvas = FindElementByC40205d81c((Struct_0205d81c*)&self->window_, (unsigned char)i);
            if (canvas != NULL)
                canvas->unk_c2 = 0;
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
        if (self->title_ != CLEAR_TITLE)
        {
            memset(self->text_, 0, REGION_LAYOUT(0x800, 0x960));
#if defined(jpn)
            char* path = self->text_;
            char* comment = path + 0x80;
            TextList list;
            ResetListHeader020727d8((List020727d8*)&list);
            SubmitScriptFromFile020727f8(&list, data_ov008_0218b400, 1001, path, 0);
            PartyMember* member = (PartyMember*)GetCombatantWithFlag0x100_0200ff1c(gameState, GetField0x3acValue_020100a8(gameState));
            ResetListHeader020727d8((List020727d8*)&list);
            unsigned char female = member->data_->female_;
            SubmitScriptFromFile020727f8(&list, path, CLEAR_TITLE, comment, female);
#else
            char* path = self->text_;
            char* inner = path + 0x80;
            char* comment = path + 0x100;
            BackgroundLoader::AddLockGlobal();
            TextList list;
            unsigned int size;
            void* file = LoadFileIntoMemory(data_ov008_0218b400, data_0211e33c, &size);
            if (file != NULL)
            {
                ResetListHeader020727d8((List020727d8*)&list);
                SubmitAndRunScript02072928(&list, (StreamHeader*)file, size, 1001, path, 0);
                ResetListHeader020727d8((List020727d8*)&list);
                SubmitAndRunScript02072928(&list, (StreamHeader*)file, size, 1001, inner, 1);
            }
            file = ExtractFileFromGP2(path, inner, &size);
            if (file != NULL)
            {
                PartyMember* member = (PartyMember*)GetCombatantWithFlag0x100_0200ff1c(gameState, GetField0x3acValue_020100a8(gameState));
                ResetListHeader020727d8((List020727d8*)&list);
                unsigned char female = member->data_->female_;
                SubmitAndRunScript02072928(&list, (StreamHeader*)file, size, CLEAR_TITLE, comment, female);
            }
            BackgroundLoader::RemoveLockGlobal();
#endif
            AppendString02042058(comment, GetFieldByKey020e0434((Container020e0310*)&self->texts_, 1000));
#if defined(jpn)
            func_0204500c(messages, comment, 0);
#else
            func_0204500c(messages, comment, 0, 0xe3);
#endif
            messages->b19b2 = 1;
            messages->b19c8 = 1;
            messages->state = 2;
            if (REGION_FLAG(self, 0x40000))
            {
                messages->b19c5 = 1;
                messages->b19b2 = 0;
            }
            else
            {
                messages->b19c5 = 0;
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
            DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
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
        InitConfig02187664((Manager02187664*)self, (int)NULL);
        func_ov008_02187a70(self, NULL);
        func_ov008_02187f6c(self, NULL);
        for (int i = 0; i < 6; i++)
        {
            Canvas* canvas = FindElementByC40205d81c((Struct_0205d81c*)&self->window_, (unsigned char)i);
            if (canvas != NULL)
                canvas->unk_c2 = 0;
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
        if (self->title_ == CLEAR_TITLE)
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
        for (int i = 0; i < self->itemCount_; i++)
        {
            if (self->items_[i] == 7)
            {
                func_0205bb04(&self->cursor_, i);
#if defined(jpn)
                int limit = 5;
                int first = self->top_;
                limit += first;
                if (i > limit)
                    self->top_ = i - 5;
                else if (i < first)
                    self->top_ = i;
#else
                if (i > self->top_ + 5)
                    self->top_ = i - 5;
                else if (i < self->top_)
                    self->top_ = i;
#endif
                return;
            }
        }
    }
}
