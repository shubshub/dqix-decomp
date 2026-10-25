#include <globaldefs.h>

#include "Combat/CombatantRecovery.h"
#include "GameState/GameState.h"
#include "World/Object3D.h"
#include "World/Zone3D.h"
#include "Resource/GameResources.h"

extern "C" void *Zone3D_GetInstance(void);
struct S02053f4c;
void SetFields1a8And1ac(CombatantRecovery*, int, int);
void SetField0x1b0_02053f6c(void *, unsigned char);
int IsValueInRange0201b5d8(int);

struct Node02021f88 {
    unsigned char type;
    unsigned char id;
    unsigned char count;
    unsigned char pad3;
    short *data;
    int x;
    int y;
    struct Node02021f88 *next;
};

struct CombatResourceStatePrefix {
#if defined(jpn)
    char pad0[0x6a8];
#else
    char pad0[0x754];
#endif
    Node02021f88 *first;
#if defined(jpn)
    char pad758[0x9ca - 0x6ac];
#else
    char pad758[0xa96 - 0x758];
#endif
    unsigned char activeCombatants;
};

// USA: func_02026bdc
extern "C" ARM void func_02026bdc(void *object, int flag) {
    CombatResourceStatePrefix *state = static_cast<CombatResourceStatePrefix *>(object);
    GameState *gameState             = GameState::GetInstance();
    for (int i = 0; i < 4; i++) {
        if (gameState->GetGameObjectByIndex(i) == 0) {
            continue;
        }
        if ((state->activeCombatants & (1 << i)) == 0) {
            continue;
        }
        GetGameResources();
        CombatantRecovery *combatant = static_cast<CombatantRecovery *>(GetCombatantWithFlag0x100_0200ff1c(gameState, i));
        if (combatant == 0) {
            continue;
        }
        Zone3D *zone = static_cast<Zone3D *>(Zone3D_GetInstance());
        if (&zone->substruct_c_ == 0 || zone->pUnknownStruct_8_ == 0) {
            return;
        }
        if ((combatant->obj3D_.unknown_0_ & 0x1000) != 0) {
            if (zone->currentZoneID_ == 10000 || zone->currentZoneID_ == 10100) {
                combatant->recoveryFlags &= ~8;
                continue;
            }
        }
        Node02021f88 *node;
        int found = 0;
        if (flag != 0) {
            state->activeCombatants &= ~(1 << i);
        }
        node      = state->first;
        int value = combatant->obj3D_.GetField06();
        if (zone->currentZoneID_ == 10000 || zone->currentZoneID_ == 10100) {
            if (value < 20000 || value > 29999) {
                value = value / 100 * 100;
            }
            while (node != 0 && found == 0) {
                for (int j = 0; j < node->count && found == 0; j++) {
                    int entryValue = static_cast<unsigned short>(node->data[j]);
                    if (entryValue < 20000 || entryValue > 29999) {
                        entryValue = entryValue / 100 * 100;
                    }
                    if (entryValue == value) {
                        combatant->recoveryFlags |= 8;
                        if (node->type == 0) {
                            combatant->recoveryFlags &= ~0x10;
                        } else {
                            combatant->recoveryFlags |= 0x10;
                            SetFields1a8And1ac(combatant, node->x, node->y);
                            SetField0x1b0_02053f6c(combatant, node->id);
                        }
                        found = 1;
                    }
                }
                node = node->next;
            }
        } else if (IsValueInRange0201b5d8(value) != 0) {
            GameObject *unknownObject = gameState->GetUnknownGameObject();
            if (unknownObject != 0) {
                int unknownValue = unknownObject->obj3D_.GetField06();
                if (unknownValue == value) {
                    combatant->recoveryFlags |= 8;
                    combatant->recoveryFlags &= ~0x10;
                    found = 1;
                }
            }
        } else {
            while (node != 0 && found == 0) {
                for (int j = 0; j < node->count && found == 0; j++) {
                    if (value == static_cast<unsigned short>(node->data[j])) {
                        combatant->recoveryFlags |= 8;
                        if (node->type == 0) {
                            combatant->recoveryFlags &= ~0x10;
                        } else {
                            combatant->recoveryFlags |= 0x10;
                            SetFields1a8And1ac(combatant, node->x, node->y);
                            SetField0x1b0_02053f6c(combatant, node->id);
                        }
                        found = 1;
                    }
                }
                node = node->next;
            }
        }
        if (found == 0) {
            combatant->recoveryFlags &= ~8;
        }
    }
}
