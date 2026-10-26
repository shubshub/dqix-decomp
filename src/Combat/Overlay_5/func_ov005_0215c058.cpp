#include <globaldefs.h>
#include "Input/Input.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#define data_ov005_0215cd10 data_ov005_0215e0f0
#endif

struct GameState;
struct SePlayer;

struct Struct_ov005_0215c058
{
#if defined(jpn)
    char pad[0x34f8];
#else
    char pad[0x3708];
#endif
    int* ptr;
};

struct Struct_ov005_0215c058_2
{
#if defined(jpn)
    char pad0[0x4f8];
#else
    char pad0[0x4fc];
#endif
    int member;
#if defined(jpn)
    char pad1[0x56c - 0x4fc];
#else
    char pad1[0x634 - 0x500];
#endif
    unsigned short flags;
};

struct Struct_ov005_0215c058_3
{
    void* target;
    int scale;
    int minX;
    int maxX;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_[8];
    int speed;
};

struct Struct_ov005_0215c058_4
{
#if defined(jpn)
    char pad0[0x196c];
#else
    char pad0[0x19f4];
#endif
    char scroll[0x1a34 - 0x19f4];
    void* unknown_1a34_;
    char pad1[0x3daa - 0x1a38];
    unsigned char unknown_3daa_;
    char pad2[0x3db8 - 0x3dab];
    unsigned char unknown_3db8_;
    char pad3;
    unsigned char state;
    signed char selected;
    unsigned char tab;
    signed char page;
    char pad4[0x3dcc - 0x3dbe];
    struct { unsigned int b0 : 2; unsigned int f2 : 1; unsigned int f3 : 1; unsigned int unknown_0_4_ : 2; unsigned int unknown_0_6_ : 1; unsigned int rest : 25; } dirty;
    char pad5[0x3de0 - 0x3dd0];
    short held;
};

extern "C" Struct_ov005_0215c058_2* func_ov017_021a193c(int*);
extern "C" void func_ov005_021551fc(char*, int, int);
extern "C" GameState* _ZN9GameState11GetInstanceEv();
extern "C" void func_ov005_02156658(Struct_ov005_0215c058_4* self, int x, int y);
extern "C" int func_ov005_02155670(Struct_ov005_0215c058_4* self, int x, int y);
extern "C" void GridCursor_SetSelectedIndex(void* obj, int v);
extern "C" void func_ov005_021579ec(Struct_ov005_0215c058_4* self, unsigned int state, unsigned char slot);
extern "C" unsigned int _ZNK9GameState12GetTickCountEv(GameState* gs);
extern "C" int GridCursor_Update(void* obj, int v);
extern "C" int func_ov005_021585fc(Struct_ov005_0215c058_4* self, int direction);
extern "C" void func_ov005_021555c0(Struct_ov005_0215c058_4* self);
extern "C" void func_ov005_021536e0(Struct_ov005_0215c058_3* frame);
extern "C" void func_ov005_021553b4(Struct_ov005_0215c058_4* self, int slot, int* x, int* y);
extern "C" void func_ov005_02154d18(Struct_ov005_0215c058_3* obj, int a, int b);
extern "C" void func_ov005_02154d34(Struct_ov005_0215c058_3* obj, int a, int b);
extern "C" void func_ov005_02154d50(Struct_ov005_0215c058_3* obj, int a, int b);
extern "C" void func_ov005_02154d7c(Struct_ov005_0215c058_3* obj, int a, int b);
extern "C" void func_ov005_021537bc(Struct_ov005_0215c058_3* frame, int mode, unsigned short value);
struct GridCursor;
extern "C" int GridCursor_GetSelectedIndex(GridCursor*);
extern "C" void SePlayer_Play(SePlayer*, int, int);
extern "C" int func_ov005_02157190(void* self);
extern "C" unsigned char* GameState_GetParty(GameState*);
extern "C" short* func_0207c5f8(unsigned char*, unsigned int);
extern "C" signed char* func_0207c60c(void*, unsigned int);
extern "C" void func_ov005_0215792c(Struct_ov005_0215c058_4* self, int mode);

extern char g_sePlayer[];
extern unsigned char data_ov005_0215cd10[];

// USA: func_ov005_0215c058
extern "C" ARM void func_ov005_0215c058(Struct_ov005_0215c058_4* self)
{
    if (self->state == 0)
    {
        self->held = self->selected - 8 + self->page * 16;
#if defined(jpn)
        self->unknown_1a34_ = (char*)self + 0x29d8;
#else
        self->unknown_1a34_ = (char*)self + 0x2a60;
#endif
        self->state++;
    }
    else if (self->state == 1)
    {
        Struct_ov005_0215c058_2* screen = func_ov017_021a193c(((Struct_ov005_0215c058*)GetGameResources())->ptr);
        func_ov005_021551fc((char*)self, screen->member, 0);
        GameState* gs = _ZN9GameState11GetInstanceEv();
        int touched = 0;
        int moved = 0;
        if (g_touchInput.pressed_)
        {
            int x;
            int y;
            touched = 1;
            g_touchInput.GetTouchPoint(&x, &y);
            self->dirty.f2 = 0;
            self->dirty.f3 = 1;
            func_ov005_02156658(self, x, y);
            int slot = func_ov005_02155670(self, x, y);
            if (slot >= 8 && slot < 0x18)
            {
                self->selected = slot;
                moved = 1;
                GridCursor_SetSelectedIndex(self->scroll, self->selected - 8);
                func_ov005_021579ec(self, self->unknown_3db8_, self->selected);
            }
        }
        else if (g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0)
        {
            touched = 1;
        }
        else if (g_touchInput.released_ != 0)
        {
            touched = 1;
        }

        if (!touched)
        {
            int tick = _ZNK9GameState12GetTickCountEv(gs);
            if (tick == 0)
                tick = 1;
            GridCursor_Update(self->scroll, tick);
            int changed = 0;
            int col = (self->selected - 8) % 4;
            if (col == 0)
            {
                if (g_keyManager.TestKeysPressed(0x20))
                    changed = func_ov005_021585fc(self, -1);
            }
            else if (col == 3)
            {
                if (g_keyManager.TestKeysPressed(0x10))
                    changed = func_ov005_021585fc(self, 1);
            }
            if (changed)
                func_ov005_021555c0(self);
        }

        short top = self->page * 16;
        short bottom = top + 16;
        if (self->held >= top && self->held < bottom)
        {
            Struct_ov005_0215c058_3 frame;
            int x;
            int y;
            func_ov005_021536e0(&frame);
#if defined(jpn)
            frame.target = (char*)self + 0x27b8;
#else
            frame.target = (char*)self + 0x2840;
#endif
            frame.scale = 0x8000;
            frame.minX = -0x3000;
            frame.maxX = 0x3000;
            frame.unknown_14_ = 0x3000;
            frame.unknown_10_ = -0x3000;
            func_ov005_021553b4(self, self->held % 16 + 8, &x, &y);
            int fx = x << 12;
            int var16 = y << 12;
            func_ov005_02154d18(&frame, fx, var16);
            func_ov005_02154d34(&frame, fx, var16);
            func_ov005_02154d50(&frame, 0x18000, 0x18000);
            func_ov005_02154d7c(&frame, 0x18000, 0x18000);
            frame.speed = 0x4800;
            func_ov005_021537bc(&frame, 0, 0x7fff);
        }

        int sel = GridCursor_GetSelectedIndex((GridCursor*)self->scroll) + 8;
        if (sel != self->selected)
        {
            self->selected = sel;
            SePlayer_Play((SePlayer*)g_sePlayer, 2, 0);
            func_ov005_021579ec(self, self->unknown_3db8_, self->selected);
        }
        else if (sel == self->selected)
        {
        if (func_ov005_02157190(self) != 0 || moved)
        {
            short index = self->selected - 8 + self->page * 16;
            unsigned char* bag = GameState_GetParty(gs);
            short* ids = func_0207c5f8(bag + 0x1d4, data_ov005_0215cd10[self->tab]);
            signed char* var21 = func_0207c60c(bag + 0x1d4, data_ov005_0215cd10[self->tab]);
            short id = ids[self->held];
            signed char amount = var21[self->held];
            ids[self->held] = ids[index];
            var21[self->held] = var21[index];
            ids[index] = id;
            var21[index] = amount;
            func_ov005_021555c0(self);
            self->dirty.unknown_0_6_ = 1;
            self->unknown_3daa_ = 0;
            self->held = -1;
            func_ov005_0215792c(self, 4);
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            screen->flags |= 0x81;
#if defined(jpn)
            self->unknown_1a34_ = (char*)self + 0x19e8;
#else
            self->unknown_1a34_ = (char*)self + 0x1a70;
#endif
            self->dirty.f2 = 1;
            self->dirty.f3 = 1;
        }
        else if (g_keyManager.TestKeysPressed(2))
        {
            self->held = -1;
            func_ov005_0215792c(self, 4);
            screen->flags |= 0x81;
#if defined(jpn)
            self->unknown_1a34_ = (char*)self + 0x19e8;
#else
            self->unknown_1a34_ = (char*)self + 0x1a70;
#endif
            self->dirty.f2 = 1;
            self->dirty.f3 = 1;
        }
        }
    }
}

#if defined(jpn)
#undef data_ov005_0215cd10
#endif
