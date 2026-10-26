#include <globaldefs.h>

struct Struct_ov031_02239ee0 { unsigned char pad[0x58]; int seed; };
struct Struct_ov031_02290d18_20 { unsigned char pad[4]; Struct_ov031_02239ee0* inner; };
extern Struct_ov031_02290d18_20 data_ov031_02290d18;

// USA: func_ov031_02239ee0
extern "C" ARM short func_ov031_02239ee0(unsigned short mask) {
	short var0 = 0;
	unsigned short count = 0;
	short idx = 0;
	do {
		if (mask & (1 << idx)) {
			var0 = idx + 1;
			count = count + 1;
		}
		idx++;
	} while (idx < 16);
	if (count <= 1) {
		return var0;
	}

	data_ov031_02290d18.inner->seed = data_ov031_02290d18.inner->seed * 0x10dcd + 0x3039;
	unsigned char var3 = (unsigned char)data_ov031_02290d18.inner->seed;
	unsigned short roll = (unsigned short)((count * var3) >> 8);

	short i = 0;
	do {
		if (mask & 1) {
			if (roll == 0) {
				return (short)(i + 1);
			}
			roll = roll - 1;
		}
		mask = mask >> 1;
		i++;
	} while (i < 16);
	return 0;
}
