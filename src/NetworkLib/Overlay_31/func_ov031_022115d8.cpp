#include <globaldefs.h>

extern "C" long long func_ov031_02212d20(void);
extern "C" void func_ov031_02211754(struct Struct_ov031_022114fc_2* obj);
extern "C" void func_ov031_02211678(void* dst, int lo, int hi);

struct Struct_ov031_022114fc_2;

// USA: func_ov031_022115d8
extern "C" ARM void func_ov031_022115d8(void* obj, int value) {
	long long pair = func_ov031_02212d20();
	func_ov031_02211678((char*)obj + 0x10, (int)pair, (int)(pair >> 32));
	*(int*)((char*)obj + 0x1c) = value;
	func_ov031_02211754((struct Struct_ov031_022114fc_2*)obj);
}
