#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Combat/CombatantRecovery.h"

struct Party021aa1ac {
    char pad0[0xf78];
    signed char memberIds[4];
    unsigned char memberCount;
};

struct Controller021aa1ac {
#if defined(jpn)
    char pad0[0x868];
#else
    char pad0[0x998];
#endif
    int unknown_998_;
#if defined(jpn)
    char unknown_86c_[0x17e2 - 0x86c];
#else
    char unknown_99c_[0x19b2 - 0x99c];
#endif
    unsigned char unknown_19b2_;
};

struct Self021aa1ac {
    unsigned char pad0;
    unsigned char done;
    char pad2[6];
    short ids[4];
    unsigned char count;
    unsigned char shown;
    unsigned short step;
};

extern "C" Controller021aa1ac* MessageSystem_GetInstance(void);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" void __clear(void* dst, unsigned int size);
#if defined(jpn)
extern "C" void func_0204500c(Controller021aa1ac* controller, const char* text, int a);
#else
extern "C" void func_0204500c(Controller021aa1ac* controller, const char* text, int a, int b);
#endif
extern "C" int func_ov017_021aa080(void);

extern char data_ov017_021d783c[];
extern char data_ov017_021d7868[];

// Overlay 17, originally func_ov017_021aa1ac (USA/EUR 0x021aa1ac, JPN 0x021aaa1c)
extern "C" ARM void FieldTask_SetPartyHpToOne(Self021aa1ac* self) {
    GameState* gs = GameState::GetInstance();
    Party021aa1ac* party = (Party021aa1ac*)GameState_GetParty(gs);
    Controller021aa1ac* controller = MessageSystem_GetInstance();
    int memberCount = party->memberCount;
    if (self->step == 0) {
        memset(self->ids, -1, sizeof(self->ids));
        self->shown = 0;
        self->count = 0;
        for (int i = 0; i < memberCount; i++) {
            int id = party->memberIds[i];
            GameObject* combatant = func_0200ff1c(gs, id);
            if (combatant == NULL) {
                continue;
            }
            Struct_020200c0* status = combatant->combatFields_.savedState_130_;
            if (status->flags & 1) {
                continue;
            }
            status->hp = 1;
            func_ov017_021c9e00(id, 1, 0, 1);
            self->ids[self->count++] = id;
        }
        if (self->count != 0) {
            char text[0x100];
            __clear(text, sizeof(text));
            sprintf(text, data_ov017_021d783c, func_0200ff1c(gs, self->ids[0])->baseStats_);
            if (++self->shown >= self->count) {
                self->step++;
            } else {
                strcat(text, data_ov017_021d7868);
            }
#if defined(jpn)
            func_0204500c(controller, text, 0);
#else
            func_0204500c(controller, text, 0, 0xe3);
#endif
            controller->unknown_19b2_ = 0;
            controller->unknown_998_ = 1;
        }
        self->step++;
    } else if (self->step == 1) {
        if (func_ov017_021aa080() == 0) {
            return;
        }
        if (self->shown >= self->count) {
            return;
        }
        char text[0x100];
        __clear(text, sizeof(text));
        sprintf(text, data_ov017_021d783c, func_0200ff1c(gs, self->ids[self->shown])->baseStats_);
        if (++self->shown >= self->count) {
            self->step++;
        } else {
            strcat(text, data_ov017_021d7868);
        }
#if defined(jpn)
        func_0204500c(controller, text, 0);
#else
        func_0204500c(controller, text, 0, 0xe3);
#endif
        controller->unknown_19b2_ = 0;
        controller->unknown_998_ = 1;
    } else if (self->step == 2) {
        if (func_ov017_021aa080() != 0) {
            self->done = 1;
        }
    }
}
