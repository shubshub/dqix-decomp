#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/GameResources.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

struct Struct_02061c04_8 { unsigned char byte0; unsigned char pad[7]; unsigned char buf[8]; unsigned char b10; unsigned char unknown_11_; unsigned short unknown_12_; };

// USA: func_ov017_021aa16c
extern "C" ARM void func_ov017_021aa16c(Struct_02061c04_8* p) {
	GetGameResources();
	func_0204693c((ByteHeader0204693c*)p);
	p->byte0 = 0x3c;
	memset(p->buf, p->byte0 - 0x3d, 8);
	p->b10 = 0;
	p->unknown_11_ = 0;
	p->unknown_12_ = 0;
}
