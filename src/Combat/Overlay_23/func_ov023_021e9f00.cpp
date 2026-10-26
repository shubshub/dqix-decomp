#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov023_021e9f00
extern "C" ARM int func_ov023_021e9f00(void* arg0) {
    Struct_02061c04 record;
    func_020ac4c0(&record);
    func_ov017_021d6134(arg0, record.unknown_2a_6_);
    return 1;
}
