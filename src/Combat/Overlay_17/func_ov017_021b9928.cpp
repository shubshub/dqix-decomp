#include <globaldefs.h>

extern "C" void func_ov008_02184968(void* a);
extern "C" void func_0208be90(void*);

struct Struct_ov017_021b9928 {
    unsigned char unknown0[0x30];
    unsigned char unknown_30_[0xe8];
    void* unknown_118_;
};

// USA: func_ov017_021b9928
extern "C" ARM void func_ov017_021b9928(char* context) {
    Struct_ov017_021b9928* state = (Struct_ov017_021b9928*)context;
	if (state->unknown_118_ != NULL) func_ov008_02184968(state->unknown_118_);
	func_0208be90(state->unknown_30_);
}
