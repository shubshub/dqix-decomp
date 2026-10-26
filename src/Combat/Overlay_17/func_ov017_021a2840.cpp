#include <globaldefs.h>
#include "GameState/GameState.h"

struct GameResources;
extern "C" int _ZN7Model3D7GetTEX0Ev(void* obj);
void StageTexFilePaletteData(NSBXXTex volatile*, bool);
struct NSBXXTex;
void StageTexFileImageData(NSBXXTex volatile*, bool);

// USA: func_ov017_021a2840
extern "C" ARM void func_ov017_021a2840(GameResources*) {
    GameState* battleStruct = GameState::GetInstance();

    int i;
    for (i = 0; i < 0xc; i++) {
        GameObject* combatant = battleStruct->GetGameObjectByIndex(i + 7);
        if (combatant == NULL) {
            continue;
        }

        void* ptr = combatant->obj3D_.pModel_;
        if (ptr == NULL) {
            continue;
        }

        int var4 = _ZN7Model3D7GetTEX0Ev(ptr);
        if (var4 != 0) {
            StageTexFilePaletteData((NSBXXTex volatile*)var4, 0);
            StageTexFileImageData((NSBXXTex volatile*)var4, 0);
        }
    }
}
