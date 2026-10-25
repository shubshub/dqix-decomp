#include <globaldefs.h>

extern "C" void* Zone3D_GetInstance(void);
extern "C" int func_ov003_0216ffbc(void* param);

struct S021700bc { char pad[0x170]; void* field170; };

// USA: func_ov003_021700bc
ARM void InitField170_021700bc(S021700bc* param) {
#if defined(jpn)
	param->field170 = (char*)Zone3D_GetInstance() + 0x860;
#else
	param->field170 = (char*)Zone3D_GetInstance() + 0x840;
#endif
	func_ov003_0216ffbc(param);
}
