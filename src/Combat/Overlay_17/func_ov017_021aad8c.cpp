#if defined(jpn)
enum { Enum_ov017_021aad8c_728 = 0x228 };
#else
enum { Enum_ov017_021aad8c_728 = 0x2d8 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj0207fcb8;
void ClearAllBuffers0207fcb8(struct Obj0207fcb8* obj);
struct Obj0207fd00;
void CallFunc0204c8f0OverEntries0207fd00(struct Obj0207fd00* obj);
extern "C" void func_0207fe80(void* obj, int a, int b, int c);
struct Cont0207fd44;
void CallFunc0204b04cOverList0x2c(struct Cont0207fd44* obj);
struct Obj2081;
void* FindElementByByte0xc4_02081da8(struct Obj2081* obj, int key);
void GetLookAndTurnOffsets020809c4(void* obj, int id, int id2, short* out1, short* out2);
int MessageSystem_GetInstance(void);
struct Container0205a330;
void SpriteEntryList_AdvanceAnimations(struct Container0205a330* c, int arg);
struct Container0205a3d0;
void SpriteEntryList_PlayAnimation(struct Container0205a3d0* c, int key);
void* SpriteEntryList_Find(struct Container0205a3d0* c, int key);
extern "C" void SpriteContext_DrawEntries(void* obj);

struct Struct_ov017_021aad8c_3 {
    char unknown_0_[4];
    short unknown_4_;
    short unknown_6_;
    char unknown_8_[0x15 - 8];
    unsigned char unknown_15_;
};

struct Struct_ov017_021aad8c {
    char unknown_0_[Enum_ov017_021aad8c_728];
    void* unknown_2d8_;
    char unknown_2dc_[4];
    void* unknown_2e0_;
    unsigned short unknown_2e4_;
};

struct Struct_ov017_021aad8c_2 {
    char unknown_0_[0x14];
    int unknown_14_;
    void* unknown_18_;
    char unknown_1c_[0x28];
    short* unknown_44_;
    short unknown_48_;
};

// USA: func_ov017_021aad8c
extern "C" ARM void func_ov017_021aad8c(struct Struct_ov017_021aad8c_2* arg0) {
    if (arg0->unknown_14_ != 5) return;

    if (arg0->unknown_18_ != NULL) {
        void* var0 = arg0->unknown_18_;
        func_0207fcb8((struct Struct_0207fcb8*)var0);
        func_0207fd00((struct Struct_0207fd00*)var0);
        func_0207fe80(var0, 2, 1, 1);
        func_0207fd44((struct Struct_0207fd44_2*)var0);
    }

    if (arg0->unknown_44_ == NULL) return;
    if (arg0->unknown_48_ < 0) return;
    if (func_02081da8((struct Struct_0207fdcc_2*)arg0->unknown_18_, arg0->unknown_48_) == NULL) return;

    short var1, var2;
    func_020809c4(arg0->unknown_18_, arg0->unknown_48_, *arg0->unknown_44_, &var1, &var2);
    var1 -= 0x10;
    var2 -= 3;

    struct Global02d8_021aad8c* g = (struct Global02d8_021aad8c*)MessageSystem_GetInstance();
    void* cont = g->f2e0;
    int key = g->f2e4;
    void* p2d8 = g->f2d8;
    if (p2d8 != NULL && cont != NULL) {
        GameState* battle = GameState::GetInstance();
        unsigned int scaleCount = battle->GetTickCount();
        SpriteEntryList_AdvanceAnimations((struct Container0205a330*)cont, scaleCount);
        SpriteEntryList_PlayAnimation((struct Container0205a3d0*)cont, key);

        struct Elem0205a3d0_021aad8c* e1 = (struct Elem0205a3d0_021aad8c*)SpriteEntryList_Find((struct Container0205a3d0*)cont, key);
        if (e1 != NULL) e1->flags15 |= 8;

        short a;
        short b = lookDelta;
        a = turnDelta;
        struct Elem0205a3d0_021aad8c* e2 = (struct Elem0205a3d0_021aad8c*)SpriteEntryList_Find((struct Container0205a3d0*)cont, key);
        if (e2 != NULL) {
            e2->field4 = a;
            e2->field6 = b;
        }

        SpriteContext_DrawEntries(p2d8);
    }
}
