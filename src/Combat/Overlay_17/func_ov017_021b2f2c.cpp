#include <globaldefs.h>
#include "Combat/BattleHeapOwner.h"

extern "C" void func_ov003_02174890(char* obj);

// USA: func_ov017_021b2f2c
extern "C" ARM void func_ov017_021b2f2c(void*) {
	if (data_ov017_021d840c != 0) {
		func_ov003_02174890((char*)data_ov017_021d840c);
	}
}
