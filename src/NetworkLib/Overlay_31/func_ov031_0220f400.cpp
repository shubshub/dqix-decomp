#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"
#include "NitroSDK/Memory.h"

struct Struct_ov031_0224e204 {
	int a; int b; int c; int d;
	int e; int f; int g; int h;
};

extern "C" void func_020c7de4(Struct_ov031_0224e204* s, int e, int f);
extern "C" void func_ov031_0220f5b4(void);

extern void* data_ov031_0224e580;

// USA: func_ov031_0220f400
extern "C" ARM void func_ov031_0220f400(void* ctx) {
	data_ov031_0224e580 = ctx;
	VectorizedMemset(ctx, 0, 0x8f4);
	char* p = (char*)data_ov031_0224e580;
	func_020c7de4((Struct_ov031_0224e204*)p, (int)(p + 0x20), 1);
	char* p2 = (char*)data_ov031_0224e580;
	*(int*)(p2 + 0x24) = 0;
	char* q = (char*)data_ov031_0224e580;
	unsigned int priority = GetContextPriority(data_02111304.activeContext);
	PopulateContext((ProcessorContext*)(q + 0x34), (unsigned int)func_ov031_0220f5b4, 0, (unsigned int)(q + 0x8f4), 0x800, priority);
	p = (char*)data_ov031_0224e580;
	MarkContextStackTopUnknownSubspace((ProcessorContext*)(p + 0x34), 0x80);
}
