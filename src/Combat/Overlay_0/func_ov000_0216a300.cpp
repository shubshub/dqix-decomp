#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

extern "C" void func_ov000_02169b78(void*);

struct Struct_ov000_02184264_8 {
	unsigned char pad[8];
	SafeAllocator* alloc;
};
extern struct Struct_ov000_02184264_8 data_ov000_02184264;

struct Variant02030b0c { int tag; int u; };

struct Struct_ov000_0216a300 {
	int tag;
	int unused;
	unsigned short value;
};

// USA: func_ov000_0216a300
extern "C" ARM int func_ov000_0216a300(struct Variant02030b0c* v) {
	struct Struct_ov000_0216a300* node = (struct Struct_ov000_0216a300*)data_ov000_02184264.alloc->Allocate(0xc);
	node->tag = 0xa;
	node->value = (unsigned short)((Script::Parameter*)v)->ToInt();
	if (node->value != 0) {
		func_ov000_02169b78(node);
	}
	return 1;
}
