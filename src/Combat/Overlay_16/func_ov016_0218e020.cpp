#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Struct_ov016_0218e020 {
	unsigned int payload[6]; // 0x0..0x17
	struct Struct_ov016_0218e020* next; // 0x18
};

struct Struct_ov016_0218de60 {
	struct Struct_ov016_0218e020* head; // 0x0
	unsigned int count;             // 0x4
	SafeAllocator* allocator;       // 0x8
};

// USA: func_ov016_0218e020
extern "C" ARM void func_ov016_0218e020(Struct_ov016_0218de60* list, void* src) {
	if (list->allocator == NULL)
		return;
	struct Struct_ov016_0218e020* node = (struct Struct_ov016_0218e020*)list->allocator->Allocate(0x1c);
	if (node == NULL)
		return;
	memcpy(node, src, 0x1c);
	node->next = NULL;
	{
		struct Struct_ov016_0218e020* cur = list->head;
		struct Struct_ov016_0218e020* next;
		if (cur == NULL)
			goto setHead;
		goto testFirst;
	advance:
		cur = next;
	testFirst:
		next = cur->next;
		if (next != NULL)
			goto advance;
		cur->next = node;
		goto after;
	setHead:
		list->head = node;
	after:
		;
	}
	list->count++;
}
