#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { Enum_ov001_0215eb3c_716 = 0x27c };
#else
enum { Enum_ov001_0215eb3c_716 = 0x2cc };
#endif

extern "C" int func_ov017_021d60f4(void*);
void BackupPairTables0207dfac(char* tables);

struct Struct_ov001_0215eb3c {
    int unknown_0_[10];
    int unknown_28_[10];
    int unknown_50_;
    int unknown_54_;
    int unknown_58_[2];
    int unknown_60_[2];
};

// USA: func_ov001_0215eb3c
extern "C" ARM int func_ov001_0215eb3c(void* arg0, int arg1) {
    GameState* var0;
    int var1;
    int var2;
    Struct_ov001_0215eb3c* var3;
    int var4;
    int var5;
    int var6;
    int var7;

    var0 = GameState::GetInstance();
    if (var0 == NULL) {
        return 0;
    }
    base = (int)bs->GetResources();
    if (base == 0) {
        return 0;
    }
    var7 = func_ov017_021d60f4(arg0);
    if (var7 < 0) {
        var2 = var1 + Enum_ov001_0215eb3c_716;
        var2 = var2 + 0xbd0;
    } else {
        var2 = var1 + Enum_ov001_0215eb3c_716 + var7 * 0x70;
    }
    if (var2 == 0) {
        return 0;
    }
    func_0207dfac((char*)var2);
    if (arg1 >= 2 && func_ov017_021d60f4((char*)arg0 + 0x8) != 0) {
        var2 = var1 + Enum_ov001_0215eb3c_716;
        var3 = (Struct_ov001_0215eb3c*)(var2 + 0xbd0);
        var4 = 0;
        for (var5 = 0; var5 < 10; var5++) {
            var4 += abs(var3->unknown_0_[var5] - var3->unknown_28_[var5]);
        }
        var4 = 0;
        for (var5 = 0; var5 < 2; var5++) {
            var4 += abs(var3->unknown_58_[var5] - var3->unknown_60_[var5]);
        }
        if (var7 >= 0) {
            var3 = (Struct_ov001_0215eb3c*)(var1 + Enum_ov001_0215eb3c_716 + var7 * 0x70);
            var4 = 0;
            for (var6 = 0; var6 < 10; var6++) {
                var4 += abs(var3->unknown_0_[var6] - var3->unknown_28_[var6]);
            }
            var4 = 0;
            for (var6 = 0; var6 < 2; var6++) {
                var4 += abs(var3->unknown_58_[var6] - var3->unknown_60_[var6]);
            }
        }
    }
    return 1;
}
