#include <globaldefs.h>

struct Struct_ov016_0218b5c4_6 {
	unsigned short id;
	char pad[0x18 - 2];
	Struct_ov016_0218b5c4_6* next;
};

// USA: func_ov016_0218e124
extern "C" ARM void* func_ov016_0218e124(Struct_ov016_0218b5c4_6** list, int id) {
	Struct_ov016_0218b5c4_6* node = *list;
	while (node) {
		if (node->id == id) return node;
		node = node->next;
	}
	return NULL;
}
