#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

extern "C" void func_ov031_022033e8(void);
extern "C" void func_ov031_02203424(void);
extern "C" void func_ov031_02203250(void);
extern "C" void func_ov031_02203178(void);
extern "C" int func_ov031_022051a8(void* a, void* b);
unsigned int DisableIRQInterrupts(void);
void SetIRQInterruptState(int mask);
struct Struct_ov031_0224e22c;
extern "C" void* func_ov031_02207108(Struct_ov031_0224e22c* item);
struct Struct_ov031_022069d0;
extern "C" void func_ov031_022070f0(Struct_ov031_022069d0* item);

// USA: func_ov031_022069d0
extern "C" ARM int func_ov031_022069d0(void* p) {
	char* obj = *(char**)((char*)p + 4);
	signed char kind = *(signed char*)(obj + 0x73);
	int match = 1;
	if (kind != 0 && kind != 4) match = 0;
	if (match != 0) {
		AwaitContextCompletion((ProcessorContext*)(*(char**)(obj + 0x68) + 0x20));
		func_ov031_022033e8();
		func_ov031_02203424();
		func_ov031_02203250();
	}
	func_ov031_02203178();
	short flags = *(short*)(obj + 0x70);
	flags &= ~6;
	*(short*)(obj + 0x70) = flags;
	void* var4 = (*(signed char*)(obj + 0x73) == 2) ? *(void**)(obj + 0x68) : *(void**)(obj + 0x64);
	func_ov031_022051a8(var4, 0);
	int mask = DisableIRQInterrupts();
	func_ov031_02207108((Struct_ov031_0224e22c*)obj);
	func_ov031_022070f0((Struct_ov031_022069d0*)obj);
	SetIRQInterruptState(mask);
	*(short*)(obj + 0x70) = *(short*)(obj + 0x70) | 0x20;
	return 0;
}
