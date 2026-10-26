#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"

extern "C" void* Zone3D_GetInstance(void* unused);

struct Struct_0208f820 {
    unsigned char unknown_0_[8];
    unsigned char unknown_8_[0xac];
    unsigned char unknown_b4_;
    unsigned char unknown_b5_;
    unsigned char unknown_b6_;
};

// USA: func_0208f820
extern "C" ARM void func_0208f820(struct Struct_0208f820* p) {
    if (p->unknown_b4_ != 0 && p->unknown_b6_ != 0) {
        if (((Object3D*)((unsigned char*)p + 8))->IsVisible() == 0) {
            return;
        }
        GameState* battle = GameState::GetInstance();
        GrottoStruct* grotto = battle->GetGrottoStruct();
        unsigned short val = *(unsigned short*)Zone3D_GetInstance(grotto);
        if (val != *(int*)((char*)grotto + 0xc)) {
            return;
        }
        ((Object3D*)((unsigned char*)p + 8))->Draw(1);
    }
}
