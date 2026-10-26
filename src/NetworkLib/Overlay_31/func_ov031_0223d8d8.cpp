#include <globaldefs.h>

unsigned int DisableSpecificInterrupts(unsigned int mask);
unsigned int EnableSpecificInterrupts(unsigned int mask);

struct Struct_ov031_0223d8d8 {
	struct Struct_ov031_0223d8d8* prev; /* 0x0 */
	struct Struct_ov031_0223d8d8* next; /* 0x4 */
};

struct Struct_ov031_0223d8d8_2 {
	struct Struct_ov031_0223d8d8* head;
};

// USA: func_ov031_0223d8d8
extern "C" ARM void func_ov031_0223d8d8(struct Struct_ov031_0223d8d8_2* list, struct Struct_ov031_0223d8d8* node) {
	unsigned int prev = DisableSpecificInterrupts(1);
	list->head->next = node;
	node->prev = list->head;
	node->next = (struct Struct_ov031_0223d8d8*)list;
	list->head = node;
	EnableSpecificInterrupts(prev);
}
