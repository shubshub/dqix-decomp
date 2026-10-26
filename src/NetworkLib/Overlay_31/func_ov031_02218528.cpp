#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov031_02218528 { char* unknown_0_; char* current; char* end; int capacity; };
extern "C" int func_ov031_0221883c(void* obj, Struct_ov031_02218528* b, int len);
extern "C" int func_020c7170(char* destination, unsigned long capacity, const char* format, ...);

extern char data_ov031_02249ed0[];
extern char data_ov031_02249df8[];

// USA: func_ov031_02218528
extern "C" ARM int func_ov031_02218528(void* obj, const char* str, const char* val) {
	char* var0 = (char*)obj + 0x1f8;
	Struct_ov031_02218528* b = (Struct_ov031_02218528*)(var0 + 0x1800);
	int len = strlen(val);
	len += (strlen(data_ov031_02249ed0) - 4) + strlen(str);

	int var3 = b->end - b->current;
	if (len + 1 > var3) {
		int var4 = len - var3 + 1;
		if (func_ov031_0221883c(obj, b, var4) == 0) {
			return 1;
		}
	}

	char* raw = strstr(b->unknown_0_, data_ov031_02249df8);
	char saved = raw[2];
	char* p = raw + 2;
	int n = strlen(p) + 1;
	memmove(p + len, p, n);
	int var9 = func_020c7170(p, len + 1, data_ov031_02249ed0, str, val);
	p[var9] = saved;
	b->current = b->current + len;
	return 0;
}
