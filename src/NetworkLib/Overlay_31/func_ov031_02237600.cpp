#include <globaldefs.h>

extern "C" ARM int func_020d4848(void* src);
extern "C" ARM int func_020d5004(int arg);
extern "C" ARM int func_020d503c(int arg);
extern "C" ARM int func_ov031_0223e2e0(int arg0, void* arg1);
extern "C" ARM unsigned int func_ov031_0223cf70(void** a);
extern "C" void func_ov031_022376fc(void);

struct Struct_ov031_02237600 {
	unsigned char pad0[0x13b8];
	unsigned short status;
	unsigned char pad1[0x1b90 - 0x13ba];
	void* pending;
	volatile unsigned char state;
};

extern "C" Struct_ov031_02237600* data_ov031_02290d0c;
namespace DuplicatePool {
	extern "C" Struct_ov031_02237600* data_ov031_02290d0c;
}

// USA: func_ov031_02237600
extern "C" ARM int func_ov031_02237600(void) {
	data_ov031_02290d0c->state = 1;
	func_020d4848(&data_ov031_02290d0c->status);

	if (data_ov031_02290d0c->status != 2) {
		if (func_020d5004((int)func_ov031_022376fc) != 2) {
			return 0;
		}
		do {
			func_020d4848(&data_ov031_02290d0c->status);
		} while (data_ov031_02290d0c->status != 2);
	}

	if (func_020d503c((int)func_ov031_022376fc) != 2) {
		return 0;
	}

	if (data_ov031_02290d0c->pending != 0) {
		func_ov031_0223e2e0(0, data_ov031_02290d0c->pending);
	}

	Struct_ov031_02237600* link = data_ov031_02290d0c;
	while (link->state != 2) {
	}

	func_ov031_0223cf70((void**)&DuplicatePool::data_ov031_02290d0c);
	return 1;
}
