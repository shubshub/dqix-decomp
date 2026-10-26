#include <globaldefs.h>

extern "C" int func_ov031_0223d8d8(void*);

// USA: func_ov031_0223d918
extern "C" ARM int func_ov031_0223d918(char* p) {
	return func_ov031_0223d8d8(*(void**)(p + 4));
}
