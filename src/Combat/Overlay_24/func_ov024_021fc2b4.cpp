#include <globaldefs.h>

extern "C" int func_ov024_021fe698(void* self, int idx);
extern "C" void func_ov024_021fdf04(void* self, int idx);
extern "C" void func_ov024_021fd954(void* self, int idx);

// USA: func_ov024_021fc2b4
extern "C" ARM void func_ov024_021fc2b4(void* self) {
	void* p = *(void**)((char*)self + 0x64c);
	unsigned int raw = *(unsigned int*)((char*)p + 0x8);
	unsigned int field = (raw << 0x16) >> 0x1e;
	if (field == 1) {
		if (!func_ov024_021fe698(self, 0x10)) {
			return;
		}
		func_ov024_021fdf04(self, 0x16);
		return;
	}
	if (*(unsigned char*)((char*)self + 0x6b) == 0) {
		return;
	}
	if (!func_ov024_021fe698(self, 0xa)) {
		return;
	}
	func_ov024_021fd954(self, 0x16);
}
