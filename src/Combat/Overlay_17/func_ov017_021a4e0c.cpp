#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov017_021a4e0c {
    unsigned char unknown_0_[0x22];
    short unknown_22_;
};

extern "C" void func_ov017_021c12fc(char* resources, unsigned char, unsigned char);

// USA: func_ov017_021a4e0c
extern "C" ARM void func_ov017_021a4e0c(GameResources* arg0) {
    char* var0 = (char*)arg0;
    GameObject* member = GameState::GetInstance()->GetLeader();
    if (member == NULL) return;
    short index = member->obj3D_.actorIndex_;
    GameResources* resources = arg0;
    Struct_ov017_021a4e0c* selection = (Struct_ov017_021a4e0c*)resources->unknown_ptr_array_371c[0];
    selection->unknown_22_ = index;
    func_ov017_021c12fc(var0, 1, 1);
}
