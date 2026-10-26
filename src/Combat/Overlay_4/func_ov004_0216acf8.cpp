#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" void func_020dc2d0(int mode);
extern "C" void func_02027bbc(unsigned char* base, int mask);

// USA: func_ov004_0216acf8
extern "C" ARM int func_ov004_0216acf8(void) {
	func_020dc2d0(0);
	unsigned char* fieldObj = (unsigned char*)GetGameResources()->unknown_ptr_36d0;
	func_02027bbc(fieldObj, 1);
	return 0;
}
