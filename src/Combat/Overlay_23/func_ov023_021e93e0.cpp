#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0209cf44 {
    int type;
    union {
        int unknown_0_;
        float unknown1_0_;
        Struct_0209cf44* unknown2_0_;
    } value;
};

struct Struct_ov023_021e93e0 {
    char unknown_0_[0x464];
    unsigned char unknown_464_[32];
    char unknown_484_[4];
    short models[10];
    unsigned char female : 1;
};

struct Struct_ov023_021e93e0_2 {
#if defined(jpn)
    char unknown_0_[0x144];
#else
    char unknown1_0_[0x150];
#endif
    Struct_ov023_021e93e0* record;
};

extern "C" int func_ov017_021d60f4(Struct_0209cf44* argument);
extern "C" GameObject* func_ov023_021e8f28(int partyIndex);
extern "C" void func_ov017_021d6134(Struct_0209cf44* output, int value);

extern "C" ARM int func_ov023_021e93e0(void* command) {
    Struct_0209cf44* arguments = (Struct_0209cf44*)command;
    GameState::GetInstance();
    GameObject* member = func_ov023_021e8f28(func_ov017_021d60f4(&arguments[0]));
    if (member == NULL) return 0;
    Struct_ov023_021e93e0* record = ((Struct_ov023_021e93e0_2*)member)->record;
    func_ov017_021d6134(&arguments[1], record->female);
    return 1;
}
