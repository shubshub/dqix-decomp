#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/FieldActorState.h"

typedef void (Struct_02076a8c_2::*Type_02000c9c_10)();

extern Type_02000c9c_10 data_020e892c[];

extern "C" void GameObject_Update(void* obj);
extern "C" void func_020790ac(void* obj);

// USA: func_02076b58
extern "C" ARM void func_02076b58(Struct_02076a8c_2* obj) {
    GameState* battleStruct = GameState::GetInstance();
    GameObject_Update(obj);
    obj->unknown_14c_ += battleStruct->GetEffectiveDeltaTime();
    if (obj->phase != 0) {
        obj->unknown_154_ += battleStruct->GetEffectiveDeltaTime();
    }
    obj->unknown_150_ += 1;
    func_020790ac(obj);
    (obj->*data_020e892c[obj->phase])();
}
