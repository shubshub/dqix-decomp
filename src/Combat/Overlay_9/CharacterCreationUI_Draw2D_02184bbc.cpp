#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

struct Cont0205d1e0;
struct Cont0205d228;
struct Cont0205d274;

void Window_ClearLayers(Cont0205d1e0*);
void Window_DrawPanes(Cont0205d228*);
void Window_FlushLayers(Cont0205d274*);

extern "C" void CharacterCreationUI_DrawTabLayers(CharacterCreationUI* self);
extern "C" void CharacterCreationUI_PlaceSprites(CharacterCreationUI* self);
extern "C" void CharacterCreationUI_PlaceCursorSprites(CharacterCreationUI* self);

// Overlay 9, originally func_ov009_02184bbc (USA/EUR 0x02184bbc, JPN 0x02185ee8)
extern "C" ARM void CharacterCreationUI_Draw2D(void* objRaw) {
    CharacterCreationUI* self = (CharacterCreationUI*)objRaw;
    signed char tab = self->state;
    if (tab == CreationTab_Setup || tab == CreationTab_Done) {
        return;
    }
    CharacterCreationUI_DrawTabLayers(self);
    CharacterCreationUI_PlaceSprites(self);
    CharacterCreationUI_PlaceCursorSprites(self);
    if (self->state != CreationTab_NewGameFinish) {
        Window_ClearLayers((Cont0205d1e0*)&self->windows[0]);
        Window_DrawPanes((Cont0205d228*)&self->windows[0]);
        Window_FlushLayers((Cont0205d274*)&self->windows[0]);
    }
    Window_ClearLayers((Cont0205d1e0*)&self->windows[1]);
    Window_DrawPanes((Cont0205d228*)&self->windows[1]);
    Window_FlushLayers((Cont0205d274*)&self->windows[1]);
}
