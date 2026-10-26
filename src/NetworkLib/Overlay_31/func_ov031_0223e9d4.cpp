#include <globaldefs.h>

extern "C" void func_ov031_0223fb60(void*, unsigned int);
extern "C" void func_ov031_0221ae00(void*);
extern "C" int func_ov031_0223fba4(void*, int, int, int);
extern "C" void func_ov031_0223e454(void*, void*, int);

struct Struct_ov031_0223e9d4 { int unknown_0_; int w1; char pad[0x14 - 8]; };

// USA: func_ov031_0223e9d4
extern "C" ARM int func_ov031_0223e9d4(void* p0, void* p1, int p2, int p3) {
	Struct_ov031_0223e9d4 buf;
	unsigned char out[0x10];
	func_ov031_0223fb60(&buf, 0x14);
	func_ov031_0221ae00(&buf);
	unsigned long long v = *(unsigned long long*)&buf;
	if (v == 0) return 0;
	int a = (int)v;
	int b = (int)(v >> 32);
	if (func_ov031_0223fba4(out, a, b, 0xd) < 0) return 0;
	func_ov031_0223e454(p1, out, 0xd);
	func_ov031_0223e454(p0, (void*)0x27ffe0c, 4);
	return 1;
}
