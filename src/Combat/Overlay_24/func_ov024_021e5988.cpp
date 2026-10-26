#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_ov000_0215440c;
struct Struct_ov000_021600f8;
extern "C" struct Struct_ov000_021600f8* func_ov000_021600f8(struct Struct_ov000_0215440c* list, int index);
extern "C" void* func_ov000_0215fff4(void* obj, int limit, int idx);
extern "C" short func_ov000_0215a16c(void* unused, int id, int delta, short* arg3);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215ccbc(void* world, void* out, GameObject* combatant,
                            short arg3, short valA, short valB, unsigned long long word, unsigned char arg7);
extern "C" void func_ov000_0215fe84(void* obj, void* node, int idx);

struct Struct_ov024_021e5988_5 { char pad0[0x18]; unsigned char count; };
struct Struct_ov024_021e5988_6 { char pad0[0xc]; short value; };
struct Struct_ov024_021e5988 { char pad0[0x22]; short hp; };
struct Struct_ov024_021e5988_2 { unsigned int id : 12; unsigned int rest : 20; };
struct Struct_ov024_021e5988_3 { char pad0[4]; struct Struct_ov024_021e5988_2 f4; };
struct Struct_0200fd38_2 { char pad0[2]; short field2; };
struct Struct_ov024_021e5988_4 {
	char pad0[4];
	struct Struct_ov000_0215440c* unknown_4_;
	struct Struct_ov024_021e5988* unknown_8_;
	struct Struct_ov024_021e5988_5* unknown_c_;
	void* unknown_10_;
};

static inline short inline_ov024_021e5988(GameObject* c) { SDK_NULL_ASSERT(c); return ((struct Struct_0200fd38_2*)c->currentStats_)->field2; }

// USA: func_ov024_021e5988
extern "C" ARM void func_ov024_021e5988(struct Struct_ov024_021e5988_4* obj, int id, struct Struct_ov024_021e5988_3* action) {
	struct Struct_ov024_021e5988_5* var0;
	GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
	if (!c) return;
	var0 = obj->unknown_c_;
	if (action->f4.id == 0x91) {
		struct Struct_ov024_021e5988_5* first = (struct Struct_ov024_021e5988_5*)func_ov000_021600f8(obj->unknown_4_, 0);
		if (first) var0 = first;
	}
	int sum = 0;
	int depth = 0;
	for (int i = 0; i < var0->count; i++) {
		struct Struct_ov024_021e5988_6* d = (struct Struct_ov024_021e5988_6*)func_ov000_0215fff4(var0, i, depth);
		if (d) sum += d->value;
	}
	sum >>= 2;
	if (sum <= 0) return;
	short var7 = 0;
	short hp = func_ov000_0215a16c(obj->unknown_10_, id, sum, &var7);
	obj->unknown_8_->hp = hp;
	void* entry = func_ov000_0215e958(obj->unknown_10_);
	if (!entry) return;
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	func_ov000_02159eac(obj->unknown_10_, &local, 0x25);
	func_ov000_0215a88c(obj->unknown_10_, entry, 0x215);
	func_ov000_0215ccbc(obj->unknown_10_, entry, c, -sum, hp,
	                       inline_ov024_021e5988(c), local.v, 0);
	func_ov000_0215fe84(obj->unknown_8_, entry, 2);
	((unsigned char*)obj->unknown_10_)[0x8e02]++;
}
