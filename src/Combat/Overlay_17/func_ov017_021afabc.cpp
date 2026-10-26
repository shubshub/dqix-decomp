#include <globaldefs.h>
#include "Resource/GameResources.h"

struct Struct_ov017_021a4368_2;
extern "C" void func_ov017_021a4368(void *p, Struct_ov017_021a4368_2* event);
extern "C" void func_020439b0(int a, int b);
extern "C" int MessageSystem_GetInstance();

struct Struct_ov017_021a4368_4 { char unknown0[4]; Struct_ov017_021a4368_2* event; };

// USA: func_ov017_021afabc
extern "C" ARM void func_ov017_021afabc(Struct_ov017_021a4368_4 *obj) {
	GameResources *ov = GetGameResources();
	void *p = ov->unknown_ptr_array_3700[0];
	func_ov017_021a4368(p, obj->event);
	func_020439b0(MessageSystem_GetInstance(), 0);
}
