#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov000_02169b78(void*);

struct Struct_ov000_02184264_2 {
	unsigned char pad[8];
	SafeAllocator* alloc;
};
extern struct Struct_ov000_02184264_2 data_ov000_02184264;

struct Struct_ov000_02169e54 {
	int tag;
};

// USA: func_ov000_02169e54
extern "C" ARM int func_ov000_02169e54() {
	struct Struct_ov000_02169e54* node = (struct Struct_ov000_02169e54*)data_ov000_02184264.alloc->Allocate(8);
	node->tag = 4;
	func_ov000_02169b78(node);
	return 1;
}
