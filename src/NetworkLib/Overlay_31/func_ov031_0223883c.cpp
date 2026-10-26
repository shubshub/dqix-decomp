#include <globaldefs.h>
#include "NitroSDK/Filesystem/NitroVM.h"
#include "NitroSDK/Filesystem/FileAccessor.h"
#include "NitroSDK/Filesystem/LowNitroHandle.h"

struct Struct_ov031_0223883c { char* path; };

extern void* data_ov031_02290d14;
extern "C" int func_ov027_021d9e1c(NitroVM* vm);
extern "C" int func_ov027_021d9e9c(NitroVM* vm, void* val, unsigned int size);
extern "C" int func_ov027_021da38c(Struct_ov031_0223883c* req, void* val);

// USA: func_ov031_0223883c
extern "C" ARM int func_ov031_0223883c(Struct_ov031_0223883c* req) {
	NitroVM vm;
	NitroVM* var1;
	int result = 0;

	if (req->path == NULL) {
		var1 = NULL;
	} else {
		NitroVM_Initialize(&vm);
		if (!NitroVM_PrepareReadFileByPath(&vm, req->path)) {
			return result;
		}
		var1 = &vm;
	}

	if (func_ov027_021d9e1c(var1) != 0) {
		*(void**)((char*)data_ov031_02290d14 + 0x1b000 + 0x144) = (char*)data_ov031_02290d14 + 0x2c;
		void* val = *(void**)((char*)data_ov031_02290d14 + 0x1b000 + 0x144);
		if (val != NULL) {
			if (func_ov027_021d9e9c(var1, val, 0x10000) != 0) {
				if (func_ov027_021da38c(req, *(void**)((char*)data_ov031_02290d14 + 0x1b000 + 0x144)) != 0) {
					result = 1;
				}
			}
		}
	}

	if (var1 == &vm) {
		NitroVM_FinishRead(&vm);
	}
	return result;
}
