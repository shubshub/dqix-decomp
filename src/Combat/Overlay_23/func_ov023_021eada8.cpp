#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021eada8
extern "C" ARM int func_ov023_021eada8(void* arg0) {
    Struct_02061c04 record;
    func_020ac4c0(&record);
    func_ov017_021d6134(arg0, record.unknown_90_.unknown_18_0_);
    return 1;
}
