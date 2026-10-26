#include <globaldefs.h>

struct Struct_ov003_0215ee44 {
	char pad[0x1e];
	unsigned char state;
	unsigned char pad1f;
	unsigned char flag;
};

// USA: func_ov003_0215ee44
extern "C" ARM int func_ov003_0215ee44(Struct_ov003_0215ee44* obj) {
	obj->state = (obj->state == 2) ? 1 : 2;
	obj->flag = 0;
	return 4;
}
