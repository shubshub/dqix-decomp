#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

extern "C" int func_020882f8(unsigned char* obj);
struct Struct_ov024_021de124;
extern "C" int func_ov024_021de25c(struct Struct_ov024_021de124* obj);
struct Struct_ov024_021da670_7;
extern "C" int func_ov024_021da9b0(struct Struct_ov024_021da670_7* obj);
struct Struct_ov024_021da670_8;
extern "C" int func_ov024_021da9c8(struct Struct_ov024_021da670_8* obj);
struct Struct_020885b4;
extern "C" int func_020885b4(struct Struct_020885b4* obj);
struct Struct_02088514;
extern "C" int func_02088514(struct Struct_02088514* obj);
struct Struct_ov024_021df454_2;
extern "C" int func_ov024_021df6ec(struct Struct_ov024_021df454_2* obj);
struct Struct_ov024_021dced0_2;
extern "C" int func_ov024_021dd010(struct Struct_ov024_021dced0_2* obj);

struct Struct_ov024_021edcc8_2 {
	char pad0[0x58];
	signed int attack : 3;
	signed int unknown_58_3_ : 3;
	signed int agility : 3;
	signed int charm : 3;
	signed int magicalMight : 3;
	signed int magicalMending : 3;
	signed int unknown_5a_2_ : 3;
	signed int unknown_5a_5_ : 3;
	signed int unknown_5b_0_ : 3;
	signed int unknown_5b_3_ : 3;
};

struct Struct_ov024_021edcc8 { int battle; };

// USA: func_ov024_021edcc8
extern "C" ARM int func_ov024_021edcc8(struct Struct_ov024_021edcc8* ctx, int id) {
	GameObject* c = GetCombatantByID(ctx->battle, id);
	if (!c) return 0;
	if (func_020882f8((unsigned char*)c->currentStats_)) return 1;
	if (func_ov024_021de25c((struct Struct_ov024_021de124*)c)) return 1;
	if (func_ov024_021da9b0((struct Struct_ov024_021da670_7*)c)) return 1;
	if (func_ov024_021da9c8((struct Struct_ov024_021da670_8*)c)) return 1;
	if (func_020885b4((struct Struct_020885b4*)c->currentStats_)) return 1;
	if (func_02088514((struct Struct_02088514*)c->currentStats_)) return 1;
	if (func_ov024_021df6ec((struct Struct_ov024_021df454_2*)c)) return 1;
	if (func_ov024_021dd010((struct Struct_ov024_021dced0_2*)c)) return 1;
	struct Struct_ov024_021edcc8_2* s = (struct Struct_ov024_021edcc8_2*)c->currentStats_;
	if (s->attack < 0) return 1;
	if (s->unknown_58_3_ < 0) return 1;
	if (s->agility < 0) return 1;
	if (s->charm < 0) return 1;
	if (s->magicalMight < 0) return 1;
	if (s->magicalMending < 0) return 1;
	if (s->unknown_5a_2_ < 0) return 1;
	if (s->unknown_5a_5_ < 0) return 1;
	if (s->unknown_5b_3_ < 0) return 1;
	return s->unknown_5b_0_ < 0;
}
