#include <globaldefs.h>


extern "C" void* Scenario_GetInstance(void);
extern "C" void func_0206e748(void* a, unsigned char b, unsigned char c, unsigned short d, unsigned short e);
extern "C" void func_ov017_021a01bc(unsigned char* self);

struct Struct_ov017_021d097c {
	unsigned char pad0[4];
	unsigned char field4;
	unsigned char field5;
	unsigned short field6;
	unsigned short field8;
};

// USA: func_ov017_021d097c
extern "C" ARM void func_ov017_021d097c(int a, Struct_ov017_021d097c* src, int b, unsigned char* self) {
	void* p = Scenario_GetInstance();
	func_0206e748(p, src->field4, src->field5, src->field6, src->field8);
	if (src->field4 == 0 || src->field4 == 2 || src->field4 == 7) {
		func_ov017_021a01bc(self);
	}
}
