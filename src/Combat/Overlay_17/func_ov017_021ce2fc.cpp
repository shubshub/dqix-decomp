#include <globaldefs.h>
#include "Resource/GameResources.h"

// USA: func_ov017_021ce2fc
extern "C" ARM void func_ov017_021ce2fc(int unused0, unsigned char* src, int arg2, GameResources* ov) {
	unsigned char* dst = (unsigned char*)ov->fieldTasks_[13];
	signed char* s = (signed char*)(src + 4);
	for (int i = 0; i < 4; i++) {
		*(signed char*)(dst + i + 0x1b) = s[i];
	}
}
