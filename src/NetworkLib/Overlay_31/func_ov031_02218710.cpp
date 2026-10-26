#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov031_02218710 {
	char* unknown_0_;
	char* current;
	char* end;
	int capacity;
};

extern "C" int func_020c7170(char* destination, unsigned long capacity, const char* format, ...);
extern "C" int func_ov031_0221883c(void* obj, Struct_ov031_02218710* b, int len);
extern const char data_ov031_02249ee8[];

// USA: func_ov031_02218710
extern "C" ARM int func_ov031_02218710(void* obj, const char* str) {
	int len;
	Struct_ov031_02218710* b = (Struct_ov031_02218710*)((char*)obj + 0x19f8);
	len = strlen(str);
	int var2 = b->end - b->current;
	if (len > var2) {
		if (func_ov031_0221883c(obj, b, len - var2 + 1) == 0) {
			return 1;
		}
		var2 = b->end - b->current;
	}

	int var3 = func_020c7170(b->current, var2, data_ov031_02249ee8, str);
	if (var3 != len) {
		return 1;
	}

	b->current = b->current + var3;
	return 0;
}
