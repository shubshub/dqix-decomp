#include <globaldefs.h>

extern "C" void func_ov017_021adc30(void* obj);
extern "C" void func_ov017_021a1880(void* obj);
extern "C" void func_ov017_021bb930(void* self);
extern "C" void func_ov017_021b9904(char* p);
extern "C" void func_ov017_021b8438(void* obj);
extern "C" void func_ov017_021a5934(void*);
extern "C" void func_ov017_021bae80(void* obj);
extern "C" void func_ov017_021babc8(void* obj);
extern "C" void func_ov003_0217e580(int* obj);
extern "C" void func_ov017_021b2f0c(void*);
struct Struct_ov017_021a3b40_2;
extern "C" void func_ov017_021b6b5c(Struct_ov017_021a3b40_2* obj);
extern "C" void func_ov003_0217eec4(int* obj);
extern "C" void func_ov017_021aad8c(void* obj);
extern "C" void func_ov017_021accfc(void*);
struct Struct_ov017_021a3b40_3;
extern "C" void func_ov017_021afa70(Struct_ov017_021a3b40_3* obj);
extern "C" void func_ov017_021c0538(void* obj);
extern "C" void func_ov017_021c11f0(void* obj);
struct Struct_ov003_0217f218;
extern "C" void func_ov003_0217f218(Struct_ov003_0217f218* obj);
extern "C" void func_ov017_021b1cc4(void*);
extern "C" void func_ov017_021b1fa0(void*);
extern "C" void func_ov017_021b2348(void*);
extern "C" void func_ov017_021c162c(void*);
extern "C" void func_ov017_021c19f8(void* obj);
extern "C" void func_ov017_021bef48(void*);
extern "C" void func_ov017_021a9248(void* obj);
struct Struct_ov017_021a3b40;
extern "C" void func_ov017_021a9998(Struct_ov017_021a3b40* obj);
extern "C" void func_ov017_021a7998(void* obj);
struct Struct_020dae68;
extern "C" void func_020dae68(Struct_020dae68* obj);

// USA: func_ov017_021a3b40
extern "C" ARM void func_ov017_021a3b40(void* unused, void* obj) {
	if (!obj) return;
	if (*((unsigned char*)obj + 1) != 0) return;

	switch (*(signed char*)obj) {
	case 1:
		func_ov017_021adc30(obj);
		break;
	case 2:
		func_ov017_021a1880(obj);
		break;
	case 5:
		func_ov017_021b9904((char*)obj);
		break;
	case 0xa:
		func_ov017_021b8438(obj);
		break;
	case 0xc:
		func_ov017_021a5934(obj);
		break;
	case 0xf:
		func_ov017_021bae80(obj);
		break;
	case 0x10:
		func_ov017_021babc8(obj);
		break;
	case 0x11:
		func_ov003_0217e580((int*)obj);
		break;
	case 4:
		func_ov017_021bb930(obj);
		break;
	case 0x12:
		func_ov017_021b2f0c(obj);
		break;
	case 0x17:
		func_ov017_021b6b5c((Struct_ov017_021a3b40_2*)obj);
		break;
	case 0x18:
		func_ov003_0217eec4((int*)obj);
		break;
	case 0x1a:
		func_ov017_021aad8c(obj);
		break;
	case 0x1f:
		func_ov017_021accfc(obj);
		break;
	case 0x26:
		func_ov017_021afa70((Struct_ov017_021a3b40_3*)obj);
		break;
	case 0x28:
		func_ov017_021c0538(obj);
		break;
	case 0x29:
		func_ov017_021c11f0(obj);
		break;
	case 0x2a:
		func_ov003_0217f218((Struct_ov003_0217f218*)obj);
		break;
	case 0x2b:
		func_ov017_021b1cc4(obj);
		break;
	case 0x2c:
		func_ov017_021b1fa0(obj);
		break;
	case 0x2d:
		func_ov017_021b2348(obj);
		break;
	case 0x2e:
		func_ov017_021c162c(obj);
		break;
	case 0x2f:
		func_ov017_021c19f8(obj);
		break;
	case 0x34:
		func_ov017_021bef48(obj);
		break;
	case 0x38:
		func_ov017_021a9248(obj);
		break;
	case 0x3a:
		func_ov017_021a9998((Struct_ov017_021a3b40*)obj);
		break;
	case 0x3f:
		func_ov017_021a7998(obj);
		break;
	case 0x4b:
		func_020dae68((Struct_020dae68*)obj);
		break;
	}
}
