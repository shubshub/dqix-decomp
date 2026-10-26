#if defined(jpn)
#define R(j,u) (j)
#define data_ov001_02164ca4 data_ov001_02166270
#define data_ov028_021d9aa0 data_ov028_021da400
#define func_ov014_02188330 func_ov014_02189234
#define func_ov014_0218854c func_ov014_0218942c
#define func_ov014_021885bc func_ov014_0218948c
#define func_ov015_02191f04 func_ov015_02192a48
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_ov015_02190d7c_2 {};
struct Struct_ov015_02190d7c : Struct_ov015_02190d7c_2 {
    char pad0[0x34];
    int selection;
    signed char mode;
    char pad39[0x194-0x39];
    int current;
    int previous;
    char pad19c[8];
    int state;
    char unknown_1a8_[0x268-0x1a8];
    short indices[0x2e];
    int cursor;
};
struct MenuEntry { char pad[0xb]; unsigned char state; };
extern "C" int func_ov015_021925a8(Struct_ov015_02190d7c*);
extern "C" void func_ov015_02191874(Struct_ov015_02190d7c*);
extern "C" int func_ov015_02191284(int*);
extern "C" void func_ov015_02191ea4(Struct_ov015_02190d7c*, int);
extern "C" void func_ov015_02191f04(Struct_ov015_02190d7c*);
extern "C" void func_ov015_02192064(Struct_ov015_02190d7c*, int);
extern "C" MenuEntry* func_ov015_02193160(Struct_ov015_02190d7c*, int, int*);
extern "C" void func_ov015_021931b4(Struct_ov015_02190d7c*, int);
extern "C" int func_ov015_021931cc(Struct_ov015_02190d7c_2*);
extern "C" void func_ov015_02192700(Struct_ov015_02190d7c*, int);

// USA: func_ov015_02191668
extern "C" ARM void func_ov015_02191668(Struct_ov015_02190d7c* self) {
    if (func_ov015_021925a8(self)) return;
    if (self->state == 0x27) func_ov015_02191874(self);
    if (g_keyManager.TestKeysPressed(1)) {
        int index = func_ov015_02191284(&self->cursor);
        self->indices[self->state] = index;
        switch (self->state) {
        case 0x24: func_ov015_02191ea4(self, index); break;
        case 0x26: func_ov015_02191f04(self); break;
        case 0x25: func_ov015_02192064(self, index); break;
        case 0x27: break;
        default:
            int start = 0;
            func_ov015_02193160(self, self->state, &start);
            index += start;
            MenuEntry* entry = func_ov015_02193160(self, self->state, &index);
            if (entry->state) {
                func_ov015_021931b4(self, self->state);
                self->state = entry->state;
                func_ov015_02192700(self, 0);
            }
            break;
        }
    } else if (g_keyManager.TestKeysPressed(2)) {
        if (self->state > 0x23) {
            self->indices[self->state] = func_ov015_02191284(&self->cursor);
            self->state = func_ov015_021931cc(self);
            func_ov015_02192700(self, 0);
        } else {
            int previous = self->current;
            self->current = self->previous;
            self->previous = previous;
            int state;
            do { state = func_ov015_021931cc(self); } while (state >= 0x23);
            if (self->mode >= 0) {
                switch (self->mode) {
                case 0: case 1:
                    while (state >= 0xf) state = func_ov015_021931cc(self);
                    break;
                case 2:
                    while (state >= 0x21) state = func_ov015_021931cc(self);
                    break;
                }
                self->mode = -1;
                if (self->current == 1) self->current = 0;
            }
            self->state = state;
            func_ov015_02192700(self, 0);
            self->selection = 0;
        }
    }
}
