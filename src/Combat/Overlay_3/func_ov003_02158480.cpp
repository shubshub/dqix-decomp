#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov003_02158334_2;

struct Struct_ov003_02158334_3 {
    char unk_0[0x18];
    Struct_ov003_02158334_2* entries;
    char unk_1c[0x20 - 0x1c];
    int* slots;
#if defined(jpn)
    char unk_24[0x1ee - 0x24];
#else
    char unk_24[0x1f2 - 0x24];
#endif
    unsigned char memberIds[4];
    unsigned char memberCount;
    signed char selected;
};

extern "C" void func_02080b54(void*, int);
extern "C" void func_02080608(void*, int);
extern "C" void func_02080b40(void*, int);
extern "C" void func_0208108c(void*, int);
struct Struct_ov003_0215570c;
extern "C" int func_ov003_0215570c(Struct_ov003_0215570c*);
extern "C" unsigned char* func_02053c6c(unsigned char*);
extern "C" void func_020806c4(void*, int);
extern "C" void func_0208103c(void*, int, int);
struct Struct_02080fa8;
extern "C" void func_02080fa8(Struct_02080fa8*, int, int);
extern "C" void func_02080828(void*, int, short*, short*);
extern "C" void func_020808c8(void*, int, short*, short*);
extern "C" void func_02080854(void*, int, int, int);
extern "C" void func_02080fe0(void*, int, int);
struct Struct_02080cc0;
extern "C" void func_02080cc0(Struct_02080cc0*, int, int);
extern "C" void func_020807c4(void*, int, short*, short*);
extern "C" void func_02080878(void*, int, short*, short*);
extern "C" void func_020807fc(void*, int, int, int);
extern "C" void func_020808a4(void*, int, int, int);
extern "C" void func_020813ec(void*, int);

// USA: func_ov003_02158480
extern "C" ARM void func_ov003_02158480(Struct_ov003_02158334_3* self) {
    Struct_ov003_02158334_2* entries = self->entries;
    short row = 0x13;
    short col = 0x1f;
    short sub = 0x2b;
    short cell = 0x37;

    func_02080b54(entries, 6);
    func_02080608(entries, 6);
    func_02080b40(entries, 0x43);
#if !defined(jpn)
    func_0208108c(entries, 0x43);
#endif

    int count = func_ov003_0215570c((Struct_ov003_0215570c*)self);
    int r8 = -1;
    if (count <= 6) {
        r8 = 7;
    } else if (count >= 7 && count <= 8) {
        r8 = 8;
    } else if (count >= 9 && count <= 10) {
        r8 = 9;
    }

    GameState* gs = GameState::GetInstance();
    unsigned char* member = (unsigned char*)gs->GetPartyMemberByIndex(self->selected);
    if (member != NULL) {
        unsigned char* base = func_02053c6c(member);
        for (unsigned char i = 0; i < 12; i++) {
            int slot = self->slots[i];
            if (slot != 0) {
                func_020806c4(entries, row);
                func_02080b40(entries, row);
                func_02080b40(entries, col);
                func_02080b40(entries, sub);
                func_0208103c(entries, row, (short)(slot - 1));
                func_02080fa8((Struct_02080fa8*)entries, sub, *(unsigned short*)(base + 0x16c + slot * 2));

                unsigned char* entry = base + slot;
                unsigned char kind = entry[0x186];
                if (kind != 0) {
                    short hi = (short)(kind + 0x12);
                    int shade = 5;
                    if (kind == 10) {
                        shade = 0xd;
                    }

                    short a, b, c, d;
                    func_02080828(entries, row, &a, &b);
                    func_020808c8(entries, row, &c, &d);
#if defined(jpn)
                    func_02080854(entries, cell, (short)(a + c + 1), (short)(b + 2));
#else
                    func_02080854(entries, cell, (short)(a + c + 1), b);
#endif
                    func_02080b40(entries, cell);
                    func_02080fe0(entries, cell, hi);
                    func_02080cc0((Struct_02080cc0*)entries, cell, shade);
                }
            }
            row = (short)(row + 1);
            col = (short)(col + 1);
            sub = (short)(sub + 1);
            cell = (short)(cell + 1);
        }
    }

    if (r8 > 0) {
        short e, f, g, h;
        func_020807c4(entries, r8, &e, &f);
        func_02080878(entries, r8, &g, &h);
        func_020807fc(entries, 6, e, f);
        func_020808a4(entries, 6, g, h);
        func_020807c4(entries, 6, &e, &f);
        func_02080878(entries, 6, &g, &h);
    }
    func_020813ec(entries, 6);
}
