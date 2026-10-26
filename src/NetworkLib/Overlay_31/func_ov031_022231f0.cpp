#include <globaldefs.h>

struct Struct_ov031_022231f0 {
	void* item[2];
	void* unknown_8_;
	unsigned int unknown_c_;
	void* unknown_10_;
};

extern "C" ARM void func_ov031_0223e2c0(int a, int b);
extern "C" ARM void func_ov031_0223ba20(void* p);
extern "C" ARM void func_ov031_0223cf70(Struct_ov031_022231f0** p);

#if defined(jpn)
extern "C" Struct_ov031_022231f0* data_ov031_02250ba8;
namespace DuplicatePool {
    extern "C" Struct_ov031_022231f0* data_ov031_02250ba8;
}
#else
extern Struct_ov031_022231f0* data_ov031_02250ba8;
#endif

// USA: func_ov031_022231f0
extern "C" ARM void func_ov031_022231f0(int param) {
	func_ov031_0223e2c0(0, param);

	if (data_ov031_02250ba8->unknown_10_) {
		func_ov031_0223e2c0(0, (int)data_ov031_02250ba8->unknown_10_);
	}

	int i = 0;
	do {
		if (data_ov031_02250ba8->item[i]) {
			func_ov031_0223ba20(data_ov031_02250ba8->item[i]);
		}
		i++;
	} while (i < 2);

	func_ov031_0223ba20(data_ov031_02250ba8->unknown_8_);

#if defined(jpn)
	func_ov031_0223cf70(&DuplicatePool::data_ov031_02250ba8);
#else
	func_ov031_0223cf70((Struct_ov031_022231f0**)0x02250BA8);
#endif
}
