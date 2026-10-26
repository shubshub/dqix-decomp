#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" int func_ov001_0215ad2c(int x);
struct Struct_ov001_0215bcc0;
extern int data_ov001_02165769;

// USA: func_ov001_0215bcc0
extern "C" ARM int func_ov001_0215bcc0(void* self, int mode) {
    GameState* battle = GameState::GetInstance();
    (int)BackgroundLoader::GetInstance();
    int var1;
    int id = func_ov001_0215ad2c(func_ov017_021d60f4(self));
    var1 = 3;
    if (mode >= 2) {
        var1 = func_ov017_021d60f4((char*)self + 0x8);
    }
    GameObject* combatant = battle->GetGameObjectByIndex(id);
    if (combatant == NULL) return 0;
    unsigned char byteField = combatant->obj3D_.animationFlags_;
    void* ptrField = combatant->obj3D_.activeAnimationRecord_;
    ((Object3D*)((struct Struct_ov001_0215bcc0*)combatant))->RemoveAnimationPackageByID(var1);
    if (combatant->obj3D_.SetAnimationByName((char const*)((int)ptrField), byteField) == 0) {
        combatant->obj3D_.SetAnimationByName((char const*)((int)&data_ov001_02165769), 0);
    }
    return 1;
}
