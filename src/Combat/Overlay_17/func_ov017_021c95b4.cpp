#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" int func_ov017_021d446c(void* obj, void* out, int flags);
extern "C" void FieldMonsterState_Init(void* obj);

// USA: func_ov017_021c95b4
extern "C" ARM void func_ov017_021c95b4(int unused, unsigned char* obj) {
    int local[3];
    if (func_ov017_021d446c(obj + 4, local, -1)) {
        FieldMonsterState_Init((void*)local[2]);
        ((Object3D*)((unsigned char*)local[2]))->MakeHidden();
    }
}
