#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" int func_020850d0(unsigned char* obj);
extern "C" int func_ov000_021564cc(struct Random* arg0, int id);

struct Struct_ov024_021e8dc0 {
	char pad0[0x10];
	struct Random* unknown_10_;
	char unknown_14_[0x78 - 0x14];
	unsigned char unknown_78_;
	unsigned char unknown_79_;
	unsigned char unknown_7a_;
};

struct Struct_ov024_021e8dc0_2 {
	char pad0[4];
	unsigned int unknown_4_0_ : 12;
	unsigned int unknown_5_4_ : 20;
	char pad8[0x10 - 0x8];
	unsigned int flags10;
	char unknown_14_[0x1c - 0x14];
	unsigned int unknown_1c_0_ : 14;
	unsigned int unknown_1d_6_ : 5;
	unsigned int unknown_1e_3_ : 13;
};

struct Struct_ov024_021e8dc0_3 {
#if defined(jpn)
	char pad0[0x144];
#else
	char pad0[0x150];
#endif
	unsigned char* field150;
};

struct Struct_ov024_021e8dc0_4 {
	unsigned int bit0 : 1;
	unsigned int unknown_0_1_ : 1;
	unsigned int rest : 30;
};

struct Struct_ov024_021fe930 {
	short v[32];
};

extern struct Struct_ov024_021fe930 data_ov024_021fe930;

static inline int IsPartyMember(int id) {
	return id >= 0 && id <= 3;
}

// USA: func_ov024_021e8dc0
extern "C" ARM int func_ov024_021e8dc0(struct Struct_ov024_021e8dc0* ctx, int id, struct Struct_ov024_021e8dc0_2* params, short* list, int num) {
	struct Random* var0 = ctx->unknown_10_;
	int count = 1;
	switch (params->unknown_1d_6_) {
		case 1: count = 2; break;
		case 2: count = (int)NextRandomFloatBetween(var0, 3.0f, 4.0f); break;
		case 6: count = 4; break;
		case 9: count = 5; break;
	}
	if (count > 1) ctx->unknown_7a_ = 1;
	if (IsPartyMember(id)) {
		struct Struct_ov024_021e8dc0_3* c = (struct Struct_ov024_021e8dc0_3*)func_0200ff1c(GameState::GetInstance(), id);
		if (c && (params->flags10 & 0x100000) && func_020850d0(c->field150)) {
			ctx->unknown_7a_ = 1;
			count *= 2;
		}
		if (params->unknown_4_0_ == 1) {
			struct Struct_ov024_021e8dc0_4* w = (struct Struct_ov024_021e8dc0_4*)(c->field150 + 0x2f4);
			if (!w) return count;
			if (!w->unknown_0_1_ && !w->bit0 && func_ov000_021564cc(ctx->unknown_10_, id)) {
				ctx->unknown_78_ = 1;
				ctx->unknown_7a_ = 1;
				count++;
			}
		}
	}
	struct Struct_ov024_021fe930 buf = data_ov024_021fe930;
	short n = 0;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < num; j++) {
			buf.v[n++] = list[j];
		}
	}
	memcpy(list, &buf, n * 2);
	return n;
}
