#include <globaldefs.h>

struct Struct_ov031_0224e22c_2 {
	int next;
};

struct Struct_ov031_022069d0 {
	char pad[0x7c];
	int next;
};

// USA: func_ov031_022070e0
extern "C" ARM void func_ov031_022070e0(Struct_ov031_0224e22c_2* head, Struct_ov031_022069d0* item) {
	item->next = head->next;
	head->next = (int)item;
}
