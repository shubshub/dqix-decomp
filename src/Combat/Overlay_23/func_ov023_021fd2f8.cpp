#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

struct Struct_ov023_021fd2f8 { char pad[0x1c]; int val; };

// USA: func_ov023_021fd2f8
extern "C" ARM int func_ov023_021fd2f8(struct Struct_ov023_021fd2f8* s) {
	if (func_02094b4c(FontBankLoader_GetInstance()) != 0) return 2;
	return s->val;
}
