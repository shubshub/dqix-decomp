#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

#if defined(jpn)
enum { Enum_ov003_0215dc20_1004 = 0x404 };
enum { Enum_ov003_0215dc20_1005 = 0x405 };
enum { Enum_ov003_0215dc20_1008 = 0x408 };
#else
enum { Enum_ov003_0215dc20_1004 = 0x3ec };
enum { Enum_ov003_0215dc20_1005 = 0x3ed };
enum { Enum_ov003_0215dc20_1008 = 0x3f0 };
#endif

// USA: func_ov003_0215dc20
extern "C" ARM void func_ov003_0215dc20(void* obj) {
	unsigned char* o = (unsigned char*)obj;
	unsigned char state;
	FontBankLoader* g;
	if (o[Enum_ov003_0215dc20_1004] == 0) return;
	state = o[Enum_ov003_0215dc20_1005];
	if (state == 0) {
		g = FontBankLoader_GetInstance();
		func_02094b3c(g, 0xa);
		if (o[Enum_ov003_0215dc20_1008] != 0) {
			func_02094b30(g, 0x1f5, 0);
		} else {
			func_02094b30(g, 0x200, 1);
		}
		o[Enum_ov003_0215dc20_1005] = o[Enum_ov003_0215dc20_1005] + 1;
		return;
	}
	if (state != 1) return;
	if (func_02094b4c(FontBankLoader_GetInstance()) != 0) {
		o[Enum_ov003_0215dc20_1004] = 0;
		o[Enum_ov003_0215dc20_1005] = 0;
	}
}
