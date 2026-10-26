#include <globaldefs.h>

struct Struct_ov031_02213f14_3 {
	unsigned char lo : 4;
	unsigned char state : 4;
	unsigned char id;
	unsigned char field2;
	unsigned char unknown_3_;
	char name[0x20];
};

struct Struct_ov031_02213f14 {
	char pad0[0xa];
	unsigned short unknown_a_;
	char name[0xb4];
};

struct Struct_ov031_02213f14_2 {
	char pad0[0x300];
	Struct_ov031_02213f14_3 entries[9];
	char unknown_444_[0x2c];
	Struct_ov031_02213f14 slots[11];
	char unknown_cb0_[0x5c];
	unsigned char lo : 4;
	unsigned char unknown_d0c_4_ : 2;
	unsigned char mode : 2;
	unsigned char unknown_d0d_;
	unsigned char unknown_d0e_;
	unsigned char unknown_d0f_;
	unsigned char count;
	unsigned char unknown_d11_;
	unsigned char unknown_d12_;
	unsigned char unknown_d13_;
};

extern "C" int func_ov031_02213800(Struct_ov031_02213f14* slot);
extern "C" int func_ov031_022145b4(Struct_ov031_02213f14* slot);
extern "C" int strncmp(const void*, const void*, unsigned int);

// USA: func_ov031_02213f14
extern "C" ARM unsigned char func_ov031_02213f14(Struct_ov031_02213f14_2* e) {
	Struct_ov031_02213f14* slot;
	int result;
	int i;

	slot = &e->slots[e->unknown_d13_];
	result = 0;
	if (e->mode == 0) {
		int count;
		char* base;
		char* name;
		Struct_ov031_02213f14_3* ent;

		count = 0;
		if (slot->unknown_a_ == 0x20) {
			result = func_ov031_02213800(slot);
			if (result > 0) {
				count++;
			} else {
				result = 0;
			}
		} else if (slot->unknown_a_ == 8) {
			result = func_ov031_022145b4(slot);
			if (result != 0) {
				count++;
			} else {
				result = 0;
			}
		}
		i = 0;
		if (i < e->count) {
			base = (char*)e;
			name = e->entries[0].name;
			ent = e->entries;
			do {
				if (slot->unknown_a_ == *(unsigned char*)(base + 0x303) && strncmp(slot->name, name, slot->unknown_a_) == 0) {
					if (count == 0) {
						result = *(unsigned char*)(base + 0x301);
					} else {
						ent->state = 1;
						e->mode = 1;
					}
					count++;
				}
				i++;
				base += 0x24;
				name += 0x24;
				ent++;
			} while (i < e->count);
		}
	} else {
		Struct_ov031_02213f14_3* ent;
		char* base;
		int count;

		i = 0;
		count = 0;
		if (i < e->count) {
			base = (char*)e;
			ent = e->entries;
			do {
				if (ent->state == 1) {
					if (count == 0) {
						ent->state = 0;
						result = *(unsigned char*)(base + 0x301);
					}
					count++;
				}
				i++;
				ent++;
				base += 0x24;
			} while (i < e->count);
		}
		if (count == 1) {
			e->mode = 0;
		}
	}
	return result;
}
