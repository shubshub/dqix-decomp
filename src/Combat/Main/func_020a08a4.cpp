#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>

// USA: func_020a08a4
extern "C" ARM int func_020a08a4(Struct_02061c04* record) {
    unsigned int v = record->unknown_15_1_;
    unsigned int var1 = v * 100 / 232;
    if (var1 != 0) {
        return var1;
    }
    if (v != 0) {
        return 1;
    }
    return var1;
}
