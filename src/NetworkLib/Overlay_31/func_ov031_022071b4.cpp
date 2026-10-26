#include <globaldefs.h>

extern "C" void* func_ov031_0220713c(void*, void*);
extern void* data_ov031_0224e230;

// USA: func_ov031_022071b4
extern "C" ARM int func_ov031_022071b4(void* item) {
	return func_ov031_0220713c(&data_ov031_0224e230, item) != 0;
}
