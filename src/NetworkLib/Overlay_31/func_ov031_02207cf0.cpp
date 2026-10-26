#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

struct Struct_ov031_022496fc {
	int field0;
	int field4;
};

extern Struct_ov031_022496fc data_ov031_022496fc;

// USA: func_ov031_02207cf0
extern "C" ARM unsigned int func_ov031_02207cf0() {
	if ((unsigned int)data_ov031_022496fc.field4 >= 0x20) {
		return -1;
	}
	ProcessorContext* ctx = data_02111304.activeContext;
	unsigned int old = GetContextPriority(ctx);
	ChangeContextPriority(ctx, data_ov031_022496fc.field4);
	return old;
}
