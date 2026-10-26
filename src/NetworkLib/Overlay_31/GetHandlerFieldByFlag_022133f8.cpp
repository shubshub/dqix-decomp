#include <globaldefs.h>

struct Struct_ov031_0224e5c4 {
	void* field0;
	void* field4;
	void* field8;
	void* fieldc;
	void* field10;
};

extern Struct_ov031_0224e5c4 data_ov031_0224e5c4;

// USA: func_ov031_022133f8
extern "C" ARM void* func_ov031_022133f8(unsigned int flags) {
	if (flags & 1) return data_ov031_0224e5c4.fieldc;
	if (flags & 2) return data_ov031_0224e5c4.field0;
	if (flags & 4) return data_ov031_0224e5c4.field4;
	if (flags & 8) return data_ov031_0224e5c4.field8;
	if (flags & 0x10) return data_ov031_0224e5c4.field10;
	return NULL;
}
