#if defined(jpn)
enum { Enum_ov017_021aad8c_728 = 0x228 };
#else
enum { Enum_ov017_021aad8c_728 = 0x2d8 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0207fcb8;
extern "C" void func_0207fcb8(struct Struct_0207fcb8* obj);
struct Struct_0207fd00;
extern "C" void func_0207fd00(struct Struct_0207fd00* obj);
extern "C" void func_0207fe80(void* obj, int a, int b, int c);
struct Struct_0207fd44_2;
extern "C" void func_0207fd44(struct Struct_0207fd44_2* obj);
struct Struct_0207fdcc_2;
extern "C" void* func_02081da8(struct Struct_0207fdcc_2* obj, int key);
extern "C" void func_020809c4(void* obj, int id, int id2, short* out1, short* out2);
extern "C" int MessageSystem_GetInstance(void);
struct Container0205a330;
extern "C" void SpriteEntryList_AdvanceAnimations(struct Container0205a330* c, int arg);
struct Container0205a3d0;
extern "C" void SpriteEntryList_PlayAnimation(struct Container0205a3d0* c, int key);
extern "C" void* SpriteEntryList_Find(struct Container0205a3d0* c, int key);
extern "C" void SpriteContext_DrawEntries(void* obj);

struct Elem0205a3d0_021aad8c {
    char pad0[4];
    short field4;
    short field6;
    char pad8[0x15 - 8];
    unsigned char unknown_15_;
};

struct Global02d8_021aad8c {
    char pad0[Enum_ov017_021aad8c_728];
    void* unknown_2d8_;
    char pad1[4];
    void* unknown_2e0_;
    unsigned short unknown_2e4_;
};

struct Struct_ov017_021aad8c_2 {
    char pad0[0x14];
    int state;
    void* unknown_18_;
    char pad2[0x28];
    short* unknown_44_;
    short unknown_48_;
};

// USA: func_ov017_021aad8c
extern "C" ARM void func_ov017_021aad8c(struct Struct_ov017_021aad8c_2* self) {
    if (self->state != 5) return;

    if (self->unknown_18_ != NULL) {
        void* list = self->unknown_18_;
        func_0207fcb8((struct Struct_0207fcb8*)list);
        func_0207fd00((struct Struct_0207fd00*)list);
        func_0207fe80(list, 2, 1, 1);
        func_0207fd44((struct Struct_0207fd44_2*)list);
    }

    if (self->unknown_44_ == NULL) return;
    if (self->unknown_48_ < 0) return;
    if (func_02081da8((struct Struct_0207fdcc_2*)self->unknown_18_, self->unknown_48_) == NULL) return;

    short var1, var2;
    func_020809c4(self->unknown_18_, self->unknown_48_, *self->unknown_44_, &var1, &var2);
    var1 -= 0x10;
    var2 -= 3;

    struct Global02d8_021aad8c* g = (struct Global02d8_021aad8c*)MessageSystem_GetInstance();
    void* cont = g->unknown_2e0_;
    int key = g->unknown_2e4_;
    void* p2d8 = g->unknown_2d8_;
    if (p2d8 != NULL && cont != NULL) {
        GameState* battle = GameState::GetInstance();
        unsigned int scaleCount = battle->GetTickCount();
        SpriteEntryList_AdvanceAnimations((struct Container0205a330*)cont, scaleCount);
        SpriteEntryList_PlayAnimation((struct Container0205a3d0*)cont, key);

        struct Elem0205a3d0_021aad8c* e1 = (struct Elem0205a3d0_021aad8c*)SpriteEntryList_Find((struct Container0205a3d0*)cont, key);
        if (e1 != NULL) e1->unknown_15_ |= 8;

        short a;
        short b = var2;
        a = var1;
        struct Elem0205a3d0_021aad8c* e2 = (struct Elem0205a3d0_021aad8c*)SpriteEntryList_Find((struct Container0205a3d0*)cont, key);
        if (e2 != NULL) {
            e2->field4 = a;
            e2->field6 = b;
        }

        SpriteContext_DrawEntries(p2d8);
    }
}
