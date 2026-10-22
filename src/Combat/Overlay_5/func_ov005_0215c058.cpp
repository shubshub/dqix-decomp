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
    char unknown_0_[0x34f8];
#else
    char unknown1_0_[0x3708];
#endif
    int* unknown_3708_;
};

struct Struct_ov005_0215c058_2
{
#if defined(jpn)
    char unknown_0_[0x4f8];
#else
    char unknown1_0_[0x4fc];
#endif
    int unknown_4fc_;
#if defined(jpn)
    char unknown1_4fc_[0x56c - 0x4fc];
#else
    char unknown_500_[0x634 - 0x500];
#endif
    unsigned short unknown_634_;
};

struct Struct_ov005_0215c058_3
{
    void* unknown_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_[8];
    int unknown_38_;
};

struct Struct_ov005_0215c058_4
{
#if defined(jpn)
    char unknown_0_[0x196c];
#else
    char unknown1_0_[0x19f4];
#endif
    char unknown_19f4_[0x1a34 - 0x19f4];
    void* unknown_1a34_;
    char unknown_1a38_[0x3daa - 0x1a38];
    unsigned char unknown_3daa_;
    char unknown_3dab_[0x3db8 - 0x3dab];
    unsigned char unknown_3db8_;
    char unknown_3db9_;
    unsigned char unknown_3dba_;
    signed char unknown_3dbb_;
    unsigned char unknown_3dbc_;
    signed char unknown_3dbd_;
    char unknown_3dbe_[0x3dcc - 0x3dbe];
    struct { unsigned int unknown_0_0_ : 2; unsigned int unknown_0_2_ : 1; unsigned int unknown_0_3_ : 1; unsigned int unknown_0_4_ : 2; unsigned int unknown_0_6_ : 1; unsigned int unknown_0_7_ : 25; } unknown_3dcc_;
    char unknown_3dd0_[0x3de0 - 0x3dd0];
    short unknown_3de0_;
};

extern "C" Struct_ov005_0215c058_2* func_ov017_021a193c(int*);
extern "C" void func_ov005_021551fc(char*, int, int);
extern "C" GameState* _ZN9GameState11GetInstanceEv();
extern "C" void func_ov005_02156658(Menu0215c058* self, int x, int y);
extern "C" int func_ov005_02155670(Menu0215c058* self, int x, int y);
extern "C" void GridCursor_SetSelectedIndex(void* obj, int v);
extern "C" void func_ov005_021579ec(Menu0215c058* self, unsigned int state, unsigned char slot);
extern "C" unsigned int _ZNK9GameState12GetTickCountEv(GameState* gs);
extern "C" int func_0205bf58(void* obj, int v);
extern "C" int func_ov005_021585fc(Menu0215c058* self, int direction);
extern "C" void func_ov005_021555c0(Menu0215c058* self);
extern "C" void func_ov005_021536e0(CursorFrame0215c058* frame);
extern "C" void func_ov005_021553b4(Menu0215c058* self, int slot, int* x, int* y);
extern "C" void func_ov005_02154d18(CursorFrame0215c058* obj, int a, int b);
extern "C" void func_ov005_02154d34(CursorFrame0215c058* obj, int a, int b);
extern "C" void func_ov005_02154d50(CursorFrame0215c058* obj, int a, int b);
extern "C" void func_ov005_02154d7c(CursorFrame0215c058* obj, int a, int b);
extern "C" void func_ov005_021537bc(CursorFrame0215c058* frame, int mode, unsigned short value);
struct Struct_0205bb84;
int GridCursor_GetSelectedIndex(Struct_0205bb84*);
void SePlayer_Play(SePlayer*, int, int);
int CheckFlag30Or401_02157190(void* self);
unsigned char* GetPtrField0x2a04_02010828(GameState*);
short* GetPointerFromArray0xbd0_0207c5f8(unsigned char*, unsigned int);
signed char* GetPointerAt0xbf0_0207c60c(void*, unsigned int);
extern "C" void func_ov005_0215792c(Menu0215c058* self, int mode);

extern char g_sePlayer[];
extern unsigned char data_ov005_0215cd10[];

// USA: func_ov005_0215c058
extern "C" ARM void func_ov005_0215c058(Struct_ov005_0215c058_4* arg0)
{
    if (arg0->unknown_3dba_ == 0)
    {
        arg0->unknown_3de0_ = arg0->unknown_3dbb_ - 8 + arg0->unknown_3dbd_ * 16;
#if defined(jpn)
        arg0->unknown_1a34_ = (char*)arg0 + 0x29d8;
#else
        arg0->unknown_1a34_ = (char*)arg0 + 0x2a60;
#endif
        arg0->unknown_3dba_++;
    }
    else if (arg0->unknown_3dba_ == 1)
    {
        Struct_ov005_0215c058_2* var0 = func_ov017_021a193c(((Struct_ov005_0215c058*)GetGameResources())->unknown_3708_);
        func_ov005_021551fc((char*)arg0, var0->unknown_4fc_, 0);
        GameState* var1 = _ZN9GameState11GetInstanceEv();
        int var2 = 0;
        int var3 = 0;
        if (g_touchInput.pressed_)
        {
            int var4;
            int var5;
            var2 = 1;
            g_touchInput.GetTouchPoint(&var4, &var5);
            arg0->unknown_3dcc_.unknown_0_2_ = 0;
            arg0->unknown_3dcc_.unknown_0_3_ = 1;
            func_ov005_02156658(arg0, var4, var5);
            int var6 = func_ov005_02155670(arg0, var4, var5);
            if (var6 >= 8 && var6 < 0x18)
            {
                self->selected = slot;
                moved = 1;
                GridCursor_SetSelectedIndex(self->scroll, self->selected - 8);
                func_ov005_021579ec(self, self->cursorMode, self->selected);
            }
        }
        else if (g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0)
        {
            var2 = 1;
        }
        else if (g_touchInput.released_ != 0)
        {
            var2 = 1;
        }

        if (!var2)
        {
            int var7 = _ZNK9GameState12GetTickCountEv(var1);
            if (var7 == 0)
                var7 = 1;
            func_0205bf58(arg0->unknown_19f4_, var7);
            int var8 = 0;
            int var9 = (arg0->unknown_3dbb_ - 8) % 4;
            if (var9 == 0)
            {
                if (g_keyManager.TestKeysPressed(0x20))
                    var8 = func_ov005_021585fc(arg0, -1);
            }
            else if (var9 == 3)
            {
                if (g_keyManager.TestKeysPressed(0x10))
                    var8 = func_ov005_021585fc(arg0, 1);
            }
            if (var8)
                func_ov005_021555c0(arg0);
        }

        short var10 = arg0->unknown_3dbd_ * 16;
        short var11 = var10 + 16;
        if (arg0->unknown_3de0_ >= var10 && arg0->unknown_3de0_ < var11)
        {
            Struct_ov005_0215c058_3 var12;
            int var13;
            int var14;
            func_ov005_021536e0(&var12);
#if defined(jpn)
            var12.unknown_0_ = (char*)arg0 + 0x27b8;
#else
            var12.unknown_0_ = (char*)arg0 + 0x2840;
#endif
            var12.unknown_4_ = 0x8000;
            var12.unknown_8_ = -0x3000;
            var12.unknown_c_ = 0x3000;
            var12.unknown_14_ = 0x3000;
            var12.unknown_10_ = -0x3000;
            func_ov005_021553b4(arg0, arg0->unknown_3de0_ % 16 + 8, &var13, &var14);
            int var15 = var13 << 12;
            int var16 = var14 << 12;
            func_ov005_02154d18(&var12, var15, var16);
            func_ov005_02154d34(&var12, var15, var16);
            func_ov005_02154d50(&var12, 0x18000, 0x18000);
            func_ov005_02154d7c(&var12, 0x18000, 0x18000);
            var12.unknown_38_ = 0x4800;
            func_ov005_021537bc(&var12, 0, 0x7fff);
        }

        int sel = GridCursor_GetSelectedIndex((Struct_0205bb84*)self->scroll) + 8;
        if (sel != self->selected)
        {
            self->selected = sel;
            SePlayer_Play((SePlayer*)g_sePlayer, 2, 0);
            func_ov005_021579ec(self, self->cursorMode, self->selected);
        }
        else if (var17 == arg0->unknown_3dbb_)
        {
        if (func_ov005_02157190(arg0) != 0 || var3)
        {
            short index = self->selected - 8 + self->page * 16;
            unsigned char* bag = GetPtrField0x2a04_02010828(gs);
            short* ids = GetPointerFromArray0xbd0_0207c5f8(bag + 0x1d4, data_ov005_0215cd10[self->tab]);
            signed char* amounts = GetPointerAt0xbf0_0207c60c(bag + 0x1d4, data_ov005_0215cd10[self->tab]);
            short id = ids[self->held];
            signed char amount = amounts[self->held];
            ids[self->held] = ids[index];
            amounts[self->held] = amounts[index];
            ids[index] = id;
            amounts[index] = amount;
            func_ov005_021555c0(self);
            self->dirty.f6 = 1;
            self->f3daa = 0;
            self->held = -1;
            func_ov005_0215792c(self, 4);
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            screen->flags |= 0x81;
#if defined(jpn)
            arg0->unknown_1a34_ = (char*)arg0 + 0x19e8;
#else
            arg0->unknown_1a34_ = (char*)arg0 + 0x1a70;
#endif
            arg0->unknown_3dcc_.unknown_0_2_ = 1;
            arg0->unknown_3dcc_.unknown_0_3_ = 1;
        }
        else if (g_keyManager.TestKeysPressed(2))
        {
            arg0->unknown_3de0_ = -1;
            func_ov005_0215792c(arg0, 4);
            var0->unknown_634_ |= 0x81;
#if defined(jpn)
            arg0->unknown_1a34_ = (char*)arg0 + 0x19e8;
#else
            arg0->unknown_1a34_ = (char*)arg0 + 0x1a70;
#endif
            arg0->unknown_3dcc_.unknown_0_2_ = 1;
            arg0->unknown_3dcc_.unknown_0_3_ = 1;
        }
        }
    }
}

#if defined(jpn)
#undef data_ov005_0215cd10
#endif
