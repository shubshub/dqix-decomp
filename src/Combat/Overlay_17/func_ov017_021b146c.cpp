#include <globaldefs.h>

#if defined(jpn)
#define REGION_FIELD_0 0x924
#define REGION_FIELD_1 0x4ec
#else
#define REGION_FIELD_0 0xb44
#define REGION_FIELD_1 0x6fc
#endif


struct Struct_ov017_021b146c;
extern "C" void func_ov017_021b14a0(struct Struct_ov017_021b146c* obj);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov017_021b146c
extern "C" ARM void func_ov017_021b146c(void* self, unsigned char param1) {
	func_ov017_021b14a0((struct Struct_ov017_021b146c*)*(void**)((char*)self + 0x3000 + REGION_FIELD_0));
	*(unsigned char*)((char*)*(void**)((char*)self + 0x3000 + REGION_FIELD_0) + 0x49) = param1;
	func_020469b4((struct TailList020469b4*)*(void**)((char*)self + 0x3000 + REGION_FIELD_1),
	                 (struct TailNode020469b4*)*(void**)((char*)self + 0x3000 + REGION_FIELD_0));
}
