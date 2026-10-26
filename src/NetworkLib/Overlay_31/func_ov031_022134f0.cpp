#include <globaldefs.h>

struct Struct_ov031_0224e5c4_7 {
	unsigned int field0;
	unsigned int field4;
	unsigned int field8;
	void* fieldc;
};

extern Struct_ov031_0224e5c4_7 data_ov031_0224e5c4;

// USA: func_ov031_022134f0
extern "C" ARM void* func_ov031_022134f0(void) {
	return *(void**)((char*)data_ov031_0224e5c4.fieldc + 0xc);
}
