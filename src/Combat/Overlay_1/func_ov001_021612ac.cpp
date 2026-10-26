#include <globaldefs.h>

struct Struct_ov001_021612ac { unsigned char pad[0x56b]; unsigned char unknown_56b_0_ : 4; };

// USA: func_ov001_021612ac
extern "C" ARM int func_ov001_021612ac(void* p) {
#if defined(jpn)
    enum { regionalFieldOffset = 0x144 };
#else
    enum { regionalFieldOffset = 0x150 };
#endif
	struct Struct_ov001_021612ac* q = *(struct Struct_ov001_021612ac**)((char*)p + regionalFieldOffset);
	if (!q) return 0;
	return q->unknown_56b_0_;
}
