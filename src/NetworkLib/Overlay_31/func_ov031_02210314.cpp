#include <globaldefs.h>

struct Struct_ov031_02210314 {
	char pad[0xa0c];
	int unknown_a0c_;
};

extern Struct_ov031_02210314* data_ov031_0224e588;

// USA: func_ov031_02210314
extern "C" ARM void func_ov031_02210314(int v) {
	Struct_ov031_02210314* p = data_ov031_0224e588;
	if (p != NULL) {
		p->unknown_a0c_ = v;
	}
}
