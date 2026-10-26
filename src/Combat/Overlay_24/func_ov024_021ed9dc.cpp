#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" void* func_ov000_02153710(void*, int);
extern "C" int func_02083be8(unsigned char* obj);
struct Struct_ov024_021dced0_2;
extern "C" int func_ov024_021dd010(struct Struct_ov024_021dced0_2* obj);
extern "C" int func_ov024_021eda60(GameObject* combatant);

struct Struct_ov024_021ed9dc { void* field0; };

// USA: func_ov024_021ed9dc
extern "C" ARM int func_ov024_021ed9dc(struct Struct_ov024_021ed9dc* holder, int id) {
    void* p = func_ov000_02153710(holder->field0, id);
    if (!p) return 0;
    if (!func_02083be8((unsigned char*)p)) return 0;
    GameObject* combatant = GetCombatantByID((int)holder->field0, id);
    if (!combatant) return 0;
    void* inner = combatant->currentStats_;
    if (*(unsigned short*)((char*)inner + 2) == 0) return 0;
    if (func_ov024_021dd010((struct Struct_ov024_021dced0_2*)combatant)) return 0;
    return !func_ov024_021eda60(combatant);
}
