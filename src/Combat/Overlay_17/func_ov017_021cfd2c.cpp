#include <globaldefs.h>
#include "World/ZoneLifecycle.h"
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"

struct Struct_ov017_021cfd2c {
	unsigned char pad[4];
	unsigned char field4;
};

extern "C" void* Zone3D_GetInstance(void);

// USA: func_ov017_021cfd2c
extern "C" ARM void func_ov017_021cfd2c(int unused, Struct_ov017_021cfd2c* obj) {
	GrottoStruct* grotto = GameState::GetInstance()->GetGrottoStruct();
	grotto->unknown_0[4] = (obj->field4 != 0) ? 1 : 0;
	func_0201bfd4(static_cast<Zone3D*>(Zone3D_GetInstance()));
}
