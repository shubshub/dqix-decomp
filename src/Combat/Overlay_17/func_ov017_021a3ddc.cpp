#include <globaldefs.h>

struct Struct_ov017_021a185c;
extern "C" void func_ov017_021a185c(Struct_ov017_021a185c* obj);

struct Struct_ov017_021a3ddc;
extern "C" void func_ov017_021b8408(Struct_ov017_021a3ddc* obj);

struct Struct_ov017_021a3ddc_2;
extern "C" void func_ov017_021b6b44(Struct_ov017_021a3ddc_2* obj);

extern "C" void func_ov003_0217eedc(int* obj);

struct Struct_ov017_021a3ddc_3;
extern "C" void func_ov017_021afa9c(Struct_ov017_021a3ddc_3* obj);

extern "C" void func_ov017_021c0520(void* obj);
extern "C" void func_ov017_021c1208(void* obj);

struct Struct_ov003_0217f230;
extern "C" void func_ov003_0217f230(Struct_ov003_0217f230* obj);

extern "C" void func_ov017_021b1ce4(void*);
extern "C" void func_ov017_021b1fa4(void*);
extern "C" void func_ov017_021b2328(void*);

// USA: func_ov017_021a3ddc
extern "C" ARM void func_ov017_021a3ddc(void* unused, void* obj) {
	if (!obj) return;
	if (*((unsigned char*)obj + 1) != 0) return;

	switch (*(signed char*)obj) {
	case 2:
		func_ov017_021a185c((Struct_ov017_021a185c*)obj);
		break;
	case 0xa:
		func_ov017_021b8408((Struct_ov017_021a3ddc*)obj);
		break;
	case 0x17:
		func_ov017_021b6b44((Struct_ov017_021a3ddc_2*)obj);
		break;
	case 0x18:
		func_ov003_0217eedc((int*)obj);
		break;
	case 0x26:
		func_ov017_021afa9c((Struct_ov017_021a3ddc_3*)obj);
		break;
	case 0x28:
		func_ov017_021c0520(obj);
		break;
	case 0x29:
		func_ov017_021c1208(obj);
		break;
	case 0x2a:
		func_ov003_0217f230((Struct_ov003_0217f230*)obj);
		break;
	case 0x2b:
		func_ov017_021b1ce4(obj);
		break;
	case 0x2c:
		func_ov017_021b1fa4(obj);
		break;
	case 0x2d:
		func_ov017_021b2328(obj);
		break;
	}
}
