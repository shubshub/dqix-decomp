#include <globaldefs.h>

struct Struct_0205dee8;
extern "C" void func_0205dee8(struct Struct_0205dee8* obj, int val);

struct Entry_0205d6a0;
extern "C" void Window_ClosePane(struct Entry_0205d6a0* a, int flag);

// USA: func_ov003_0216ff90
extern "C" ARM void func_ov003_0216ff90(char* obj) {
	if (*(void**)(obj + 0x3c) == 0) return;
	func_0205dee8((struct Struct_0205dee8*)*(void**)(obj + 0x3c), 0);
	Window_ClosePane((struct Entry_0205d6a0*)*(void**)(obj + 0x3c), 0);
}
