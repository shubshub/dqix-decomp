#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

extern "C" int func_ov031_0220a800(char* self);

// USA: func_ov031_02203b1c
extern "C" ARM int func_ov031_02203b1c(void) {
	char* mgr = (char*)data_02111304.activeContext->unknown_A4;
	if (mgr == NULL) {
		goto ret_zero;
	}
	if (*(unsigned char*)(mgr + 9) != 0) {
		return func_ov031_0220a800(mgr);
	}
	{
		int var1 = *(int*)(mgr + 0x44);
		if (var1 != 0) {
			goto ret_f44;
		}
		if (*(unsigned char*)(mgr + 8) == 4) {
			goto ret_f44;
		}
		{
			unsigned char t = (unsigned char)(*(unsigned char*)(mgr + 8) + 0xf6);
			if (t > 1) {
				goto ret_neg1;
			}
		}
	ret_f44:
		return var1;
	}
ret_neg1:
	return -1;
ret_zero:
	return 0;
}
