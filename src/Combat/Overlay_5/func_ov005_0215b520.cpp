#include <globaldefs.h>
#include "Graphics/Background.h"
#include "Resource/GameResources.h"
#include "Graphics/Vector.h"
#include "GameState/GameState.h"


#if defined(jpn)
#define REGION(j,u) (j)
#define data_ov005_0215cbec data_ov005_0215dfcc
#define data_ov005_0215cbdc data_ov005_0215dfbc
#else
#define REGION(j,u) (u)
#endif

struct MemberScreen {
    char unknown[REGION(0x4f8,0x4fc)];
    int member;
};

extern "C" void G3_MultMtx43(int cmd);

struct Struct_02000c9c_91;
extern "C" void Background_DrawScreen(struct BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);
struct BackgroundGraphics;
extern "C" void Background_ClearMap(struct BackgroundGraphics* obj, void* p);
extern "C" void Background_FlushMap(void* p, int flag);
extern "C" void SprSprite_DrawGroup(void* obj, int val, int param1);
extern "C" void func_ov005_0215792c(void* obj, unsigned char mode);
extern "C" void func_ov005_021579ec(void* obj, unsigned int a, unsigned char b);
extern "C" void func_ov005_02154d34(void* obj, int a, int b);
extern "C" void func_ov005_02154d7c(void* obj, int a, int b);
extern "C" MemberScreen* func_ov017_021a193c(int* p);
struct GameState;
struct Field150Holder02052e14;
extern "C" short* func_02052e14(Field150Holder02052e14*);

extern const unsigned char data_ov005_0215cbec[];
extern const unsigned char data_ov005_0215cbdc[];

#define G3_MTX_PUSH  (*(volatile int*)0x04000444)
#define G3_MTX_POP   (*(volatile int*)0x04000448)
#define G3_MTX_SCALE (*(volatile int*)0x0400046c)
#define G3_MTX_TRANS (*(volatile int*)0x04000470)

struct Struct_ov005_0215b520 {
    char data[0x88];
};

struct ItemTable;
struct Element020de650;
struct Struct_ov003_02178910 {
    char pad0[0x48];
    ItemTable* field48;
    Element020de650* field4c;
    char unknown_50_[REGION(0x680,0x704)];
    int field754;
    char unknown_758_[0x18];
    short field770;
    unsigned short unknown_772_;
    unsigned short flags;
    unsigned char unknown_776_;
};
struct Struct_ov005_02153ba4 {
    short item;
    signed char count;
    unsigned char equipped;
    void* vramState;
    Struct_ov005_0215b520* model;
    int x, y, offset;
    short unknown_18_;
};
extern "C" void func_ov023_021dcba4(void*, short);

struct Struct_ov005_0215b520_2 {
    char pad0[REGION(0xea0,0xea4)];
    BackgroundGraphics list;
    char unknown_ec4_[0x1244 - 0xec4];
    Struct_ov003_02178910 unknown_1244_;
    char unknown_19bc_[REGION(0x19ac - 0x1240,0x1a34 - 0x1244) - sizeof(Struct_ov003_02178910)];
    char motion[0x3c];
    Struct_ov005_0215b520 models[36];
    Struct_ov005_02153ba4 slots[24];
    Struct_ov005_0215b520 unknown_3030_[24];
    Struct_ov005_0215b520 unknown_3cf0_;
    short unknown_3d78_;
    char unknown_3d7a_[0x3db8 - 0x3d7a];
    unsigned char mode;
    char pad4;
    unsigned char state;
    signed char unknown_3dbb_;
    unsigned char cursor;
    char pad5[0x3dcc - 0x3dbd];
    unsigned int flags;
    char pad6[0x3de2 - 0x3dd0];
    short level;
    int step;
    int accum;
    int phase;
};

// USA: func_ov005_0215b520
extern "C" ARM void func_ov005_0215b520(Struct_ov005_0215b520_2* self) {
    unsigned char state = self->state;
    if (state == 0 && self->phase == 0) {
        func_ov005_0215792c(self, 1);
        self->flags |= 0x100;
        void* gs = (void*)GameState::GetInstance();
        GameResources* res = GetGameResources();
        MemberScreen* holder = func_ov017_021a193c((int*)res->unknown_ptr_array_3700[2]);
        short* tbl = func_02052e14((Field150Holder02052e14*)func_0200ff1c((GameState*)gs, holder->member));
        self->accum += self->step;
        if (self->accum >= 3) {
            self->accum -= 3;
            self->level += 0x29;
            if (self->level >= 0x7b) {
                self->level = 0x7b;
                self->phase = 1;
            }
        }
        if (self->mode == 1) {
            for (int i = 0; i < 8; i++) {
                int sel = 0;
                if (i == self->cursor) sel = 1;
                int k = sel * 11;
                int y = (i * 0x18) << 12;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (self->level + 0x7f) << 12;
                G3_MTX_TRANS = y;
                G3_MTX_TRANS = -0x200000;
                SprSprite_DrawGroup(&self->models[k + 4], 0, 1);
                G3_MTX_POP = 1;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (self->level + 0x100) << 12;
                G3_MTX_TRANS = y;
                G3_MTX_TRANS = -0x200000;
                Matrix4x3 rot;
                rot = RotationMatrixY(0x3244);
                G3_MultMtx43((int)&rot);
                SprSprite_DrawGroup(&self->models[k + 4], 0, 1);
                G3_MTX_POP = 1;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (self->level + 0x70) << 12;
                G3_MTX_TRANS = y;
                G3_MTX_TRANS = -0x200000;
                G3_MTX_SCALE = 0x14000;
                G3_MTX_SCALE = 0x1000;
                G3_MTX_SCALE = 0x1000;
                SprSprite_DrawGroup(&self->models[k + 5], 0, 1);
                G3_MTX_POP = 1;
                Struct_ov005_0215b520* e = &self->models[k + 7 + i];
                if (tbl[data_ov005_0215cbec[i]] > 0) {
                    e = &self->models[k + 6];
                }
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (self->level + 0x85) << 12;
                G3_MTX_TRANS = y;
                G3_MTX_TRANS = -0x1ff000;
                SprSprite_DrawGroup(e, 0, 1);
                G3_MTX_POP = 1;
            }
        }
        if (self->phase == 1) {
            self->state++;
            self->level = 0;
            self->accum = 0;
            self->phase = 0;
        }
    } else if (state == 1 && self->phase == 0) {
        self->flags |= 0x100;
        self->accum += self->step;
        if (self->accum >= 3) {
            self->accum -= 3;
            self->level += 6;
            if (self->level >= 0x10) {
                self->level = 0x10;
                self->phase = 1;
            }
        }
        Background_ClearMap((struct BackgroundGraphics*)&self->list, 0);
        Background_DrawScreen(&self->list, 0, 0, 0, 0x20 - self->level, 0, 0x10, 0x16, 0xffff);
        unsigned char cursor = self->cursor;
        short y = cursor * 2 + 0xf;
        Background_DrawScreen(&self->list, (unsigned char)(cursor + 1), 0, 0, y + 0x10 - self->level, 0, 4, 3, 0xffff);
        Background_FlushMap(&self->list, 0);
        if (self->phase == 1) {
            self->state++;
            self->level = 0;
            self->accum = 0;
        }
    } else if (state == 2 && self->phase == 1) {
        func_ov005_0215792c(self, 3);
        self->flags |= 0x100;
        func_ov005_021579ec(self, self->mode, self->unknown_3dbb_);
        func_ov005_02154d34(self->motion, 0x85000, 0x17000);
        func_ov005_02154d7c(self->motion, 0x76000, 0x16000);
        self->flags |= 0x800;
    } else if (state == 0 && self->phase == 1) {
        self->flags |= 0x800;
        func_ov005_0215792c(self, 1);
        self->flags |= 0x100;
        self->accum += self->step;
        if (self->accum >= 3) {
            self->accum -= 3;
            self->level += 6;
            if (self->level >= 0x10) {
                self->level = 0x10;
                self->phase = 2;
            }
        }
        Background_ClearMap((struct BackgroundGraphics*)&self->list, 0);
        Background_DrawScreen(&self->list, 0, 0, 0, self->level + 0x10, 0, 0x10, 0x16, 0xffff);
        unsigned char cursor = self->cursor;
        short y = cursor * 2 + 0xf;
        Background_DrawScreen(&self->list, (unsigned char)(cursor + 1), 0, 0, y + self->level, 0, 4, 3, 0xffff);
        Background_FlushMap(&self->list, 0);
        if (self->phase == 2) {
            self->state++;
            self->level = 0;
            self->accum = 0;
        }
    } else if (state == 1 && self->phase == 2) {
        void* gs = (void*)GameState::GetInstance();
        GameResources* res = GetGameResources();
        MemberScreen* holder = func_ov017_021a193c((int*)res->unknown_ptr_array_3700[2]);
        short* tbl = func_02052e14((Field150Holder02052e14*)func_0200ff1c((GameState*)gs, holder->member));
        self->accum += self->step;
        if (self->accum >= 3) {
            self->accum -= 3;
            self->level += 0x29;
            if (self->level >= 0x7b) {
                self->level = 0x7b;
                self->phase = 1;
            }
        }
        if (self->mode == 1) {
            for (int i = 0; i < 8; i++) {
                int sel = 0;
                if (i == self->cursor) sel = 1;
                int k = sel * 11;
                int y = (i * 0x18) << 12;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (0xfa - self->level) << 12;
                G3_MTX_TRANS = y;
                G3_MTX_TRANS = -0x200000;
                SprSprite_DrawGroup(&self->models[k + 4], 0, 1);
                G3_MTX_POP = 1;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (0x17b - self->level) << 12;
                G3_MTX_TRANS = y;
                G3_MTX_TRANS = -0x200000;
                Matrix4x3 rot;
                rot = RotationMatrixY(0x3244);
                G3_MultMtx43((int)&rot);
                SprSprite_DrawGroup(&self->models[k + 4], 0, 1);
                G3_MTX_POP = 1;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (0xeb - self->level) << 12;
                G3_MTX_TRANS = y;
                G3_MTX_TRANS = -0x200000;
                G3_MTX_SCALE = 0x14000;
                G3_MTX_SCALE = 0x1000;
                G3_MTX_SCALE = 0x1000;
                SprSprite_DrawGroup(&self->models[k + 5], 0, 1);
                G3_MTX_POP = 1;
                Struct_ov005_0215b520* e = &self->models[k + 7 + i];
                if (tbl[data_ov005_0215cbdc[i]] > 0) {
                    e = &self->models[k + 6];
                }
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (0x100 - self->level) << 12;
                G3_MTX_TRANS = y;
                G3_MTX_TRANS = -0x1ff000;
                SprSprite_DrawGroup(e, 0, 1);
                G3_MTX_POP = 1;
            }
        }
        if (self->phase == 1) {
            self->state = 0;
            self->level = 0;
            self->accum = 0;
            self->phase = 0;
            func_ov005_0215792c(self, 0);
            self->flags |= 0x100;
        }
    }
#if defined(jpn)
    func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_3700[2]);
    short item = self->slots[self->unknown_3dbb_].item;
    self->unknown_1244_.flags |= 0x80;
    func_ov023_021dcba4(&self->unknown_1244_, item);
#endif

}
