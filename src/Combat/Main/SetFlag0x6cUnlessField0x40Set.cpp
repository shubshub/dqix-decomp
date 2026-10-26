#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" void FieldMonsterState_Init(void* p);

// USA: func_02078660
ARM void SetFlag0x6cUnlessField0x40Set_02078660(void* p) {
    if (((Object3D*)p)->GetInheritedAlpha() != 0) return;
    FieldMonsterState_Init(p);
    ((Object3D*)p)->MakeHidden();
}
