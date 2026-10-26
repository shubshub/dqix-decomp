#include <globaldefs.h>

struct Struct_ov031_02207120_2 { unsigned char pad[0x7c]; Struct_ov031_02207120_2* next; };
struct Struct_ov031_02207120 { Struct_ov031_02207120_2* head; };

// USA: func_ov031_0220713c
extern "C" ARM Struct_ov031_02207120_2** func_ov031_0220713c(Struct_ov031_02207120* list, Struct_ov031_02207120_2* target) {
	Struct_ov031_02207120_2* node = list->head;
	Struct_ov031_02207120_2** link = (Struct_ov031_02207120_2**)list;
	if (node != NULL) {
		do {
			if (node == target) return link;
			link = &node->next;
			node = node->next;
		} while (node != NULL);
	}
	return NULL;
}
