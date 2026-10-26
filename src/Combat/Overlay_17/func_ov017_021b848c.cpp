#include <globaldefs.h>
#include "GameState/GameState.h"


struct Obj020397cc;
struct FlagWord020466f4;

struct Struct_ov017_021b848c {
    unsigned char pad0[0x8e49];
    unsigned char unknown_8e49_;
};

struct Struct_ov017_021b848c_2 {
    unsigned char pad0[0x1c];
    unsigned char info[2];
    unsigned short unknown_1e_;
    unsigned char pad20[4];
    unsigned short id;
    unsigned char unknown_26_[2];
    int field_28;
    unsigned char pad2c[0x46 - 0x2c];
    unsigned char member;
    unsigned char unknown_47_;
    int unknown_48_;
    unsigned char unknown_4c_[0x51 - 0x4c];
    unsigned char unknown_51_;
    unsigned char unknown_52_[0x6b0 - 0x52];
    Struct_ov017_021b848c* context;
    unsigned short state;
    unsigned char unknown_6b6_[2];
    int unknown_6b8_;
    unsigned char unknown_6bc_[0x6c6 - 0x6bc];
    unsigned char unknown_6c6_;
};

extern "C" int MessageSystem_GetInstance();
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" void func_ov017_021c9c64(unsigned short a0, unsigned char a1);
extern "C" void func_ov017_021c8b78(unsigned short param);
extern "C" void* GlobalFlags_GetInstance(void);
extern "C" void FlagWord_ClearBits(FlagWord020466f4* word, unsigned int mask);
extern "C" void FlagWord_SetBits(unsigned int* obj, unsigned int mask);
extern "C" void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);
extern "C" void func_020a35cc(unsigned char* obj, unsigned char index);
extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);
extern "C" void HaltSystem(void);
extern "C" void func_ov017_021c3f70(unsigned short tag);

// USA: func_ov017_021b848c
extern "C" ARM void func_ov017_021b848c(Struct_ov017_021b848c_2* self, signed char* present, int member, int arg3,
                                         unsigned short arg4, signed char arg5, int arg6, int arg7) {
    GameState* battle = GameState::GetInstance();
    MessageSystem_GetInstance();
    unsigned short state = self->state;
    if (state == 4 || state == 6 || state == 0) return;
    if (present[GameState_GetProtagonistIndex(battle)] == 0) return;

    int var2 = member >= 0 && member <= 3;
    if (!var2 || present[member] == 0 || battle->GetGameObjectByIndex(member) == NULL) {
        func_ov017_021c9c64(self->id, 0);
        func_ov017_021c8b78(self->id);
        self->state = 5;
        return;
    }

    void* flags = GlobalFlags_GetInstance();
    FlagWord_ClearBits((FlagWord020466f4*)flags, 0x200);
    FlagWord_SetBits((unsigned int*)flags, 0x40000);
    GameObject* actor = battle->GetLeader();
    if (actor != NULL) {
        GameObject_DisableControl((struct Obj020397cc*)actor, 1);
        *(unsigned short*)((char*)actor + 0xb2) = 0;
    }
    if (present[0] != 0 && battle->GetGameObjectByIndex(0) != NULL) {
        func_020a35cc(self->info, 0);
    }
    if (present[1] != 0 && battle->GetGameObjectByIndex(1) != NULL) {
        func_020a35cc(self->info, 1);
    }
    if (present[2] != 0 && battle->GetGameObjectByIndex(2) != NULL) {
        func_020a35cc(self->info, 2);
    }
    if (present[3] != 0 && battle->GetGameObjectByIndex(3) != NULL) {
        func_020a35cc(self->info, 3);
    }
    self->member = member;
    if (func_020a35e0(self->info, self->member) == 0) HaltSystem();
    if (arg3 == 0) GameState_GetProtagonistIndex(battle);
    self->unknown_48_ = arg3;
    self->unknown_1e_ = arg4;
    if (arg7 >= 0) self->field_28 = arg7;
    if (arg5 > -1) {
        self->unknown_51_ = arg5;
        if (self->context != NULL) self->context->unknown_8e49_ = arg5;
    }
    func_ov017_021c3f70(self->id);
    if (member != GameState_GetProtagonistIndex(battle)) {
        if (arg6 != 0) self->unknown_6c6_ = 1;
        self->unknown_6b8_ = 0;
        self->state = 4;
    } else {
        self->state = 6;
    }
}
