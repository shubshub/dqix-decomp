#include <globaldefs.h>

extern "C" int func_ov031_02207180(void* v);
extern "C" int func_ov031_022071b4(void* item);

// USA: func_ov031_022068cc
extern "C" ARM int func_ov031_022068cc(void* obj) {
	if ((int)obj >= 0) {
		if (func_ov031_02207180(obj) != 0) {
			if (func_ov031_022071b4(obj) == 0) {
				return 1;
			}
		}
	}
	return 0;
}
