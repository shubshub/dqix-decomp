#include <globaldefs.h>

extern "C" int func_ov031_0220f330(void* obj);

extern int data_ov031_0224e54c;

// USA: func_ov031_0220f2cc
extern "C" ARM int func_ov031_0220f2cc(void) {
	return func_ov031_0220f330(&data_ov031_0224e54c);
}
