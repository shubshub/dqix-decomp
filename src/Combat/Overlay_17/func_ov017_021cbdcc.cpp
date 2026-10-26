#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" void* func_ov017_021b8470(void* obj);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cbdcc {
	unsigned short field4;
	unsigned char bytes[8];
};

struct Struct_ov017_021cbdcc_2 {
	unsigned char tag;
	unsigned char pad0[3];
	Struct_ov017_021cbdcc unknown_4_;
	unsigned char pad1[6];
};

// USA: func_ov017_021cbdcc
extern "C" ARM void func_ov017_021cbdcc(void) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
	void* evtBuf = LinkMessageQueue_GetInstance();
	unsigned char* base = (unsigned char*)GetGameResources() + 0x3000;
	void* h = *(void**)(base + regionalOffset0);
	void* r = func_ov017_021b8470(h);
	if (!r) return;

	Struct_ov017_021cbdcc_2 buf;
	buf.tag = 0x7e;
	void* ptr2 = *(void**)((char*)r + 0x8000 + 0xe18);
	unsigned short val = *(unsigned short*)((char*)ptr2 + 8);

	Struct_ov017_021cbdcc* var7 = &buf.unknown_4_;
	unsigned char* p = var7->bytes;
	int i = 0;
	var7->field4 = val;
	for (; i < 8; p++) {
		*p = *(unsigned int*)((char*)r + 0x8000 + 0xde0 + i * 4);
		i++;
	}
	func_0205e330(evtBuf, &buf, 0);
}
