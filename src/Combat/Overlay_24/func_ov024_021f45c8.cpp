#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov024_021fea1c { int ids[2]; };

extern "C" GameObject* func_ov000_021536f8(int unused, int id);
extern "C" void* func_ov000_02160130(void);
extern "C" int func_ov000_0215fb54(int unused, int key, struct Struct_ov024_021fea1c* out);
extern "C" void* func_ov000_02162d88(void* obj, int key);

struct Struct_ov024_021f45c8 {
	unsigned char pad0;
	unsigned char flags : 4;
	unsigned char groupCount : 2;
	unsigned char pad1 : 2;
	char pad2[2];
	unsigned short key;
	char pad6[8];
	unsigned char memberCount : 4;
	unsigned char weight : 4;
	char unknown_f_[0x18 - 0xf];
};
struct Struct_ov024_021f45c8_2 { int field0; };
struct Struct_ov024_021f45c8_3 { unsigned char pad0; unsigned char flags : 4; unsigned char groupCount : 2; unsigned char pad1 : 2; };
struct Struct_ov024_021f45c8_4 {
	char pad0[4];
	unsigned int key : 12;
	unsigned int unknown_5_4_ : 20;
	char pad8[0x18 - 8];
	unsigned int unknown_18_0_ : 5;
	unsigned int kind : 7;
	unsigned int unknown_19_4_ : 20;
};
extern struct Struct_ov024_021fea1c data_ov024_021fea1c[];

// USA: func_ov024_021f45c8
extern "C" ARM int func_ov024_021f45c8(struct Struct_ov024_021f45c8_2* obj, int id, struct Struct_ov024_021f45c8_4* action, int* outCount, short* arg4) {
	GameObject* c;
	void* work;
	int count;
	int i;
	c = func_ov000_021536f8(obj->field0, id);
	if (!c) return 0;
	work = func_ov000_02160130();
	if (!work) return 0;
	struct Struct_ov024_021f45c8* groups = (struct Struct_ov024_021f45c8*)((char*)obj->field0 + 0x81b0);
	if (!groups) return 0;
	if (action->kind == 0xc) {
		struct Struct_ov024_021fea1c rec;
		rec.ids[1] = data_ov024_021fea1c[63].ids[1];
		rec.ids[0] = data_ov024_021fea1c[63].ids[0];
		count = func_ov000_0215fb54(obj->field0, action->key, &rec);
		for (i = 0; i < count; i++) {
			if (!func_ov000_02162d88(work, rec.ids[i])) return 0;
			if (((struct Struct_ov024_021f45c8_3*)groups)->groupCount >= 3) {
				int found = 0;
				int j;
				for (j = 0; j < groups->groupCount; j++) {
					if (groups[j].key == rec.ids[i]) {
						found = 1;
						break;
					}
				}
				if (!found) {
					for (j = 0; j < groups->groupCount; j++) {
						if (groups[j].weight == 0) {
							found = 1;
							break;
						}
					}
					if (!found) return 0;
				}
			}
		}
	}
	int limit = 5;
	if (c->obj3D_.unknown_2_ == 0x10a) limit = 8;
	if (limit <= groups->flags) return 0;
	*outCount = 1;
	*arg4 = id;
	return 1;
}
