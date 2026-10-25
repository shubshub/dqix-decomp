#include <globaldefs.h>
#include "Graphics/LightingManager.h"
#include "GameState/GameState.h"

extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_ov001_021601f8(void* a, void* b);

struct Struct_ov001_02165880_42 {
    int unknown_0_;
    char unknown_4_[0xc - 4];
    int unknown_c_;
    int unknown_10_;
    char unknown_14_[0x2c - 0x10 - 4];
    int unknown_2c_;
    int unknown_30_;
};
extern Struct_ov001_02165880_42 data_ov001_02165880;

struct Struct_ov001_02164d14_2 { char unknown_0_[0x20]; int unknown_20_, unknown_24_, unknown_28_, unknown_2c_; };
extern Struct_ov001_02164d14_2 data_ov001_02164d14;

extern int data_ov001_02164d34[];

struct Struct_ov001_02160504 { char unknown_0_[0x44]; int unknown_44_; char unknown_48_[0x54 - 0x48]; Struct_ov001_02160504* unknown_54_; };
struct Struct_ov001_02160504_2 {
    
#if defined(jpn)
    char unknown_0_[0x430];
#else
    char unknown1_0_[0x410];
#endif

    int unknown_410_;
    char unknown_414_[0x41c - 0x414];
    Struct_ov001_02160504* unknown_41c_;
    char unknown_420_[0x834 - 0x420];
    unsigned char unknown_834_;
};
struct Struct_ov001_02160504_3 { char unknown_0_[0x94]; int unknown_94_; int unknown_98_; };

// USA: func_ov001_02160504
extern "C" ARM int func_ov001_02160504(void) {
    GameState* battle = GameState::GetInstance();
    Big02160504* big = (Big02160504*)Zone3D_GetInstance();
    DataStruct02160504* d = (DataStruct02160504*)LightingManager::GetInstance();
    if (big->field834 != 0) return 1;
    int idx = battle->GetTimeOfDay();
    d->field98 = idx;
    if (!(data_ov001_02165880.flag & 1)) {
        data_ov001_02164d14.f20 = data_ov001_02165880.field0;
        data_ov001_02164d14.f24 = data_ov001_02165880.field10;
        data_ov001_02164d14.f28 = data_ov001_02165880.field30;
        data_ov001_02164d14.f2c = data_ov001_02165880.field2c;
        data_ov001_02165880.flag |= 1;
    }
    var2->unknown_94_ = data_ov001_02164d34[var3];
    if (var1->unknown_410_ == 1) {
        Struct_ov001_02160504* var4 = var1->unknown_41c_;
        while (var4 != NULL) {
            if (var4->unknown_44_ != 0) {
                func_ov001_021601f8((void*)var4->unknown_44_, (char*)var4 + 4);
            }
            var4 = var4->unknown_54_;
        }
        var1->unknown_834_ = 1;
    }
    return 1;
}
