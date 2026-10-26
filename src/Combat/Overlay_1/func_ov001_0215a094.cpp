#include <globaldefs.h>

struct Struct_ov001_02164624;
extern "C" int func_ov001_02164624(Struct_ov001_02164624* arr, int idx);
extern Struct_ov001_02164624* data_ov001_02165884;

struct Struct_ov001_0215a094 { int type; char pad4[0x38]; int field3c; };

// USA: func_ov001_0215a094
extern "C" ARM int func_ov001_0215a094(char* self) {
	Struct_ov001_0215a094* p = *(Struct_ov001_0215a094**)(self + 0x18);
	if (p != 0) {
		if (p->field3c == 0 && p->type == 0xc) {
			if (data_ov001_02165884 != 0) {
				int r = func_ov001_02164624(data_ov001_02165884, *(int*)(self + 0x70));
				if (r != 0) {
					*(void**)(self + 0x1c) = 0;
					*(void**)(self + 0x18) = 0;
				}
			}
		}
	}
	return (*(void**)(self + 0x8) == 0 && *(void**)(self + 0x10) == 0 &&
	        *(void**)(self + 0x18) == 0 && *(void**)(self + 0x20) == 0 &&
	        *(void**)(self + 0x28) == 0 && *(void**)(self + 0x30) == 0 &&
	        *(void**)(self + 0x38) == 0 && *(void**)(self + 0x40) == 0) ? 1 : 0;
}
