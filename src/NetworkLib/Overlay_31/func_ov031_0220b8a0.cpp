#include <globaldefs.h>
#include "NitroSDK/Memory.h"

// USA: func_ov031_0220b8a0
extern "C" ARM void func_ov031_0220b8a0(unsigned int* ctx) {
	VectorizedMemset(ctx, 0, 0x5c);
	ctx[0] = 0x67452301;
	ctx[1] = 0xefcdab89;
	ctx[2] = 0x98badcfe;
	ctx[3] = 0x10325476;
	ctx[4] = 0xc3d2e1f0;
}
