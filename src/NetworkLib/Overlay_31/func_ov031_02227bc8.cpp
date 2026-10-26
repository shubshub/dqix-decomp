#include <globaldefs.h>


extern int* data_ov031_02290c48;

extern "C" int func_ov031_02222adc(void* buf);
extern "C" void HaltSystem(void);

// USA: func_ov031_02227bc8
extern "C" ARM int func_ov031_02227bc8(void) {
	char buf[0xe8];
	int val = *data_ov031_02290c48;
	switch (val) {
		case 0:
		case 1:
		case 3:
		case 5:
			return 0;
		case 2:
			return 1;
		case 4:
			return 2;
		case 6: {
			int r = func_ov031_02222adc(buf);
			if (r != 1) {
				HaltSystem();
			}
			int a = *(int*)(buf + 0x20);
			if (a >= 0 && a <= 3) {
				int b = *(int*)(buf + 0x24);
				if (b == 1) {
					return 3;
				}
			}
			return 5;
		}
		case 7:
			return 4;
	}
}
