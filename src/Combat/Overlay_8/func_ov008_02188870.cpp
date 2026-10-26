#include <globaldefs.h>
#include "GameState/GameState.h"

struct GridCursor;
extern "C" int GridCursor_GetSelectedIndex(struct GridCursor* s);

struct Container0205a3d0;
struct Container0205a330;

extern "C" void SpriteEntryList_SetFirstObject(struct Container0205a3d0* c, int key, int val);
extern "C" void SpriteEntryList_PlayAnimation(struct Container0205a3d0* c, int key);
extern "C" void SpriteEntryList_AdvanceAnimations(struct Container0205a330* c, int arg);

struct Elem02188870 {
    char unk0[4];
    unsigned short f4;
    unsigned short unknown_6_;
    char unknown_8_[0x15 - 8];
    unsigned char f15;
};
extern "C" struct Elem02188870* SpriteEntryList_Find(struct Container0205a3d0* c, int key);


extern "C" void SpriteContext_DrawEntries(void* obj);

struct Struct_ov008_02188870_2 {
    char pad0[0x730];
    void* f730;
    char pad1[0x738 - 0x734];
    void* f738;
    char pad2[0xb18 - 0x73c];
    unsigned int unknown_b18_;
    char pad3[0xb29 - 0xb1c];
    unsigned char unknown_b29_;
};

// USA: func_ov008_02188870
extern "C" ARM void func_ov008_02188870(struct Struct_ov008_02188870_2* obj) {
    if (obj->f730 == 0) return;
    if (!(obj->unknown_b18_ & 8)) return;
    if (!(obj->unknown_b18_ & 0x80000)) return;

    GameState* battle = GameState::GetInstance();
    int sum = GridCursor_GetSelectedIndex((struct GridCursor*)((char*)obj + 0x750));
    short val = (short)(((sum - obj->unknown_b29_) << 4) + 7);

    SpriteEntryList_SetFirstObject((struct Container0205a3d0*)obj->f738, 0, 0x3f);
    SpriteEntryList_PlayAnimation((struct Container0205a3d0*)obj->f738, 0);

    struct Elem02188870* e = SpriteEntryList_Find((struct Container0205a3d0*)obj->f738, 0);
    if (e != NULL) {
        e->f15 |= 8;
    }

    unsigned int count = battle->GetTickCount();
    SpriteEntryList_AdvanceAnimations((struct Container0205a330*)obj->f738, count);

    e = SpriteEntryList_Find((struct Container0205a3d0*)obj->f738, 0);
    if (e != NULL) {
        e->f4 = 4;
        e->unknown_6_ = val;
    }

    SpriteContext_DrawEntries(obj->f730);
}
