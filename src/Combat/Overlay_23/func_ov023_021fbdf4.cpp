#include <globaldefs.h>
#if defined(jpn)
#define REGION_FIELD_0 0x716
#else
#define REGION_FIELD_0 0x79a
#endif


extern "C" void func_ov023_021ddf5c(void *obj, int v);

struct Struct_ov004_02158bd4 {
	char pad[REGION_FIELD_0];
	unsigned char field;
};

// USA: func_ov023_021fbdf4
extern "C" ARM void func_ov023_021fbdf4(struct Struct_ov004_02158bd4 *obj, int v) {
	obj->field = v;
	func_ov023_021ddf5c((char*)obj + 0x20, v);
}
