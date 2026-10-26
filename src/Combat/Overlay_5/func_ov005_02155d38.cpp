#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

struct Foo0207df50;
extern "C" void VramState_Rewind(struct Foo0207df50* p);
struct Foo02048004;
extern "C" void SprSprite_Unload(struct Foo02048004* obj);

struct Struct_ov005_021556e4_2 {
	char pad0[4];
	struct Foo0207df50* f1;
	struct Foo02048004* f2;
	char pad2[0x18 - 0xc];
	short field18;
};

// USA: func_ov005_02155d38
extern "C" ARM void func_ov005_02155d38(Struct_ov005_021556e4_2* obj) {
	if (obj->f1) VramState_Rewind(obj->f1);
	if (obj->f2) SprSprite_Unload(obj->f2);
	obj->field18 = -1;
}
