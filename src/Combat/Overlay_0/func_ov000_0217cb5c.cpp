#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov000_0217cb5c_7520 = 0x1f98 };
#else
enum { Enum_ov000_0217cb5c_7520 = 0x1d60 };
#endif

struct Struct_0205c570;
struct SePlayer;
struct Entry_0205d6a0;
struct Struct0217f8c0;
struct TableEntry0217f8c0;

struct Struct_ov000_0215767c_2 {
    char pad0[0x70];
    signed char members[4];
    char pad1[0x17c - 0x74];
    int unknown_17c_;
    char pad2[0x188 - 0x180];
    char entryList[Enum_ov000_0217cb5c_7520 - 0x188];
    signed char kinds[8];
    signed char unknown_1d68_;
    signed char mode;
    unsigned char step;
    char pad3[5];
    unsigned char unknown_1d70_;
    char pad4;
    unsigned short flags;
};

struct Party {
    char p[0xf7c];
    unsigned char count;
};

struct Struct_ov000_0215ab88 {
    char p[0x10];
    char slots[8];
    signed char slot;
};

extern "C" int Window_GetSelectedIndex(Struct_0205c570*);
extern "C" void SePlayer_Play(SePlayer*, int, int);
extern "C" void* GameState_GetParty(GameState*);
extern "C" void Window_ClosePane(Entry_0205d6a0*, int);
extern "C" TableEntry0217f8c0* func_ov000_0217f8c0(Struct0217f8c0*);
extern SePlayer g_sePlayer;
extern "C" {
void Zone3D_GetInstance();
int func_ov000_0217c594(void*, int);
extern "C" void func_ov000_02174da4(void*, void*);
void func_ov000_02177038(void*, int, int, int, int);
int func_ov000_0217f990(void*);
Struct_ov000_0215ab88* func_ov000_02161318(void*, int);
void func_ov000_02176634(void*, void*, int, int, int);
void func_ov000_02176e3c(void*, int, int, int, int, int);
void func_ov000_02180394(void*);
}

// USA: func_ov000_0217cb5c
extern "C" ARM void func_ov000_0217cb5c(Struct_ov000_0215767c_2* self, int a, int b)
{
    Zone3D_GetInstance();
    self->flags |= 0x100;
    int mode = Window_GetSelectedIndex((Struct_0205c570*)self->entryList);
    if (mode < 0) mode = 0;
    self->mode = mode;
    if (func_ov000_0217c594(self, 0)) {
        SePlayer_Play(&g_sePlayer, 1, 0);
        int table[4];
        func_ov000_02174da4(self, table);
        switch (table[self->mode]) {
        case 0:
            func_ov000_02177038(self, 0, self->kinds[self->unknown_1d68_], a, b);
            self->unknown_1d68_++;
            self->kinds[self->unknown_1d68_] = 13;
            Window_ClosePane((Entry_0205d6a0*)self->entryList, 1);
            self->flags |= 4;
            if (func_ov000_0217f990(self) == 0) {
                self->flags &= ~4;
                self->unknown_17c_ = -1;
                GameState* game = GameState::GetInstance();
                Party* party = (Party*)GameState_GetParty(game);
                unsigned char count = party->count;
                for (unsigned char i = 0; i < count; i++) {
                    Struct_ov000_0215ab88* c = func_ov000_02161318(self, self->members[i]);
                    if (c) {
                        c->slots[c->slot] = 100;
                    }
                }
            }
            break;
        case 1:
            func_ov000_02177038(self, 0, self->kinds[self->unknown_1d68_], a, b);
            self->step = 0;
            self->unknown_1d68_++;
            self->kinds[self->unknown_1d68_] = 2;
            func_ov000_02176634(self, func_ov000_0217f8c0((Struct0217f8c0*)self), 2, a, b);
            break;
        case 2:
            self->flags &= ~0x100;
            func_ov000_02176e3c(self, 0, self->kinds[self->unknown_1d68_], a, b, 1);
            self->unknown_1d70_ = 0;
            self->unknown_1d68_++;
            self->kinds[self->unknown_1d68_] = 10;
            break;
        case 3:
            func_ov000_02177038(self, 0, self->kinds[self->unknown_1d68_], a, b);
            self->unknown_1d68_++;
            self->kinds[self->unknown_1d68_] = 11;
            Window_ClosePane((Entry_0205d6a0*)self->entryList, 1);
            func_ov000_02180394(self);
            break;
        }
    }
}
