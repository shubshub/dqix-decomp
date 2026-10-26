#include <globaldefs.h>
#include "GameState/GameState.h"

struct Fields020407b4;

struct Struct_ov017_021917f0_2 {
    char unk_0[0x29c];
    unsigned int unknown_29c_0_ : 4;
    unsigned int unknown_29c_4_ : 5;
};

struct Struct_ov017_021917f0 {
    unsigned char unk_0;
    unsigned char unknown_1_;
    short unknown_2_[3];
    short unknown_8_[3];
    unsigned char unknown_e_;
    unsigned char unknown_f_;
    short unknown_10_[3];
    short unknown_16_[3];
};

extern "C" GameObject* func_0200ff1c(GameState* gameState, int combatantId);
extern "C" Struct_ov017_021917f0_2* func_02053c6c(unsigned char* obj);
extern "C" Struct_ov017_021917f0* func_02099f60(void);
extern "C" int func_02053eb4(void*, int);
extern "C" void func_02053ec0(unsigned char*, int);
extern "C" void func_020407b4(Fields020407b4* dst, int a, int b, int c);
extern "C" void func_0203db34(unsigned char* obj, int a, int b, int c);

// USA: func_ov017_021917f0
extern "C" ARM void func_ov017_021917f0(int idx, int mode) {
#if defined(jpn)
 enum { regionalOffset = 0x180 };
#else
 enum { regionalOffset = 0x18c };
#endif
    GameState* gs = GameState::GetInstance();
    Struct_ov017_021917f0_2* info;
    GameObject* combatant = func_0200ff1c(gs, idx);
    GameObject* obj = gs->GetGameObjectByIndex(idx * 12 + 0x1c);
    if (combatant == NULL || obj == NULL) return;
    info = func_02053c6c((unsigned char*)combatant);
    if (info == NULL) return;
    Struct_ov017_021917f0* entry = &func_02099f60()[info->unknown_29c_4_];
    if (mode == 1) {
        int bone = func_02053eb4(combatant, entry->unknown_e_);
        func_02053ec0((unsigned char*)combatant, bone);
        func_020407b4((Fields020407b4*)obj, entry->unknown_10_[0], entry->unknown_10_[1], entry->unknown_10_[2]);
        func_0203db34((unsigned char*)obj, entry->unknown_16_[0], entry->unknown_16_[1], entry->unknown_16_[2]);
        obj->obj3D_.Detach();
        obj->obj3D_.Attach(&combatant->obj3D_, bone);
        if (entry->unknown_16_[0] != 0 || entry->unknown_16_[1] != 0 || entry->unknown_16_[2] != 0) {
            obj->obj3D_.SetFlag16();
        } else {
            obj->obj3D_.ClearFlag16();
        }
    } else if (mode == 0) {
        int bone = func_02053eb4(combatant, entry->unknown_1_);
        func_02053ec0((unsigned char*)combatant, bone);
        func_020407b4((Fields020407b4*)obj, entry->unknown_2_[0], entry->unknown_2_[1], entry->unknown_2_[2]);
        func_0203db34((unsigned char*)obj, entry->unknown_8_[0], entry->unknown_8_[1], entry->unknown_8_[2]);
        obj->obj3D_.Detach();
        obj->obj3D_.Attach(&combatant->obj3D_, bone);
        if (entry->unknown_8_[0] != 0 || entry->unknown_8_[1] != 0 || entry->unknown_8_[2] != 0) {
            obj->obj3D_.SetFlag16();
        } else {
            obj->obj3D_.ClearFlag16();
        }
    }
    unsigned int* flags = (unsigned int*)((char*)combatant + regionalOffset);
    if (info->unknown_29c_4_ == 6) {
        *flags |= 0x20;
    } else {
        *flags &= ~0x20;
    }
    if (obj->obj3D_.unknown_2_ < 0) {
        obj->obj3D_.MakeHidden();
    } else {
        obj->obj3D_.MakeVisible();
    }
}
