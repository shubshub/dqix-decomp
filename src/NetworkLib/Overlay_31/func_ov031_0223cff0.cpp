#include <globaldefs.h>
#include "NitroSDK/TouchScreen.h"


extern "C" void* func_ov031_0223cf4c(unsigned int len, int align);
extern "C" void HaltSystem(void);
extern "C" void func_ov031_0223d0a4();

struct Struct_ov031_02290d40 { unsigned char pad0[4]; void* inner; };
extern struct Struct_ov031_02290d40 data_ov031_02290d40;

// USA: func_ov031_0223cff0
extern "C" ARM void func_ov031_0223cff0(void) {
	data_ov031_02290d40.inner = func_ov031_0223cf4c(0x3a, 4);

	TouchScreenCalibration var0;
	if (GetTouchScreenCalibration(&var0) == 0) {
		HaltSystem();
	}
	SaveTouchScreenCalibration(&var0);

	EnableTouchScreen(0, 4, (TouchScreenSample*)data_ov031_02290d40.inner, 5);
	WaitForTouchScreenOperations(2);
	if (GetTouchScreenErrors(2) != 0) {
		HaltSystem();
	}
	func_ov031_0223d0a4();
}
