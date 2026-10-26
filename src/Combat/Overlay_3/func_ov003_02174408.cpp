#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov003_02174114_4 {
	unsigned char a;
	unsigned char b;
	unsigned char pad1[0x12];
	unsigned char pad2[0x24];
	unsigned short e;
	unsigned short f;
	unsigned char g;
};

// USA: func_ov003_02174408
extern "C" ARM void func_ov003_02174408(Struct_ov003_02174114_4* obj) {
	obj->a = 0x63;
	obj->b = 0;
	memset(obj->pad1, 0, sizeof(obj->pad1));
	memset(obj->pad2, -1, sizeof(obj->pad2));
	obj->e = 0x64;
	obj->f = 0;
	obj->g = 0;
}
