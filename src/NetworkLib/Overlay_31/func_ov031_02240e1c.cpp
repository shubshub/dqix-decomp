#include <globaldefs.h>

extern "C" void (* volatile data_ov031_02290fc8)(void*);

struct Struct_ov031_02240e1c {
	Struct_ov031_02240e1c* next;
};

// USA: func_ov031_02240e1c
extern "C" ARM void func_ov031_02240e1c(Struct_ov031_02240e1c* head) {
	if (!head) return;
	do {
		Struct_ov031_02240e1c* next = head->next;
		if (head != next) {
			Struct_ov031_02240e1c* var1 = *(Struct_ov031_02240e1c* *)&next->next;
			data_ov031_02290fc8(next);
			head->next = var1;
		} else {
			data_ov031_02290fc8(head);
			head = NULL;
		}
	} while (head);
}
