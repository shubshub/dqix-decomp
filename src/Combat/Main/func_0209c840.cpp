#include <globaldefs.h>
#include "GameState/GameState.h"

int CountEntriesType1WithId_020bc0a4(int id);
struct Obj020bc180;
void CallFunc020c0204OnActiveNode(struct Obj020bc180* obj, int value, int arg);
void* CallFunc020bc594OnField0_020bc068(void* obj, int unused);
void SoundPlayer_RestoreHeapState(void* obj, int arg2);
int SoundPlayer_LoadSeq(void* obj, void* arg1, int* out);
struct Obj0203aba8;
int SoundPlayer_StartSeq(struct Obj0203aba8* obj, void* key, void* target);
extern "C" void func_0209c2e0(void* obj, int a, int b);
extern "C" void func_020bbd9c(void);
void SoundPlayer_StopSeqOnHandle(void* obj, void* a, int b);
int SetContextAndQuery0203ab6c(void* obj, void* arg1);

struct Struct_0209c840 {
    char unknown_0_[0xb0];
    int unknown_b0_;
    int unknown_b4_;
    short unknown_b8_;
    short unknown_ba_;
    void* unknown_bc_;
    void* unknown_c0_;
    void* unknown_c4_;
    unsigned char unknown_c8_0_ : 1;
    unsigned char unknown_c8_1_ : 7;
    unsigned char unknown_c9_;
    unsigned short unknown_ca_;
    unsigned char unknown_cc_;
    unsigned char unknown_cd_;
    short unknown_ce_;
};

// USA: func_0209c840
extern "C" ARM void func_0209c840(struct Struct_0209c840* arg0) {
    GameState* var0 = GameState::GetInstance();

    if (arg0->unknown_c9_ == 1) {
        arg0->unknown_ca_ = 0x320;
        if (arg0->unknown_b0_ == 1) {
            int var1 = func_020bc0a4(arg0->unknown_b8_);
            if (var1 <= 0) {
                arg0->unknown_ca_ = 0;
            } else {
                arg0->unknown_c8_0_ = 1;
                func_020bc180((struct Struct_0209c2e0_2*)&arg0->unknown_bc_, 0, 0x14);
            }
        } else if (arg0->unknown_b0_ == 2) {
            arg0->unknown_ca_ = 0;
        }
        arg0->unknown_c9_ = 2;
        return;
    }

    if (arg0->unknown_c9_ == 2) {
        unsigned int var2 = var0->GetEffectiveDeltaTime();
        if (var2 < arg0->unknown_ca_) {
            arg0->unknown_ca_ = arg0->unknown_ca_ - var2;
            return;
        }
        CallFunc020bc594OnField0_020bc068(&actor->fieldBC, 1);
        if (actor->field_b4 > 0) {
            SoundPlayer_RestoreHeapState(actor, actor->field_b4);
        }
        SoundPlayer_LoadSeq(actor, (void*)(int)actor->field_ce, 0);
        SoundPlayer_StartSeq((struct Obj0203aba8*)actor, (void*)(int)actor->field_ce, &actor->fieldC4);
        func_0209c2e0(actor, actor->field_cd, 0);
        func_020bbd9c();
        arg0->unknown_ca_ = 0x1f4;
        arg0->unknown_c9_ = 3;
        return;
    }

    if (arg0->unknown_c9_ != 3) {
        return;
    }

    if (arg0->unknown_ce_ > -1 && func_020bc0a4(arg0->unknown_ce_) > 0) {
        return;
    }

    {
        unsigned int var3 = var0->GetEffectiveDeltaTime();
        if (var3 < arg0->unknown_ca_) {
            arg0->unknown_ca_ = arg0->unknown_ca_ - var3;
            return;
        }
    }

    SoundPlayer_StopSeqOnHandle(actor, &actor->fieldC4, 0);
    actor->field_ce = -1;
    if (actor->state == 1) {
        if (actor->field_b4 > 0) {
            SoundPlayer_RestoreHeapState(actor, actor->field_b4);
        }
        func_0203ab6c(arg0, (void*)(int)arg0->unknown_b8_);
        if (arg0->unknown_c8_0_) {
            func_020bc068(&arg0->unknown_bc_, 0);
            func_020bc180((struct Struct_0209c2e0_2*)&arg0->unknown_bc_, 0, 0);
            func_0209c2e0(arg0, arg0->unknown_cd_, 0x1e);
        } else {
            func_0209c2e0(arg0, arg0->unknown_cd_, 0);
        }
    }
    arg0->unknown_c9_ = 0;
}
