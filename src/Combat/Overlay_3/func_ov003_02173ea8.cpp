#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02173ea8_236 = 0xe8 };
enum { Enum_ov003_02173ea8_238 = 0xea };
#else
enum { Enum_ov003_02173ea8_236 = 0xec };
enum { Enum_ov003_02173ea8_238 = 0xee };
#endif

extern "C" int* func_020936f8(void);
extern "C" void func_02093f68(char* obj);
extern "C" void func_ov003_02173b4c(void* obj);
extern "C" void func_ov003_02173bd8(void* obj);

// USA: func_ov003_02173ea8
extern "C" ARM void func_ov003_02173ea8(unsigned char* obj) {
	unsigned char f;
	func_02093f68((char*)func_020936f8());
	f = obj[Enum_ov003_02173ea8_236];
	if (f == 0) return;
	if (f == 1) {
		if (obj[Enum_ov003_02173ea8_238] < 2) return;
	}
	if (f == 6) return;
	func_ov003_02173b4c(obj);
	func_ov003_02173bd8(obj);
}
