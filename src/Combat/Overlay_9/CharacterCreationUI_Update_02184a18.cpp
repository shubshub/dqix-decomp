#include "Resource/CreationEnums.h"
#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#if defined(jpn)
extern "C" int func_ov009_02185c58(void*);
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0205d81c;
struct Struct021885b8;

struct Canvas {
    char unk_0[0xc5];
    unsigned char flags_;
};

struct WindowBase {
    char unk_0[4];
    int frame_[0x14];
    int cursor_[0x10];
    unsigned char unk_94[4];
};

struct TextWindow {
    WindowBase base_;
    char unk_98[0xbc - 0x98];
};

void AdvanceActor020a20d8(void* camera);
Canvas* FindElementForFieldB0_0205d8c4(Struct_0205d81c* window);
int IsField0x9cEqual3_0204c7cc(unsigned char* canvas);
void SetFieldAt0x30_0205bc24(void* frame, int value);
extern "C" int Window_Update(TextWindow* window, unsigned int ticks);
extern "C" void CharacterModel_Update(void* character);
extern "C" void CharacterCreationUI_UpdateRotation(void* self, unsigned int ticks);
extern "C" void CharacterCreationUI_SwapCharacters(void* self);
void CharacterCreationUI_LoadNextCharacter(Struct021885b8* self);
void CharacterCreationUI_LoadTabGraphics(void* self);

struct CharacterCreation {
    char unk_0[R(0x1bc, 0x1f8)];
    TextWindow windows_[2];
    char unk_370[0x7f8 - 0x370];
    void* character_;
    void* nextCharacter_;
    char unk_800[0x878 - 0x800];
    Object3D wings_;
    char camera_[0x2c8];
    char unk_bec[0xc58 - 0xbec];
    signed char state_;
    unsigned char step_;
    char unk_c5a[0xcd8 - 0xc5a];
    Object3D finishEffect_;
    unsigned char selection_;
    unsigned char windowInput_;
    char unk_d86[0xd9c - 0xd86];
    unsigned int flags_;

    void HandleTab();
};

typedef void (CharacterCreation::*CreationTabHandler)();

struct CreationTabHandlers {
    CreationTabHandler handlers[13];
};

extern const CreationTabHandlers CharacterCreationUI_tabHandlers;
extern const CreationTabHandler __ptmf_null;

// Overlay 9, originally func_ov009_02184a18 (USA/EUR 0x02184a18, JPN 0x02185aac)
extern "C" ARM int CharacterCreationUI_Update(CharacterCreation* self)
{
    unsigned int ticks = GameState::GetInstance()->GetTickCount();
    if (ticks == 0)
        ticks = 1;
    if (self->state_ != CreationTab_Setup)
        AdvanceActor020a20d8(self->camera_);
    if (self->state_ == CreationTab_Confirm && self->step_ == ConfirmStep_Input)
    {
        Canvas* canvas = FindElementForFieldB0_0205d8c4((Struct_0205d81c*)&self->windows_[1]);
        if (canvas != NULL && IsField0x9cEqual3_0204c7cc((unsigned char*)canvas) != 0 && !(canvas->flags_ & 2))
            SetFieldAt0x30_0205bc24(&self->windows_[1].base_.frame_, -1);
    }
    Window_Update(&self->windows_[0], ticks);
    self->windowInput_ = Window_Update(&self->windows_[1], ticks);
    if (self->flags_ & CreationFlag_ShowFinishModels)
    {
        self->wings_.AdvanceEffects();
        self->finishEffect_.AdvanceEffects();
    }
    if (self->character_ != NULL)
        CharacterModel_Update(self->character_);
    if (self->nextCharacter_ != NULL)
        CharacterModel_Update(self->nextCharacter_);
    CharacterCreationUI_UpdateRotation(self, ticks);
    CharacterCreationUI_SwapCharacters(self);
    CharacterCreationUI_LoadNextCharacter((Struct021885b8*)self);

    CreationTabHandlers table = CharacterCreationUI_tabHandlers;
    table.handlers[CreationTab_Done] = __ptmf_null;
    if (table.handlers[self->state_] == 0)
        return 0;
    (self->*table.handlers[self->state_])();
    CharacterCreationUI_LoadTabGraphics(self);
#if defined(jpn)
    func_ov009_02185c58((char*)self + 0xdc);
#endif
    return self->state_ == CreationTab_Done;
}
