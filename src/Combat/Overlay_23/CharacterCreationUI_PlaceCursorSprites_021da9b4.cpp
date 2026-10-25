#include <globaldefs.h>
#include "Graphics/Window.h"
#include "GameState/GameState.h"
#include "NitroSDK/OSLanguage.h"
#include "Resource/CharacterCreationUI.h"
#include "Graphics/SpriteEntry.h"

#if defined(jpn)
#include "Graphics/SpriteAffineTransform.h"

struct Struct_0205d81c;
struct Container0205a330;
void SpriteEntryList_SetFirstObject(Container0205a3d0*, int, int);
void SpriteEntryList_PlayAnimation(Container0205a3d0*, int);
SpriteEntry* SpriteEntryList_Find(Container0205a3d0*, int);
void SpriteEntryList_SetPosition(Container0205a3d0*, int, short, short);
void SpriteEntryList_AdvanceAnimations(Container0205a330*, int);
extern "C" void SpriteContext_DrawEntries(void*);
WindowPane* FindElementByC40205d81c(Struct_0205d81c*, int);
int WindowPane_IsOpen(unsigned char*);

// Overlay 23, originally func_ov023_021da9b4 (USA/EUR 0x021da9b4, JPN 0x021db240)
extern "C" ARM void CharacterCreationUI_PlaceCursorSprites(CharacterCreationUI* self) {
    GameState* state = GameState::GetInstance();
    if (self->mainSpriteContext != NULL) {
        signed char tab = self->state;
        if (tab >= CreationTab_Gender && tab <= CreationTab_NameEntry) {
            short y = (short)(((tab - CreationTab_Gender) << 4) + 0x2b);
            SpriteEntryList_SetFirstObject(self->mainSpriteEntries, 0, 0x78);
            SpriteEntryList_PlayAnimation(self->mainSpriteEntries, 0);
            SpriteEntry* entry = SpriteEntryList_Find(self->mainSpriteEntries, 0);
            if (entry != NULL) entry->flags |= SpriteEntryFlag_Shown;
            unsigned int ticks = state->GetTickCount();
            SpriteEntryList_AdvanceAnimations((Container0205a330*)self->mainSpriteEntries, ticks);
            SpriteEntryList_SetPosition(self->mainSpriteEntries, 0, 0x6c, y);
            SpriteContext_DrawEntries(self->mainSpriteContext);
        }
    }
    if (self->subSpriteContext == NULL) return;
    WindowPane* pane = FindElementByC40205d81c((Struct_0205d81c*)&self->windows[CreationWindowIndex_Bottom], BottomWindow_YesNoPane);
    if (pane == NULL) return;
    if (!WindowPane_IsOpen((unsigned char*)pane)) return;
    short x = (short)(pane->tileX_ << 3);
    short y = (short)(pane->tileY_ << 3);
    x = (short)(x + pane->pixelX_);
    y = (short)(y + pane->pixelY_);
    SpriteEntryList_SetFirstObject(self->subSpriteEntries, 0, 0x3f);
    SpriteEntryList_PlayAnimation(self->subSpriteEntries, 0);
    SpriteEntry* entry = SpriteEntryList_Find(self->subSpriteEntries, 0);
    if (entry != NULL) entry->flags |= SpriteEntryFlag_Shown;
    unsigned int ticks = state->GetTickCount();
    SpriteEntryList_AdvanceAnimations((Container0205a330*)self->subSpriteEntries, ticks);
    SpriteEntryList_SetPosition(self->subSpriteEntries, 0, (short)(x - 8), (short)(y - 2));
    SpriteContext_DrawEntries(self->subSpriteContext);
}
#else
struct Struct0200fb08;
ARM unsigned char GameState_GetLanguage(struct Struct0200fb08* obj);

void SpriteEntryList_SetFirstObject(struct Container0205a3d0* c, int key, int val);
void SpriteEntryList_PlayAnimation(struct Container0205a3d0* c, int key);
struct SpriteEntry* SpriteEntryList_Find(struct Container0205a3d0* c, int key);
ARM void SpriteEntryList_SetPosition(struct Container0205a3d0* c, int key, short a, short b);

struct Container0205a330;
void SpriteEntryList_AdvanceAnimations(struct Container0205a330* c, int arg);

extern "C" void SpriteContext_DrawEntries(void* obj);

struct Struct_0205d81c;
ARM struct WindowPane* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
ARM int WindowPane_IsOpen(unsigned char* obj);

// Overlay 23, originally func_ov023_021da9b4 (USA/EUR 0x021da9b4, JPN 0x021db240)
extern "C" ARM void CharacterCreationUI_PlaceCursorSprites(CharacterCreationUI* self) {
    GameState* gameState = GameState::GetInstance();

    if (self->mainSpriteContext != 0) {
        signed char tab = self->state;
        if (tab >= CreationTab_Gender && tab <= CreationTab_NameEntry) {
            short x = 0x6c;
            short y = (short)(((tab - CreationTab_Gender) << 4) + 0x2b);
            GameState* game = GameState::GetInstance();
            int language = GameState_GetLanguage((struct Struct0200fb08*)game);
            struct Container0205a3d0* entries = self->mainSpriteEntries;
            if (language == OSLanguage_Italian) x = 0x64;
            SpriteEntryList_SetFirstObject(entries, 0, 0x78);
            SpriteEntryList_PlayAnimation(entries, 0);
            struct SpriteEntry* entry = SpriteEntryList_Find(entries, 0);
            if (entry != NULL) {
                entry->flags |= SpriteEntryFlag_Shown;
            }
            unsigned int ticks = game->GetTickCount();
            SpriteEntryList_AdvanceAnimations((struct Container0205a330*)entries, ticks);
            SpriteEntryList_SetPosition(entries, 0, x, y);
            SpriteContext_DrawEntries(self->mainSpriteContext);
        }
    }

    if (self->subSpriteContext == 0) {
        return;
    }
    struct WindowPane* pane = FindElementByC40205d81c((struct Struct_0205d81c*)&self->windows[CreationWindowIndex_Bottom], BottomWindow_YesNoPane);
    if (pane == 0) {
        return;
    }
    if (!WindowPane_IsOpen((unsigned char*)pane)) {
        return;
    }
    short x = (short)(pane->tileX_ << 3);
    short y = (short)(pane->tileY_ << 3);
    x = (short)(x + pane->pixelX_);
    y = (short)(y + pane->pixelY_);

    struct Container0205a3d0* entries = self->subSpriteEntries;
    SpriteEntryList_SetFirstObject(entries, 0, 0x78);
    SpriteEntryList_PlayAnimation(entries, 0);
    struct SpriteEntry* entry = SpriteEntryList_Find(entries, 0);
    if (entry != NULL) {
        entry->flags |= SpriteEntryFlag_Shown;
    }
    unsigned int ticks = gameState->GetTickCount();
    SpriteEntryList_AdvanceAnimations((struct Container0205a330*)entries, ticks);
    SpriteEntryList_SetPosition(entries, 0, (short)(x - 8), (short)(y - 2));
    SpriteContext_DrawEntries(self->subSpriteContext);
}
#endif
