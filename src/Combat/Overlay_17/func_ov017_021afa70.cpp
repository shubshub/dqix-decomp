#include <globaldefs.h>

#include "Resource/GameResources.h"

extern "C" void func_ov017_021a3b40(void *p, int v);
extern "C" void func_0205c96c(void *p, int v);

struct Struct_ov017_021a3b40_3 { char pad[4]; int field4; };

// USA: func_ov017_021afa70
extern "C" ARM void func_ov017_021afa70(Struct_ov017_021a3b40_3 *obj) {
	GameResources *ov = GetGameResources();
	void *p = *(void **)((char *)ov + 0x3000
#if defined(jpn)
        + 0x4f0
#else
        + 0x700
#endif
);
	func_ov017_021a3b40(p, obj->field4);
	func_0205c96c((char *)obj + 0x48, 0);
}
