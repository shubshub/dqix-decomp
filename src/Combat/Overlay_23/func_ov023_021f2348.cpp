#include <globaldefs.h>

struct Struct_ov023_021f2348 {
	char pad[0x438];
	unsigned short flags;
};

// USA: func_ov023_021f2348
extern "C" ARM void func_ov023_021f2348(void* obj, int flag) {
	Struct_ov023_021f2348* o = (Struct_ov023_021f2348*)obj;
	if (flag != 0) o->flags |= 0x400;
	else o->flags &= ~0x400;
}
