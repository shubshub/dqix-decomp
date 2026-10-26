#include <globaldefs.h>

extern int data_ov031_02291e04;
extern int data_ov031_02291e68;
extern "C" void func_ov031_022115d8(void* obj, int value);

#if defined(jpn)
enum { Enum_ov031_0224342c_16 = 0x34 };
#else
enum { Enum_ov031_0224342c_16 = 0x10 };
#endif

// USA: func_ov031_0224342c
extern "C" ARM void func_ov031_0224342c(int value) {
	*(int*)((char*)&data_ov031_02291e04 + Enum_ov031_0224342c_16) = value;
	func_ov031_022115d8(&data_ov031_02291e68, value);
}
