#include <globaldefs.h>
#include "GameState/GameState.h"

void BlankFunction0208be8c(void);

struct Container0205a3d0;
struct Container0205a330;

struct Elem021bb930 {
    char unk0[4];
    unsigned short unk4;
    unsigned short unk6;
    char unk8[0x15 - 0x8];
    unsigned char flags15;
};

extern struct Elem021bb930* SpriteEntryList_Find(struct Container0205a3d0*, int);
extern void SpriteEntryList_PlayAnimation(struct Container0205a3d0*, int);
extern void SpriteEntryList_AdvanceAnimations(struct Container0205a330*, int);
extern void SpriteEntryList_SetFirstObject(struct Container0205a3d0*, int, int);
extern "C" void SpriteContext_DrawEntries(void* p);

struct Sub021bb930 {
    char pad0[0x3c];
    struct Container0205a3d0* c;
};

struct Obj021bb930 {
#if defined(jpn)
    char pad0[0xfa];
#else
    char pad0[0xfe];
#endif
    unsigned char flag0xfe;
    char pad1[0x120 - 0xff];
    void* field120;
    char pad2[0x168 - 0x124];
    struct Sub021bb930* sub;
};

// USA: func_ov017_021bb930  (semantic: ProcessSubEntryAndFinalize021bb930)
extern "C" ARM void func_ov017_021bb930(struct Obj021bb930* self) {
    if (self->flag0xfe != 0 && self->sub != NULL) {
        GameState* battleStruct = GameState::GetInstance();
        struct Container0205a3d0* c = self->sub->c;
        if (c != NULL) {
            struct Elem021bb930* e;
            unsigned int count;
            SpriteEntryList_PlayAnimation(c, 1);
            e = SpriteEntryList_Find(c, 1);
            if (e != NULL) {
                e->flags15 |= 0x8;
            }
            count = battleStruct->GetTickCount();
            SpriteEntryList_AdvanceAnimations((struct Container0205a330*)c, count);
            e = SpriteEntryList_Find(c, 1);
            if (e != NULL) {
                e->unk4 = 0xd8;
                e->unk6 = 0x98;
            }
            SpriteEntryList_SetFirstObject(c, 1, 6);
        }
        SpriteContext_DrawEntries(self->sub);
    }
    if (self->field120 != 0) {
        BlankFunction0208be8c();
    }
}
