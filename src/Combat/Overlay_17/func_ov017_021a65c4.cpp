#include <globaldefs.h>
#include "Resource/GameResources.h"

struct TailList020469b4;
struct TailNode020469b4;
struct Struct_ov017_021a65c4;

extern "C" void func_ov017_021a6608(Struct_ov017_021a65c4* p);
extern "C" void func_020469b4(TailList020469b4* list, TailNode020469b4* node);

#if defined(jpn)
static const int kList=0x4ec, kNode=0x96c;
#else
static const int kList=0x6fc, kNode=0xb8c;
#endif

// USA: func_ov017_021a65c4
extern "C" ARM void func_ov017_021a65c4(void* unused, unsigned char b, int flag) {
	GameResources* ov = GetGameResources();
	char* base = (char*)ov + 0x3000;
	TailList020469b4* list = *(TailList020469b4**)(base + kList);
	Struct_ov017_021a65c4* node = *(Struct_ov017_021a65c4**)(base + kNode);
	func_ov017_021a6608(node);
	*((unsigned char*)node + 0xc) = b;
	if (flag != 0) {
		*((unsigned char*)node + 0xb) = 1;
	}
	func_020469b4(list, (TailNode020469b4*)node);
}
