#include <globaldefs.h>

struct Struct_ov014_02187520 {
	struct Struct_ov014_02187520* next;
};

struct Struct_ov014_021872dc {
	unsigned char pad0[0xb8];
	struct Struct_ov014_02187520* head;
	struct Struct_ov014_02187520* target;
};

// USA: func_ov014_02187520
extern "C" ARM short func_ov014_02187520(struct Struct_ov014_021872dc* s) {
	struct Struct_ov014_02187520* n = s->head;
	short i = 0;
	while (n != NULL) {
		if (n == s->target) return i / 16;
		n = n->next;
		i++;
	}
	return -1;
}
