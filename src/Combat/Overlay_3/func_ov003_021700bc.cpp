#include <globaldefs.h>

extern "C" void* Zone3D_GetInstance(void);
extern "C" int func_ov003_0216ffbc(void* param);

struct Struct_ov003_0216bcfc { char pad[0x170]; void* field170; };

// USA: func_ov003_021700bc
extern "C" ARM void func_ov003_021700bc(Struct_ov003_0216bcfc* param) {
#if defined(jpn)
	param->field170 = (char*)Zone3D_GetInstance() + 0x860;
#else
	param->field170 = (char*)Zone3D_GetInstance() + 0x840;
#endif
	func_ov003_0216ffbc(param);
}
