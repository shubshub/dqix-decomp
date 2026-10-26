#include <globaldefs.h>

extern int data_ov001_02165958[16];

// USA: func_ov001_0215a818
extern "C" ARM int* func_ov001_0215a818(int* arg0) {
	int i;
	for (i = 0; i < 0x10; i++) {
		if (data_ov001_02165958[i] == 0) {
			*arg0 = i;
			return &data_ov001_02165958[i];
		}
	}
	return NULL;
}
