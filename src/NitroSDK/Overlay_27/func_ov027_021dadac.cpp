#include <globaldefs.h>

struct Struct_ov027_021da38c {
	char pad[0x4bc];
	struct Struct_ov027_021da38c *next;
};

struct Struct_ov027_021dd940 {
	char pad[0x18];
	struct Struct_ov027_021da38c *head;
};

extern struct Struct_ov027_021dd940 data_ov027_021dd940;

// USA: func_ov027_021dadac
extern "C" ARM void func_ov027_021dadac(struct Struct_ov027_021da38c *node) {
	struct Struct_ov027_021da38c *cur = data_ov027_021dd940.head;
	if (cur == NULL) {
		data_ov027_021dd940.head = node;
	} else {
		struct Struct_ov027_021da38c *next = cur->next;
		if (next != NULL) {
			do {
				cur = next;
				next = cur->next;
			} while (next != NULL);
		}
		cur->next = node;
	}
	node->next = NULL;
}
