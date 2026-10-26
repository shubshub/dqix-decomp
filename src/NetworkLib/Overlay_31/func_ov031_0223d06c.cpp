#include <globaldefs.h>
#include "NitroSDK/TouchScreen.h"

extern "C" void func_ov031_0223cf70(void** slot);
extern void* data_ov031_02290d44;

// USA: func_ov031_0223d06c
extern "C" ARM void func_ov031_0223d06c(void) {
	int a = 4;
	int b = a;
	do {
		DisableTouchScreen();
		WaitForTouchScreenOperations(a);
	} while (GetTouchScreenErrors(b) != 0);
	func_ov031_0223cf70(&data_ov031_02290d44);
}
