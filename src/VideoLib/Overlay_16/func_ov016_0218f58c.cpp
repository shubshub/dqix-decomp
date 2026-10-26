#include <globaldefs.h>
#include "NitroSDK/Filesystem/FileAccessor.h"

struct Struct_ov016_0218f58c {
	char pad[0x8];
	int position;
	NitroVM* vm;
	unsigned char active;
};

// USA: func_ov016_0218f58c
extern "C" ARM int func_ov016_0218f58c(Struct_ov016_0218f58c* o, void* buf, int size) {
	if (o->active == 1) {
		NitroVM_AwaitCommandCompletion(o->vm);
		NitroVM_Seek(o->vm, o->position, 0);
		o->active = 0;
	}
	if (NitroVM_ReadSync(o->vm, buf, size) == -1)
		return 0;
	o->position += size;
	return 1;
}
