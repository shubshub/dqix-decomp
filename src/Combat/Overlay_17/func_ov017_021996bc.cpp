#include <globaldefs.h>

int FreeVRAMStagingMemory(void const*);

struct Struct_ov017_02199684 { unsigned char pad[0x14]; int val; unsigned char pad2[0x20 - 0x18]; };

// USA: func_ov017_021996bc
extern "C" ARM void func_ov017_021996bc(Struct_ov017_02199684* arr, int count) {
	for (int i = 0; i < count; i++) {
		int old = arr[i].val;
		arr[i].val = 0;
		if (old != 0) {
			FreeVRAMStagingMemory((void const*)old);
		}
	}
}
