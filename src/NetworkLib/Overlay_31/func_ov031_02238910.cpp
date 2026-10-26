#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"

extern "C" int func_ov027_021d8b40(int index, int flag);
#if defined(jpn)
extern "C" void func_ov027_021dcd5c(int index);
#else
extern "C" void func_ov025_021dcd5c(void* obj);
#endif

extern unsigned short* data_ov031_02290d14;

// USA: func_ov031_02238910
extern "C" ARM void func_ov031_02238910(int index) {
	if (func_ov027_021d8b40(index, 1) != 0) return;
	unsigned short mask = (unsigned short)~(1 << index);
	int var1 = DisableIRQInterrupts();
	data_ov031_02290d14[1] &= mask;
	data_ov031_02290d14[2] &= mask;
	data_ov031_02290d14[3] &= mask;
	data_ov031_02290d14[4] &= mask;
	data_ov031_02290d14[5] &= mask;
	data_ov031_02290d14[6] &= mask;
	SetIRQInterruptState(var1);
#if defined(jpn)
	func_ov027_021dcd5c(index);
#else
	func_ov025_021dcd5c((void*)index);
#endif

}
