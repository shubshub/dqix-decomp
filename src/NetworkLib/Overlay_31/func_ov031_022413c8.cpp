#include <globaldefs.h>

extern "C" int func_ov031_02207434(int id);
void SleepCurrentContext(unsigned int ms);

// USA: func_ov031_022413c8
extern "C" ARM int func_ov031_022413c8(int unused, int id) {
	int state = func_ov031_02207434(id);
	if (state != -0x1a) return state;
	do {
		SleepCurrentContext(0x1f4);
		state = func_ov031_02207434(id);
	} while (state == -0x1a);
	return state;
}
