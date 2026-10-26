#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>

extern "C" int func_020ac4c0(void* dst);
extern "C" int func_020a0870(Struct_02061c04* p);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021e99a8
extern "C" ARM int func_ov023_021e99a8(void* obj) {
    Struct_02061c04 record;
    func_020ac4c0(&record);
    int var1 = func_020a0870(&record);
    func_ov017_021d6134(obj, var1);
    return 1;
}
