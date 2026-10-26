#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" void func_ov017_021a3ddc(void* p, void* obj);

struct Struct_ov017_021a3ddc_3 { char pad[4]; void* field4; };

// USA: func_ov017_021afa9c
extern "C" ARM void func_ov017_021afa9c(Struct_ov017_021a3ddc_3* obj) {
	void* p = *(void**)((char*)GetGameResources()
#if defined(jpn)
        + 0x34f0
#else
        + 0x3700
#endif
);
	func_ov017_021a3ddc(p, obj->field4);
}
