#include <globaldefs.h>

struct Struct_ov031_02240210 {
	struct Struct_ov031_02240210* next;
	struct Struct_ov031_02240210* prev;
	int id;
	void* data;
	int field10;
};

extern struct Struct_ov031_02240210* volatile data_ov031_02290fdc;
extern "C" void (* volatile data_ov031_02290fc8)(void*);
extern "C" void* func_ov031_022401b8(void* target);

struct Struct_ov031_02240210_2 {
	char pad2c[0x2c];
	void* field2c;
	void* unknown_30_;
	char unknown_34_[0x3c - 0x34];
	void* field3c;
};

extern "C" int func_ov031_02240e70(void* obj);

// USA: func_ov031_02240210
extern "C" ARM int func_ov031_02240210(void* target) {
	int result = 0;
	struct Struct_ov031_02240210* node = (struct Struct_ov031_02240210*)func_ov031_022401b8(target);
	if (node == NULL) {
		goto done;
	}
	struct Struct_ov031_02240210* head = data_ov031_02290fdc;
	if (head != head->next) {
		node->next->prev = node->prev;
		node->prev->next = node->next;
		if (data_ov031_02290fdc == node) {
			data_ov031_02290fdc = node->prev;
		}
	} else {
		data_ov031_02290fdc = NULL;
	}
	{
		struct Struct_ov031_02240210_2* obj = (struct Struct_ov031_02240210_2*)node->data;
		void (*fn)(int, void*, void*) = (void (*)(int, void*, void*))obj->field3c;
		void* a = obj->unknown_30_;
		void* b = obj->field2c;
		func_ov031_02240e70(obj);
		data_ov031_02290fc8(node);
		fn(8, a, b);
	}
	result = 1;
done:
	return result;
}
