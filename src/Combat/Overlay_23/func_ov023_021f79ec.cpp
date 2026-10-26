#include <globaldefs.h>

struct Struct_ov011_02186f08 { char pad[0xc]; unsigned char flags; char pad2[3]; void* field10; char pad3[0x1c - 0x14]; int field1c; };

// USA: func_ov023_021f79ec
extern "C" ARM void func_ov023_021f79ec(struct Struct_ov011_02186f08* obj, void* v) {
	obj->field10 = v;
	obj->field1c = 0;
	obj->flags |= 3;
}
