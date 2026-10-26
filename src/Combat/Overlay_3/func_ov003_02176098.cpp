#include <globaldefs.h>

struct Struct_020e28dc;
struct Struct_020e2794_2;
extern "C" int func_020e28dc(struct Struct_020e28dc* o);
extern "C" void func_020e2794(struct Struct_020e2794_2* self, void* b);

struct Struct_ov003_0217480c {
	void* field0;
};

// USA: func_ov003_02176098
extern "C" ARM void func_ov003_02176098(struct Struct_ov003_0217480c* p) {
	if (p->field0 == NULL) return;
	if (!func_020e28dc((struct Struct_020e28dc*)p->field0)) return;
#if defined(jpn)
    enum { Enum_ov003_02176098_2008 = 0x754 };
#else
    enum { Enum_ov003_02176098_2008 = 0x7d8 };
#endif
	void* b = (char*)p + Enum_ov003_02176098_2008;
	func_020e2794((struct Struct_020e2794_2*)p->field0, b);
}
