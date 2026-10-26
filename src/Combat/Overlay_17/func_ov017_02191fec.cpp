#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_0219219c(char* base, int idx);
extern "C" int func_ov017_021920dc(int unused, int id);

// USA: func_ov017_02191fec
extern "C" ARM int func_ov017_02191fec(int a, int id) {
    int result = 1;
    GameState* battle = GameState::GetInstance();
    GameObject* c = battle->GetCombatantByIndex(id);
    if (c != NULL && (*(int*)((char*)c->currentStats_ + 0x14) & 0x1000000)) {
        if (func_ov017_0219219c((char*)a, id) != 0) {
            unsigned char* p1 = (unsigned char*)func_ov017_0219219c((char*)a, id);
            if (p1) *p1 |= 1;
            unsigned char* p2 = (unsigned char*)func_ov017_0219219c((char*)a, id);
            if (p2) *p2 |= 4;
        }
        result = 0;
    }
    if (func_ov017_021920dc(a, id) != 0) {
        if (func_ov017_0219219c((char*)a, id) != 0) {
            unsigned char* p3 = (unsigned char*)func_ov017_0219219c((char*)a, id);
            if (p3) *p3 |= 1;
            unsigned char* p4 = (unsigned char*)func_ov017_0219219c((char*)a, id);
            if (p4) *p4 |= 2;
        }
        result = 0;
    }
    return result;
}
