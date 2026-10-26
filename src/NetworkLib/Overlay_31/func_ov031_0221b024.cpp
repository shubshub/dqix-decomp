#include <globaldefs.h>

extern "C" int func_ov031_0221b780(int a0, int a1, int a2); // WaitAndRegisterHandler2_0221b780
extern "C" int func_ov031_0221b7fc(int a, int b, int c, int d);
extern "C" int func_ov031_0221b848(void);

struct Struct_ov031_0224e6a0_2 {
	unsigned char pad[8];
	int field8;
};
extern Struct_ov031_0224e6a0_2 data_ov031_0224e6a0;

// USA: func_ov031_0221b024
extern "C" ARM int func_ov031_0221b024(int obj, int* arr, int extra) {
	int var0 = obj;
	int i = 0;
	int var2 = data_ov031_0224e6a0.field8;

	do {
		if (arr[i] != 0) {
			do {
				func_ov031_0221b780(var2, 0x100, var0);
			} while (func_ov031_0221b7fc(var0, var2, 0x100, extra) == 0);
		}
		i++;
		var0 += 0x100;
		var2 += 0x100;
	} while (i < 4);

	return func_ov031_0221b848() != 0;
}
