#include <globaldefs.h>

extern "C" void func_ov031_0221038c(int v);
extern "C" void func_ov031_022103dc(void* value);
struct BlockedContextList;
void UnblockContexts(struct BlockedContextList*);

extern void* data_ov031_0224e588;

// USA: func_ov031_022103f8
extern "C" ARM void func_ov031_022103f8(void* value) {
	func_ov031_0221038c(0);
	func_ov031_022103dc(value);
	UnblockContexts((BlockedContextList*)((char*)data_ov031_0224e588 + 0xa04));
}
