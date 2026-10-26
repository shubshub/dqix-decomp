#include <globaldefs.h>

struct Struct_ov016_0218b5c4_5 {
	char pad[0x18];
	Struct_ov016_0218b5c4_5* next;
};

// USA: func_ov016_0218e14c
extern "C" ARM void* func_ov016_0218e14c(Struct_ov016_0218b5c4_5** list, int n) {
	Struct_ov016_0218b5c4_5* node = *list;
	while (n > 0) {
		if (node == NULL) return NULL;
		node = node->next;
		n--;
	}
	return node;
}
