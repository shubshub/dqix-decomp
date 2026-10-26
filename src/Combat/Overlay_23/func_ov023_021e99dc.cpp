#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>

extern "C" int func_020ac4c0(void* dst);

extern "C" int func_020a090c(Struct_02061c04* p);

extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov023_021e99dc
extern "C" ARM int func_ov023_021e99dc(void* obj) {
	Struct_02061c04 record;
	func_020ac4c0(&record);
	int var1 = func_020a090c(&record);
	func_ov017_021d6134(obj, var1);
	return 1;
}
