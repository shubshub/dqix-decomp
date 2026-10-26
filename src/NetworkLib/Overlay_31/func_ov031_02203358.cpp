#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

extern "C" int func_ov031_0220a540(void* self);
extern "C" int func_ov031_022032a4(void* self);

// USA: func_ov031_02203358
extern "C" ARM int func_ov031_02203358(void) {
	void* mgr = *(void**)((char*)data_02111304.activeContext + 0xa4);
	if (mgr) {
		if (*((unsigned char*)mgr + 9) != 0) {
			return func_ov031_0220a540(mgr);
		}
		return func_ov031_022032a4(mgr);
	}
	return 1;
}
