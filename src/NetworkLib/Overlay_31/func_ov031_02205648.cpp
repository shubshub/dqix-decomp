#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

struct Struct_ov031_022054fc {
	unsigned short field0;
	unsigned char field2;
	unsigned char unknown_3_;
};

struct Struct_ov031_0224e204 {
	int a; int b; int c; int d;
	int e; int f; int g; int h;
};

struct Struct_01ffd34c;

extern "C" int func_ov031_022054fc(Struct_ov031_022054fc* p);
extern "C" void func_020c7de4(Struct_ov031_0224e204* s, int e, int f);
struct Mutex;
void ZeroInitializeMutex(Mutex*);
void PopulateContext(ProcessorContext*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
void MarkContextReadyAndSwitch(ProcessorContext* context);
extern "C" void func_ov031_022052b4(void);

// USA: func_ov031_02205648
extern "C" ARM int func_ov031_02205648(int a, void* ctx, Struct_ov031_022054fc* p) {
	int var0 = func_ov031_022054fc(p);
	func_020c7de4((Struct_ov031_0224e204*)ctx, a, p->unknown_3_);
	ZeroInitializeMutex((Mutex*)((char*)ctx + 0xe0));
	PopulateContext((ProcessorContext*)((char*)ctx + 0x20), (unsigned int)func_ov031_022052b4, (unsigned int)ctx, a + var0, p->field0, p->field2);
	MarkContextReadyAndSwitch((ProcessorContext*)((char*)ctx + 0x20));
	return a + var0;
}
