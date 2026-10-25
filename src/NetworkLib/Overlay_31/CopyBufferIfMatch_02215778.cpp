#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" void func_ov031_022157f8(int a, void *buf);
extern "C" int memcmp(void *a, void *b, int n);
extern char data_ov031_02249b3c;

// USA: func_ov031_02215778
ARM void CopyBufferIfMatch_02215778(int a, void *dst) {
	unsigned int buf[6];
	func_ov031_022157f8(a, buf);
	if (memcmp(buf, &data_ov031_02249b3c, 8) == 0) {
		VectorizedInvertedMemcpy(&buf[2], dst, 0xa);
	}
}
