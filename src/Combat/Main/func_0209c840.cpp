#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_020bc0a4(int id);
struct Struct_0209c2e0_2;
extern "C" void func_020bc180(struct Struct_0209c2e0_2* obj, int value, int arg);
extern "C" void* func_020bc068(void* obj, int unused);
extern "C" void SoundPlayer_RestoreHeapState(void* obj, int arg1);
extern "C" int SoundPlayer_LoadSeq(void* obj, void* arg1, int* out);
struct Obj0203aba8;
extern "C" int SoundPlayer_StartSeq(struct Obj0203aba8* obj, void* key, void* target);
extern "C" void func_0209c2e0(void* obj, int a, int b);
extern "C" void func_020bbd9c(void);
extern "C" void SoundPlayer_StopSeqOnHandle(void* obj, void* a, int b);
extern "C" int func_0203ab6c(void* obj, void* arg1);

struct Struct_0209c840 {
    char pad0[0xb0];
    int state;
    int field_b4;
    short field_b8;
    short field_ba;
    void* fieldBC;
    void* fieldC0;
    void* fieldC4;
    unsigned char unknown_c8_0_ : 1;
    unsigned char unknown_c8_1_ : 7;
    unsigned char unknown_c9_;
    unsigned short unknown_ca_;
    unsigned char field_cc;
    unsigned char unknown_cd_;
    short field_ce;
};

// USA: func_0209c840
extern "C" ARM void func_0209c840(struct Struct_0209c840* actor) {
    GameState* battle = GameState::GetInstance();

    if (actor->unknown_c9_ == 1) {
        actor->unknown_ca_ = 0x320;
        if (actor->state == 1) {
            int count = func_020bc0a4(actor->field_b8);
            if (count <= 0) {
                actor->unknown_ca_ = 0;
            } else {
                actor->unknown_c8_0_ = 1;
                func_020bc180((struct Struct_0209c2e0_2*)&actor->fieldBC, 0, 0x14);
            }
        } else if (actor->state == 2) {
            actor->unknown_ca_ = 0;
        }
        actor->unknown_c9_ = 2;
        return;
    }

    if (actor->unknown_c9_ == 2) {
        unsigned int elapsed = battle->GetEffectiveDeltaTime();
        if (elapsed < actor->unknown_ca_) {
            actor->unknown_ca_ = actor->unknown_ca_ - elapsed;
            return;
        }
        func_020bc068(&actor->fieldBC, 1);
        if (actor->field_b4 > 0) {
            SoundPlayer_RestoreHeapState(actor, actor->field_b4);
        }
        SoundPlayer_LoadSeq(actor, (void*)(int)actor->field_ce, 0);
        SoundPlayer_StartSeq((struct Obj0203aba8*)actor, (void*)(int)actor->field_ce, &actor->fieldC4);
        func_0209c2e0(actor, actor->unknown_cd_, 0);
        func_020bbd9c();
        actor->unknown_ca_ = 0x1f4;
        actor->unknown_c9_ = 3;
        return;
    }

    if (actor->unknown_c9_ != 3) {
        return;
    }

    if (actor->field_ce > -1 && func_020bc0a4(actor->field_ce) > 0) {
        return;
    }

    {
        unsigned int elapsed = battle->GetEffectiveDeltaTime();
        if (elapsed < actor->unknown_ca_) {
            actor->unknown_ca_ = actor->unknown_ca_ - elapsed;
            return;
        }
    }

    SoundPlayer_StopSeqOnHandle(actor, &actor->fieldC4, 0);
    actor->field_ce = -1;
    if (actor->state == 1) {
        if (actor->field_b4 > 0) {
            SoundPlayer_RestoreHeapState(actor, actor->field_b4);
        }
        func_0203ab6c(actor, (void*)(int)actor->field_b8);
        if (actor->unknown_c8_0_) {
            func_020bc068(&actor->fieldBC, 0);
            func_020bc180((struct Struct_0209c2e0_2*)&actor->fieldBC, 0, 0);
            func_0209c2e0(actor, actor->unknown_cd_, 0x1e);
        } else {
            func_0209c2e0(actor, actor->unknown_cd_, 0);
        }
    }
    actor->unknown_c9_ = 0;
}
