#include <globaldefs.h>

struct Struct_ov001_02165880_27 { char pad[0x24]; void* field24; };
extern struct Struct_ov001_02165880_27 data_ov001_02165880;
extern "C" void* func_ov001_02159044(void* ctx);

// USA: func_ov001_0215d768
extern "C" ARM int func_ov001_0215d768(void) {
	func_ov001_02159044(data_ov001_02165880.field24);
	return 1;
}
