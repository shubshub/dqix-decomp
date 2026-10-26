#include <globaldefs.h>
#include "NitroSDK/Cache.h"

extern "C" int LoadToMainBG0CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" int LoadToSubBG0CharacterData(int arg0, int arg1, unsigned int arg2);

extern char* data_ov031_02290d38;

// USA: func_ov031_0223c6d8
extern "C" ARM void func_ov031_0223c6d8(void* unused, unsigned char* flag) {
	if (*flag == 0) return;
	char* base = data_ov031_02290d38;
	if (flag == (unsigned char*)(base + 0x67c)) {
		CleanInvalidateCacheRange(*(void**)(data_ov031_02290d38 + 0x638), 0x6000);
		LoadToMainBG0CharacterData((int)*(void**)(data_ov031_02290d38 + 0x638), 0, 0x6000);
	} else {
		CleanInvalidateCacheRange(*(void**)(data_ov031_02290d38 + 0x668), 0x3000);
		LoadToSubBG0CharacterData((int)*(void**)(data_ov031_02290d38 + 0x668), 0x3000, 0x3000);
	}
	*flag = 0;
}
