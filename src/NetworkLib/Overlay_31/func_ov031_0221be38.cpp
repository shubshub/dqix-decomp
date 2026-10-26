#include <globaldefs.h>

#if defined(jpn)
#define func_020ca390 func_020cbe5c
#endif

extern "C" void func_020ca390(int, void*, unsigned int);

struct Struct_ov031_0221b9b0 { unsigned char data[0x100]; };

// USA: func_ov031_0221be38
extern "C" ARM void func_ov031_0221be38(Struct_ov031_0221b9b0 *slots, int idx) {
	func_020ca390(0, &slots[idx], 0x100);
	slots[idx].data[0xe7] = 0xff;
}
