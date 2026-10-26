#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>

// USA: func_020a08d8
extern "C" ARM int func_020a08d8(Struct_02061c04* record) {
    unsigned int v = record->unknown_16_2_;
    unsigned int var1 = v * 100 / 944;
    if (var1 != 0) {
        return var1;
    }
    if (v != 0) {
        return 1;
    }
    return var1;
}
