#include <globaldefs.h>

extern "C" int func_ov031_02205030(int);
extern "C" int func_ov031_02205364(void*);
extern void* data_ov031_022496a4;
extern int data_ov031_022496dc;

struct Struct_ov031_0224e1c0 {
	char pad[0xc];
	int fieldc;
};
extern Struct_ov031_0224e1c0 data_ov031_0224e1c0;

// USA: func_ov031_02204df8
extern "C" ARM int func_ov031_02204df8(void) {
	int result = func_ov031_02205030(*(int*)((char*)data_ov031_022496a4 + 0x20));
	if (result >= 0) {
		data_ov031_0224e1c0.fieldc = func_ov031_02205364(&data_ov031_022496dc);
	}
	return result;
}
