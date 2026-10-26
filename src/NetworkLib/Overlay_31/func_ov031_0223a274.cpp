#include <globaldefs.h>

struct Struct_ov031_0223a274 { unsigned char pad[0x4c]; int field4c; };
struct Struct_ov031_02290d18_24 { unsigned char pad[4]; struct Struct_ov031_0223a274* inner; };
extern struct Struct_ov031_02290d18_24 data_ov031_02290d18;

// USA: func_ov031_0223a274
extern "C" ARM void func_ov031_0223a274(int v) {
	data_ov031_02290d18.inner->field4c = v;
}
