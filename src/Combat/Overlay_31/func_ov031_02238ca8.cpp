#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"

extern "C" void func_ov031_02239108(unsigned short v);
#if defined(jpn)
extern "C" void func_ov027_021dcd5c(void* obj);
#else
extern "C" void func_ov025_021dcd5c(void* obj);
#endif
extern "C" int func_ov027_021d8b40(int index, int flag);
extern unsigned short* data_ov031_02290d14;

// USA: func_ov031_02238ca8
extern "C" ARM void func_ov031_02238ca8(void) {
	unsigned short index = 1;
	unsigned short var1 = 0;
	do {
		if (data_ov031_02290d14[5] & (1 << index)) {
			if (func_ov027_021d8b40(index, 3) != 0) {
				var1 |= (1 << index);
			} else {
				unsigned short mask = (unsigned short)~(1 << index);
				int var3 = DisableIRQInterrupts();
				data_ov031_02290d14[1] &= mask;
				data_ov031_02290d14[2] &= mask;
				data_ov031_02290d14[3] &= mask;
				data_ov031_02290d14[4] &= mask;
				data_ov031_02290d14[5] &= mask;
				data_ov031_02290d14[6] &= mask;
				SetIRQInterruptState(var3);
#if defined(jpn)
				func_ov027_021dcd5c((void*)index);
#else
				func_ov025_021dcd5c((void*)index);
#endif
			}
		}
		index++;
	} while (index < 0x10);

	if (var1 == 0) {
		func_ov031_02239108(7);
	} else {
		func_ov031_02239108(4);
	}
}
