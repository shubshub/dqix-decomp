#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#if defined(jpn)
enum { Enum_ov003_021749f0_4161 = 0xfbd };
enum { Enum_ov003_021749f0_4166 = 0xfc2 };
#else
enum { Enum_ov003_021749f0_4161 = 0x1041 };
enum { Enum_ov003_021749f0_4166 = 0x1046 };
#endif

// USA: func_ov003_021749f0
extern "C" ARM void func_ov003_021749f0(char* self) {
	if (!(*(unsigned short*)(self + Enum_ov003_021749f0_4166) & 0x40)) {
		return;
	}
	unsigned char state = *(unsigned char*)(self + Enum_ov003_021749f0_4161);
	if (state == 0) {
		FontBankLoader* g = FontBankLoader_GetInstance();
		func_02094b34(g, 0x1fb, 0x66, 0, 0);
		*(unsigned char*)(self + Enum_ov003_021749f0_4161) = *(unsigned char*)(self + Enum_ov003_021749f0_4161) + 1;
	} else if (state == 1) {
		if (func_02094b4c(FontBankLoader_GetInstance()) != 0) {
			*(unsigned short*)(self + Enum_ov003_021749f0_4166) &= ~0x40;
			*(unsigned char*)(self + Enum_ov003_021749f0_4161) = 0;
		}
	}
}
