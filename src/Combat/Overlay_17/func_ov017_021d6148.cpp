#include <globaldefs.h>

struct Struct_ov001_0215af34 { unsigned int type; Struct_ov001_0215af34* link; };

// USA: func_ov017_021d6148
extern "C" ARM void func_ov017_021d6148(Struct_ov001_0215af34* o, unsigned int v) {
	if (o->type == 3) {
		o = o->link;
		o->link = (Struct_ov001_0215af34*)v;
	}
}
