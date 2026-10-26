#include <globaldefs.h>

struct Struct_ov027_021e33e0_19 {
	unsigned char pad0[8];
	unsigned char* ptr;
};

extern Struct_ov027_021e33e0_19 data_ov027_021e33e0;

// USA: func_ov027_021dd0ac
extern "C" ARM int func_ov027_021dd0ac(void) {
	return data_ov027_021e33e0.ptr[0x50d] == 1;
}
