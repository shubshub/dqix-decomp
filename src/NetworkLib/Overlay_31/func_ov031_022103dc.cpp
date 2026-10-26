#include <globaldefs.h>

extern void* data_ov031_0224e588;

// USA: func_ov031_022103dc
extern "C" ARM void func_ov031_022103dc(void* value) {
	void* volatile* var0 = (void* volatile*)data_ov031_0224e588;
	if (var0 != NULL) {
		(void)*var0;
		*var0 = value;
	}
}
