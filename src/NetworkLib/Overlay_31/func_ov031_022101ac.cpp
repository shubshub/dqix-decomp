#include <globaldefs.h>

struct Struct_ov031_022101ac {
	char pad[0x30];
	int unknown_30_;
};

extern Struct_ov031_022101ac* data_ov031_0224e588;

// USA: func_ov031_022101ac
extern "C" ARM void func_ov031_022101ac(int v) {
	Struct_ov031_022101ac* p = data_ov031_0224e588;
	if (p != NULL) {
		p->unknown_30_ = v;
	}
}
