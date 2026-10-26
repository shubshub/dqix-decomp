#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"

struct Struct_ov017_021cfcb4 {
	unsigned char pad[4];
	unsigned char field4;
};

// USA: func_ov017_021cfcb4
extern "C" ARM void func_ov017_021cfcb4(int unused, Struct_ov017_021cfcb4* obj) {
	GrottoStruct* grotto = GameState::GetInstance()->GetGrottoStruct();
	grotto->unknown_0[3] = (obj->field4 != 0) ? 1 : 0;
	if (obj->field4 != 0) {
		grotto->unknown_0[4] = 0;
	}
}
