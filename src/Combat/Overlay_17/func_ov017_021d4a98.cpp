#include <globaldefs.h>

struct Struct_ov017_021d4a98 { int type; int val; };
struct Struct_ov017_021d4a98_2 { unsigned char pad[0x14]; Struct_ov017_021d4a98* cursor; };

// USA: func_ov017_021d4a98
extern "C" ARM void func_ov017_021d4a98(Struct_ov017_021d4a98_2* obj, int val) {
	obj->cursor->type = 2;
	Struct_ov017_021d4a98* e = obj->cursor;
	obj->cursor = e + 1;
	e->val = val;
}
