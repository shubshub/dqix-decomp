#include <globaldefs.h>

extern void* data_ov031_0224e580;

// USA: func_ov031_0220ff78
extern "C" ARM int func_ov031_0220ff78(int* obj) {
	int type = *(int*)((char*)obj + 8);
	switch (type) {
	case 0xc9: {
		int fieldC = *(int*)((char*)obj + 0xc);
		*(int*)((char*)*(void**)((char*)data_ov031_0224e580 + 0x24) + 0x24) = fieldC;
		*(int*)((char*)*(void**)((char*)data_ov031_0224e580 + 0x24) + 0x20) = 1;
		break;
	}
	case 0xca: {
		unsigned int v = (unsigned int)(*(int*)((char*)obj + 0xc) - 2);
		if (v <= 1) {
			*(int*)((char*)*(void**)((char*)data_ov031_0224e580 + 0x24) + 0x24) = 0;
			*(int*)((char*)*(void**)((char*)data_ov031_0224e580 + 0x24) + 0x20) = 1;
		}
		break;
	}
	}
	return 1;
}
