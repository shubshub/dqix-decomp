#include <globaldefs.h>

extern "C" int func_ov027_021d9de8(int a);
extern void* data_ov027_021e33ec;

// USA: func_ov027_021d8aec
extern "C" ARM int func_ov027_021d8aec(int id) {
	if (data_ov027_021e33ec != NULL && func_ov027_021d9de8(id) != 0) {
		int v = *(int*)((char*)data_ov027_021e33ec + (id - 1) * 4 + 0x1000 + 0x4e8);
		if (v == 7) return 1;
	}
	return 0;
}
