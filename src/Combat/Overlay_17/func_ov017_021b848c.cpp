#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define func_020c9be0 func_020cb6ac
#endif

struct Struct_02018300_3;
struct Struct_02038598_4;

struct Struct_ov017_021b848c {
    unsigned char unknown_0_[0x8e49];
    unsigned char unknown_8e49_;
};

struct Struct_ov017_021b848c_2 {
    unsigned char unknown_0_[0x1c];
    unsigned char unknown_1c_[2];
    unsigned short unknown_1e_;
    unsigned char unknown_20_[4];
    unsigned short unknown_24_;
    unsigned char unknown_26_[2];
    int unknown_28_;
    unsigned char unknown_2c_[0x46 - 0x2c];
    unsigned char unknown_46_;
    unsigned char unknown_47_;
    int unknown_48_;
    unsigned char unknown_4c_[0x51 - 0x4c];
    unsigned char unknown_51_;
    unsigned char unknown_52_[0x6b0 - 0x52];
    Struct_ov017_021b848c* unknown_6b0_;
    unsigned short unknown_6b4_;
    unsigned char unknown_6b6_[2];
    int unknown_6b8_;
    unsigned char unknown_6bc_[0x6c6 - 0x6bc];
    unsigned char unknown_6c6_;
};

int MessageSystem_GetInstance();
int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" void func_ov017_021c9c64(unsigned short a0, unsigned char a1);
void EnqueueEventTag122_021c8b78(unsigned short param);
void* GlobalFlags_GetInstance(void);
void FlagWord_ClearBits(FlagWord020466f4* word, unsigned int mask);
void FlagWord_SetBits(unsigned int* obj, unsigned int mask);
void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);
void SetBitInField0x34_020a35cc(unsigned char* obj, unsigned char index);
int TestBitAt0x34_020a35e0(unsigned char* obj, unsigned char index);
extern "C" void func_020c9be0(void);
extern "C" void func_ov017_021c3f70(unsigned short arg0);

// USA: func_ov017_021b848c
extern "C" ARM void func_ov017_021b848c(Struct_ov017_021b848c_2* arg0, signed char* arg1, int arg2, int arg3,
                                         unsigned short arg4, signed char arg5, int arg6, int arg7) {
    GameState* battle = GameState::GetInstance();
    MessageSystem_GetInstance();
    unsigned short state = self->state;
    if (state == 4 || state == 6 || state == 0) return;
    if (present[GameState_GetProtagonistIndex(battle)] == 0) return;

    int var2 = arg2 >= 0 && arg2 <= 3;
    if (!var2 || arg1[arg2] == 0 || var0->GetGameObjectByIndex(arg2) == NULL) {
        func_ov017_021c9c64(arg0->unknown_24_, 0);
        func_ov017_021c8b78(arg0->unknown_24_);
        arg0->unknown_6b4_ = 5;
        return;
    }

    void* flags = GlobalFlags_GetInstance();
    FlagWord_ClearBits((FlagWord020466f4*)flags, 0x200);
    FlagWord_SetBits((unsigned int*)flags, 0x40000);
    GameObject* actor = battle->GetUnknownGameObject();
    if (actor != NULL) {
        GameObject_DisableControl((struct Obj020397cc*)actor, 1);
        *(unsigned short*)((char*)actor + 0xb2) = 0;
    }
    if (arg1[0] != 0 && var0->GetGameObjectByIndex(0) != NULL) {
        func_020a35cc(arg0->unknown_1c_, 0);
    }
    if (arg1[1] != 0 && var0->GetGameObjectByIndex(1) != NULL) {
        func_020a35cc(arg0->unknown_1c_, 1);
    }
    if (arg1[2] != 0 && var0->GetGameObjectByIndex(2) != NULL) {
        func_020a35cc(arg0->unknown_1c_, 2);
    }
    if (arg1[3] != 0 && var0->GetGameObjectByIndex(3) != NULL) {
        func_020a35cc(arg0->unknown_1c_, 3);
    }
    self->member = member;
    if (TestBitAt0x34_020a35e0(self->info, self->member) == 0) func_020c9be0();
    if (arg3 == 0) GameState_GetProtagonistIndex(battle);
    self->field_48 = arg3;
    self->field_1e = arg4;
    if (arg7 >= 0) self->field_28 = arg7;
    if (arg5 > -1) {
        arg0->unknown_51_ = arg5;
        if (arg0->unknown_6b0_ != NULL) arg0->unknown_6b0_->unknown_8e49_ = arg5;
    }
    EnqueueEventTag127ForParty_021c3f70(self->id);
    if (member != GameState_GetProtagonistIndex(battle)) {
        if (arg6 != 0) self->field_6c6 = 1;
        self->field_6b8 = 0;
        self->state = 4;
    } else {
        arg0->unknown_6b4_ = 6;
    }
}
