#include <globaldefs.h>

struct Struct_ov031_022415e0 {
	int unk0;
	int field4;
};

extern "C" void func_ov031_022415c8(void* dst, const void* src, unsigned int length);
extern "C" int func_ov031_022414cc(Struct_ov031_022415e0* obj, int b, void* c, int d, int e);
extern char data_ov031_02291a04[0x400];

// USA: func_ov031_022415e0
extern "C" ARM int func_ov031_022415e0(Struct_ov031_022415e0* a, int b, int* pos, char* buf, int count) {
	int remaining = count;
	while (remaining > 0) {
		if (a->field4 != 0) {
			return -1;
		}
		int var1 = 0x400 - *pos;
		if (remaining <= var1) {
			var1 = remaining;
		}
		func_ov031_022415c8(data_ov031_02291a04 + *pos, buf, var1);
		buf += var1;
		*pos += var1;
		remaining -= var1;
		if (*pos == 0x400) {
			int result = func_ov031_022414cc(a, b, data_ov031_02291a04, 0x400, 0);
			if (result <= 0) {
				return result;
			}
			*pos -= result;
		}
	}
	return count;
}
