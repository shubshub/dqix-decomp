#include <globaldefs.h>

extern int* data_ov031_02290d60;
extern "C" int func_ov031_0223bfa0(int);

// USA: func_ov031_0223da38
extern "C" ARM int func_ov031_0223da38(int idx) {
	int v = *(int*)((char*)(data_ov031_02290d60 + idx) + 0x800);
	return func_ov031_0223bfa0(v);
}
