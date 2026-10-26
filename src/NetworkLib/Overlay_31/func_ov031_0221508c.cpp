#include <globaldefs.h>

extern "C" void func_ov031_022134cc(int v);
extern "C" int func_ov031_0220cf6c(void);

// USA: func_ov031_0221508c
extern "C" ARM int func_ov031_0221508c(char* obj, int state) {
	if (state == 0x11) return state;
	unsigned char i = 0;
	unsigned char count = *(unsigned char*)(obj + 0xd12);
	if (i < count) {
		do {
			if (*(unsigned char*)(obj + i * 4 + 0x444) == 0) break;
			i++;
		} while (i < count);
	}
	if (state == 6) {
		if (count == i) {
			if (i == 0) {
				func_ov031_022134cc(5);
			} else {
				func_ov031_022134cc(6);
			}
			return 0x11;
		}
	} else {
		if (count == 0) return state;
		if (count == i) return state;
		unsigned char v = *(unsigned char*)(obj + i * 4 + 0x446);
		if (v < 0x14) return state;
	}
	*(unsigned char*)(obj + 0xd13) = (unsigned char)i;
	if (func_ov031_0220cf6c() != 1) {
		*(unsigned char*)(obj + 0xd0e) = (unsigned char)state;
		state = 7;
	}
	return state;
}
