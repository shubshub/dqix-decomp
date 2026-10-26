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
    char unknown_0_[0x56b];
    unsigned char unknown_56b_0_ : 4;
};

struct Struct_ov003_0215a5b4_2 {
    char unknown_0_[Enum_ov003_0215a5b4_336];
    struct Struct_ov003_0215a5b4* unknown_150_;
};

struct Struct_ov003_0215a5b4_3 {
    char unknown_0_[Enum_ov003_0215a5b4_2464];
    int unknown_9a0_;
};

struct Struct_ov003_0215a5b4_4 {
    char unknown_0_[0x64];
    char unknown_64_[0x7c - 0x64];
    char* unknown_7c_;
    char unknown_80_[0xf4 - 0x80];
    char unknown_f4_[0x580 - 0xf4];
    unsigned char unknown_580_;
    char unknown_581_[0x588 - 0x581];
    unsigned char unknown_588_;
};

struct Struct_0201099c_3;
struct Struct_0205d81c;

struct MessageWork0215a5b4* MessageSystem_GetInstance();
void Window_SetPanePalette(struct Struct_0205d81c* s, int key, int value);
int KeyTable_Get(struct Container020e0310* c, int key);
int Text_Append(char* dst, const char* src);
extern "C" void __clear(void* buf, int n);
unsigned char GameState_GetPartyOrder(char* obj, void* dst);
extern "C" void func_ov003_021592d8(struct BattleMenu0215a5b4* self, struct Combatant0215a5b4* combatant, char* out);
extern "C" void func_ov003_02159250(struct BattleMenu0215a5b4* self, char* text);
extern "C" void func_ov003_0215c01c(struct BattleMenu0215a5b4* self, int mode, int flag);

// USA: func_ov003_0215a5b4
extern "C" ARM void func_ov003_0215a5b4(struct BattleMenu0215a5b4* self) {
    struct MessageWork0215a5b4* work = MessageSystem_GetInstance();
    unsigned char step = self->step;
    if (step == 0) {
        GameState* game = GameState::GetInstance();
        Window_SetPanePalette((struct Struct_0205d81c*)self->menu, 0, 1);
        Window_SetPanePalette((struct Struct_0205d81c*)self->menu, 1, 1);
        Window_SetPanePalette((struct Struct_0205d81c*)self->menu, 2, 1);
        memset(self->text, 0, kRegion960);
        Text_Append(self->text,
                             (const char*)KeyTable_Get((struct Container020e0310*)self->messages, 0x3fc));
        unsigned char ids[4];
        char* line = self->text + kRegion860;
        __clear(ids, sizeof(ids));
        int count = GameState_GetPartyOrder((char*)game, ids);
        for (int i = 0; i < count; i++) {
            struct Combatant0215a5b4* combatant =
                (struct Combatant0215a5b4*)GetCombatantWithFlag0x100_0200ff1c(game, ids[i]);
            if (combatant == NULL) {
                continue;
            }
            int var8;
            if (var7->unknown_150_ != NULL) {
                var8 = var7->unknown_150_->unknown_56b_0_ != 0;
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
    if (var1 == 1 && var0->unknown_9a0_ == 3) {
        func_ov003_0215c01c(arg0, 1, 0);
        arg0->unknown_588_ = 2;
        arg0->unknown_580_ = 0;
    }
}
