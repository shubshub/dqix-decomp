#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0xc6
#define REGION_OFFSET_1 0x430
#define REGION_OFFSET_2 0xc7
#else
#define REGION_OFFSET_0 0x86
#define REGION_OFFSET_1 0x3f0
#define REGION_OFFSET_2 0x87
#endif


struct Struct_ov000_02171b3c {
	unsigned char pad0[REGION_OFFSET_0];
	unsigned char unknown_86_;
	unsigned char pad1[REGION_OFFSET_1 - REGION_OFFSET_2];
	int unknown_3f0_[0x10];
};

// USA: func_ov000_02171b3c
extern "C" ARM void func_ov000_02171b3c(struct Struct_ov000_02171b3c* obj) {
	int i;
	for (i = 0; i < 0x10; i++) {
		obj->unknown_3f0_[i] = 0;
	}
	obj->unknown_86_ = 0;
}
