#include <globaldefs.h>

extern "C" void* VectorizedInvertedMemcpy(void* dst, void* src, int n);
extern void* data_ov031_0224e580;

// USA: func_ov031_0220f770
extern "C" ARM int func_ov031_0220f770(int* b) {
	int result = 1;
	if (*(int*)((char*)b + 8) == 0xcf) {
		void* g = *(void**)((char*)data_ov031_0224e580 + 0x24);
		int base = *(int*)((char*)g + 0x18);
		int len = *(int*)((char*)b + 0x10);
		int limit = *(int*)((char*)g + 0x14);
		int src = *(int*)((char*)g + 0xc);
		if ((unsigned int)limit < (unsigned int)(base + len)) {
			len = limit - base;
		}
		if (src != 0) {
			VectorizedInvertedMemcpy((char*)b + 0x14, (void*)(src + base), len);
		}

		int var6 = base + len;
		*(int*)((char*)(*(void**)((char*)data_ov031_0224e580 + 0x24)) + 0x18) = var6;

		if (*(int*)((char*)b + 0xc) != 0) {
			result = 0;
		} else {
			*(int*)((char*)(*(void**)((char*)data_ov031_0224e580 + 0x24)) + 0x24) = var6;
			*(int*)((char*)(*(void**)((char*)data_ov031_0224e580 + 0x24)) + 0x20) = 1;
		}
	}
	return result;
}
