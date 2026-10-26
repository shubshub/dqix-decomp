#include <globaldefs.h>

#if defined(jpn)
#define func_ov017_021a7c28 func_ov017_021a85b8
#endif

// USA: func_ov017_021a7c28
extern "C" ARM void func_ov017_021a7c28(unsigned char* dst, unsigned char* src) {
	dst[0xc] = src[0];
	dst[0xd] = src[1];
	*(unsigned short*)(dst+0xe) = *(unsigned short*)(src+2);
	*(unsigned short*)(dst+0x10) = *(unsigned short*)(src+4);
	*(int*)(dst+0x14) = *(int*)(src+8);
	dst[0x18] = src[0xc];
	dst[0x19] = src[0xd];
	dst[0x1a] = src[0xe];
	dst[0x1b] = src[0xf];
	*(short*)(dst+0x1c) = *(short*)(src+0x10);
	dst[0x1e] = src[0x12];
	*(int*)(dst+0x20) = *(int*)(src+0x14);
}
