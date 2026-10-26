#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_0208be8c(void);

struct Container0205a3d0;
struct Container0205a330;

struct Elem021bb930 {
    char unk0[4];
    unsigned short unk4;
    unsigned short unknown_6_;
    char unknown_8_[0x15 - 0x8];
    unsigned char unknown_15_;
};

extern "C" struct Elem021bb930* SpriteEntryList_Find(struct Container0205a3d0*, int);
extern "C" void SpriteEntryList_PlayAnimation(struct Container0205a3d0*, int);
extern "C" void SpriteEntryList_AdvanceAnimations(struct Container0205a330*, int);
extern "C" void SpriteEntryList_SetFirstObject(struct Container0205a3d0*, int, int);
extern "C" void SpriteContext_DrawEntries(void* p);

struct Struct_ov017_021bb930_2 {
    char pad0[0x3c];
    struct Container0205a3d0* c;
};

struct Struct_ov017_021bb930_3 {
#if defined(jpn)
    char pad0[0xfa];
#else
    char pad0[0xfe];
#endif
    unsigned char unknown_fe_;
    char pad1[0x120 - 0xff];
    void* unknown_120_;
    char pad2[0x168 - 0x124];
    struct Struct_ov017_021bb930_2* sub;
};

// USA: func_ov017_021bb930
extern "C" ARM void func_ov017_021bb930(struct Struct_ov017_021bb930_3* self) {
    if (self->unknown_fe_ != 0 && self->sub != NULL) {
        GameState* battleStruct = GameState::GetInstance();
        struct Container0205a3d0* c = self->sub->c;
        if (c != NULL) {
            struct Elem021bb930* e;
            unsigned int count;
            SpriteEntryList_PlayAnimation(c, 1);
            e = SpriteEntryList_Find(c, 1);
            if (e != NULL) {
                e->unknown_15_ |= 0x8;
            }
            count = battleStruct->GetTickCount();
            SpriteEntryList_AdvanceAnimations((struct Container0205a330*)c, count);
            e = SpriteEntryList_Find(c, 1);
            if (e != NULL) {
                e->unk4 = 0xd8;
                e->unknown_6_ = 0x98;
            }
            SpriteEntryList_SetFirstObject(c, 1, 6);
        }
        SpriteContext_DrawEntries(self->sub);
    }
    if (self->unknown_120_ != 0) {
        func_0208be8c();
    }
}
