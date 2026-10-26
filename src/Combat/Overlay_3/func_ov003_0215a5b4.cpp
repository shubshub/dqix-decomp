#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0215a5b4_336 = 0x144 };
enum { Enum_ov003_0215a5b4_2464 = 0x870 };
enum { Enum_ov003_0215a5b4_2400 = 0x800 };
enum { Enum_ov003_0215a5b4_2144 = 0x700 };
#else
enum { Enum_ov003_0215a5b4_336 = 0x150 };
enum { Enum_ov003_0215a5b4_2464 = 0x9a0 };
enum { Enum_ov003_0215a5b4_2400 = 0x960 };
enum { Enum_ov003_0215a5b4_2144 = 0x860 };
#endif
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct Struct_ov003_0215a5b4 {
    char pad0[0x56b];
    unsigned char unknown_56b_0_ : 4;
};

struct Struct_ov003_0215a5b4_2 {
    char pad0[Enum_ov003_0215a5b4_336];
    struct Struct_ov003_0215a5b4* status;
};

struct MessageWork0215a5b4 {
    char pad0[Enum_ov003_0215a5b4_2464];
    int state;
};

struct Struct_ov003_0215a5b4_4 {
    char pad0[0x64];
    char messages[0x7c - 0x64];
    char* text;
    char unknown_80_[0xf4 - 0x80];
    char menu[0x580 - 0xf4];
    unsigned char step;
    char unknown_581_[0x588 - 0x581];
    unsigned char mode;
};

struct Container020e0310;
struct Struct_0205d81c;

extern "C" struct MessageWork0215a5b4* MessageSystem_GetInstance();
extern "C" void Window_SetPanePalette(struct Struct_0205d81c* s, int key, int value);
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int Text_Append(char* dst, const char* src);
extern "C" void __clear(void* buf, int n);
extern "C" unsigned char GameState_GetPartyOrder(char* obj, void* dst);
extern "C" void func_ov003_021592d8(struct Struct_ov003_0215a5b4_4* self, struct Struct_ov003_0215a5b4_2* combatant, char* out);
extern "C" void func_ov003_02159250(struct Struct_ov003_0215a5b4_4* self, char* text);
extern "C" void func_ov003_0215c01c(struct Struct_ov003_0215a5b4_4* self, int mode, int flag);

// USA: func_ov003_0215a5b4
extern "C" ARM void func_ov003_0215a5b4(struct Struct_ov003_0215a5b4_4* self) {
    struct MessageWork0215a5b4* work = MessageSystem_GetInstance();
    unsigned char step = self->step;
    if (step == 0) {
        GameState* game = GameState::GetInstance();
        Window_SetPanePalette((struct Struct_0205d81c*)self->menu, 0, 1);
        Window_SetPanePalette((struct Struct_0205d81c*)self->menu, 1, 1);
        Window_SetPanePalette((struct Struct_0205d81c*)self->menu, 2, 1);
        memset(self->text, 0, Enum_ov003_0215a5b4_2400);
        Text_Append(self->text,
                             (const char*)KeyTable_Get((struct Container020e0310*)self->messages, 0x3fc));
        unsigned char ids[4];
        char* line = self->text + Enum_ov003_0215a5b4_2144;
        __clear(ids, sizeof(ids));
        int count = GameState_GetPartyOrder((char*)game, ids);
        for (int i = 0; i < count; i++) {
            struct Struct_ov003_0215a5b4_2* combatant =
                (struct Struct_ov003_0215a5b4_2*)func_0200ff1c(game, ids[i]);
            if (combatant == NULL) {
                continue;
            }
            int var8;
            if (combatant->status != NULL) {
                var8 = combatant->status->unknown_56b_0_ != 0;
            } else {
                var8 = 0;
            }
            if (var8) {
                continue;
            }
            memset(line, 0, 0x80);
            func_ov003_021592d8(self, combatant, line);
            Text_Append(self->text, line);
        }
        Text_Append(self->text,
                             (const char*)KeyTable_Get((struct Container020e0310*)self->messages, 0x42e));
        func_ov003_02159250(self, self->text);
        self->step++;
    }
    if (step == 1 && work->state == 3) {
        func_ov003_0215c01c(self, 1, 0);
        self->mode = 2;
        self->step = 0;
    }
}
