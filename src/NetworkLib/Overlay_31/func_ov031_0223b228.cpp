#include <globaldefs.h>

struct Struct_ov031_0223b228_2 {
	unsigned short id;
	unsigned char pad[0x42];
};

struct Struct_ov031_0223b228 {
	unsigned char pad0[0x100];
	Struct_ov031_0223b228_2 elems[3];
	unsigned char unknown_1cc_[0x34];
	unsigned short counter;
	unsigned short unknown_202_;
	unsigned char unknown_204_[4];
	void* slots[16];
	unsigned char unknown_248_[0x84b];
	unsigned char unknown_a93_;
	unsigned int ticks;
};

extern Struct_ov031_0223b228* data_ov031_02290d20;

// USA: func_ov031_0223b228
extern "C" ARM void func_ov031_0223b228(void) {
	int i = 0;
	do {
		void* slot = *(void**)((char*)data_ov031_02290d20->slots + i * sizeof(void*));
		if (slot == 0) {
			continue;
		}
		Struct_ov031_0223b228_2* elem = (Struct_ov031_0223b228_2*)((char*)data_ov031_02290d20->elems + i * sizeof(Struct_ov031_0223b228_2));
		if (i != 1) {
			continue;
		}
		if (data_ov031_02290d20->unknown_a93_ == 1) {
			if (elem->id != 0x10) {
				return;
			}
			data_ov031_02290d20->ticks++;
			if ((data_ov031_02290d20->ticks & 1) != 0) {
				continue;
			}
			data_ov031_02290d20->counter++;
			if (data_ov031_02290d20->counter >= 0x24) {
				data_ov031_02290d20->counter = 0;
			}
		} else {
			data_ov031_02290d20->unknown_202_ = 0xbc;
			if (elem->id != 0xbd) {
				continue;
			}
			data_ov031_02290d20->unknown_a93_ = 1;
			data_ov031_02290d20->counter = 0;
			data_ov031_02290d20->ticks = 0;
		}
	} while (++i < 16);
}
