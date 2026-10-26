#include <globaldefs.h>

struct Struct_ov017_021d4a78 { int type; int val; };
struct Struct_ov017_021d4a78_2 { unsigned char pad[0x14]; Struct_ov017_021d4a78* cursor; };

// USA: func_ov017_021d4a78
extern "C" ARM void func_ov017_021d4a78(Struct_ov017_021d4a78_2* obj, int val) {
	obj->cursor->type = 0;
	Struct_ov017_021d4a78* e = obj->cursor;
	obj->cursor = e + 1;
	e->val = val;
}
