#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>

// USA: func_020a090c
extern "C" ARM int func_020a090c(Struct_02061c04* record) {
    unsigned int v = record->unknown_12_7_;
    unsigned int var1 = v * 100 / 448;
    if (var1 != 0) {
        return var1;
    }
    if (v != 0) {
        return 1;
    }
    return var1;
}
