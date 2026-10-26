#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02173490_480 = 0x1ec };
enum { kRegioncc = 0xca };
enum { Enum_ov003_02173490_212 = 0xd0 };
enum { Enum_ov003_02173490_236 = 0xe8 };
enum { Enum_ov003_02173490_238 = 0xea };
enum { Enum_ov003_02173490_237 = 0xe9 };
enum { Enum_ov003_02173490_239 = 0xeb };
#else
enum { Enum_ov003_02173490_480 = 0x1e0 };
enum { kRegioncc = 0xcc };
enum { Enum_ov003_02173490_212 = 0xd4 };
enum { Enum_ov003_02173490_236 = 0xec };
enum { Enum_ov003_02173490_238 = 0xee };
enum { Enum_ov003_02173490_237 = 0xed };
enum { Enum_ov003_02173490_239 = 0xef };
#endif

extern "C" int func_ov003_0217bdb8(void* p);

// USA: func_ov003_02173490
extern "C" ARM void func_ov003_02173490(unsigned char* obj) {
	int ok = (func_ov003_0217bdb8(obj + Enum_ov003_02173490_480) != 0);
	if (!ok) return;
	obj[kRegioncc] = 1;
	obj[Enum_ov003_02173490_212] = 0;
	obj[Enum_ov003_02173490_236] = 4;
	obj[Enum_ov003_02173490_238] = 0;
	obj[Enum_ov003_02173490_237] = 4;
	obj[Enum_ov003_02173490_239] = 0;
}
