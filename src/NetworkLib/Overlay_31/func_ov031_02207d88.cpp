#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov031_02207d88_2 {
	const char* name;
};

struct Struct_ov031_02207d88 {
	char pad[0x814];
	Struct_ov031_02207d88_2** items;
	int count;
};

// USA: func_ov031_02207d88
extern "C" ARM Struct_ov031_02207d88_2* func_ov031_02207d88(Struct_ov031_02207d88* obj, const char* key) {
	int i = 0;
	Struct_ov031_02207d88_2** items;
	int count = obj->count;
	if (count > 0) {
		items = obj->items;
		do {
			Struct_ov031_02207d88_2* e = items[i];
			if (strcmp(e->name, key) == 0) {
				return e;
			}
			i++;
		} while (i < count);
	}
	return 0;
}
