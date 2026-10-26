#include <globaldefs.h>

extern "C" void* func_ov001_02159f14(void*);

// USA: func_ov001_0215a3d8
extern "C" ARM void* func_ov001_0215a3d8(void* ctx, int val) {
	int* node = (int*)func_ov001_02159f14(ctx);
	if (node) {
		node[0] = 4;
		node[4] = val;
	}
	return node;
}
