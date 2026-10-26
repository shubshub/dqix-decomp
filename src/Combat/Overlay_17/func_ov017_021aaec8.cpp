#include <globaldefs.h>

struct Struct_0207fd88;
extern "C" void func_0207fd88(struct Struct_0207fd88* obj);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void func_0204359c(void* obj, int count);
extern "C" void func_020439b0(void* a, int b);

// USA: func_ov017_021aaec8
extern "C" ARM void func_ov017_021aaec8(char* p) {
	if (*(int*)(p + 0x14) == 5) {
		void* var0 = *(void**)(p + 0x18);
		if (var0 != NULL) func_0207fd88((struct Struct_0207fd88*)var0);
	}
	void* x = (void*)MessageSystem_GetInstance();
	func_0204359c(x, 8);
	func_020439b0(x, 0);
}
