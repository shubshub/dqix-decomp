#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

void InitRegionArray02087628(char* p);
#define InitRegionArray02087628 InitRegionArray02087628

unsigned char CopyOutRegion0x5718_02011494(char* src, void* dst);

int GameState_GetProtagonistIndex(GameState* b);

extern "C" void __clear(void* buf, int size);

void* GetFieldAt0x150_02053c6c(unsigned char* p);
#define GetFieldAt0x150_02053c6c GetFieldAt0x150_02053c6c

signed char GetSignedField6Bit_021b6c2c(int a, int b);
#define GetSignedField6Bit_021b6c2c GetSignedField6Bit_021b6c2c

struct Base02087510;
int FindFreeSlotAndStore02087510(Base02087510* base, char id, void* data);
#define FindFreeSlotAndStore02087510 FindFreeSlotAndStore02087510

#define GetCombatantAtField0x3ac _Z24GetCombatantAtField0x3acP9GameState

struct Obj020397cc;
void GameObject_DisableControl(Obj020397cc* p, int flag);

// USA: func_ov017_021b6c78  (semantic: Dispatch_021b6c78)
extern "C" ARM void func_ov017_021b6c78(void) {
    GameState* battle = GameState::GetInstance();
    void* region = GameState_GetParty(battle);
    InitRegionArray02087628((char*)region);

    if (*((unsigned char*)region + 0xf7c) <= 1) {
        return;
    }

    char buf1[4];
    char buf2[0x10];
    unsigned char count = CopyOutRegion0x5718_02011494((char*)battle, buf1);

    for (unsigned char idx = 0; idx < count; idx = (unsigned char)(idx + 1)) {
        char id = buf1[idx];
        if (id != GameState_GetProtagonistIndex(battle)) {
            __clear(buf2, 0x10);
            GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(battle, id);
            if (combatant) {
                unsigned char* fp = (unsigned char*)GetFieldAt0x150_02053c6c((unsigned char*)combatant);
                memcpy(buf2, fp + 0x54 + 0x400, 0x10);
            }
            signed char v = GetSignedField6Bit_021b6c2c(id, 1);
            if (v >= 0) {
                FindFreeSlotAndStore02087510((Base02087510*)region, v, buf2);
            }
        }
    }

    GameObject* c = battle->GetProtagonist();
    if (c) {
        GameObject_DisableControl((Obj020397cc*)c, 1);
    }
}
