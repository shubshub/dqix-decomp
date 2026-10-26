#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" int func_ov017_021d60f4(int a);
extern "C" void func_ov017_0219b578(int a, int b, int c);

// USA: func_ov001_02160a48
extern "C" ARM int func_ov001_02160a48(int a) {
	int b = func_ov017_021d60f4(a);
	int c = func_ov017_021d60f4(a + 0x8);
	func_ov017_0219b578((int)GetGameResources(), b, c);
	return 1;
}
