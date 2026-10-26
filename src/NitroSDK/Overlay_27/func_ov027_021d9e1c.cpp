#include <globaldefs.h>
#include "NitroSDK/Filesystem/NitroVM.h"
#include "NitroSDK/Filesystem/FileAccessor.h"

#pragma optimize_for_size off

// USA: func_ov027_021d9e1c
extern "C" ARM int func_ov027_021d9e1c(NitroVM* vm) {
	char buf[0x60];
	char* p4 = NULL;
	int r5 = 0;
	if (vm != NULL) {
		int a = *(int*)((char*)vm + 0x2c);
		int b = *(int*)((char*)vm + 0x24);
		int off = a - b;
		int n = NitroVM_ReadSync(vm, buf, 0x60);
		if ((unsigned int)n >= 0x60) p4 = buf;
		NitroVM_Seek(vm, off, 0);
	} else {
		p4 = (char*)0x27ffe00;
	}
	if (p4 != NULL) {
		int a = *(int*)(p4 + 0x2c);
		int b = *(int*)(p4 + 0x3c);
		r5 = a + 0x268 + b;
		if ((unsigned int)r5 < 0x10000) r5 = 0x10000;
	}
	return r5;
}
