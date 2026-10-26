#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" int func_ov031_0223a2b0(void* ctx);
extern "C" int func_ov031_02239be8(void);
extern "C" unsigned short func_ov031_02239bd4(void);
extern "C" int func_ov031_0223a288(int c);

struct Struct_ov031_0223b0c0 {
	unsigned short cmd;
	unsigned short arg;
	unsigned char data[0x40];
};

struct Struct_ov031_0223b0c0_2 {
	unsigned char pad0[0x100];
	unsigned char slots[2][0x44];
	unsigned char unknown_188_[0x204 - 0x188];
	int counter;
	int unknown_208_[2];
	unsigned char unknown_210_[0xa90 - 0x210];
	unsigned char state;
	unsigned char unknown_a91_;
	unsigned char unknown_a92_;
	unsigned char unknown_a93_;
	unsigned char unknown_a94_[0xab0 - 0xa94];
	Struct_ov031_0223b0c0* packet;
};

extern Struct_ov031_0223b0c0_2* data_ov031_02290d20;

// USA: func_ov031_0223b0c0
extern "C" ARM void func_ov031_0223b0c0(unsigned short cmd, unsigned short arg, const void* src) {
	if (data_ov031_02290d20->unknown_a93_ == 1) {
		data_ov031_02290d20->packet->cmd = cmd;
		data_ov031_02290d20->packet->arg = arg;
		VectorizedInvertedMemcpy(src, data_ov031_02290d20->packet->data, 0x40);
	} else {
		data_ov031_02290d20->counter++;
		data_ov031_02290d20->packet->cmd = 0xbc;
		data_ov031_02290d20->packet->data[0] = data_ov031_02290d20->unknown_a92_;
	}

	if (func_ov031_02239be8() != 5) {
		return;
	}
	if (func_ov031_0223a2b0(data_ov031_02290d20) == 0) {
		data_ov031_02290d20->counter += 4;
		return;
	}

	if (data_ov031_02290d20->unknown_a93_ == 0) {
		data_ov031_02290d20->counter++;
	} else {
		data_ov031_02290d20->counter = 0;
		if (func_ov031_02239bd4() != 3) {
			data_ov031_02290d20->state = 0x1b;
			return;
		}
	}

	unsigned short i = 0;
	do {
		int result = func_ov031_0223a288(i);
		if (result != 0) {
			VectorizedInvertedMemcpy((const void*)result, data_ov031_02290d20->slots[i], 0x44);
			data_ov031_02290d20->unknown_208_[i] = 1;
		} else {
			data_ov031_02290d20->unknown_208_[i] = 0;
		}
	} while (++i < 2);
}
