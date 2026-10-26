#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


// USA: func_ov017_021b33d8
extern "C" ARM void func_ov017_021b33d8(void* obj) {
	int var0 = (int)BackgroundLoader::GetInstance();
	int i;
	for (i = 0; i < 0xe; i++) {
		int v = *(int*)((char*)obj + i * 4 + 0x10);
		if (v >= 0) {
			((BackgroundLoader*)(var0))->RemoveTask((int)(v));
		}
	}
	*(short*)((char*)obj + 8) = -1;
	((unsigned char*)obj)[0xa] = 0;
	((unsigned char*)obj)[0xb] = 0;
	int j;
	for (j = 0; j < 0xe; j++) {
		*(int*)((char*)obj + j * 4 + 0x10) = -1;
	}
}
