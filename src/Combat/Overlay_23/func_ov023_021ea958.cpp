#include <globaldefs.h>

extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_ov017_021d6134(void*, unsigned short);

// USA: func_ov023_021ea958
ARM int SetTextFromCurrentEntry_021ea958(void* obj) {
	void* p = Zone3D_GetInstance();
	unsigned short v = *(unsigned short*)p;
	func_ov017_021d6134(obj, v);
	return 1;
}
