#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

// USA: func_020a0460
extern "C" ARM void func_020a0460(Struct_02061c04* record, unsigned int amount) {
    unsigned int v = record->unknown_14_0_ + amount;
    if (v > 500) {
        v = 500;
    }
    record->unknown_14_0_ = v;
}
