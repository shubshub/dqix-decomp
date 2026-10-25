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
    char unknown_0_[0x70];
    signed char unknown_70_[4];
    char unknown_74_[0x17c - 0x74];
    int unknown_17c_;
    char unknown_180_[0x188 - 0x180];
    char unknown_188_[Enum_ov000_0217cb5c_7520 - 0x188];
    signed char unknown_1d60_[8];
    signed char unknown_1d68_;
    signed char unknown_1d69_;
    unsigned char unknown_1d6a_;
    char unknown_1d6b_[5];
    unsigned char unknown_1d70_;
    char unknown_1d71_;
    unsigned short unknown_1d72_;
};

struct Struct_ov000_02182a74 {
    char unknown_0_[0xf7c];
    unsigned char unknown_f7c_;
};

struct Struct_ov000_0215ab88 {
    char unknown_0_[0x10];
    char unknown_10_[8];
    signed char unknown_18_;
};

int Window_GetSelectedIndex(Struct_0205c570*);
void SePlayer_Play(SePlayer*, int, int);
void* GameState_GetParty(GameState*);
void Window_ClosePane(Entry_0205d6a0*, int);
TableEntry0217f8c0* FindMatchingTableEntry0217f8c0(Struct0217f8c0*);
extern SePlayer g_sePlayer;
extern "C" {
void Zone3D_GetInstance();
int func_ov000_0217c594(void*, int);
void func_ov000_02174da4(void*, void*);
void func_ov000_02177038(void*, int, int, int, int);
int func_ov000_0217f990(void*);
Struct_ov000_0215ab88* func_ov000_02161318(void*, int);
void func_ov000_02176634(void*, void*, int, int, int);
void func_ov000_02176e3c(void*, int, int, int, int, int);
void func_ov000_02180394(void*);
}

// USA: func_ov000_0217cb5c
extern "C" ARM void func_ov000_0217cb5c(Struct_ov000_0215767c_2* arg0, int arg1, int arg2)
{
    Zone3D_GetInstance();
    self->flags |= 0x100;
    int mode = Window_GetSelectedIndex((Struct_0205c570*)self->entryList);
    if (mode < 0) mode = 0;
    self->mode = mode;
    if (func_ov000_0217c594(self, 0)) {
        SePlayer_Play(&g_sePlayer, 1, 0);
        int table[4];
        _Z22CopyStaticData02174da4iPv(self, table);
        switch (table[self->mode]) {
        case 0:
            func_ov000_02177038(self, 0, self->kinds[self->kindIndex], a, b);
            self->kindIndex++;
            self->kinds[self->kindIndex] = 13;
            Window_ClosePane((Entry_0205d6a0*)self->entryList, 1);
            self->flags |= 4;
            if (func_ov000_0217f990(self) == 0) {
                self->flags &= ~4;
                self->field17c = -1;
                GameState* game = GameState::GetInstance();
                Party* party = (Party*)GameState_GetParty(game);
                unsigned char count = party->count;
                for (unsigned char i = 0; i < count; i++) {
                    Combatant* c = func_ov000_02161318(self, self->members[i]);
                    if (c) {
                        c->slots[c->slot] = 100;
                    }
                }
            }
            break;
        case 1:
            func_ov000_02177038(arg0, 0, arg0->unknown_1d60_[arg0->unknown_1d68_], arg1, arg2);
            arg0->unknown_1d6a_ = 0;
            arg0->unknown_1d68_++;
            arg0->unknown_1d60_[arg0->unknown_1d68_] = 2;
            func_ov000_02176634(arg0, func_ov000_0217f8c0((Struct_ov000_021735d0_3*)arg0), 2, arg1, arg2);
            break;
        case 2:
            arg0->unknown_1d72_ &= ~0x100;
            func_ov000_02176e3c(arg0, 0, arg0->unknown_1d60_[arg0->unknown_1d68_], arg1, arg2, 1);
            arg0->unknown_1d70_ = 0;
            arg0->unknown_1d68_++;
            arg0->unknown_1d60_[arg0->unknown_1d68_] = 10;
            break;
        case 3:
            func_ov000_02177038(self, 0, self->kinds[self->kindIndex], a, b);
            self->kindIndex++;
            self->kinds[self->kindIndex] = 11;
            Window_ClosePane((Entry_0205d6a0*)self->entryList, 1);
            func_ov000_02180394(self);
            break;
        }
    }
}
