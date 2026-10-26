#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

struct Struct_ov024_021df6ec { char unk[0x14]; int flags; };
struct Struct_ov024_021df454_2 { char unk[0x138]; struct Struct_ov024_021df6ec* inner; };
extern "C" int func_ov024_021df6ec(struct Struct_ov024_021df454_2* obj);

struct Struct_ov024_021e9198 { char pad[0x10]; void* unknown_10_; };
struct Struct_ov024_021e9198_2 { unsigned short unknown_0_0_ : 6; unsigned short code : 3; unsigned short rest : 7; };

// USA: func_ov024_021e9198
extern "C" ARM int func_ov024_021e9198(struct Struct_ov024_021e9198* ctx, int id, int code, int mode) {
	GameObject* c = GetCombatantByID((int)ctx->unknown_10_, id);
	if (!c) return 0;
	if (mode != 0) {
		if (!func_ov024_021df6ec((struct Struct_ov024_021df454_2*)c)) goto ret0;
		struct Struct_ov024_021e9198_2* b = (struct Struct_ov024_021e9198_2*)((char*)c->currentStats_ + 0x22);
		if (b->code != code) goto ret0;
		switch (code) {
			case 1: return 0x26;
			case 2: return 0x140;
			case 3: return 0x126;
			case 4: return 0x13d;
			default: goto ret0;
		}
	}
	if (!func_ov024_021df6ec((struct Struct_ov024_021df454_2*)c)) goto ret0;
	{
		struct Struct_ov024_021e9198_2* b = (struct Struct_ov024_021e9198_2*)((char*)c->currentStats_ + 0x22);
		if (b->code != code) goto ret0;
		switch (code) {
			case 1: return 0x27;
			case 2: return 0x141;
			case 3: return 0x137;
			case 4: return 0x13f;
			default: goto ret0;
		}
	}
ret0:
	return 0;
}
