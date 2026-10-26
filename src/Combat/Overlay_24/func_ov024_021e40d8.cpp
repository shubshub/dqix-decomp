#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantByID(int unused, int id);
extern "C" int func_ov024_021eae14(void* obj, int id);
struct Struct_ov024_021e2bd0;
extern "C" void* func_ov024_021e8ca0(struct Struct_ov024_021e2bd0* obj, int id);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021e40d8 { char pad0[0x10]; void* unknown_10_; };

// USA: func_ov024_021e40d8
extern "C" ARM long long func_ov024_021e40d8(struct Struct_ov024_021e40d8* obj, int unused, int id) {
	GameObject* combatant = GetCombatantByID((int)obj->unknown_10_, id);
	if (!combatant) return 0;
	if (func_ov024_021eae14(obj, id) > 0) {
		void* entry = func_ov024_021e8ca0((struct Struct_ov024_021e2bd0*)obj, 0xcb);
		if (entry) {
			func_ov000_0215cd44(obj->unknown_10_, entry, combatant, 0, 0, 0, 0);
		}
	}
	return 0;
}
