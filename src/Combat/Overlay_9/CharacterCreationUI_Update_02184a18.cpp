#include "Resource/CreationEnums.h"
#if defined(jpn)
extern "C" int func_ov009_02185c58(void*);
#endif
#include <globaldefs.h>
#include "Graphics/Window.h"
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"

struct Struct_0205d81c;
struct Struct021885b8;

extern "C" void FollowCamera_Update(void* camera);
extern "C" WindowPane* Window_GetActivePane(Struct_0205d81c* window);
extern "C" int WindowPane_IsReady(unsigned char* canvas);
extern "C" void TouchGrid_SetTouchedCell(void* frame, int value);
extern "C" int Window_Update(CreationWindow* window, unsigned int ticks);
extern "C" void CharacterModel_Update(void* character);
extern "C" void CharacterCreationUI_UpdateRotation(void* self, unsigned int ticks);
extern "C" void CharacterCreationUI_SwapCharacters(void* self);
extern "C" void CharacterCreationUI_LoadNextCharacter(Struct021885b8* self);
extern "C" void CharacterCreationUI_LoadTabGraphics(void* self);

typedef void (CharacterCreationUI::*CreationTabHandler)();

struct CreationTabHandlers {
    CreationTabHandler handlers[13];
};

extern const CreationTabHandlers CharacterCreationUI_tabHandlers;
extern const CreationTabHandler __ptmf_null;

// Overlay 9, originally func_ov009_02184a18 (USA/EUR 0x02184a18, JPN 0x02185aac)
extern "C" ARM int CharacterCreationUI_Update(CharacterCreationUI* self)
{
    unsigned int ticks = GameState::GetInstance()->GetTickCount();
    if (ticks == 0)
        ticks = 1;
    if (self->state != CreationTab_Setup)
        FollowCamera_Update(self->camera);
    if (self->state == CreationTab_Confirm && self->step == ConfirmStep_Input)
    {
        WindowPane* pane = Window_GetActivePane((Struct_0205d81c*)&self->windows[CreationWindowIndex_Bottom]);
        if (pane != NULL && WindowPane_IsReady((unsigned char*)pane) != 0 && !(pane->flags_ & 2))
            TouchGrid_SetTouchedCell(&self->windows[CreationWindowIndex_Bottom].frame, -1);
    }
    Window_Update(&self->windows[CreationWindowIndex_Summary], ticks);
    self->windowInput = Window_Update(&self->windows[CreationWindowIndex_Bottom], ticks);
    if (self->flags & CreationFlag_ShowFinishModels)
    {
        self->wings.AdvanceEffects();
        self->finishEffect.AdvanceEffects();
    }
    if (self->character != NULL)
        CharacterModel_Update(self->character);
    if (self->nextCharacter != NULL)
        CharacterModel_Update(self->nextCharacter);
    CharacterCreationUI_UpdateRotation(self, ticks);
    CharacterCreationUI_SwapCharacters(self);
    CharacterCreationUI_LoadNextCharacter((Struct021885b8*)self);

    CreationTabHandlers table = CharacterCreationUI_tabHandlers;
    table.handlers[CreationTab_Done] = __ptmf_null;
    if (table.handlers[self->state] == 0)
        return 0;
    (self->*table.handlers[self->state])();
    CharacterCreationUI_LoadTabGraphics(self);
#if defined(jpn)
    func_ov009_02185c58(&self->nameFilter);
#endif
    return self->state == CreationTab_Done;
}
