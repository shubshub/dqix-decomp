#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>

extern "C" int func_020ac4c0(void* dst);

extern "C" Struct_020ac4f8 func_ov023_021e8fe8(Struct_020ac4f8 v, int kind);
struct Struct_0209cf44 {
    int type;
    union {
        int unknown_0_;
        float unknown1_0_;
        Struct_0209cf44* unknown2_0_;
    } value;
};

extern "C" void func_ov017_021d6134(Struct_0209cf44* output, int val);

// USA: func_ov023_021e9be4
extern "C" ARM int func_ov023_021e9be4(void* obj) {
    Struct_0209cf44* var0 = (Struct_0209cf44*)obj;
    Struct_02061c04 record;
    func_020ac4c0(&record);

    Struct_020ac4f8 result = func_ov023_021e8fe8(record.unknown_0_.elapsed, 0);

    func_ov017_021d6134(&var0[0], result.hours);
    func_ov017_021d6134(&var0[1], result.minutes);
    return 1;
}
