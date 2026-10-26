#include <globaldefs.h>

struct Struct_ov031_022919bc { int unknown_0_; int unknown_4_; };
extern Struct_ov031_022919bc data_ov031_022919bc;

struct Struct_ov031_022919c4 { void* val; int pad; };
extern Struct_ov031_022919c4 data_ov031_022919c4[];
extern Struct_ov031_022919c4 data_ov031_022919c8[];

extern "C" int func_ov031_022413c8(int unused, void* id);
extern "C" void func_ov031_02241720(void* obj);

// USA: func_ov031_0224175c
extern "C" ARM void func_ov031_0224175c(void* target, void** ptr) {
	int var0 = (data_ov031_022919bc.unknown_0_ + 1) & 7;
	if (var0 == data_ov031_022919bc.unknown_4_) {
		func_ov031_022413c8(0, data_ov031_022919c4[data_ov031_022919bc.unknown_4_].val);
		func_ov031_02241720(data_ov031_022919c8[data_ov031_022919bc.unknown_4_].val);
		data_ov031_022919bc.unknown_4_ = (data_ov031_022919bc.unknown_4_ + 1) & 7;
	}
	if (*ptr == 0) {
		return;
	}
	int var1 = data_ov031_022919bc.unknown_0_;
	data_ov031_022919c4[var1].val = target;
	data_ov031_022919c8[var1].val = *ptr;
	*ptr = 0;
	data_ov031_022919bc.unknown_0_ = var0;
}
