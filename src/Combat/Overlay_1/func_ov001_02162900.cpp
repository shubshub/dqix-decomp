#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" int LoadToMainBG3ScreenData(int arg0, int arg1, unsigned int arg2);
extern "C" int LoadToSubBG3ScreenData(int arg0, int arg1, unsigned int arg2);
extern "C" int LoadToMainBG3CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" int LoadToSubBG3CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" int func_ov017_021d60f4(void* a);

// USA: func_ov001_02162900
extern "C" ARM int func_ov001_02162900(void* param) {
	unsigned char buf1[0x20];
	unsigned char buf2[0x600];
	int mode = func_ov017_021d60f4(param);
	VectorizedMemset(buf1, 0, sizeof(buf1));
	VectorizedMemset(buf2, 0, sizeof(buf2));
	if (mode == 0) {
		LoadToMainBG3CharacterData((int)buf1, 0, sizeof(buf1));
		LoadToMainBG3ScreenData((int)buf2, 0, sizeof(buf2));
	} else {
		LoadToSubBG3CharacterData((int)buf1, 0, sizeof(buf1));
		LoadToSubBG3ScreenData((int)buf2, 0, sizeof(buf2));
	}
	return 1;
}
