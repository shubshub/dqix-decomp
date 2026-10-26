#include <globaldefs.h>

struct Struct_ov031_02205194 {
	unsigned char pad[0x64];
	int unknown_64_;
	int field68;
};

// USA: func_ov031_02205194
extern "C" ARM int func_ov031_02205194(struct Struct_ov031_02205194* obj) {
	int v = obj->unknown_64_;
	if (v == 0) v = obj->field68;
	return v;
}
