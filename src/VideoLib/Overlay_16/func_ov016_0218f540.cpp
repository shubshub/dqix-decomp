#include <globaldefs.h>
#include "NitroSDK/Filesystem/FileAccessor.h"

struct Struct_ov016_0218f540 {
	char pad[0x8];
	int position;
	NitroVM* vm;
	unsigned char active;
};

// USA: func_ov016_0218f540
extern "C" ARM int func_ov016_0218f540(Struct_ov016_0218f540* o, int pos) {
	if (o->active == 1) {
		NitroVM_AwaitCommandCompletion(o->vm);
		o->active = 0;
	}
	if (!NitroVM_Seek(o->vm, pos, 0))
		return 0;
	o->position = pos;
	return 1;
}
