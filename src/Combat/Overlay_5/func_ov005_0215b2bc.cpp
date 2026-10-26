#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/Brightness.h>
#include "Resource/GameResources.h"
#include "Input/Input.h"

struct MenuTail {
#if defined(jpn)
    char pad[0x4f8];
#else
    char pad[0x4fc];
#endif
    int index;
};

struct SePlayer;
extern SePlayer g_sePlayer;

struct Struct_ov005_02156ecc_2;
struct Struct_ov005_02156ecc;
extern "C" void func_ov005_02157174(Struct_ov005_02156ecc*, Struct_ov005_02156ecc_2*);

struct GridCursor;
extern "C" int GridCursor_GetSelectedIndex(GridCursor*);
extern "C" int GridCursor_Update(void*, int);
extern "C" int func_ov005_02157190(void*);
extern "C" char* func_ov017_021a193c(int*);
extern "C" void func_ov005_021551fc(char*, int, int);
extern "C" void SePlayer_Play(SePlayer*, int, int);
extern "C" void func_ov005_021555c0(void*);
extern "C" void func_ov005_0215792c(void*, unsigned char);
extern "C" unsigned char func_ov005_021586c4(void*, int, int);

struct Struct_ov005_02153ba4 {
    short item_;
    signed char count_;
    unsigned char unknown_3_;
    void* vramState_;
    void* model_;
    int x_;
    int y_;
    int unknown_14_;
    short unknown_18_;
};

struct Struct_ov005_0215b2bc {
    int a;
    int b;
    int c;
};

struct Struct_ov000_0217ab8c {
    char pad0[0xd90];
#if defined(jpn)
    char pad1[0x196c - 0xd90];
#else
    char pad1[0x19f4 - 0xd90];
#endif
    char scale_[0x2d90 - 0x19f4];
    Struct_ov005_02153ba4 slots_[24];
    char pad2[0x3d78 - 0x2d90 - sizeof(Struct_ov005_02153ba4) * 24];
    short count_;
    char pad3[0x3daa - 0x3d7a];
    unsigned char unknown_3daa_;
    char pad4[0x3db8 - 0x3dab];
    unsigned char unknown_3db8_;
    char pad5[0x3dba - 0x3db9];
    unsigned char unknown_3dba_;
    unsigned char unknown_3dbb_;
    unsigned char kind_;
    signed char page_;
    unsigned char unknown_3dbe_;
    unsigned char unknown_3dbf_;
    char unknown_3dc0_[0x3dcc - 0x3dc0];
    unsigned int flags_;
    char pad8[0x3dfc - 0x3dd0];
    unsigned char pages_[8];
};

// USA: func_ov005_0215b2bc
extern "C" ARM void func_ov005_0215b2bc(Struct_ov000_0217ab8c* self) {
    if (self->unknown_3dba_ == 0) {
        if (!IsBrightnessTransitionActive(GetGameResources())) {
            self->unknown_3dba_++;
        }
    } else if (self->unknown_3dba_ == 1) {
        int found = 0;
        int flag2 = 0;
        unsigned char sel = 255;
        int var3 = 0;
        int var4;
        int by;
        if (g_touchInput.pressed_ != 0) {
            var3 = 1;
            g_touchInput.GetTouchPoint(&var4, &by);
            sel = func_ov005_021586c4(self, var4, by);
            if (sel != 255) {
                found = var3;
                flag2 = found;
            } else if (var4 > 0x80) {
                for (int i = found; i < 8; i++) {
                    int row = i * 0x18;
                    int hi = row + 0x18;
                    if (by > row && by < hi) {
                        found = 1;
                        flag2 = found;
                        sel = i;
                        break;
                    }
                }
            }
        }
        if (var3 == 0) {
            found = 1;
            unsigned int tick = GameState::GetInstance()->GetTickCount();
            GridCursor_Update(self->scale_, tick ? tick : found);
            sel = GridCursor_GetSelectedIndex((GridCursor*)&self->scale_[0]);
            if (func_ov005_02157190(self)) flag2 = 1;
        }
        if (found != 0 && self->kind_ != sel) {
            self->unknown_3dbe_ = self->kind_;
            self->unknown_3dbf_ = self->page_;
            self->pages_[self->kind_] = self->page_;
            self->kind_ = sel;
            self->page_ = self->pages_[sel & 0xff];
        }
        self->unknown_3dbb_ = self->kind_;
        MenuTail* hold = (MenuTail*)func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_3700[2]);
        func_ov005_021551fc((char*)self, hold->index, 0);
        if (flag2 == 0) return;
        SePlayer_Play(&g_sePlayer, 1, 0);
        func_ov005_021555c0(self);
        self->flags_ |= 0x40;
        self->unknown_3daa_ = 0;
        func_ov005_0215792c(self, 1);
        Struct_ov005_02153ba4* slots;
        int j = 0;
        for (; j < 8; j++) {
            slots = self->slots_;
            Struct_ov005_02153ba4* s = &slots[j];
            if (j == self->count_) continue;
            if (s->item_ < 0) continue;
            Struct_ov005_02156ecc_2* m = (Struct_ov005_02156ecc_2*)s->model_;
            Struct_ov005_0215b2bc t = *(Struct_ov005_0215b2bc*)((char*)m + 0x1c);
            t.b = 0x17000;
            func_ov005_02157174((Struct_ov005_02156ecc*)m, (Struct_ov005_02156ecc_2*)&t);
        }
    }
}
