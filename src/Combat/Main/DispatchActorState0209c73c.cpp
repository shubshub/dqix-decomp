#include <globaldefs.h>

void SoundPlayer_StopSeqOnHandle(void* obj, void* a, int b);
void SoundPlayer_RestoreHeapState(void* obj, int arg2);
int SetContextAndQuery0203ab6c(void* obj, void* arg1);
extern "C" void func_0209c5e8(void* obj);
int SoundPlayer_LoadSeq(void* obj, void* arg1, int* out);
struct Obj0203aba8;
int SoundPlayer_StartSeq(struct Obj0203aba8* obj, void* key, void* target);
extern "C" void func_0209c2e0(void* obj, int a, int b);

struct Actor0209c73c {
    char pad0[0xb0];
    int state;               // 0xb0
    int field_b4;             // 0xb4
    short field_b8;             // 0xb8
    short field_ba;               // 0xba
    void* fieldBC;                 // 0xbc
    void* fieldC0;                   // 0xc0
    void* fieldC4;                     // 0xc4
    unsigned char field_c8;              // 0xc8
    unsigned char field_c9;                // 0xc9
    short field_ca;                          // 0xca
    unsigned char field_cc;                    // 0xcc
    unsigned char field_cd;                      // 0xcd
    short field_ce;                                // 0xce
};

// USA: func_0209c73c
ARM void DispatchActorState0209c73c(struct Actor0209c73c* actor) {
    if (actor->field_ce < 0) return;
    SoundPlayer_StopSeqOnHandle(actor, (void*)&actor->fieldC4, 0);
    actor->field_ce = -1;
    if (actor->state == 1) {
        if (actor->field_b4 > 0) {
            SoundPlayer_RestoreHeapState(actor, actor->field_b4);
        }
        SetContextAndQuery0203ab6c(actor, (void*)(int)actor->field_b8);
        func_0209c5e8(actor);
        func_0209c2e0(actor, actor->field_cd, 0);
        return;
    }
    if (actor->state != 2) return;
    if (actor->field_b4 > 0) {
        SoundPlayer_RestoreHeapState(actor, actor->field_b4);
    }
    SoundPlayer_LoadSeq(actor, (void*)(int)actor->field_ba, 0);
    SoundPlayer_StartSeq((struct Obj0203aba8*)actor, (void*)(int)actor->field_ba, &actor->fieldC0);
    func_0209c2e0(actor, actor->field_cd, 0);
}
