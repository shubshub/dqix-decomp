#include <globaldefs.h>
#include "Resource/GameResources.h"

#if defined(jpn)
#define REGION(j,u) (j)
#else
#define REGION(j,u) (u)
#endif

struct MemberScreen {
    char unknown[REGION(0x4f8,0x4fc)];
    int member;
};

extern "C" long labs(long);
struct Struct_ov005_02156ecc;
struct Struct_ov005_02156ecc_2;
extern "C" void func_ov005_02157174(Struct_ov005_02156ecc*, Struct_ov005_02156ecc_2*);
struct StructAt020473c8;
extern "C" void func_020473c8(StructAt020473c8*, int);
extern "C" void SprSprite_DrawGroup(void* obj, int val, int param1);
struct ItemTable;
extern "C" void* ItemTable_Find(ItemTable*, int);
extern "C" MemberScreen* func_ov017_021a193c(int* p);
extern "C" int func_020dd4c4(char a, void* b);
extern "C" void func_ov005_02154d18(void* obj, int a, int b);
extern "C" void func_ov005_02154d34(void* obj, int a, int b);
extern "C" void func_ov005_02154d50(void* obj, int a, int b);
extern "C" void func_ov005_02154d7c(void* obj, int a, int b);

#define G3_MTX_PUSH  (*(volatile int*)0x04000444)
#define G3_MTX_POP   (*(volatile int*)0x04000448)
#define G3_MTX_TRANS (*(volatile int*)0x04000470)

struct Struct_ov005_02159c88 { int x; int y; int z; };

struct Struct_ov005_02159c88_2 {
    char pad0[0x1c];
    Struct_ov005_02159c88 pos;
    char pad1[0x80 - 0x28];
    short color;
    short timer;
    char unknown84[4];
};

struct Struct_ov005_02159c88_3 {
    short id;
    char pad[6];
    Struct_ov005_02159c88_2* obj;
    int x;
    int y;
    int pad2[2];
};

struct Struct_ov005_02159c88_4 {
    char pad0[0xdf4];
    void* container;
    char pad1[REGION(0x19ac,0x1a34) - 0xdf8];
    char frame;
    char pad2[0x2c80 - 0x1a35];
    char unknown_2c80_[0x80];
    short unknown_2d00_;
    char pad3[0x2d08 - 0x2d02];
    char entry2d08[0x80];
    short unknown_2d88_;
    char pad4[0x2d90 - 0x2d8a];
    Struct_ov005_02159c88_3 slots[0x18];
    Struct_ov005_02159c88_2 unknown_3030_[24];
    Struct_ov005_02159c88_2 unknown_3cf0_;
    short selected;
    char unknown_3d7a_[0x3da8 - 0x3d7a];
    unsigned char unknown_3da8_;
    unsigned char unknown_3da9_;
    char padA[1];
    unsigned char unknown_3dab_;
    char unknown_3dac_[0x3db8 - 0x3dac];
    unsigned char mode;
    char unknown_3db9_[2];
    signed char cursor;
    unsigned char cursor2;
};

// USA: func_ov005_02159c88
extern "C" ARM void func_ov005_02159c88(Struct_ov005_02159c88_4* self) {
    for (int n = 0; n < 0x1f; n++) {
        for (int i = 0; i < 0x18; i++) {
            Struct_ov005_02159c88_3* s = &self->slots[i];
            int px, var4, cx, var6, dx, dy;
            Struct_ov005_02159c88_2* o;
            o = s->obj;
            if (i != self->selected && s->id >= 0) {
                cx = o->pos.x;
                px = s->x;
                var4 = s->y;
                var6 = o->pos.y;
                dx = px - cx;
                dy = var4 - var6;
                if (dx != 0 || dy != 0) {
                    Struct_ov005_02159c88 t;
                    t.x = (int)((float)cx + 0.01f * (float)dx);
                    t.y = (int)((float)var6 + 0.01f * (float)dy);
                    t.z = 0;
                    if (labs(px - t.x) < 0x800 && labs(var4 - t.y) < 0x800) {
                        t.x = px;
                        t.y = var4;
                        t.z = 0;
                    }
                    func_ov005_02157174((Struct_ov005_02156ecc*)o, (Struct_ov005_02156ecc_2*)&t);
                }
            }
        }
    }
    for (int k = 0; k < 24; k++) {
        if (self->unknown_3030_[k].timer < 0x1f)
            self->unknown_3030_[k].timer++;
    }
    if (self->selected >= 0 && self->unknown_3cf0_.timer < 0x1f)
        self->unknown_3cf0_.timer = self->unknown_3cf0_.timer + 1;
    if (self->mode == 0) {
        for (int i = 0; i < 8; i++) {
            Struct_ov005_02159c88_3* s = &self->slots[i];
            if (i != self->selected && s->id >= 0) {
                Struct_ov005_02159c88_2* o = s->obj;
                Struct_ov005_02159c88 v = o->pos;
                v.y = (i * 0x18) << 12;
                func_ov005_02157174((Struct_ov005_02156ecc*)o, (Struct_ov005_02156ecc_2*)&v);
                G3_MTX_PUSH = 0;
                func_020473c8((StructAt020473c8*)o, 1);
                G3_MTX_POP = 1;
                if (self->unknown_3da8_ == 0 && self->unknown_3da9_ == 0) {
                    int tx = v.x + REGION(0x11000,0x8000);
                    int ty = v.y + REGION(0x10000,0x8000);
                    int var18 = v.z + 0x1000;
                    G3_MTX_PUSH = 0;
                    G3_MTX_TRANS = tx;
                    G3_MTX_TRANS = ty;
                    G3_MTX_TRANS = var18;
                    self->unknown_2d88_ = 0xf0a;
                    SprSprite_DrawGroup(self->entry2d08, 0, 1);
                    G3_MTX_POP = 1;
                }
            }
        }
    } else {
        for (int i = 0; i < 0x18; i++) {
            Struct_ov005_02159c88_3* s = &self->slots[i];
            int c = self->cursor;
            if (i == c && c >= 8 && c < 0x18) {
                int px = s->x;
                int var23 = s->y;
                Struct_ov005_02159c88 p = s->obj->pos;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = px;
                G3_MTX_TRANS = var23;
                G3_MTX_TRANS = p.z - 0x1000;
                self->unknown_2d00_ = 0x25f;
                func_020473c8((StructAt020473c8*)self->unknown_2c80_, 1);
                G3_MTX_POP = 1;
            }
            int id = s->id;
            if (id >= 0) {
                void* elem = ItemTable_Find((ItemTable*)self->container, (short)id);
                if (elem != 0) {
                    Struct_ov005_02159c88_2* o = s->obj;
                    GameResources* res = GetGameResources();
                    MemberScreen* holder = func_ov017_021a193c((int*)res->unknown_ptr_array_3700[2]);
                    if (func_020dd4c4(holder->member, elem) != 0) {
                        int px = s->x;
                        int var31 = s->y;
                        Struct_ov005_02159c88 p = o->pos;
                        if (i >= 8 && i < 0x18) {
                            G3_MTX_PUSH = 0;
                            G3_MTX_TRANS = px;
                            G3_MTX_TRANS = var31;
                            G3_MTX_TRANS = p.z - 0x1000;
                            self->unknown_2d00_ = 0x1ce7;
                            func_020473c8((StructAt020473c8*)self->unknown_2c80_, 1);
                            G3_MTX_POP = 1;
                        }
                        o->color = 0x3def;
                    } else {
                        o->color = 0x7fff;
                    }
                }
                if (i != self->selected) {
                    Struct_ov005_02159c88_2* o = s->obj;
                    if (i == self->cursor2 || i >= 8) {
                        G3_MTX_PUSH = 0;
                        func_020473c8((StructAt020473c8*)o, 1);
                        G3_MTX_POP = 1;
                        if (i < 8) {
                            if (self->unknown_3da8_ == 0 && self->unknown_3da9_ == 0) {
                                Struct_ov005_02159c88 v = o->pos;
                                G3_MTX_PUSH = 0;
                                G3_MTX_TRANS = v.x + REGION(0x11000,0x8000);
                                G3_MTX_TRANS = v.y + REGION(0x10000,0x8000);
                                G3_MTX_TRANS = v.z + 0x1000;
                                self->unknown_2d88_ = 0xf0a;
                                SprSprite_DrawGroup(self->entry2d08, 0, 1);
                                G3_MTX_POP = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    if (self->selected >= 0 && self->unknown_3dab_ == 0) {
        G3_MTX_PUSH = 0;
        func_020473c8((StructAt020473c8*)&self->unknown_3cf0_, 1);
        G3_MTX_POP = 1;
        Struct_ov005_02159c88 v = self->unknown_3cf0_.pos;
        func_ov005_02154d18(&self->frame, v.x, v.y);
        func_ov005_02154d34(&self->frame, v.x, v.y);
        func_ov005_02154d50(&self->frame, 0x18000, 0x18000);
        func_ov005_02154d7c(&self->frame, 0x18000, 0x18000);
        if (self->selected < 8 && self->unknown_3dab_ == 0) {
            Struct_ov005_02159c88 w = self->unknown_3cf0_.pos;
            G3_MTX_PUSH = 0;
            G3_MTX_TRANS = w.x + REGION(0x11000,0x8000);
            G3_MTX_TRANS = w.y + REGION(0x10000,0x8000);
            G3_MTX_TRANS = w.z + 0x1000;
            self->unknown_2d88_ = 0xf0a;
            SprSprite_DrawGroup(self->entry2d08, 0, 1);
            G3_MTX_POP = 1;
        }
    }
}
