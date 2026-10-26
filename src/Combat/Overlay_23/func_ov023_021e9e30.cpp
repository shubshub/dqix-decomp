#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

extern "C" void func_ov017_021d6134(void* obj, int val);

// USA: func_ov023_021e9e30
extern "C" ARM int func_ov023_021e9e30(void* arg0) {
    Struct_02061c04 record;
    func_020ac4c0(&record);
    func_ov017_021d6134(arg0, record.unknown_28_0_);
    return 1;
}
