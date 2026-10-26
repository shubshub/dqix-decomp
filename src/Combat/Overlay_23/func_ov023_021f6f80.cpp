#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

struct Foo02048004;
extern "C" void SprSprite_Unload(Foo02048004* obj);

// USA: func_ov023_021f6f80
extern "C" ARM void func_ov023_021f6f80(void* p) {
	SprSprite_Unload((Foo02048004*)((char*)p + 0x20));
}
