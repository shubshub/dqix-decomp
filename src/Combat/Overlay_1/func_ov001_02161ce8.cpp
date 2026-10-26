#include <globaldefs.h>
#include "Graphics/LightingManager.h"

extern "C" void func_ov017_021d6134(void* obj, int val);

// USA: func_ov001_02161ce8
extern "C" ARM int func_ov001_02161ce8(void* obj) {
	int v = *(int*)((char*)LightingManager::GetInstance() + 0x98);
	func_ov017_021d6134(obj, v);
	return 1;
}
