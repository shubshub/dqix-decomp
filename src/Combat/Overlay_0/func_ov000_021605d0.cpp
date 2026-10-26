#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x218
#define REGION_OFFSET_1 0x21c
#define REGION_OFFSET_2 0x7000
#define REGION_OFFSET_3 0x2c
#define REGION_OFFSET_4 0x30
#else
#define REGION_OFFSET_0 0x29c
#define REGION_OFFSET_1 0x2a0
#define REGION_OFFSET_2 0x6000
#define REGION_OFFSET_3 0xe3c
#define REGION_OFFSET_4 0xe40
#endif

#include "Util/Random.h"

struct Struct_ov000_021605d0 {
	struct Random* unknown_0_;
	int fieldB;
	int fieldC;
};

// USA: func_ov000_021605d0
extern "C" ARM void func_ov000_021605d0(unsigned char* obj, struct Struct_ov000_021605d0* params) {
	*(struct Random**)(obj + REGION_OFFSET_0) = params->unknown_0_;
	*(int*)(obj + REGION_OFFSET_1) = params->fieldB;
	*(int*)(obj + 0x4) = params->fieldC;

	struct Random* var0 = *(struct Random**)(obj + REGION_OFFSET_0);
	if (var0 == NULL) return;
	*(unsigned int*)(obj + REGION_OFFSET_2 + REGION_OFFSET_3) = GetRandomStateHi(var0);
	*(unsigned int*)(obj + REGION_OFFSET_2 + REGION_OFFSET_4) = GetRandomStateLo(var0);
}
