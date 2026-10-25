#include <globaldefs.h>
#include "Resource/GameResources.h"

struct EventHeader021a4368;
extern "C" void func_ov017_021a4368(void *p, EventHeader021a4368* event);
extern "C" void func_020439b0(int a, int b);
int MessageSystem_GetInstance();

struct ObjWithField4_021afabc { char unknown0[4]; EventHeader021a4368* event; };

// USA: func_ov017_021afabc
ARM void CallField700ThenNotify_021afabc(ObjWithField4_021afabc *obj) {
	GameResources *ov = GetGameResources();
	void *p = ov->unknown_ptr_array_3700[0];
	func_ov017_021a4368(p, obj->event);
	func_020439b0(MessageSystem_GetInstance(), 0);
}
