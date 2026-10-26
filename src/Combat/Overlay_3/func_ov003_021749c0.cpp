#include <globaldefs.h>

extern "C" void func_ov023_021dca88(void* obj);

struct FlagWord020466f4;
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
extern "C" void* GlobalFlags_GetInstance(void);

// USA: func_ov003_021749c0
extern "C" ARM void func_ov003_021749c0(char* obj) {
	func_ov023_021dca88(obj + 0x3c);
#if defined(jpn)
    enum { Enum_ov003_021749c0_4166 = 0xfc2 };
#else
    enum { Enum_ov003_021749c0_4166 = 0x1046 };
#endif
	*(unsigned short*)(obj + Enum_ov003_021749c0_4166) &= ~0x800;
	FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 1);
}
