#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" char* func_ov031_02218e2c(void* a, void* b);

// USA: func_ov031_02218ed8
extern "C" ARM int func_ov031_02218ed8(void* a, void* b, char* dest, int maxLen) {
	char* s = func_ov031_02218e2c(a, b);
	if (s == NULL) {
		return 0;
	}
	if ((int)strlen(s) >= maxLen) {
		return 0;
	}
	strcpy(dest, s);
	return 1;
}
