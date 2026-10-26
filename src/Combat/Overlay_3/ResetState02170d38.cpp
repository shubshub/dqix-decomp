#include <globaldefs.h>
#include "Resource/Brightness.h"
#if defined(jpn)
enum { kRegion4494 = 0x41e4 };
#else
enum { kRegion4494 = 0x4494 };
#endif

extern "C" void LinkSession_GetInstance();
extern "C" void LinkSession_End();
extern "C" void func_ov017_0219bd1c(int a, int b, int c, int d);

// USA: func_ov003_02170d38
ARM void ResetState02170d38(char*) {
	LinkSession_GetInstance();
	LinkSession_End();
	*(int*)((char*)GetGameResources() + kRegion4494) = 0;
	GameResources* p = GetGameResources();
	ClearFlags04(p, 2);
	ClearFlags00(p, 4);
	func_ov017_0219bd1c(1, 0, 0, 0);
}
