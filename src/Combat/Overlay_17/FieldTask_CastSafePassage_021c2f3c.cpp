#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_02057924(void);
extern "C" void* LinkSession_GetInstance(void);
extern "C" void func_020531f0(void* obj);
struct Obj020397cc;
void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);
struct U16Field0x6_020375f8;
extern "C" void func_ov017_021c2b6c(void* self);
void ForwardResetAndCaptureTimestamp_021c2e50(char* self);
void InitAndDispatchCombatant_021c2ea4(unsigned char* self);
int CountValidCombatants02058618(void* unused);
unsigned long long GetCurrentTimestamp(void);
extern "C" unsigned long long _ll_udiv(unsigned long long dividend, unsigned int divisor, unsigned int flag);
int LinkSession_IsActive(int* obj);
void GameObject_EnableControl(void* obj);
extern "C" void func_ov017_021c310c(void* self);
extern "C" void ROMFilesystem_InitFileTables(void);

// USA: FieldTask_CastSafePassage  (semantic: UpdateStateMachine_021c2f3c)
#pragma optimize_for_size off
// Overlay 17, originally func_ov017_021c2f3c (USA/EUR 0x021c2f3c, JPN 0x021c3438)
extern "C" ARM void FieldTask_CastSafePassage(unsigned char* self) {
    GameObject* combatant = GameState::GetInstance()->GetLeader();
    void* r7 = func_02057924();
    void* r5 = LinkSession_GetInstance();

    if (combatant == 0) self[0x8c] = 3;
    unsigned char state = self[0x8c];
    if (state == 0) {
        if (combatant != 0) {
            func_020531f0(combatant);
            GameObject_DisableControl((struct Obj020397cc*)combatant, 1);
        }

        if (((Object3D*)((struct U16Field0x6_020375f8*)combatant))->GetField06() == 0x2710 ||
            ((Object3D*)((struct U16Field0x6_020375f8*)combatant))->GetField06() == 0x2774) {
            self[0x8c] = 2;
            return;
        }

        if (self[0x94] == 0) { self[0x8c] = 1; return; }
        if (self[0x94] != 1) return;
        if (LinkSession_IsActive((int*)r5) != 0) {
            self[0x8c] = 2;
            return;
        }
        self[0x8c] = 3;
        return;
    }

    if (state == 1) {
        func_ov017_021c2b6c(self);
        if (*(void**)(self + 0x90) != 0) self[0x8c] = 2;
        return;
    }
    if (state == 2) {
        if (self[0x94] == 0) {
            ForwardResetAndCaptureTimestamp_021c2e50((char*)self);
            return;
        }
        if (self[0x94] == 1) InitAndDispatchCombatant_021c2ea4(self);
        return;
    }
    if (state != 3) return;

    if (*(void**)(self + 0x90) != 0) {
        if (CountValidCombatants02058618(r7) > 0) return;
    }

    unsigned long long diff = GetCurrentTimestamp() - *(unsigned long long*)(self + 0x98);
    unsigned long long quotient = _ll_udiv(diff << 6, 0x82ea, 0);
    if (quotient < 0x4b0) return;

    self[0x1] = 1;
    func_ov017_021c310c(self);
    if (self[0x96] != 0) ROMFilesystem_InitFileTables();
    if (combatant != 0) GameObject_EnableControl(combatant);
}
