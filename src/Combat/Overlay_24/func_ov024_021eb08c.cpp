#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);
extern "C" int func_02088dd8(unsigned char* obj);
extern "C" void func_02088e48(unsigned char* obj, unsigned char val);
extern "C" void func_020488ac(unsigned char* obj, int value);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" int func_020ac4c0(void* dst);
struct Struct_020a056c;
extern "C" void func_020a056c(struct Struct_020a056c* p, unsigned int amount);
extern "C" int func_020ac494(void* src);

struct Struct_ov024_021eb08c { char pad0[0x10]; struct Random* rng; };
struct Struct_ov024_021eb08c_2 {
	char pad0[0x24];
	unsigned int unknown_24_0_ : 7;
	unsigned int chanceA : 7;
	unsigned int unknown_25_6_ : 7;
	unsigned int chanceB : 7;
	unsigned int : 4;
	unsigned char unknown_28_;
	unsigned char unknown_29_;
};

static inline int inline_ov024_021eb08c(int slot) {
	return slot >= 0 && slot <= 3;
}

// USA: func_ov024_021eb08c
extern "C" ARM int func_ov024_021eb08c(struct Struct_ov024_021eb08c* obj, int slot, int id, unsigned int kind) {
	struct Random* rng;
	GameObject* c = func_ov000_021536f8((int)obj->rng, id);
	if (!c) return 0;
	struct Struct_ov024_021eb08c_2* effect = *(struct Struct_ov024_021eb08c_2**)((char*)c + 0x148);
	if (!effect) return 0;
	if (!inline_ov024_021eb08c(slot)) return 0;
	rng = obj->rng;
	unsigned int roll = NextRandomMax(rng, 100);
	if (!func_02088dd8((unsigned char*)c->currentStats_)) return 0;
	int turns = NextRandomBetween(rng, effect->unknown_28_, effect->unknown_29_);
	int result = 0;
	if (kind == effect->unknown_24_0_) {
		if (roll < effect->chanceA) {
			func_02088e48((unsigned char*)c->currentStats_, (unsigned char)turns);
			func_020488ac((unsigned char*)c, 1);
			result = 1;
			*(short*)((char*)c->currentStats_ + 0x2e) = slot;
		}
	} else if (kind == effect->unknown_25_6_) {
		if (roll < effect->chanceB) {
			func_02088e48((unsigned char*)c->currentStats_, (unsigned char)turns);
			func_020488ac((unsigned char*)c, 1);
			result = 1;
			*(short*)((char*)c->currentStats_ + 0x2e) = slot;
		}
	}
	if (result && slot == GameState_GetProtagonistIndex(GameState::GetInstance())) {
		char block[0xb0];
		func_020ac4c0(block);
		func_020a056c((struct Struct_020a056c*)block, 1);
		func_020ac494(block);
	}
	return result;
}
