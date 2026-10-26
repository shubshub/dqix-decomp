#include <globaldefs.h>

extern int GetProcessorMode();
extern void SleepCurrentContext(unsigned int milliseconds);

extern int data_ov031_0224c9d0;
extern int data_ov031_0224e1c8;
extern int data_ov031_0224e1c4;

// USA: func_ov031_02206f3c
extern "C" ARM int func_ov031_02206f3c(void) {
	int v = data_ov031_0224c9d0;
	if (v == 0) {
		if ((data_ov031_0224e1c8 & 3) == 1) {
			if (GetProcessorMode() != 0x12) {
				SleepCurrentContext(10);
			}
		}
	} else {
		if (data_ov031_0224e1c4 == 0) {
			data_ov031_0224e1c4 = v;
		}
	}
	return data_ov031_0224c9d0;
}
