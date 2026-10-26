#include <globaldefs.h>
#include "Resource/GameResources.h"
#if defined(jpn)
#define REGION_FIELD_0 0x4ec
#define REGION_FIELD_1 0x960
#else
#define REGION_FIELD_0 0x6fc
#define REGION_FIELD_1 0xb80
#endif


struct Struct_ov017_021a93f0;
extern "C" void func_ov017_021a942c(Struct_ov017_021a93f0* p);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(TailList020469b4* list, TailNode020469b4* node);

// USA: func_ov017_021a93f0
extern "C" ARM void func_ov017_021a93f0(void* unused, int arg1, int arg2) {
	char* base = (char*)GetGameResources() + 0x3000;
	TailList020469b4* list = *(TailList020469b4**)(base + REGION_FIELD_0);
	Struct_ov017_021a93f0* node = *(Struct_ov017_021a93f0**)(base + REGION_FIELD_1);
	func_ov017_021a942c(node);
	*(int*)((char*)node + 0xc) = arg1;
	*(int*)((char*)node + 0x10) = arg2;
	func_020469b4(list, (TailNode020469b4*)node);
}
