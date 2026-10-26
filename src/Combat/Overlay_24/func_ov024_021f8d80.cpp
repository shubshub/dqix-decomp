#include <globaldefs.h>

extern "C" void __clear(void* dst, int size);

struct Struct_ov024_021f8d80_3 {
	unsigned short unknown_0_;
	char pad2[0x14 - 2];
	unsigned int unknown_14_;
};
struct Struct_ov024_021f8d80 {
	char pad0[0x138];
	struct Struct_ov024_021f8d80_3* stats;
};
struct Struct_ov024_021f8d80_2 {
	char pad0[0x10];
	unsigned int flags10;
};

// USA: func_ov024_021f8d80
extern "C" ARM int func_ov024_021f8d80(void* unused, int* outIndex, struct Struct_ov024_021f8d80_2* ctx, struct Struct_ov024_021f8d80** arg3, int count, float* arg5, float* arg6, int arg7) {
	int priority[8];
	__clear(priority, sizeof(priority));
	for (int i = 0; i < count; i++) {
		struct Struct_ov024_021f8d80_3* stats = arg3[i]->stats;
		unsigned int flags = stats->unknown_14_;
		if ((ctx->flags10 & 0x400) && (flags & 0x200)) {
			priority[i] = -1;
		} else if (flags & 8) {
			priority[i] = 1;
		} else if (flags & 0x20) {
			priority[i] = 2;
		} else if (flags & 0x10) {
			priority[i] = 3;
		} else if (stats->unknown_0_ <= arg6[i]) {
			priority[i] = 5;
		} else {
			priority[i] = 4;
		}
	}
	int best = 0;
	for (int i = 1; i < count; i++) {
		if (priority[i] > priority[best]) {
			best = i;
		} else if (priority[i] == priority[best]) {
			int hp = arg3[i]->stats->unknown_0_;
			int var7 = arg3[best]->stats->unknown_0_;
			int var8 = 0;
			int margin = hp - (int)arg5[i] * arg7;
			int var10 = var7 - (int)arg5[best] * arg7;
			if (margin <= 0) {
				if (var10 > 0) {
					var8 = 1;
				} else if (hp > var7) {
					var8 = 1;
				}
			} else if (margin < var10) {
				var8 = 1;
			}
			if (var8) best = i;
		}
	}
	*outIndex = best;
	return priority[best] >= 0;
}
