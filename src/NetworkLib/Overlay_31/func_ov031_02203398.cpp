#include <globaldefs.h>

struct Struct_ov031_02203398 {
	char pad[0x8];
	unsigned char unknown_8_;
};

extern "C" int func_ov031_02201f10(int, int, int);
void CycleCurrentPriorityContexts();

extern "C" int func_ov031_02201f98(int, int);
extern "C" int func_ov031_02201f84(int, int);

// USA: func_ov031_02203398
extern "C" ARM void func_ov031_02203398(Struct_ov031_02203398* obj) {
	CycleCurrentPriorityContexts();
	unsigned char field8 = obj->unknown_8_;
	if (field8 == 3 || field8 == 4) {
		func_ov031_02201f98((int)obj, 0x19);
		obj->unknown_8_ = 7;
	} else if (field8 != 0) {
		func_ov031_02201f84((int)obj, 0x1a);
	}
}
