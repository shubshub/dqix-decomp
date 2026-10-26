#include <globaldefs.h>

#if defined(jpn)
#define RG(usa, jpn) (jpn)
#else
#define RG(usa, jpn) (usa)
#endif

struct TailNode020469b4 { unsigned char pad0[2]; unsigned char inList; unsigned char pad3; void* next; };
struct TailList020469b4 { void* head; void* tail; };
extern "C" void func_020469b4(TailList020469b4* list, TailNode020469b4* node);

// USA: func_ov017_0219bc88
extern "C" ARM void func_ov017_0219bc88(unsigned char* base, void* unused1) {
	base += 0x3000;
	TailNode020469b4* node = *(TailNode020469b4**)(base + RG(0xbb4, 0x994));
	if (node->inList == 0) {
		TailList020469b4* list = *(TailList020469b4**)(base + RG(0x6fc, 0x4ec));
		func_020469b4(list, node);
	}
}
