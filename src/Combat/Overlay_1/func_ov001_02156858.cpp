#include <globaldefs.h>
#include "Resource/GameResources.h"

// USA: func_ov001_02156858
extern "C" ARM int func_ov001_02156858(void*) {
	char* p = (char*)GetGameResources();
#if defined(jpn)
	return *(unsigned char*)(p + 0x40c2);
#else
	return *(unsigned char*)(p + 0x42e2);
#endif
}
