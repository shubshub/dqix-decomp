#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_ov024_021da670_6;
extern "C" int func_ov024_021da998(struct Struct_ov024_021da670_6* obj);
struct Struct_ov024_021dd028_5;
extern "C" int func_ov024_021dd260(struct Struct_ov024_021dd028_5* obj);

extern "C" void func_02088234(void* obj);
extern "C" void func_020881ac(void* obj);
extern "C" void func_02088914(unsigned char* obj);
extern "C" void func_020889b4(void* obj);
extern "C" void func_02088a04(void* obj);
extern "C" void func_02088a54(unsigned char* obj);
extern "C" void func_02088aa8(unsigned char* obj);
extern "C" void func_02088b34(unsigned char* obj);
extern "C" void func_02088964(unsigned char* obj);
extern "C" void func_02088b84(unsigned char* obj);
extern "C" void func_020888c4(unsigned char* obj);
extern "C" void func_02088af0(unsigned char* obj);
extern "C" void func_02088bd4(unsigned char* obj);
struct Struct_02088674;
extern "C" void func_02088674(struct Struct_02088674* obj);
extern "C" void func_02088cf4(unsigned char* obj);
extern "C" void func_02088d4c(unsigned char* obj);
extern "C" void func_02088c38(unsigned char* obj);
extern "C" void func_02088c9c(unsigned char* obj);
extern "C" void func_020890f4(unsigned char* obj);
extern "C" void func_02089144(unsigned char* obj);
extern "C" void func_02089194(unsigned char* obj);
extern "C" void func_02088d9c(unsigned char* obj);
extern "C" void func_02087838(void* obj);
extern "C" void func_0208792c(void* obj);
extern "C" void func_02087a20(void* obj);
extern "C" void func_02087b14(void* obj);
extern "C" void func_02087c08(void* obj);
extern "C" void func_02087cfc(void* obj);
extern "C" void func_02087df0(void* obj);
extern "C" void func_02087efc(unsigned char* obj);
extern "C" void func_020880e4(void* obj);
extern "C" void func_02087ff0(void* obj);

void ApplyCombatantBuffs(int unused, int combatantId);

struct Struct_ov024_021ddc80_5;
extern "C" void* func_ov024_021e8cfc(struct Struct_ov024_021ddc80_5* obj, void* c, int kind, int arg3);

struct Struct_ov024_021e2bd0;
extern "C" void* func_ov024_021e8ca0(struct Struct_ov024_021e2bd0* obj, int id);

extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021ea85c { char pad0[0x10]; void* unknown_10_; };

// USA: func_ov024_021ea85c
extern "C" ARM void* func_ov024_021ea85c(struct Struct_ov024_021ea85c* obj, int id, int arg2) {
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return 0;
	int flagA = func_ov024_021da998((struct Struct_ov024_021da670_6*)c);
	int var2 = func_ov024_021dd260((struct Struct_ov024_021dd028_5*)c);
	func_02088234(c->currentStats_);
	func_020881ac(c->currentStats_);
	func_02088914((unsigned char*)c->currentStats_);
	func_020889b4(c->currentStats_);
	func_02088a04(c->currentStats_);
	func_02088a54((unsigned char*)c->currentStats_);
	func_02088aa8((unsigned char*)c->currentStats_);
	func_02088b34((unsigned char*)c->currentStats_);
	func_02088964((unsigned char*)c->currentStats_);
	func_02088b84((unsigned char*)c->currentStats_);
	func_020888c4((unsigned char*)c->currentStats_);
	func_02088964((unsigned char*)c->currentStats_);
	func_02088af0((unsigned char*)c->currentStats_);
	func_02088bd4((unsigned char*)c->currentStats_);
	func_02088674((struct Struct_02088674*)c->currentStats_);
	func_02088cf4((unsigned char*)c->currentStats_);
	func_02088d4c((unsigned char*)c->currentStats_);
	func_02088c38((unsigned char*)c->currentStats_);
	func_02088c9c((unsigned char*)c->currentStats_);
	func_020890f4((unsigned char*)c->currentStats_);
	func_02089144((unsigned char*)c->currentStats_);
	func_02089194((unsigned char*)c->currentStats_);
	func_02088d9c((unsigned char*)c->currentStats_);
	func_02087838(c->currentStats_);
	func_0208792c(c->currentStats_);
	func_02087a20(c->currentStats_);
	func_02087b14(c->currentStats_);
	func_02087c08(c->currentStats_);
	func_02087cfc(c->currentStats_);
	func_02087df0(c->currentStats_);
	func_02087efc((unsigned char*)c->currentStats_);
	func_020880e4(c->currentStats_);
	func_02087ff0(c->currentStats_);
	ApplyCombatantBuffs((int)obj->unknown_10_, id);
	void* result = 0;
	if (flagA) {
		result = func_ov024_021e8cfc((struct Struct_ov024_021ddc80_5*)obj, c, 0, arg2);
	} else if (var2 && !func_ov024_021dd260((struct Struct_ov024_021dd028_5*)c)) {
		result = func_ov024_021e8cfc((struct Struct_ov024_021ddc80_5*)obj, c, 8, arg2);
	}
	if (arg2 != 0 && result == 0) {
		void* entry = func_ov024_021e8ca0((struct Struct_ov024_021e2bd0*)obj, 0xf1);
		result = entry;
		func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0, 0);
	}
	return result;
}
