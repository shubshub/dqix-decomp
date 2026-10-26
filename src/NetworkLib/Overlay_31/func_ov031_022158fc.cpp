#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_020c0328;
extern "C" void func_020c0328(struct Struct_020c0328* state);

extern "C" void func_020c0368(struct Struct_020c0328* state, const void* data, unsigned int length);
extern "C" void func_020c0430(void* digest, struct Struct_020c0328* state);

// USA: func_ov031_022158fc
extern "C" ARM void func_ov031_022158fc(void* src, void* dst) {
	char state[0x58];
	char digest[0x14];
	func_020c0328((struct Struct_020c0328*)state);
	func_020c0368((struct Struct_020c0328*)state, src, 0x18);
	func_020c0430(digest, (struct Struct_020c0328*)state);
	VectorizedInvertedMemcpy(digest + 3, dst, 0xd);
}
