#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

extern "C" void func_ov031_0220a66c(int count, char* self);
extern "C" void func_ov031_022035e0(int count, void* obj);

// USA: func_ov031_02203670
extern "C" ARM void func_ov031_02203670(int count) {
	void* mgr = *(void**)((char*)data_02111304.activeContext + 0xa4);
	if (mgr == NULL) return;
	if (*((unsigned char*)mgr + 9) != 0) {
		func_ov031_0220a66c(count, (char*)mgr);
	} else {
		func_ov031_022035e0(count, mgr);
	}
}
