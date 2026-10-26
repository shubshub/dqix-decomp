#include <globaldefs.h>

struct Struct_ov031_022039b0 { unsigned char pad0[0x8]; unsigned char type; unsigned char unknown_9_; };
struct Struct_02111304_5 { unsigned char pad0[0x4]; void* ctx; };

extern Struct_02111304_5 data_02111304;
extern unsigned char data_ov031_0224c980;

extern "C" int func_ov031_02201414(void* obj, int id, Struct_ov031_022039b0* node);
extern "C" void func_ov031_02201364(void* obj, unsigned int length, Struct_ov031_022039b0* node);
extern "C" int func_ov031_0220a87c(void* a0, int a1, void* a2, int a3, Struct_ov031_022039b0* n);
extern "C" int func_ov031_022037a8(void* a0, int a1, void* a2, int a3, Struct_ov031_022039b0* n);

// USA: func_ov031_022039b0
extern "C" ARM int func_ov031_022039b0(void* a0, int a1, void* a2, int a3) {
	Struct_ov031_022039b0* n = *(Struct_ov031_022039b0**)((char*)data_02111304.ctx + 0xa4);
	if (n) {
		int result;
		if (n->type == 0xa) {
			if (a1 != 0) func_ov031_02201414(a0, a1, n);
			if (a3 != 0) func_ov031_02201414(a2, a3, n);
			result = a1 + a3;
		} else if (n->type == 0xb) {
			if (a1 != 0) func_ov031_02201364(a0, a1, n);
			if (a3 != 0) func_ov031_02201364(a2, a3, n);
			result = a1 + a3;
		} else {
			if (n->unknown_9_ != 0) {
				result = func_ov031_0220a87c(a0, a1, a2, a3, n);
			} else {
				result = func_ov031_022037a8(a0, a1, a2, a3, n);
			}
		}
		if (data_ov031_0224c980 == 0) {
			return result;
		}
	}
	return 0;
}
