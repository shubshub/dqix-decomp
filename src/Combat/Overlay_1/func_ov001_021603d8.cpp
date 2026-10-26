#include <globaldefs.h>
#include "Graphics/LightingManager.h"

extern "C" void* Zone3D_GetInstance(void);
extern "C" int func_ov017_021d60f4(void* a);
extern "C" void func_ov001_021601f8(void* a, void* b);
extern "C" void Zone3D_Draw(void* big);

struct Struct_ov001_021603d8 { char unknown_0_[0x44]; int unknown_44_; char unknown_48_[0x54 - 0x48]; struct Struct_ov001_021603d8* unknown_54_; };
struct Struct_ov001_021603d8_2 {
#if defined(jpn)
    char unknown_0_[0x430];
#else
    char unknown1_0_[0x410];
#endif
    int unknown_410_;
#if defined(jpn)
    char unknown_434_[0x43c - 0x434];
#else
    char unknown_414_[0x41c - 0x414];
#endif
    struct Struct_ov001_021603d8* unknown_41c_;
#if defined(jpn)
    char unknown_440_[0x852 - 0x440];
#else
    char unknown_420_[0x832 - 0x420];
#endif
    unsigned char unknown_832_;
    unsigned char unknown_833_;
    unsigned char unknown_834_;
};
struct Struct_ov001_021603d8_3 { char unknown_0_[0x90]; int unknown_90_; int unknown_94_; int unknown_98_; };

struct Struct_ov001_02165880_41 {
    int unknown_0_;
    unsigned char unknown_4_[0x10 - 0x4];
    int unknown_10_;
    int unknown_14_;
    unsigned char unknown_18_[0x2c - 0x18];
    int unknown_2c_;
    int unknown_30_;
};
extern Struct_ov001_02165880_41 data_ov001_02165880;

struct Struct_ov001_02164d14 {
    unsigned char unknown_0_[0x10];
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
};
extern Struct_ov001_02164d14 data_ov001_02164d14;

extern int data_ov001_02164d24[];

// USA: func_ov001_021603d8
extern "C" ARM int func_ov001_021603d8(void* obj) {
    Big_021603d8* big = (Big_021603d8*)Zone3D_GetInstance();
    DataStruct_021603d8* d = (DataStruct_021603d8*)LightingManager::GetInstance();
    int idx = func_ov017_021d60f4(obj);
    d->field98 = idx;
    if (!(data_ov001_02165880.field14 & 1)) {
        data_ov001_02164d14.field10 = data_ov001_02165880.field0;
        data_ov001_02164d14.field14 = data_ov001_02165880.field10;
        data_ov001_02164d14.field18 = data_ov001_02165880.field30;
        data_ov001_02164d14.field1c = data_ov001_02165880.field2c;
        data_ov001_02165880.field14 |= 1;
    }
    var1->unknown_94_ = data_ov001_02164d24[var2];

    if (var0->unknown_410_ == 1) {
        if (var0->unknown_834_ != 0) {
            return 1;
        }
        Struct_ov001_021603d8* var3 = var0->unknown_41c_;
        while (var3 != NULL) {
            if (var3->unknown_44_ != 0) {
                func_ov001_021601f8((void*)var3->unknown_44_, (char*)var3 + 4);
            }
            var3 = var3->unknown_54_;
        }
        var0->unknown_834_ = 1;
    } else {
        int var4[4];
        var4[0] = data_ov001_02165880.unknown_0_;
        var4[1] = data_ov001_02165880.unknown_10_;
        var4[2] = data_ov001_02165880.unknown_30_;
        var4[3] = data_ov001_02165880.unknown_2c_;
        var1->unknown_94_ = var4[var2];
        var1->unknown_90_ = 0;
        ((LightingManager*)var1)->RecomputeAdvancedLighting();
    }

    big->field832 = 1;
    big->field833 = 1;
    Zone3D_Draw(big);
    return 1;
}
