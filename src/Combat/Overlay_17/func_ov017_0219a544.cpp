#if defined(jpn)
enum { Enum_ov017_0219a544_16516 = 0x3e64, Enum_ov017_0219a544_0 = 10 };
#else
enum { Enum_ov017_0219a544_16516 = 0x4084, Enum_ov017_0219a544_0 = 0 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02041f70(char* buf, int a, int b);
extern "C" int func_02041a28(char* dst, int x);
struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int func_02039730(void* unused, int index);
extern "C" int func_02042084(char* buffer, char* label, int width, int extra);

struct Struct_ov017_021d6470 { int values[5]; };
extern struct Struct_ov017_021d6470 data_ov017_021d6470;
extern int data_ov017_021d6460[4];

// USA: func_ov017_0219a544
extern "C" ARM void func_ov017_0219a544(unsigned char* a, char* buf, int type, int value) {
	if (!buf) return;
	if (type == 3 && value > 0) {
		func_02041f70(buf, 3, 2);
	}
	int var0 = value;
	if (type == 3 && value <= 0) {
		struct Struct_ov017_021d6470 local = data_ov017_021d6470;
		GameObject* combatant;
		int idx = 0;
		GameState* battle = GameState::GetInstance();
		combatant = battle->GetProtagonist();
		while (((volatile int*)local.values)[idx] != 7) {
			var0 = (signed char)func_02039730(combatant, ((volatile int*)local.values)[idx]);
			if (var0 > 0) break;
			idx = (idx + 1) & 0xff;
		}
	}
	int key = (var0 < 0) ? 0 : var0;
	struct Container020e0310* container = *(struct Container020e0310**)(a + Enum_ov017_0219a544_16516);
	int fieldResult = KeyTable_Get(container, key);
	if (!fieldResult) return;
	func_02041a28(buf, 0);
	int width = data_ov017_021d6460[type];
	func_02042084(buf, (char*)fieldResult, width, Enum_ov017_0219a544_0);
}
