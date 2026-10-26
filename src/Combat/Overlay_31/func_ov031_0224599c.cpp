#include <globaldefs.h>
#include "std_library_functions.h"


void SleepCurrentContext(unsigned int ticks);
extern "C" int func_ov031_0220d540(void);
extern "C" void* func_ov031_0220ec04(int index);
extern "C" int func_ov031_0220ca88(void);
extern "C" int func_ov031_0220c970(void* arg0, unsigned int size);
extern "C" int func_ov031_02245c68(int mode);
extern "C" void func_ov031_0220eadc(void);
extern "C" int func_ov031_0220eb88(int newVal);
extern "C" int func_ov031_0220eb30(void);
extern "C" int func_020c7ea0(void* queue, int* msg, int flags);
extern "C" void MIi_CpuClearFast(unsigned int value, void* dest, int count);
extern "C" void func_020ca4b4(const void* src, void* dest, int count);

struct Struct_ov031_0224599c {
	int kind;
	void* allocation;
	unsigned int size;
	int unknown_c_;
};

struct Struct_ov031_02291f24_3 {
	unsigned char b0;
	int field4;
	int field8;
	int fieldC;
	int field10;
	void* field14;
	char field18[0x14];
	struct Struct_ov031_0224599c arena;
};

struct Struct_ov031_02292040 {
	unsigned short length;
	char rest[0xbe];
};

extern struct Struct_ov031_02291f24_3 data_ov031_02291f24;
extern struct Struct_ov031_02292040 data_ov031_02292040;
extern int data_ov031_02291f60;

static inline void inline_ov031_0224599c(void* dest, int count) {
	MIi_CpuClearFast(0, dest, count);
}

static inline void inline_ov031_0224599c_2(const void* src, void* dest, int count) {
	func_020ca4b4(src, dest, count);
}

enum Enum_ov031_0224599c { Enum_ov031_0224599c_1 = 1, Enum_ov031_0224599c_4 = 4, Enum_ov031_0224599c_5 = 5 };

// USA: func_ov031_0224599c
extern "C" ARM void func_ov031_0224599c(void) {
	void* buf = data_ov031_02291f24.field14;
	unsigned int size;
	char* heap;
	int msg;

	if (buf == NULL) {
		return;
	}
	if (data_ov031_02291f24.b0 != 0) {
		size = data_ov031_02291f24.b0 * 0xd0 + 0xc;
	} else {
		size = 0x11ec;
	}
	memset(buf, 0, size + 0x2300);
	if (buf == NULL) {
		return;
	}
	heap = (char*)buf + 0x2300;
	if (func_ov031_0220c970(buf, 0x2300) != 0) {
		return;
	}
	data_ov031_02291f24.arena.kind = 2;
	data_ov031_02291f24.arena.allocation = heap;
	data_ov031_02291f24.arena.size = size;
	data_ov031_02291f24.arena.unknown_c_ = 0;

	while (data_ov031_02291f24.field4 == 0) {
		switch (func_ov031_0220d540()) {
		case 1:
			func_ov031_02245c68(1);
			break;
		case 3:
			if (data_ov031_02292040.length == 0) {
				func_ov031_0220eadc();
				func_ov031_02245c68(3);
			} else if (func_ov031_02245c68(5) == 0) {
				inline_ov031_0224599c(&data_ov031_02292040, 0xc0);
			}
			break;
		case 6:
			func_020c7ea0(&data_ov031_02291f60, &msg, 1);
			{
				Enum_ov031_0224599c found = Enum_ov031_0224599c_1;
				Enum_ov031_0224599c var5 = Enum_ov031_0224599c_4;
				if (msg == found) {
					if (data_ov031_02291f24.fieldC == 0) {
						func_ov031_0220eb88(1);
						if (func_ov031_0220eb30() >= 1) {
							inline_ov031_0224599c_2(func_ov031_0220ec04(0), &data_ov031_02292040, 0xc0);
						}
						func_ov031_0220eb88(0);
						func_ov031_02245c68(4);
					}
				} else if (msg == var5) {
					func_ov031_02245c68(4);
				}
			}
			break;
		case 9:
			func_020c7ea0(&data_ov031_02291f60, &msg, 1);
			{
				Enum_ov031_0224599c done = Enum_ov031_0224599c_5;
				if (msg == done) {
					func_ov031_02245c68(6);
				}
			}
			break;
		case 12:
			SleepCurrentContext(1);
			func_ov031_02245c68(9);
			break;
		default:
			for (;;) {
				SleepCurrentContext(10000);
			}
		}
	}

	while (data_ov031_02291f24.field4 != 0) {
		switch (func_ov031_0220d540()) {
		case 1:
			data_ov031_02291f24.field4 = 0;
			break;
		case 3:
			func_ov031_02245c68(2);
			break;
		case 6:
			func_ov031_02245c68(4);
			break;
		case 9:
			func_ov031_02245c68(6);
			break;
		case 12:
			func_ov031_02245c68(9);
			break;
		default:
			for (;;) {
				SleepCurrentContext(10000);
			}
		}
	}

	if (func_ov031_0220ca88() == 0) {
		return;
	}
}
