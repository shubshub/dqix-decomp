#include <globaldefs.h>

struct Struct020A2CF0;
extern "C" void Camera_Init(void* obj);
void ResetState020a2cf0(struct Struct020A2CF0* obj);
void InitCombatController020a2010(void* obj);

// USA: func_ov004_02163408
ARM void* DoInitResetOrder_02163408(void* obj) {
	InitCombatController020a2010(obj);
	ResetState020a2cf0((struct Struct020A2CF0*)obj);
	Camera_Init(obj);
	return obj;
}
