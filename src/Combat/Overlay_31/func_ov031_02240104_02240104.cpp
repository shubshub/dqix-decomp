#include <globaldefs.h>

typedef void* (*Type_ov031_02240104)(int size, int align);
extern Type_ov031_02240104 data_ov031_02290fc4;

struct Struct_ov031_02240104 {
	struct Struct_ov031_02240104* prev;
	struct Struct_ov031_02240104* next;
	int field8;
	int fieldC;
	int field10;
};
extern struct Struct_ov031_02240104* data_ov031_02290fdc;
extern int data_ov031_02290fd8;

// USA: func_ov031_02240104
extern "C" ARM int func_ov031_02240104(int arg) {
	int id = -1;
	struct Struct_ov031_02240104* node = (struct Struct_ov031_02240104*)data_ov031_02290fc4(0x14, 4);

	if (node != NULL) {
		if (data_ov031_02290fdc == NULL) {
			node->prev = node;
			node->next = node;
			*(struct Struct_ov031_02240104* volatile*)&data_ov031_02290fdc = node;
		} else {
			node->prev = data_ov031_02290fdc->prev;
			node->next = data_ov031_02290fdc;
			data_ov031_02290fdc->prev->next = node;
			data_ov031_02290fdc->prev = node;
		}

		int old = *(volatile int*)&data_ov031_02290fd8;
		data_ov031_02290fd8 = *(volatile int*)&data_ov031_02290fd8 + 1;
		node->field8 = old;
		node->fieldC = arg;
		node->field10 = -1;
		id = node->field8;
		if (data_ov031_02290fd8 < 0) {
			data_ov031_02290fd8 = 0;
		}
	}

	return id;
}
