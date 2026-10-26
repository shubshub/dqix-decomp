#include <globaldefs.h>

extern "C" unsigned long long func_ov031_0221170c(unsigned int* p);
extern "C" long long func_ov031_02212d20(void);

// USA: func_ov031_02211608
extern "C" ARM int func_ov031_02211608(void* obj) {
	unsigned long long a = func_ov031_0221170c((unsigned int*)((char*)obj + 0x10));
	if (a == 0) return 1;
	unsigned long long b = (unsigned long long)func_ov031_02212d20();
	return a == b;
}
