#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov031_0221a434(void*, void*);
extern "C" int func_ov031_0221a518(void*, void*);
extern "C" void func_ov031_0221a4cc(void);
extern "C" void* func_ov031_02211b54(void*, void*);
extern "C" void* func_ov031_02211b98(void*, void*, int);
extern char data_ov031_02249a80;

// USA: func_ov031_02212524
extern "C" ARM int func_ov031_02212524(char* str, void* b) {
	if (!func_ov031_0221a434((void*)func_ov031_02211b54, (void*)func_ov031_02211b98)) return 0;
	int r;
	if (strlen(str) == 0) {
		r = func_ov031_0221a518(&data_ov031_02249a80, b);
	} else {
		r = func_ov031_0221a518(str, b);
	}
	if (r != 0) return 1;
	func_ov031_0221a4cc();
	return 0;
}
