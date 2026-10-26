#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>

// USA: func_020a0870
extern "C" ARM int func_020a0870(Struct_02061c04* record) {
    unsigned int v = record->unknown_14_0_;
    unsigned int var1 = v * 100 / 307;
    if (var1 != 0) {
        return var1;
    }
    if (v != 0) {
        return 1;
    }
    return var1;
}
