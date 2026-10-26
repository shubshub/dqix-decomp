#include <globaldefs.h>

extern int data_ov031_0224e5b4[];

// USA: func_ov031_02212248
extern "C" ARM int func_ov031_02212248(void) {
	int *p = (int*)data_ov031_0224e5b4[1];
	if (p != NULL) {
		unsigned short v = *(unsigned short*)((char*)p + 4);
		if (v == 6) return 1;
	}
	return 0;
}
