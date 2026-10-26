#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov023_021e9f9c
extern "C" ARM int func_ov023_021e9f9c(void* arg0) {
    Struct_02061c04 record;
    func_020ac4c0(&record);
    unsigned int value = record.unknown48;
    if (value > 0x7fffffff) value = 0x7fffffff;
    func_ov017_021d6134(arg0, value);
    return 1;
}
