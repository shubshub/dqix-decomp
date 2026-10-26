#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" void func_ov027_021da690(void* src, int* dataPtr, void* arg2, unsigned int* local);
extern int data_ov027_021dd8b8[3];

// USA: func_ov027_021da61c
extern "C" ARM void func_ov027_021da61c(void* dst, void* src) {
	unsigned int local = 0x22c0000;
	*(int*)dst = *(int*)((char*)src + 0x24);
	*(int*)((char*)dst + 4) = *(int*)((char*)src + 0x34);
	int* dataPtr = data_ov027_021dd8b8;
	char* entry = (char*)dst + 0xc;
	int i = 0;
	do {
		func_ov027_021da690(src, dataPtr, entry, &local);
		i++;
		entry += 0x10;
		dataPtr++;
	} while (i < 3);
	VectorizedInvertedMemcpy((char*)src + 0x160, (char*)dst + 0x3c, 0x88);
}
