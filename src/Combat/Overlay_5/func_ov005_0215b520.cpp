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

struct Struct_ov005_02153ba4_2 {
    char unknown_0_[REGION(0x4f8,0x4fc)];
    int unknown_4fc_;
};

extern "C" void G3_MultMtx43(int cmd);

struct BackgroundResourceEntry;
void Background_DrawScreen(struct BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);
struct BackgroundGraphics;
void Background_ClearMap(struct BackgroundGraphics* obj, void* p);
extern "C" void Background_FlushMap(void* p, int flag);
extern "C" void SprSprite_DrawGroup(void* obj, int val, int param1);
extern "C" void func_ov005_0215792c(void* obj, unsigned char mode);
extern "C" void func_ov005_021579ec(void* obj, unsigned int a, unsigned char b);
extern "C" void func_ov005_02154d34(void* obj, int a, int b);
extern "C" void func_ov005_02154d7c(void* obj, int a, int b);
MemberScreen* GetField1c_021a193c(int* p);
struct GameState;
struct Struct_02052e14;
extern "C" short* func_02052e14(Struct_02052e14*);

extern const unsigned char data_ov005_0215cbec[];
extern const unsigned char data_ov005_0215cbdc[];

#define G3_MTX_PUSH  (*(volatile int*)0x04000444)
#define G3_MTX_POP   (*(volatile int*)0x04000448)
#define G3_MTX_SCALE (*(volatile int*)0x0400046c)
#define G3_MTX_TRANS (*(volatile int*)0x04000470)

struct Struct_ov005_0215b520 {
    char unknown_0_[0x88];
};

struct ItemTable;
struct Element020de650;
struct Obj021dcae0 {
    char pad0[0x48];
    ItemTable* field48;
    Element020de650* field4c;
    char pad50[REGION(0x680,0x704)];
    int field754;
    char pad758[0x18];
    short field770;
    unsigned short field772;
    unsigned short flags;
    unsigned char field776;
};
struct Struct_ov005_02153ba4 {
    short unknown_0_;
    signed char unknown_2_;
    unsigned char unknown_3_;
    void* unknown_4_;
    Struct_ov005_0215b520* unknown_8_;
    int unknown_c_, unknown_10_, unknown_14_;
    short unknown_18_;
};
extern "C" void func_ov023_021dcba4(void*, short);

struct Scene0215b520 {
    char pad0[REGION(0xea0,0xea4)];
    BackgroundGraphics list;
    char beforeInfo[0x1244 - 0xec4];
    Obj021dcae0 infoWindow;
    char beforeMotion[REGION(0x19ac - 0x1240,0x1a34 - 0x1244) - sizeof(Obj021dcae0)];
    char motion[0x3c];
    Entry0215b520 models[36];
    EquipmentSlot slots[24];
    Entry0215b520 slotModels[24];
    Entry0215b520 dragModel;
    short dragged;
    char beforeMode[0x3db8 - 0x3d7a];
    unsigned char mode;
    char pad4;
    unsigned char state;
    signed char modeB;
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
extern "C" ARM void func_ov005_0215b520(Scene0215b520* self) {
    unsigned char state = self->state;
    if (state == 0 && self->phase == 0) {
        func_ov005_0215792c(self, 1);
        self->flags |= 0x100;
        void* gs = (void*)GameState::GetInstance();
        GameResources* res = GetGameResources();
        MemberScreen* holder = GetField1c_021a193c((int*)res->unknown_ptr_array_3700[2]);
        short* tbl = GetField150Ptr0x488((Field150Holder02052e14*)GetCombatantWithFlag0x100_0200ff1c((GameState*)gs, holder->member));
        self->accum += self->step;
        if (self->accum >= 3) {
            self->accum -= 3;
            self->level += 0x29;
            if (self->level >= 0x7b) {
                self->level = 0x7b;
                self->phase = 1;
            }
        }
        if (arg0->unknown_3db8_ == 1) {
            for (int var5 = 0; var5 < 8; var5++) {
                int var6 = 0;
                if (var5 == arg0->unknown_3dbc_) var6 = 1;
                int var7 = var6 * 11;
                int var8 = (var5 * 0x18) << 12;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (arg0->unknown_3de2_ + 0x7f) << 12;
                G3_MTX_TRANS = var8;
                G3_MTX_TRANS = -0x200000;
                SprSprite_DrawGroup(&self->models[k + 4], 0, 1);
                G3_MTX_POP = 1;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (arg0->unknown_3de2_ + 0x100) << 12;
                G3_MTX_TRANS = var8;
                G3_MTX_TRANS = -0x200000;
                Matrix4x3 rot;
                rot = RotationMatrixY(0x3244);
                G3_MultMtx43((int)&rot);
                SprSprite_DrawGroup(&self->models[k + 4], 0, 1);
                G3_MTX_POP = 1;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (arg0->unknown_3de2_ + 0x70) << 12;
                G3_MTX_TRANS = var8;
                G3_MTX_TRANS = -0x200000;
                G3_MTX_SCALE = 0x14000;
                G3_MTX_SCALE = 0x1000;
                G3_MTX_SCALE = 0x1000;
                SprSprite_DrawGroup(&self->models[k + 5], 0, 1);
                G3_MTX_POP = 1;
                Struct_ov005_0215b520* var10 = &arg0->unknown_1a70_[var7 + 7 + var5];
                if (var4[data_ov005_0215cbec[var5]] > 0) {
                    var10 = &arg0->unknown_1a70_[var7 + 6];
                }
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (arg0->unknown_3de2_ + 0x85) << 12;
                G3_MTX_TRANS = var8;
                G3_MTX_TRANS = -0x1ff000;
                SprSprite_DrawGroup(e, 0, 1);
                G3_MTX_POP = 1;
            }
        }
        if (arg0->unknown_3dec_ == 1) {
            arg0->unknown_3dba_++;
            arg0->unknown_3de2_ = 0;
            arg0->unknown_3de8_ = 0;
            arg0->unknown_3dec_ = 0;
        }
    } else if (var0 == 1 && arg0->unknown_3dec_ == 0) {
        arg0->unknown_3dcc_ |= 0x100;
        arg0->unknown_3de8_ += arg0->unknown_3de4_;
        if (arg0->unknown_3de8_ >= 3) {
            arg0->unknown_3de8_ -= 3;
            arg0->unknown_3de2_ += 6;
            if (arg0->unknown_3de2_ >= 0x10) {
                arg0->unknown_3de2_ = 0x10;
                arg0->unknown_3dec_ = 1;
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
    } else if (var0 == 2 && arg0->unknown_3dec_ == 1) {
        func_ov005_0215792c(arg0, 3);
        arg0->unknown_3dcc_ |= 0x100;
        func_ov005_021579ec(arg0, arg0->unknown_3db8_, arg0->unknown_3dbb_);
        func_ov005_02154d34(arg0->unknown_1a34_, 0x85000, 0x17000);
        func_ov005_02154d7c(arg0->unknown_1a34_, 0x76000, 0x16000);
        arg0->unknown_3dcc_ |= 0x800;
    } else if (var0 == 0 && arg0->unknown_3dec_ == 1) {
        arg0->unknown_3dcc_ |= 0x800;
        func_ov005_0215792c(arg0, 1);
        arg0->unknown_3dcc_ |= 0x100;
        arg0->unknown_3de8_ += arg0->unknown_3de4_;
        if (arg0->unknown_3de8_ >= 3) {
            arg0->unknown_3de8_ -= 3;
            arg0->unknown_3de2_ += 6;
            if (arg0->unknown_3de2_ >= 0x10) {
                arg0->unknown_3de2_ = 0x10;
                arg0->unknown_3dec_ = 2;
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
        MemberScreen* holder = GetField1c_021a193c((int*)res->unknown_ptr_array_3700[2]);
        short* tbl = GetField150Ptr0x488((Field150Holder02052e14*)GetCombatantWithFlag0x100_0200ff1c((GameState*)gs, holder->member));
        self->accum += self->step;
        if (self->accum >= 3) {
            self->accum -= 3;
            self->level += 0x29;
            if (self->level >= 0x7b) {
                self->level = 0x7b;
                self->phase = 1;
            }
        }
        if (arg0->unknown_3db8_ == 1) {
            for (int var19 = 0; var19 < 8; var19++) {
                int var20 = 0;
                if (var19 == arg0->unknown_3dbc_) var20 = 1;
                int var21 = var20 * 11;
                int var22 = (var19 * 0x18) << 12;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (0xfa - arg0->unknown_3de2_) << 12;
                G3_MTX_TRANS = var22;
                G3_MTX_TRANS = -0x200000;
                SprSprite_DrawGroup(&self->models[k + 4], 0, 1);
                G3_MTX_POP = 1;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (0x17b - arg0->unknown_3de2_) << 12;
                G3_MTX_TRANS = var22;
                G3_MTX_TRANS = -0x200000;
                Matrix4x3 rot;
                rot = RotationMatrixY(0x3244);
                G3_MultMtx43((int)&rot);
                SprSprite_DrawGroup(&self->models[k + 4], 0, 1);
                G3_MTX_POP = 1;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (0xeb - arg0->unknown_3de2_) << 12;
                G3_MTX_TRANS = var22;
                G3_MTX_TRANS = -0x200000;
                G3_MTX_SCALE = 0x14000;
                G3_MTX_SCALE = 0x1000;
                G3_MTX_SCALE = 0x1000;
                SprSprite_DrawGroup(&self->models[k + 5], 0, 1);
                G3_MTX_POP = 1;
                Struct_ov005_0215b520* var24 = &arg0->unknown_1a70_[var21 + 7 + var19];
                if (var18[data_ov005_0215cbdc[var19]] > 0) {
                    var24 = &arg0->unknown_1a70_[var21 + 6];
                }
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (0x100 - arg0->unknown_3de2_) << 12;
                G3_MTX_TRANS = var22;
                G3_MTX_TRANS = -0x1ff000;
                SprSprite_DrawGroup(e, 0, 1);
                G3_MTX_POP = 1;
            }
        }
        if (arg0->unknown_3dec_ == 1) {
            arg0->unknown_3dba_ = 0;
            arg0->unknown_3de2_ = 0;
            arg0->unknown_3de8_ = 0;
            arg0->unknown_3dec_ = 0;
            func_ov005_0215792c(arg0, 0);
            arg0->unknown_3dcc_ |= 0x100;
        }
    }
#if defined(jpn)
    GetField1c_021a193c((int*)GetGameResources()->unknown_ptr_array_3700[2]);
    short item = self->slots[self->modeB].item;
    self->infoWindow.flags |= 0x80;
    func_ov023_021dcba4(&self->infoWindow, item);
#endif

}
