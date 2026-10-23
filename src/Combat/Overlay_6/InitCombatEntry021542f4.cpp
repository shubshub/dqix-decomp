#include <globaldefs.h>

void InitCombatController020a2010(void* objIn);
void Camera_SetTarget(unsigned char* obj, int a, int b, int c);
void SetField0x238False_020a27a0(void* obj);
extern "C" void func_0202e5d8(void*, int, int, int);
extern "C" void func_0202e0a4(void*);

// USA: func_ov006_021542f4
ARM void InitCombatEntry021542f4(void *obj) {
	if (!obj) return;
	InitCombatController020a2010(obj);
	Camera_SetTarget((unsigned char*)obj, 0, 0xffffe171, 0);
	func_0202e5d8(obj, 0, 0x2eb8, 0xa000);
	func_0202e0a4(obj);
	SetField0x238False_020a27a0(obj);
}
