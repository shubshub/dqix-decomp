#include <globaldefs.h>

extern "C" void func_ov031_0223e2c0(int idx, void* obj);
extern "C" void func_ov031_0223ba20(int a);

struct Struct_ov031_02226d48;
extern "C" void func_ov031_0223c534(Struct_ov031_02226d48* obj);

struct Struct_ov031_0223da58;
extern "C" int func_ov031_0223da58(Struct_ov031_0223da58* obj);

extern "C" unsigned int func_ov031_0223cf70(void** a);

struct Struct_ov031_022257d4 {
	Struct_ov031_02226d48* grid[3][4];
	Struct_ov031_0223da58* flagsA[0x2f];
	Struct_ov031_0223da58* unknown_ec_[4];
	int unknown_fc_[2];
	int unknown_104_[4];
};

extern "C" Struct_ov031_022257d4* data_ov031_02250bfc;
namespace DuplicatePool {
	extern "C" Struct_ov031_022257d4* data_ov031_02250bfc;
}

// USA: func_ov031_022257d4
extern "C" ARM void func_ov031_022257d4(void* obj) {
	int i;
	int j;

	func_ov031_0223e2c0(0, obj);

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			func_ov031_0223c534(data_ov031_02250bfc->grid[i][j]);
			if (i == 0) {
				func_ov031_0223ba20(data_ov031_02250bfc->unknown_104_[j]);
			}
		}
	}

	for (i = 0; i < 2; i++) {
		func_ov031_0223ba20(data_ov031_02250bfc->unknown_fc_[i]);
	}

	for (i = 0; i < 4; i++) {
		func_ov031_0223da58(data_ov031_02250bfc->unknown_ec_[i]);
	}

	for (i = 0; i < 0x2f; i++) {
		func_ov031_0223da58(data_ov031_02250bfc->flagsA[i]);
	}

	func_ov031_0223cf70((void**)&DuplicatePool::data_ov031_02250bfc);
}
