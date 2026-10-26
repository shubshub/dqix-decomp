#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(struct ByteHeader0204693c* p);

struct Struct_02046c98;
extern "C" void func_02046c98(struct Struct_02046c98* h);

extern "C" void func_02046e70(void* obj, int a, int b);

// USA: func_ov017_021b621c
extern "C" ARM void func_ov017_021b621c(unsigned char* self, int a, int b) {
	(int)GetGameResources();
	func_0204693c((struct ByteHeader0204693c*)self);
	self[0] = 0x16;
	func_02046e70(self + 0xc, a, b);
	func_02046c98((struct Struct_02046c98*)(self + 0xc));
	self[0xfc] = 0;
	*(short*)(self + 0xfe) = -1;
	if (a == 0) self[0xfd] = 0xf;
	else self[0xfd] = 0;
	self[8] = 1;
	*(short*)(self + 0x100) = -1;
}
