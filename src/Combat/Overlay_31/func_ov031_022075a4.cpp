#include <globaldefs.h>

struct Struct_ov031_022075a4 { char pad[0x72]; signed char state; };

// USA: func_ov031_022075a4
extern "C" ARM int func_ov031_022075a4(Struct_ov031_022075a4* obj, int cmd, int flags) {
	if (obj == NULL) {
		return -1;
	}
	if (cmd == 3) goto case3;
	if (cmd == 4) goto case4;
	goto def;
case3:
	return (obj->state == 1) ? 0 : 4;
case4:
	if (flags & 4) {
		obj->state = 0;
	} else {
		obj->state = 1;
	}
def:
	return 0;
}
