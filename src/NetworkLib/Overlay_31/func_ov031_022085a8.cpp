#include <globaldefs.h>

extern "C" void func_ov031_0220afe0(void* ctx);
extern "C" void func_ov031_0220b028(void* ctx, const void* data, unsigned int len);
extern "C" void func_ov031_0220b0e0(void* ctx, void* out);
extern "C" void func_ov031_0220b8a0(unsigned int* ctx);
extern "C" void func_ov031_0220b8f4(void* ctx, const void* data, unsigned int len);
extern "C" void func_ov031_0220b9ac(void* ctx, void* out);
extern "C" void* func_ov031_02207d88(void* obj, const char* key);
extern "C" int func_ov031_02208400(void* obj, void* entry);

// USA: func_ov031_022085a8
extern "C" ARM int func_ov031_022085a8(void* obj) {
	unsigned char var0 = *(unsigned char*)((char*)obj + 0x5af);
	unsigned int marker = *(unsigned int*)((char*)obj + 0x45c);
	int base = var0 ? 0 : 0x8000;
	if (marker == 0xffffffff) {
		return base | 4;
	}
	int mode = *(int*)((char*)obj + 0x458);
	switch (mode) {
	case 3: {
		func_ov031_0220afe0((char*)obj + 0x3fc);
		unsigned int start = *(unsigned int*)((char*)obj + 0x460);
		unsigned int end = *(unsigned int*)((char*)obj + 0x464);
		func_ov031_0220b028((char*)obj + 0x3fc, (const void*)start, end - start);
		func_ov031_0220b0e0((char*)obj + 0x3fc, (char*)obj + 0x468);
		*(unsigned int*)((char*)obj + 0x47c) = 0x10;
		break;
	}
	case 4: {
		func_ov031_0220b8a0((unsigned int*)((char*)obj + 0x348));
		unsigned int start = *(unsigned int*)((char*)obj + 0x460);
		unsigned int end = *(unsigned int*)((char*)obj + 0x464);
		func_ov031_0220b8f4((char*)obj + 0x348, (const void*)start, end - start);
		func_ov031_0220b9ac((char*)obj + 0x348, (char*)obj + 0x468);
		*(unsigned int*)((char*)obj + 0x47c) = 0x14;
		break;
	}
	default:
		return base | 3;
	}
	void* entry = func_ov031_02207d88(obj, (const char*)((char*)obj + 0x5b0));
	if (entry == 0) {
		return base | 1;
	}
	return base | func_ov031_02208400(obj, entry);
}
