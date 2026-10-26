#include <globaldefs.h>
#include "NitroSDK/Filesystem/FileAccessor.h"

struct Struct_ov016_0218f678 {
	char pad[0xc];
	NitroVM* vm;
	unsigned char active;
};

// USA: func_ov016_0218f678
extern "C" ARM void func_ov016_0218f678(Struct_ov016_0218f678* o) {
	if (o->active == 1) {
		NitroVM_AwaitCommandCompletion(o->vm);
	}
	o->active = 0;
}
