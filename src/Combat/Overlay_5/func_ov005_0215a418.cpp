#if defined(jpn)
#define func_ov005_0215a418 func_ov005_0215b96c
#endif

#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Graphics/Vector.h>
#include "Resource/GameResources.h"


#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

extern "C" void G3_MultMtx43(int cmd);

extern "C" char* func_ov017_021a193c(int*);
struct Field150Holder02052e14;
extern "C" short* func_02052e14(Field150Holder02052e14*);
extern "C" void SprSprite_DrawGroup(void* obj, int val, int param1);

extern const unsigned char data_ov005_0215cc1c[];

#define G3_MTX_PUSH  (*(volatile int*)0x04000444)
#define G3_MTX_POP   (*(volatile int*)0x04000448)
#define G3_MTX_SCALE (*(volatile int*)0x0400046c)
#define G3_MTX_TRANS (*(volatile int*)0x04000470)

struct Entry0215a418 { char data[0x88]; };

struct Struct_ov005_0215a418_3 {
    char pad[0x1000];
    Entry0215a418 entries[1];
};

struct Struct_ov005_0215a418 {
    char pad0[LOW_REGION(0x19e8, 0x1a70)];
    Entry0215a418 entries[(LOW_REGION(0x3d30, 0x3db8) - LOW_REGION(0x19e8, 0x1a70)) / 0x88];
    char pad1[LOW_REGION(0x3d30, 0x3db8) - LOW_REGION(0x19e8, 0x1a70) - ((LOW_REGION(0x3d30, 0x3db8) - LOW_REGION(0x19e8, 0x1a70)) / 0x88) * 0x88];
    unsigned char mode;
    char pad2[3];
    unsigned char cursor;
};

// USA: func_ov005_0215a418
extern "C" ARM void func_ov005_0215a418(Struct_ov005_0215a418* self) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = GetGameResources();
    char* holder = func_ov017_021a193c((int*)res->unknown_ptr_array_3700[2]);
    short* tbl = func_02052e14((Field150Holder02052e14*)(func_0200ff1c(gs,*(int*)(holder + LOW_REGION(0x4f8, 0x4fc)))));
    if (self->mode != 0) return;

    for (int i = 0; i < 8; i++) {
        int sel = 0;
        if (i == self->cursor) sel = 1;
        int k = sel * 11;
        int y = (i * 0x18) << 12;
        G3_MTX_PUSH = 0;
        G3_MTX_TRANS = 0x7f000;
        int off = (k + 4) * 0x88;
        Entry0215a418* ents = ((Struct_ov005_0215a418_3*)((char*)self + LOW_REGION(0x9e8, 0xa70)))->entries;
        G3_MTX_TRANS = y;
        G3_MTX_TRANS = -0x200000;
        SprSprite_DrawGroup((Entry0215a418*)((char*)ents + off), 0, 1);
        G3_MTX_POP = 1;
        G3_MTX_PUSH = 0;
        G3_MTX_TRANS = 0x100000;
        G3_MTX_TRANS = y;
        G3_MTX_TRANS = -0x200000;
        Matrix4x3 mtxCopy = RotationMatrixY(0x3244);
        G3_MultMtx43((int)&mtxCopy);
        SprSprite_DrawGroup((Entry0215a418*)((char*)ents + off), 0, 1);
        G3_MTX_POP = 1;
        G3_MTX_PUSH = 0;
        G3_MTX_TRANS = 0x70000;
        G3_MTX_TRANS = y;
        G3_MTX_TRANS = -0x200000;
        G3_MTX_SCALE = 0x14000;
        G3_MTX_SCALE = 0x1000;
        G3_MTX_SCALE = 0x1000;
        SprSprite_DrawGroup(&self->entries[k + 5], 0, 1);
        G3_MTX_POP = 1;
        Entry0215a418* e = &self->entries[k + 7 + i];
        if (tbl[data_ov005_0215cc1c[i]] > 0) {
            e = &self->entries[k + 6];
        }
        G3_MTX_PUSH = 0;
        G3_MTX_TRANS = 0x85000;
        G3_MTX_TRANS = y;
        G3_MTX_TRANS = -0x1ff000;
        SprSprite_DrawGroup(e, 0, 1);
        G3_MTX_POP = 1;
    }
}
