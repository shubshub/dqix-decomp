#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>

// USA: func_020ac614
extern "C" ARM void func_020ac614(struct Struct_020ac4f8* arg0, int amount) {
    arg0->hours += amount;
    if (arg0->hours > 0x270f) {
        arg0->hours = 0x270f;
        arg0->minutes = 0x3b;
        arg0->seconds = 0x3b;
    }
}
