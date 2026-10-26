#include <globaldefs.h>

struct Struct_ov014_021874f8 {
	struct Struct_ov014_021874f8* next;
};

struct Struct_ov014_02186bc8_3 {
	char pad[0xb8];
	struct Struct_ov014_021874f8* head;
};

// USA: func_ov014_021874f8
extern "C" ARM short func_ov014_021874f8(struct Struct_ov014_02186bc8_3* obj) {
	struct Struct_ov014_021874f8* p = obj->head;
	short count = 0;
	while (p) {
		count++;
		p = p->next;
	}
	return count;
}
