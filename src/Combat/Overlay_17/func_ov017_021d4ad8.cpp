#include <globaldefs.h>

struct Struct_ov017_021d4ad8 { int type; int val; };
struct Struct_ov017_021d4ad8_2 { unsigned char pad[0x14]; Struct_ov017_021d4ad8* cursor; };

// USA: func_ov017_021d4ad8
extern "C" ARM void func_ov017_021d4ad8(Struct_ov017_021d4ad8_2* obj, int val) {
	obj->cursor->type = 1;
	Struct_ov017_021d4ad8* e = obj->cursor;
	obj->cursor = e + 1;
	e->val = val;
}
