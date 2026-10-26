#include <globaldefs.h>

extern "C" int func_ov031_0220d60c(void);

struct Struct_ov031_0220ece8_3 {
	unsigned char used;
	unsigned char pad0[3];
	int id;
	Struct_ov031_0220ece8_3* next;
	Struct_ov031_0220ece8_3* prev;
	unsigned char pad1[0xd0 - 0x10];
};

struct Struct_ov031_0220ece8 {
	int count;
	Struct_ov031_0220ece8_3* tail;
	Struct_ov031_0220ece8_3* head;
};

struct Struct_ov031_0220ece8_2 {
	unsigned char pad0[0x270];
	Struct_ov031_0220ece8* header;
	unsigned int unknown_274_;
};

// USA: func_ov031_0220ece8
extern "C" ARM Struct_ov031_0220ece8_3* func_ov031_0220ece8(void) {
	int base = func_ov031_0220d60c();
	Struct_ov031_0220ece8_2* ctx = (Struct_ov031_0220ece8_2*)(base + 0x2000);
	Struct_ov031_0220ece8* h = ctx->header;
	Struct_ov031_0220ece8_3* e = 0;
	if (h == 0) return e;
	if (ctx->unknown_274_ <= 0xc) return e;

	unsigned int capacity = (ctx->unknown_274_ - 0xc) / 0xd0;
	if (capacity == 0) return e;
	if (capacity <= (unsigned int)h->count) return e;

	int i = 0;
	if (i < capacity) {
		Struct_ov031_0220ece8_3* arr = (Struct_ov031_0220ece8_3*)((char*)h + 0xc);
		do {
			e = (Struct_ov031_0220ece8_3*)((char*)arr + i * sizeof(Struct_ov031_0220ece8_3));
			if (e->used == 0) break;
			i++;
		} while (i < capacity);
	}
	if (i >= capacity) return e;

	e->used = 1;
	e->id = h->count;
	e->prev = 0;
	e->next = h->head;
	h->head = e;
	if (e->next != 0) {
		e->next->prev = e;
	} else {
		h->tail = e;
	}
	h->count = h->count + 1;
	return e;
}
